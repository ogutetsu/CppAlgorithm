#pragma once
#include <functional>
#include <iostream>
#include <tuple>
#include <vector>

//関数名とテストメソッドのextern宣言するdefine
#define DEBUGEXTERN(func) extern void func(); extern void func##Test ();
//DEBUGEXTERNのTestメソッドを宣言しないもの 実装していないのにexternするのも気持ち悪いので用意してます
#define DEBUGEXTERN_NOTEST(func) extern void func();


#define DEBUGTUPLE(no, name, func) std::make_tuple((no), (name), func, func##Test )

//テストメソッドを使用しない場合 (出来るだけテストメソッドの実装は行うべき)
#define DEBUGTUPLE_NOTEST(no, name, func) std::make_tuple((no), (name), func, nullptr )


typedef std::tuple<int, std::string, std::function<void(void)>, std::function<void(void)>> callname;

class DebugMenu
{
public:
	void AddMenu(callname t)
	{
		table.push_back(t);
	}

	void SetExitNumber(int num)
	{
		exitNumber = num;
	}

	void Exec()
	{
		AddMenu(std::make_tuple(exitNumber, "Exit", nullptr, nullptr));
		while (1)
		{
			for (auto t : table)
			{
				std::cout << std::get<0>(t) << " : " << std::get<1>(t) << std::endl;
			}
			int s;
			int op;
			
			std::cout << "select number -> ";
			std::cin >> s;
			if (s == exitNumber) break;	//exitNumberが入力されたら終了
			
			//Optionは 0は実行 1はテスト実行にする
			std::cout << "Run or Test(0..Run 1..Test) -> ";
			std::cin >> op;
			
			
			auto f = std::find_if(table.begin(), table.end(),
				[=](auto t)
			{
				return s == (int)std::get<0>(t);
			});

			if (f != table.end())
			{
				auto number = std::get<0>(*f);

				std::cout << "select : " << std::get<1>(*f) << std::endl;
				if (op == 0)
				{//実行
					if (std::get<2>(*f) != nullptr) std::get<2>(*f)();
				}
				else
				{//テストメソッド実行
					if (std::get<3>(*f) != nullptr) std::get<3>(*f)();
				}
			}
			std::cout << std::endl;
		}
	}


private:

	std::vector<callname> table;

	int exitNumber = 99;

};

