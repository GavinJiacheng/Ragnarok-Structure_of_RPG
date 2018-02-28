#include "Linkedlist.h"


template<class Any>
linkedlist<Any>::linkedlist()
{
	head = new Node<Any>(0);
	tail = head;
	curr = head;
	size = 1;
}

template<class Any>
void linkedlist<Any>::append(Any* item)
{
	Node<Any>* newNode = new Node<Any>(item);
	newNode->prev = tail;
	tail = newNode;
	curr = tail;
	size++;
}

template<class Any>
int linkedlist<Any>::listsize()
{
	return size;
}


template<class Any>
void linkedlist<Any>::add(int index, Any* item)
{
	if (index > size || index < 0)
		return;
	curr = head;
	for (int i = 1; i < index; i++)
	{
		curr = curr->next;
	}
	Node<Any> * newNode = new Node<Any>(item);
	newNode->next = curr->next;
	newNode->prev = curr;
	curr = newNode;
	size++;
}

template<class Any>
Any* linkedlist<Any>::getindex(int index)
{
	if (index > size || index < 0)
		return false;
	curr = head;
	for (int i = 1; i < index; i++)
	{
		curr = curr->next;
	}
	return curr -> item;
}

template<class Any>
Any* linkedlist<Any>::removecurr()
{
	if (curr->next == NULL)
	{
		Any* item = removelast();
		return item;
	}
	if (curr->prev == NULL)
	{
		Any* item = removefirst();
		return item;
	}
	Any* item = curr->item;
	curr->prev->next = curr->next;
	curr->next->prev = curr->prev;
	Node<Any>* deleteone = curr;
	curr = curr - next;
	delete deleteone;
	deleteone = NULL;
	size--;
	return item;
}

template<class Any>
Any* linkedlist<Any>::remove(int index)
{
	if (index > size || index < 0)
		return false;
	curr = head;
	for (int i = 1; i < index; i++)
	{
		curr = curr->next;
	}
	Any* item = removecurr();
	return item;
}

template<class Any>
Any* linkedlist<Any>::removelast()
{
	Any* item = tail->item;
	if (size == 1)
	{
		sleeplist();
		return item;
	}
	Node<Any>* deleteone = tail;
	if (curr == tail)
		curr = curr->prev;
	tail = tail->prev;
	tail->next = NULL;
	delete deleteone;
	deleteone = NULL;
	size--;
	return item;
}

template<class Any>
Any* linkedlist<Any>::removefirst()
{
	Any* item = head - item;
	if (size == 1)
	{
		sleeplist();
		return item;
	}
	Node<Any>* deleteone = head;
	if (curr == head)
		curr = curr->next;
	head = head->next;
	head->prev = NULL;
	delete deleteone;
	deleteone = NULL;
	size--;
	return item;
}

template<class Any>
Any* linkedlist<Any>::currentitem()
{
	return curr->item;
}

template<class Any>
Any* linkedlist<Any>::lastitem()
{
	return tail->item;
}

template<class Any>
Any* linkedlist<Any>::firstitem()
{
	return head->item;
}

template<class Any>
void linkedlist<Any>::sleeplist()
{
	head->item = 0;
}

template<class Any>
linkedlist<Any>::~linkedlist()
{
	curr = head;
	Node<Any>* delteone
	for (int i = 0; i < size; i++)
	{
		delteone = curr;
		curr = curr->next;
		delete deleteone;
		deleteone = NULL;
	}
	delete curr;
	curr = NULL;
	head = NULL;
	tail = NULL;
	size = 0;
}