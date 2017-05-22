//stack.h
#ifndef STACK_H
#define STACK_H
#include "list.h"

template <class T>
class Stack
{
	List<T> stackL;
public:
	Stack(){}
	~Stack(){}
	int Size() const { return stackL.Size(); }
	bool Empty() const { return stackL.Empty(); }
	const T & Top() const { return stackL.Back(); }
	T Pop()
	{
		T item = stackL.Back();
		stackL.Pop_back();
		return item;
	}
	void Push(const T & item) { stackL.Push_back(item); }
	void Clear() { stackL.Clear(); }
};
#endif
