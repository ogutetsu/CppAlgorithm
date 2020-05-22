#include <functional>
#include <iostream>


using namespace std;

struct Card { char suit, value; };


void StableSort()
{

	function<void(Card[], int)> Bubble = [](Card* C, int N)
	{
		for(int i = 0; i < N-1; i++)
		{
			for(int j = N-1; j >= i+1; j--)
			{
				if(C[j].value < C[j-1].value)
				{
					swap(C[j], C[j - 1]);
				}
			}
		}
	};


	function<void(Card[], int)> Selection = [](Card* C, int N)
	{
		for (int i = 0; i < N - 1; i++)
		{
			int minj = i;
			for (int j = i; j < N; j++)
			{
				if (C[j].value < C[minj].value)
				{
					minj = j;
				}
			}
			swap(C[i], C[minj]);
		}

	};


	//�ǂ��炩�Ɉ���\�[�g���ʂ����邱�Ƃł��̃e�[�u���Ɣ�r���邱�Ƃ�
	//���肵���\�[�g���ʂ��ǂ����� O(N)�ł킩��
	function<bool(Card[], Card[], int)> isStable = [](Card* C1, Card* C2, int N)
	{
		for(int i = 0; i < N; i++)
		{
			if (C1[i].suit != C2[i].suit) return false;
		}
	
		return true;
	};

	function<void(Card[], int)> Print = [](Card* C1, int N)
	{
		for(int i = 0; i < N; i++)
		{
			cout << C1[i].suit << C1[i].value << " ";
		}
		cout << endl;
	};

	Card C1[100], C2[100];
	int N;

	cout << "������� -> ";
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		cin >> C1[i].suit >> C1[i].value;
	}
	for (int i = 0; i < N; i++) C2[i] = C1[i];

	Bubble(C1, N);
	Selection(C2, N);

	
	Print(C1, N);	//�o�u���\�[�g����
	cout << "Stable" << endl;
	
	Print(C2, N);	//�I���\�[�g����

	bool stable = isStable(C1, C2, N);
	if(stable)
	{
		cout << "Stable" << endl;
	}
	else
	{
		cout << "Not stable" << endl;
	}
		
}


