#include <functional>
#include <iostream>


using namespace std;


//最悪のケースでは O(N²)になる

void InsertionSort()
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

	int N, i, j;
	int A[100];

	cout << "個数を入力 -> ";
	
	cin >> N;

	
	for (i = 0; i < N; i++) cin >> A[i];

	trace(A, N);
	insertionSort(A, N);

	
}


