
#include "MaximumProfitTestGen.h"

#include <iostream>

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

