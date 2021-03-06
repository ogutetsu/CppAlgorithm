﻿#include "InsertionSort.h"

#include <functional>
#include <iostream>


using namespace std;


//最悪のケースでは O(N²)になる

int InsertionSort::Run()
{
	function<void(int[], int)> trace = [](int* A, int N)
	{
		int i;
		for(i = 0; i < N; i++)
		{
			if (i > 0) cout << " ";
			cout << A[i];
		}
		cout << endl;
	};

	function<void(int[], int)> insertionSort = [=](int* A, int N)
	{
		int j, i, v;
		for(i = 1; i < N; i++)
		{
			v = A[i];
			j = i - 1;
			while(j >= 0 && A[j] > v)
			{
				A[j + 1] = A[j];
				j--;
			}
			A[j + 1] = v;
			trace(A, N);
		}
	};

	int N, i;
	int A[100];

	cout << "個数を入力 -> ";
	
	cin >> N;

	
	for (i = 0; i < N; i++) cin >> A[i];

	trace(A, N);
	insertionSort(A, N);

	return 0;
}

void InsertionSort::TestGen()
{
	Test1();
}

void InsertionSort::Test1()
{
	string file = TestFileMaker(1);

	ofstream of(file);

	of << 6 << endl;
	of << "5 2 4 6 1 3" << endl;


	
}


