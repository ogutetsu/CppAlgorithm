// CppAlgorithm.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include "DebugMenu.h"
#include "Order/MaximumProfit.h"
#include "Sort/InsertionSort.h"
#include "Sort/SelectionSort.h"
#include "Sort/BubbleSort.h"
#include "Sort/ShellSort.h"
#include "Sort/StableSort.h"
#include "DataStructure/Stack.h"
#include "DataStructure/Queue.h"
#include "DataStructure/LinkedList.h"



int main()
{
    DebugMenu menu;

	menu.SetExitNumber(99);

	menu.AddMenu(MAKETUPLE(1, MaximumProfit));
	menu.AddMenu(MAKETUPLE(2, InsertionSort));
	menu.AddMenu(MAKETUPLE(3, BubbleSort));
	menu.AddMenu(MAKETUPLE(4, SelectionSort));
	menu.AddMenu(MAKETUPLE(5, StableSort));
	menu.AddMenu(MAKETUPLE(6, ShellSort));
	menu.AddMenu(MAKETUPLE(7, Stack));
	menu.AddMenu(MAKETUPLE(8, Queue));
	menu.AddMenu(MAKETUPLE(9, LinkedList));

	menu.Exec();

	
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
