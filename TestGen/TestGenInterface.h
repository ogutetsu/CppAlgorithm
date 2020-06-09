#pragma once

#include <fstream>
#include <string>

class ITestGen
{
public:
	virtual void Generate() = 0;

	std::string TestFileMaker(std::string basename, int suffix)
	{
		std::string res;
		res = Dir + "/" + basename + "/" + basename + "Test" + std::to_string(suffix);

		return res;
	}


private:
	std::string Dir = "TestResource";
	
	
};


