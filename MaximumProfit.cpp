#include <iostream>
#include <algorithm>


using namespace std;
static const int MAX = 200'000;


void MaximumProfit()
{
	int R[MAX], n;

	cout << "個数を入力 -> ";
	
	cin >> n;

	for (int i = 0; i < n; i++) cin >> R[i];

	//できる限りの最小値
	int maxv = -2'000'000'000;
	int minv = R[0];

	for(int i = 1; i < n; i++)
	{
		maxv = max(maxv, R[i] - minv);	//最大値を更新
		minv = min(minv, R[i]);		//ここまでの最小値
	}

	cout << "最大値 : " << maxv << endl;
	
}


