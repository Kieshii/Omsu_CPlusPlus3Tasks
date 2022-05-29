#include <iostream>
#include "BufferedList.h"

BufferedList::BufferedList() {
	buffer = new Node;
	buffer->next = buffer;
	buffer->prev = buffer;
	buffer->data = -2;
	length = 0;
}
BufferedList::BufferedList(const BufferedList& list) {
	buffer = new Node;
	Node* p = list.buffer->next;
	Node* t;
	Node* tl = buffer;
	while (p != list.buffer) {
		t = new Node;
		tl->next = t;
		t->prev = tl;
		t->data = p->data;
		tl = tl->next;
		p = p->next;
	}
	buffer->prev = tl;
	tl->next = buffer;
	length = list.length;
}
BufferedList::BufferedList(BufferedList&& list):buffer(nullptr), length(0) {
	buffer = list.buffer;
	length = list.length;
	list.buffer = nullptr;
	list.length = 0;
}
BufferedList::~BufferedList() {
	if(length != 0) {
		empty();
	}
	delete buffer;
}
