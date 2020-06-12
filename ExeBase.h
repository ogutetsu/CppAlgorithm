#pragma once
#include <string>
#include <filesystem>
#include <fstream>
#include <iostream>

#include "ScopeTimer.h"

#define EXE_CONSTRUCTOR(className) className( std::string name = #className ) : IExec(name) {}

class IExec
{
public:
	IExec(std::string name) : name_(name) {}
	IExec(char* name) : name_(name){}
	virtual ~IExec() {}

	std::string GetName() { return name_; }
	
	virtual int Run() = 0;

	void TestRun()
	{
		using namespace std::filesystem;
		directory_iterator dit(TestDir + "/" + name_ + "/"), end;
		std::error_code err;
		for (; dit != end && !err; dit.increment(err))
		{
			std::string filename = (*dit).path().string();
			std::cout << filename << std::endl;

			std::ifstream fi(filename);

			auto bk = std::cin.rdbuf();

			std::cin.rdbuf(fi.rdbuf());

			{
				ScopeTimer timer(filename.c_str());
				Run();
			}
			std::cin.rdbuf(bk);
		}
	}
	
	virtual void TestGen(){}

	std::string TestFileMaker(int suffix)
	{
		return TestFileMaker(name_, suffix);
	}

	std::string TestFileMaker(std::string basename, int suffix)
	{
		using namespace std::filesystem;
		std::string res;
		std::string Dir = TestDir + "/" + basename + "/";
		//指定されたディレクトリがなければ作成する
		if(!exists(Dir))
		{
			create_directory(Dir);
		}
		
		res = Dir + basename + "Test" + std::to_string(suffix);

		return res;
	}


private:
	std::string name_;

	std::string TestDir = "TestResource";

	
};

