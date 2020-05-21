#pragma once
#include <functional>
#include <iostream>
#include <tuple>
#include <vector>


typedef std::tuple<int, std::string, std::function<void(void)>> callname;

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
		AddMenu(std::make_tuple(exitNumber, "Exit", nullptr));
		while (1)
		{
			for (auto t : table)
			{
				std::cout << std::get<0>(t) << " : " << std::get<1>(t) << std::endl;
			}
			int s;
			std::cout << "select number -> ";
			std::cin >> s;

			auto f = std::find_if(table.begin(), table.end(),
				[=](auto t)
			{
				return s == (int)std::get<0>(t);
			});


			if (f != table.end())
			{
				auto number = std::get<0>(*f);
				if (number == exitNumber) break;

				std::cout << "select : " << std::get<1>(*f) << std::endl;

				if(std::get<2>(*f) != nullptr) std::get<2>(*f)();
			}
			std::cout << std::endl;
		}
	}


private:

	std::vector<callname> table;

	int exitNumber = 99;

};

