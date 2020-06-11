#pragma once

#include "../ExeBase.h"

class LinkedList : public IExec
{
public:
	EXE_CONSTRUCTOR(LinkedList)


	int Run() override;
	void TestGen() override;



private:
	void Test1();
};
