﻿#include "BubbleSort.h"

#include <functional>
#include <iostream>

using namespace std;


//最悪のケースでは O(N²)になる
int BubbleSort::Run()
{
	
	function<int(int[], int)> sort = [](int* A, int N)
	{
		int sw = 0;
		bool flag = 1;
		for(int i = 0; flag; i++)
		{
			flag = 0;
			for(int j = N-1; j >= i + 1; j--)
			{
				if(A[j] < A[j-1])
				{
					swap(A[j], A[j - 1]);
					flag = 1;
					sw++;
				}
			}
		}
		return sw;
	};

	int A[100], N, sw;


	cout << "個数を入力 -> ";

	cin >> N;

	for (int i = 0; i < N; i++) cin >> A[i];

	sw = sort(A, N);

	for(int i = 0; i < N; i++)
	{
		if (i) cout << " ";
		cout << A[i];
	}
	cout << endl;
	cout << "交換回数 : " << sw << endl;

	return 0;
}

void BubbleSort::TestGen()
{
	Test1();
}

void BubbleSort::Test1()
{
	string file = TestFileMaker(1);

	ofstream of(file);
	of << 5 << endl;
	of << "5 3 2 4 1" << endl;
}

