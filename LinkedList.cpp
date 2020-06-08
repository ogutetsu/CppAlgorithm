#include <iostream>

template<class T>
class ChainList
{
public:
	ChainList(T v) : value(v) { head = nullptr; tail = nullptr; }
	ChainList* GetHead() { return head; }
	ChainList* GetTail() { return tail; }
	void SetHead(ChainList* l) { head = l; }
	void SetTail(ChainList* l) { tail = l; }
	T GetValue() { return value; }

private:
	ChainList* head;
	ChainList* tail;
	T value;
};

template<class T>
class LinkedListData
{
public:
	LinkedListData()
	{
	}
	void Insert(T v)
	{
		if (l == nullptr)
		{
			l = new ChainList<T>(v);
		}
		else
		{
			l->SetHead(new ChainList<T>(v));
			l->GetHead()->SetTail(l);
			l = l->GetHead();
		}
	}

	void Delete(T key)
	{
		ChainList<T>* top = l;
		while (top)
		{
			if (top->GetValue() == key)
			{
				break;
			}
			top = top->GetTail();
			if (top == nullptr) return;
		}
		ChainList<T>* h = top->GetHead();
		ChainList<T>* t = top->GetTail();
		if (h) h->SetTail(t);
		if (t) t->SetHead(h);
		delete top;
	}



	T GetTopValue()
	{
		return l->GetValue();
	}




private:
	ChainList<T>* l;


};





void LinkedList()
{
	
}
