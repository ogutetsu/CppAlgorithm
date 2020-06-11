#pragma once

#include "../ExeBase.h"

class Queue : public IExec
{
public:
	EXE_CONSTRUCTOR(Queue)


	int Run() override;
	void TestGen() override;



private:
	
};

