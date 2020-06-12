#pragma once

#include "../ExeBase.h"

class InsertionSort : public IExec
{
public:
	EXE_CONSTRUCTOR(InsertionSort)


	int Run() override;
	void TestGen() override;



private:
	void Test1();
};
