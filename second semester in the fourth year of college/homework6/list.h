// list.h
#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <stdlib.h>

template<class T>
class List
{
	struct Node
	{
		T data;
		Node * prev;
		Node * next;
		Node(const T & d = T(), Node * p = NULL, Node * n = NULL):data(d), prev(p), next(n){}
	};
	Node * head;
	Node * tail;
	int size;
	void Init()
	{
		size = 0;
		head = new Node;
		tail = new Node;
		head->next = tail;
		tail->prev = head;
	}

public:
	class const_iterator
	{
		//protected:
	public:
		Node * current;
		T & retrieve() const { return current->data; }
		const_iterator(Node * p):current(p){}
		friend class List<T>;

	public:
		const_iterator():current(NULL){}
		const T & operator*() const { return retrieve(); }

		const_iterator & operator++()
		{
			current = current->next;
			return *this;
		}
		const_iterator operator++(int)
		{
			const_iterator old = *this;
			++(*this);
			return old;
		}
		const_iterator & operator--()
		{
			current = current->prev;
			return *this;
		}
		const_iterator operator--(int)
		{
			const_iterator old = *this;
			--(*this);
			return old;
		}

		bool operator==(const const_iterator & rhs) const { return current == rhs.current; }
		bool operator!=(const const_iterator & rhs) const { return current != rhs.current; }
	};

	class iterator:public const_iterator
	{
	protected:
		iterator(Node * p):const_iterator(p){}
		friend class List<T>;

	public:
		iterator(){}
		T & operator*() { return retrieve(); }
		const T & operator*() const { return const_iterator::operator*(); }

		iterator & operator++()
		{
			current = current->next;
			return *this;
		}
		iterator operator++(int)
		{
			iterator old = *this;
			++(*this);
			return old;
		}
		iterator & operator--()
		{
			current = current->prev;
			return *this;
		}
		iterator operator--(int)
		{
			iterator old = *this;
			--(*this);
			return old;
		}
	};

	List(){ Init(); }
	List(const List<T> & l)
	{
		Init();
		operator=(l);
	}
	~List()
	{
		Clear();
		delete head;
		delete tail;
	}
	const List & operator=(const List & l);

	iterator Begin() { return iterator(head->next); }
	const_iterator Begin() const { return const_iterator(head->next); }
	iterator End() { return iterator(tail); }
	const_iterator End() const { return const_iterator(tail); }

	T & Front() { return * Begin(); }
	const T & Front() const { return * Begin(); }
	T & Back() { return * --End(); }
	const T & Back() const { return * --End(); }
	void Push_front(const T & item) { Insert(Begin(), item); }
	void Push_back(const T & item) { Insert(End(), item); }
	void Pop_front() { Erase(Begin()); }
	void Pop_back() { Erase(--End()); }
	iterator Erase(iterator itr);
	iterator Insert(iterator itr, const T & item);

	int Size() const { return size; }
	bool Empty() const { return size == 0; }
	void Clear() { while(!Empty()) Pop_front(); }
};

template<class T>
const List<T> & List<T>::operator=(const List<T> & l)
{
	Clear();
	for(const_iterator itr = l.Begin(); itr != l.End(); ++itr)
		Push_back(*itr);
	return *this;
}

template<class T>
typename List<T>::iterator List<T>::Erase(iterator itr)
{
	Node * p = itr.current;
	iterator re(p->next);
	p->prev->next = p->next;
	p->next->prev = p->prev;
	delete p;
	size--;
	return re;
}

template<class T>
typename List<T>::iterator List<T>::Insert(iterator itr, const T & item)
{
	Node * p = itr.current;
	size++;
	p->prev->next = new Node(item, p->prev, p);			//666!
	p->prev = p->prev->next;		//666!
	return iterator(p->prev);
}

#endif
