#pragma once

#include "../ExeBase.h"

class SelectionSort : public IExec
{
public:
	EXE_CONSTRUCTOR(SelectionSort)


	int Run() override;
	void TestGen() override;



private:
	
};
