#include "MaximumProfit.h"

#include <iostream>
#include <algorithm>
#include <filesystem>
#include <random>


using namespace std;
static const int MAX = 200'000;


int MaximumProfit::Run()
{
	int R[MAX], n;

	cout << "������� -> ";

	cin >> n;

	for (int i = 0; i < n; i++) cin >> R[i];

	//�ł������̍ŏ��l
	int maxv = -2'000'000'000;
	int minv = R[0];

	for (int i = 1; i < n; i++)
	{
		maxv = max(maxv, R[i] - minv);	//�ő�l���X�V
		minv = min(minv, R[i]);		//�����܂ł̍ŏ��l
	}

	cout << "�ő�l : " << maxv << endl;
	return 0;
}



/*
 * ����� 2 <= N <= 200,000
 * 1 <= R <= 10,000,000,000
 */
void MaximumProfit::TestGen()
{
	Test1();
	Test2();
	Test3();
	Test4();
}



void MaximumProfit::Test1()
{
	string file = TestFileMaker("MaximumProfit", 1);

	ofstream of(file);

	of << 2 << endl;
	of << 10 << endl << 20 << endl;

}

void MaximumProfit::Test2()
{
	string file = TestFileMaker("MaximumProfit", 2);

	ofstream of(file);

	of << 6 << endl;
	of << 5 << endl;
	of << 3 << endl;
	of << 1 << endl;
	of << 3 << endl;
	of << 4 << endl;
	of << 3 << endl;
}

void MaximumProfit::Test3()
{
	string file = TestFileMaker("MaximumProfit", 3);

	ofstream of(file);

	of << 3 << endl;
	of << 4 << endl;
	of << 3 << endl;
	of << 2 << endl;

}

void MaximumProfit::Test4()
{
	string file = TestFileMaker("MaximumProfit", 4);

	ofstream of(file);

	int N = 200'000;
	int R = 10'000'000'000;
	of << N << endl;


	std::random_device seed;
	std::mt19937_64 engine(seed());
	std::uniform_int_distribution<int> dist(0, R);
	for (int i = 0; i < N; i++)
	{
		//�����_���ɐ��l�����߂�
		of << dist(engine) << endl;
	}


}


