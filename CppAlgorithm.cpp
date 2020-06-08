﻿// CppAlgorithm.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include "DebugMenu.h"


extern void MaximumProfit();
extern void InsertionSort();
extern void BubbleSort();
extern void SelectionSort();
extern void StableSort();
extern void ShellSort();
extern void Stack();
extern void Queue();
extern void LinkedList();

int main()
{
    DebugMenu menu;

	menu.SetExitNumber(99);

	menu.AddMenu(std::make_tuple(1, "MaximumProfit", MaximumProfit));
	menu.AddMenu(std::make_tuple(2, "InsertionSort", InsertionSort));
	menu.AddMenu(std::make_tuple(3, "BubbleSort", BubbleSort));
	menu.AddMenu(std::make_tuple(4, "SelectionSort", SelectionSort));
	menu.AddMenu(std::make_tuple(5, "StableSort", StableSort));
	menu.AddMenu(std::make_tuple(6, "ShellSort", ShellSort));
	menu.AddMenu(std::make_tuple(7, "Stack", Stack));
	menu.AddMenu(std::make_tuple(8, "Queue", Queue));
	menu.AddMenu(std::make_tuple(9, "LinkedList", LinkedList));


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
