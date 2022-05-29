#pragma once

#include "AbstractList.h"
#include "Iterator.h"
#include <iostream>

class BufferedList : public List {
private:
	Node* buffer;
	int length;
public:
	class ListIterator : public Iterator {
	private:
		Node* p;
		Node* buf;
		int index;
		int length;
	public:
		ListIterator(BufferedList& list) {
			buf = list.getBuffer();
			length = list.getLength();
		}
		void start() override {
			p = buf;
			index = -1;
		}
		void next() override {
			p = p->next;
			index++;
		}
		Node* getNow() override {
			return p;
		}
		bool finish() override {
			return index >= length - 1;
		}
	};
	BufferedList();
	BufferedList(const BufferedList&);
	BufferedList(BufferedList&&);
	~BufferedList();
	void addElem(Iterator* it, int elem) override {
		Node* p = new Node;
		if (length == 0) {
			p->next = buffer;
			p->prev = buffer;
			p->data = elem;
			buffer->next = p;
			buffer->prev = p;
		}
		else {
			Node* t = it->getNow();
			t->next->prev = p;
			p->next = t->next;
			p->prev = t;
			p->data = elem;
			t->next = p;
		}
		length++;
	}
	Node* getBuffer() override {
		return buffer;
	}
	void deleteElem(Iterator* it)override {
		Node* p = it->getNow();
		p->next->prev = p->prev;
		p->prev->next = p->next;
		delete p;
		length--;
	}
	Iterator* findElem(int elem) override{
		Node* p = buffer->next;
		int i = 0;
		while (p != buffer) {
			i++;
			if (p->data == elem) {
				break;
			}
			p = p->next;
		}
		if (p != buffer) {
			ListIterator* it = new ListIterator(*this);
			it->start();
			for (int j = 0; j < i;j++) {
				it->next();
			}
			return it;
		}
		return nullptr;
	}
	void empty() {
		Node* p = buffer;
		Node* t = NULL;
		while (p->next != buffer) {
			p = p->next;
			delete t;
			t = p;
		}
		delete t;
		length = 0;
	}
	bool isEmpty() override { return length == 0; }
	int getLength()override { return length; }
	Iterator* start() override {
		Iterator* it = new ListIterator(*this);
		it->start();
		it->next();
		return it;
	}
	BufferedList operator=(BufferedList list) {
		if (this != &list){
			empty();
			buffer = list.buffer;
			length = list.length;
		}
		return *this;
	}
};