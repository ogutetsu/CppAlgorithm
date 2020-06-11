#pragma once
#include <functional>
#include <iostream>
#include <tuple>
#include <vector>

#include "ExeBase.h"

#include "TestGen/TestGen.h"



#define MAKETUPLE(no, execlass) std::make_tuple((no), (IExec*)(new execlass( #execlass )))


typedef std::tuple<int, IExec*> exetype;

class Exit : public IExec
{
public:
	Exit(std::string name) : IExec(name) {}
	int Run() override { return 0; }
};


class DebugMenu
{
public:

	void AddMenu(exetype t)
	{
		exeTable.push_back(t);
	}
	

	void SetExitNumber(int num)
	{
		exitNumber = num;
	}

	void Exec()
	{
		AddMenu(MAKETUPLE(exitNumber, Exit));
		while (1)
		{
			for (auto t : exeTable)
			{
				std::cout << std::get<0>(t) << " : " << std::get<1>(t)->GetName() << std::endl;
			}
			int s;
			int op;
			
			std::cout << "select number -> ";
			std::cin >> s;
			if (s == exitNumber) break;	//exitNumberが入力されたら終了
			
			//0は実行 1はテスト実行にする
			std::cout << "Run or Test(0..Run 1..Test) -> ";
			std::cin >> op;
			
			
			auto f = std::find_if(exeTable.begin(), exeTable.end(),
				[=](auto t)
			{
				return s == (int)std::get<0>(t);
			});

			if (f != exeTable.end())
			{
				auto number = std::get<0>(*f);

				std::cout << "select : " << std::get<1>(*f)->GetName() << std::endl;
				if (op == 0)
				{//実行
					std::get<1>(*f)->Run();
				}
				else if(op == 1)
				{//テストメソッド実行
					std::get<1>(*f)->TestRun();
				}
				else if(op == 9)
				{//テスト生成
					std::get<1>(*f)->TestGen();
				}
			}
			std::cout << std::endl;
		}
	}


private:
	std::vector<exetype> exeTable;

	int exitNumber = 99;

};

