#include <iostream>
#include <algorithm>


using namespace std;
static const int MAX = 200'000;


void MaximumProfit()
{
	int R[MAX], n;

	cout << "������� -> ";
	
	cin >> n;

	for (int i = 0; i < n; i++) cin >> R[i];

	//�ł������̍ŏ��l
	int maxv = -2'000'000'000;
	int minv = R[0];

	for(int i = 1; i < n; i++)
	{
		maxv = max(maxv, R[i] - minv);	//�ő�l���X�V
		minv = min(minv, R[i]);		//�����܂ł̍ŏ��l
	}

	cout << "�ő�l : " << maxv << endl;
	
}


