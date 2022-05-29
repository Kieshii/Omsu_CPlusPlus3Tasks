#pragma once
#include "Iterator.h"


class List {
public:
	virtual Node* getBuffer() = 0;
	virtual void addElem(Iterator* it, int elem) = 0;
	virtual void deleteElem(Iterator* it) = 0;
	virtual Iterator* findElem(int elem) = 0;
	virtual void empty() = 0;
	virtual bool isEmpty() = 0;
	virtual int getLength() = 0;
	virtual Iterator* start() = 0;
};
