#pragma once

#include "../ExeBase.h"

class MaximumProfit : public IExec
{
public:
	EXE_CONSTRUCTOR(MaximumProfit)


	int Run() override;
	void TestGen() override;



private:
	void Test1();
	void Test2();
	void Test3();
	void Test4();
};
