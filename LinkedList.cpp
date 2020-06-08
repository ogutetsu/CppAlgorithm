#include <iostream>

using namespace std;


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
		first = nullptr;
		last = nullptr;
	}

	//���X�g�̐擪�Ƀf�[�^��ǉ�
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

	//key�����ŏ��̗v�f���폜����
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

	//�擪�̗v�f���폜
	void DeleteFirst()
	{
		ChainList<T>* l = first;
		first->GetTail()->SetHead(nullptr);
		first = first->GetTail();
		delete l;
	}

	//�����̗v�f���폜
	void DeleteLast()
	{
		ChainList<T>* l = last;
		last->GetHead()->SetTail(nullptr);
		last = last->GetHead();
		delete l;
	}


	//�o��
	void Print()
	{
		ChainList<T>* node = first;
		while(node)
		{
			cout << node->GetValue() << " ";
			node = node->GetTail();
		}
		cout << endl;
	}
	


	//�e�X�g�p���\�b�h
	T GetTopValue()
	{
		return first->GetValue();
	}

	T GetLastValue()
	{
		return last->GetValue();
	}



private:
	//�擪�̃f�[�^
	ChainList<T>* first;

	//�����̃f�[�^
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
