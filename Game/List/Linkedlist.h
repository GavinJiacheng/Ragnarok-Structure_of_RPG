#ifndef LINKEDLIST_H
#define LINKEDLIST_H


template<class Any>
class linkedlist
{
public:
	linkedlist()
	{
		head = new Node<Any>(0);
		tail = head;
		curr = head;
		size = 1;
	}

	~linkedlist()
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

	void append(Any* item)
	{
		Node<Any>* newNode = new Node<Any>(item);
		newNode->prev = tail;
		tail->next = newNode;
		tail = newNode;
		curr = tail;
		if (size == 1)
			head->next = tail;
		size++;
	}

	void add(int index, Any* item)
	{
		if (index > size || index < 0)
			return;
		if (index == 1 || size == 1) 
		{
			append(item);
			return;
		}
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

	Any* getindex(int index)
	{
		if (index > size || index < 0)
			return false;
		curr = head;
		for (int i = 1; i < index; i++)
		{
			curr = curr->next;
		}
		return curr->item;
	}
	//int indexOf(Any* item);
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
		curr = curr -> next;
		delete deleteone;
		deleteone = NULL;
		size--;
		return item;
	}

	Any* remove(int index)
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

	Any* removelast()
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

	Any* removefirst()
	{
		Any* item = head -> item;
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

	Any* currentitem()
	{
		return curr->item;
	}

	Any* lastitem()
	{
		return tail->item;
	}

	Any* firstitem()
	{
		return head->item;
	}

	void sleeplist()
	{
		head->item = 0;
	}

	int listsize()
	{
		return size;
	}

private:
	template<class Any>
	struct Node 
	{
		Any* item;
		Node<Any>* prev;
		Node<Any>* next;
		Node<Any>(Any* it)
		{
			item = it; next = NULL; prev = NULL;
		}
	};

	int size;
	Node<Any>* head;
	Node<Any>* tail;
	Node<Any>* curr;
};



#endif


