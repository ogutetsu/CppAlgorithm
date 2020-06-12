#pragma once

#include "../ExeBase.h"

class Stack : public IExec
{
public:
	EXE_CONSTRUCTOR(Stack)


	int Run() override;
	void TestGen() override;



private:
	void Test1();
};
