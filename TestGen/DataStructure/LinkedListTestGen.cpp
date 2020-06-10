
#include "LinkedListTestGen.h"

#include <iostream>
#include <random>

using namespace std;

void LinkedListTestGen::Generate()
{
	Test1();
}

void LinkedListTestGen::Test1()
{
	string file = TestFileMaker("LinkedList", 1);

	ofstream of(file);

	of << 7 << endl;
	of << "insert " << "5" << endl;
	of << "insert " << "2" << endl;
	of << "insert " << "3" << endl;
	of << "insert " << "1" << endl;
	of << "delete " << "3" << endl;
	of << "insert " << "6" << endl;
	of << "delete " << "5" << endl;

	
}

