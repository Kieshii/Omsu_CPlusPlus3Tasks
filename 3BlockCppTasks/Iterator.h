#pragma once

struct Node
{
	int data;
	Node* next;
	Node* prev;
};

class Iterator {
public:
	virtual void start() = 0;
	virtual void next() = 0;
	virtual bool finish()  = 0;
	virtual Node* getNow()  = 0;
};
