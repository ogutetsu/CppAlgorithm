#include "SelectionSort.h"

#include <functional>
#include <iostream>

using namespace std;


// O(N²)

int SelectionSort::Run()
{
	function<int(int[], int)> sort = [](int* A, int N)	{
		int sw = 0;

		for(int i = 0; i < N-1; i++)
		{
			int minj = i;
			for(int j = i; j < N; j++)
			{
				if(A[j] < A[minj])
				{
					minj = j;
				}				
			}
			swap(A[i], A[minj]);
			if(i != minj) sw++;
		}
		
		return sw;
	};


	int A[100], N, sw;


	cout << "個数を入力 -> ";

	cin >> N;

	for (int i = 0; i < N; i++) cin >> A[i];

	sw = sort(A, N);

	for (int i = 0; i < N; i++)
	{
		if (i) cout << " ";
		cout << A[i];
	}
	cout << endl;
	cout << "交換回数 : " << sw << endl;

	return 0;
	
}

void SelectionSort::TestGen()
{
}

