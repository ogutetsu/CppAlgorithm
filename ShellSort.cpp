#include <functional>
#include <iostream>
#include <vector>

using namespace std;


void ShellSort()
{
	int cnt;
	function<void(int[], int, int)> insertionSort = [&cnt](int* A, int N, int G)
	{
		//GÇÕä‘äu
		for(int i = G; i < N; i++)
		{
			int value = A[i];
			int j = i - G;
			while( j >= 0 && A[j] > value)
			{
				A[j + G] = A[j];
				j = j - G;
				cnt++;
			}
			A[j + G] = value;
		}
	};

	function<void(int[], int)> shellSort = [&cnt, insertionSort](int* A, int N)
	{

		//êîóÒGÇÃçÏê¨
		vector<int> G;
		for(int h = 1; ;)
		{
			if (h > N) break;
			G.push_back(h);
			h = 3 * h + 1;
		}

		//ä‘äuGÇéwíËÇµÇΩë}ì¸É\Å[Ég
		for(int i = G.size()-1; i >= 0; i--)
		{
			insertionSort(A, N, G[i]);
		}

		cout << "size : " << G.size() << endl;
		cout << "G : ";
		for(int i = G.size()-1; i>= 0; i--)
		{
			cout << G[i];
			if (i) cout << " ";
		}
		cout << endl;
	};
	
	cnt = 0;
	int N;
	int A[100000];
	cout << "å¬êîÇì¸óÕ -> ";
	cin >> N;

	for (int i = 0; i < N; i++) cin >> A[i];

	shellSort(A, N);

	cout << "cnt : " << cnt << endl;

	for (int i = 0; i < N; i++) cout << A[i] << " ";
	cout << endl;
	
}

