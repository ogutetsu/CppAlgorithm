
#include "MaximumProfitTestGen.h"

#include <iostream>

using namespace std;

/*
 * 制約は 2 <= N <= 200,000
 * 1 <= R <= 10,000,000,000
 */
void MaximumProfitTestGen::Generate()
{

	string file = TestFileMaker("MaximumProfit", 1);
	cout << file;

	ofstream of(file);

	of << 2 << endl;
	of << 10 << endl << 20 << endl;
	

	
}

