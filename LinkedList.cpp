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

	//リストの先頭にデータを追加
	void Insert(T v)
	{
		if (first == nullptr)
		{
			first = new ChainList<T>(v);
			last = first;
		}
		else
		{
			first->SetHead(new ChainList<T>(v));
			first->GetHead()->SetTail(first);
			first = first->GetHead();
		}
	}

	//keyを持つ最初の要素を削除する
	void Delete(T key)
	{
		ChainList<T>* top = first;
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
		if (t)
		{
			t->SetHead(h);
			if (t == last)
			{
				last = t->GetHead();
			}

		}
		delete top;
	}

	//先頭の要素を削除
	void DeleteFirst()
	{
		ChainList<T>* l = first;
		first->GetTail()->SetHead(nullptr);
		first = first->GetTail();
		delete l;
	}

	//末尾の要素を削除
	void DeleteLast()
	{
		ChainList<T>* l = last;
		last->GetHead()->SetTail(nullptr);
		last = last->GetHead();
		delete l;
	}


	T GetTopValue()
	{
		return first->GetValue();
	}

	T GetLastValue()
	{
		return last->GetValue();
	}



private:
	//先頭のデータ
	ChainList<T>* first;

	//末尾のデータ
	ChainList<T>* last;

};





void LinkedList()
{
	
}
