#include <functional>
#include <iostream>


using namespace std;

template<typename T>
class StackData
{
public:
	StackData() { depth = 0; }

	void Push(T v)
	{
		
		s[depth] = v;
		depth++;
	}

	T Pop()
	{
		return s[--depth];
	}


	bool IsEmpty()
	{
		return depth == 0;
	}

	int Size()
	{
		return depth;
	}
	

private:
	T s[100];
	int depth;
};




void Stack()
{

	cout << "入力例" << endl << "1 2 + 3 4 - *" << endl;
	
	
	
	StackData<int> s;
	
	int i = 0;
	int v1, v2;
	string in;
	while(cin >> in)
	{
		switch (in[0])
		{
		case '+':
			v1 = s.Pop();
			v2 = s.Pop();
			s.Push(v2 + v1);
			break;
		case '-':
			v1 = s.Pop();
			v2 = s.Pop();
			s.Push(v2 - v1);
			break;
		case '*':
			v1 = s.Pop();
			v2 = s.Pop();
			s.Push(v2 * v1);
			break;
		case '/':
			v1 = s.Pop();
			v2 = s.Pop();
			s.Push(v2 / v1);
			break;
		//数値はスタックへ確保
		default:
			s.Push(atoi(in.c_str()));
			break;
		}
		
	}

	cout << s.Pop() << endl;

	cin.clear();
	
}


