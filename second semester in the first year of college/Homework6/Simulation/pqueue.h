#include "list.h"
template<class T>
class PQueue
{
	List<T> queueL;
public:
	PQueue(){}
	~PQueue(){}
	int Size() const { return queueL.Size();}
	bool Empty() const { return queueL.Empty();}
	const T & Front() const { return queueL.Front();}
	void Push(const T & item) { queueL.Push_back(item);}
	T Pop();
	void Clear() { queueL.Clear();}
};

template<class T>
T PQueue<T>::Pop()
{
	List<T>::iterator itr, min = queueL.Begin();
	for (itr = min; itr != queueL.End(); ++itr)
		if((*itr)<(*min))
			min = itr;
	T item = * min;
	queueL.Erase(min);
	return item;
}
