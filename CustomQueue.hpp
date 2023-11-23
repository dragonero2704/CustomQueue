
#include <functional>
#include "CustomNode.hpp"

typedef unsigned long long size_t;

template <class Value>
class CustomQueue
{
protected:
	QueueNode<Value> *_top;
	QueueNode<Value> *_last;
	size_t _size;
	// recursive deletion method
	void recDestroy(QueueNode<Value> node)
	{
		if (node->next != nullptr)
			recDestroy(node->next);
		delete node;
	}

public:
	// constructor
	CustomQueue()
	{
		this->_top = nullptr;
		this->_last = nullptr;
		this->_size = 0;
	}
	CustomQueue(Value value)
	{
		this->_top = new QueueNode<Value>(value);
		this->_last = this->_top;
		this->_size = 1;
	}
	CustomQueue(Value *start, Value *end)
	{
		this->_top = new QueueNode<Value>(*start);
		this->_last = this->_top;
		start++;
		this->_size = 1;
		while (start != end)
		{
			this->_last->next = new QueueNode<Value>(*start);
			start++;
			this->_size++;
		}
	}
	// destructor
	~CustomQueue()
	{
		// iterative approach
		QueueNode<Value> *current = this->_top;
		QueueNode<Value> *next;
		while (current != nullptr)
		{
			next = current->next;
			delete current;
			current = next;
		}
		this->_top = nullptr;
		this->_last = nullptr;
		this->_size = 0;
		// recursive approah
		// recDestroy(this->top);
	}

	// returns a constant reference to the top value
	Value front() const
	{
		return this->_top->value;
	}
	const Value &back() const
	{
		return this->_last->value;
	}

	void push(Value value)
	{
		this->_last->next = new QueueNode<Value>(value);
		this->_last = this->_last->next;
		this->_size++;
	}

	void pop()
	{
		if (this->_top == nullptr)
			return; // the queue is empty
		QueueNode<Value> *newTop = this->_top->next;
		delete this->_top;
		this->_top = newTop;
		this->_size--;
	}

	void empty()
	{
		~CustomQueue();
	}

	bool isempty()
	{
		return this->_size == 0;
	}

	size_t size()
	{
		return this->_size;
	}

	
};

template <class Value, class Comparator = std::less<Value>>
class PriorityQueue : public CustomQueue<Value>
{
public:
	PriorityQueue()
	{
		this->_top = nullptr;
		this->_last = nullptr;
		this->_size = 0;
	}
	PriorityQueue(const Value &value)
	{
		this->_top = new QueueNode<Value>(value);
		this->_last = this->_top;
		this->_size = 1;
	}

	~PriorityQueue()
	{
		// iterative approach
		QueueNode<Value> *current = this->_top;
		QueueNode<Value> *next;
		while (current != nullptr)
		{
			next = current->next;
			delete current;
			current = next;
		}
		this->_top = nullptr;
		this->_last = nullptr;
		this->_size = 0;
	}
	// push method override
	void push(const Value &value)
	{

	}
};