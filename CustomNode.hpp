#pragma once
// debug macros
// #include "macros.h"

template <class Value>
class QueueNode {
	template<class _Value>
	friend class CustomQueue;
private:
	QueueNode<Value>* next;
	Value value;
public:
	// constructors
	QueueNode() {
		this->value = Value();
		this->next  = nullptr;
	}

	QueueNode(Value value) {
		this->value = value;
		this->next  = nullptr;
	}
	// destructor
	~QueueNode() {}
};