#pragma once
#include <string>
#include <filesystem>
#include <fstream>
#include <iostream>

#include "ScopeTimer.h"


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
		directory_iterator dit("TestResource/" + name_ + "/"), end;
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
	

private:
	std::string name_;
	
};

