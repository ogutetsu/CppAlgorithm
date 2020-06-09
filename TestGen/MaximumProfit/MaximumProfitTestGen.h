#pragma once

#include "../TestGenInterface.h"


class MaximumProfitTestGen : public ITestGen
{
public:
	void Generate() override;

private:
	void Test1();
	void Test2();
	void Test3();
	
	
};


