#include <iostream>

using namespace std;


template<class T>
class ChainList
{
public:
	ChainList(T v) : value(v) { prev = nullptr; next = nullptr; }
	ChainList* GetPrev() { return prev; }
	ChainList* GetNext() { return next; }
	void SetPrev(ChainList* l) { prev = l; }
	void SetNext(ChainList* l) { next = l; }
	T GetValue() { return value; }

private:
	ChainList* prev;
	ChainList* next;
	T value;
};

template<class T>
class LinkedListData
{
public:
	LinkedListData()
	{
		first = nullptr;
		last = nullptr;
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
			first->SetPrev(new ChainList<T>(v));
			first->GetPrev()->SetNext(first);
			first = first->GetPrev();
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
			top = top->GetNext();
			if (top == nullptr) return;
		}
		ChainList<T>* h = top->GetPrev();
		ChainList<T>* t = top->GetNext();
		if (h) h->SetNext(t);
		if (t)
		{
			t->SetPrev(h);
			if (t == last)
			{
				last = t->GetPrev();
			}

		}
		delete top;
	}

	//先頭の要素を削除
	void DeleteFirst()
	{
		ChainList<T>* l = first;
		first->GetNext()->SetPrev(nullptr);
		first = first->GetNext();
		delete l;
	}

	//末尾の要素を削除
	void DeleteLast()
	{
		ChainList<T>* l = last;
		last->GetPrev()->SetNext(nullptr);
		last = last->GetPrev();
		delete l;
	}


	//出力
	void Print()
	{
		ChainList<T>* node = first;
		while(node)
		{
			cout << node->GetValue() << " ";
			node = node->GetNext();
		}
		cout << endl;
	}
	


	//テスト用メソッド
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
	int N;
	cin >> N;

	LinkedListData<int> data;

	for(int i = 0; i < N; i++)
	{
		string cmd;
		int v;
		cin >> cmd >> v;

		if(cmd == "insert")
		{
			data.Insert(v);
		}
		else if(cmd == "delete")
		{
			data.Delete(v);
		}
		else if(cmd == "deleteFirst")
		{
			data.DeleteFirst();
		}
		else if(cmd == "deleteLast")
		{
			data.DeleteLast();
		}

	}

	data.Print();
	
	
}
