
#include "MaximumProfitTestGen.h"

#include <iostream>
#include <random>

using namespace std;

/*
 * 制約は 2 <= N <= 200,000
 * 1 <= R <= 10,000,000,000
 */
void MaximumProfitTestGen::Generate()
{

	Test1();
	Test2();
	Test3();
	Test4();
	
}

void MaximumProfitTestGen::Test1()
{
	string file = TestFileMaker("MaximumProfit", 1);

	ofstream of(file);

	of << 2 << endl;
	of << 10 << endl << 20 << endl;

}

void MaximumProfitTestGen::Test2()
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

void MaximumProfitTestGen::Test3()
{
	string file = TestFileMaker("MaximumProfit", 3);

	ofstream of(file);

	of << 3 << endl;
	of << 4 << endl;
	of << 3 << endl;
	of << 2 << endl;
	
}

void MaximumProfitTestGen::Test4()
{
	string file = TestFileMaker("MaximumProfit", 4);

	ofstream of(file);

	int N = 200'000;
	int R = 10'000'000'000;
	of << N << endl;


	std::random_device seed;
	std::mt19937_64 engine(seed());
	std::uniform_int_distribution<int> dist(0, R);
	for(int i = 0; i < N; i++)
	{
		//ランダムに数値を求める
		of << dist(engine) << endl;
	}
	
	
}

