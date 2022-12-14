#include <iostream>
#include"List.h"
#include<string>

template<typename T>
void Display(List<T>& list, int& operationNum, int& displayOperationNum);

template<typename T>
void Insert(List<T>& list, int& operationNum);

template<>
void Insert(List<char*>& list, int& operationNum);

template<typename T>
void Edit(List<T>& list, int& operationNum);

template<>
void Edit(List<char*>& list, int& operationNum);

template<typename T>
void Delete(List<T>& list, int& operationNum);

template<typename T>
void Change(List<T>& list, int& operationNum);

int main()
{
	List<int> list;

	//要素の操作の操作番号
	int operationNum = 0;

	//要素の表示の操作番号
	int displayOperationNum = 0;

	while (true)
	{
		std::cout << "[要素の操作]" << std::endl;
		std::cout << "1.要素の表示" << std::endl;
		std::cout << "2.要素の挿入" << std::endl;

		if (list.Size() > 0)
		{
			std::cout << "3.要素の編集" << std::endl;
			std::cout << "4.要素の削除" << std::endl;
		}

		std::cout << "5.要素の並び替え(オプション)" << std::endl;
		std::cout << std::endl;
		std::cout << "----------------------------------" << std::endl;
		std::cout << "操作を選択してください" << std::endl;

		std::cout << std::endl;

		if (operationNum == 0)
		{
			//操作番号を取得
			std::cin >> operationNum;
		}
		system("cls");

		switch (operationNum)
		{
		case 1://要素の表示

			Display(list, operationNum, displayOperationNum);

			break;

		case 2://最後尾に要素を追加

			Insert(list, operationNum);

			break;

		case 3://任意の場所の値を変更

			Edit(list, operationNum);

			break;

		case 4://任意の場所の削除

			Delete(list, operationNum);

			break;

		case 5://任意の場所と任意の場所を入れ替え

			Change(list, operationNum);

			break;
		}
	}

	return 0;
}

template<typename T>
void Display(List<T>& list, int& operationNum, int& displayOperationNum)
{
	std::cout << "[要素の表示]" << std::endl;
	std::cout << "1.要素の一覧表示" << std::endl;
	std::cout << "2.順番を指定して要素を表示" << std::endl;
	std::cout << "9.要素操作に戻る" << std::endl;
	std::cout << std::endl;
	std::cout << "操作を選択してください" << std::endl;

	//操作番号を取得
	std::cin >> displayOperationNum;
	system("cls");

	switch (displayOperationNum)
	{
	case 1:

		std::cout << "[要素の一覧表示]" << std::endl;

		//一覧表示
		list.Dump();

		std::cout << "要素数:" << list.Size() << std::endl;

		break;

	case 2:

		std::cout << "[順番を指定して要素を表示]" << std::endl;
		std::cout << "表示したい要素の順番を指定してください。" << std::endl;

		//指定する番号を取得
		int specifyNum;
		std::cin >> specifyNum;
		std::cout << std::endl;

		//指定して表示
		list.Specifyvalue(specifyNum);

		break;

	case 9:

		operationNum = 0;
		break;
	}

	//要素操作に戻らなかったら
	if (displayOperationNum == 1 || displayOperationNum == 2)
	{
		std::cout << std::endl;
		std::cout << "----------------------------------" << std::endl;
		std::cout << "1.要素の表示に戻る" << std::endl;
		std::cout << "2.要素の操作に戻る" << std::endl;

		//操作番号を取得
		std::cin >> displayOperationNum;

		system("cls");
		switch (displayOperationNum)
		{
		case 1:

			operationNum = 1;

			break;

		case 2:

			operationNum = 0;

			break;

		default:
			break;
		}
	}
}

template<typename T>
void Insert(List<T>& list, int& operationNum)
{
	std::cout << "[リスト要素の挿入]" << std::endl;
	std::cout << std::endl;
	std::cout << "要素を追加する場所を指定してください。最後尾に追加する場合は何も入力しないでください。" << std::endl;

	std::string insertNum;
	while (std::getchar() != '\n');

	std::getline(std::cin, insertNum);

	if (insertNum == "")
	{
		std::cout << "追加する要素の値を入力してください" << std::endl;
		T value{};

		std::cin >> value;

		list.PushBack(value);

		std::cout << "要素" << value << "が" << "最後尾に挿入されました" << std::endl;
	}
	else
	{
		int index = std::atoi(insertNum.c_str());

		std::cout << "追加する要素の値を入力してください" << std::endl;
		T value{};

		std::cin >> value;

		list.Insert(value, index);

		std::cout << "要素" << value << "が" << index << "番目に挿入されました" << std::endl;
	}

	std::cout << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "9.要素操作に戻る" << std::endl;

	std::cin >> operationNum;
	system("cls");

	if (operationNum == 9)
	{
		operationNum = 0;
	}
	else
	{
		operationNum = 2;
	}
}

template<>
void Insert(List<char*>& list, int& operationNum)
{
	std::cout << "[リスト要素の挿入]" << std::endl;
	std::cout << std::endl;
	std::cout << "要素を追加場所を指定してください。最後尾に追加する場合は何も入力しないでください。" << std::endl;

	std::string insertNum;
	while (std::getchar() != '\n');

	std::getline(std::cin, insertNum);

	if (insertNum == "")
	{
		std::cout << "追加する要素の値を入力してください" << std::endl;
		char value[64];

		std::cin >> value;

		list.PushBack(value);

		std::cout << "要素" << value << "が" << "最後尾に挿入されました" << std::endl;
	}
	else
	{
		int index = std::atoi(insertNum.c_str());

		std::cout << "追加する要素の値を入力してください" << std::endl;
		char value[64];

		std::cin >> value;

		list.Insert(value, index);

		std::cout << "要素" << value << "が" << index << "番目に挿入されました" << std::endl;
	}

	std::cout << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "9.要素操作に戻る" << std::endl;

	std::cin >> operationNum;
	system("cls");

	if (operationNum == 9)
	{
		operationNum = 0;
	}
	else
	{
		operationNum = 2;
	}
}

template<typename T>
void Edit(List<T>& list, int& operationNum)
{
	std::cout << "[要素の編集]" << std::endl;
	std::cout << std::endl;
	std::cout << "編集したい要素の番号を入力してください" << std::endl;

	int valueNum;
	std::cin >> valueNum;
	std::cout << std::endl;

	if (list.Search(valueNum))
	{
		std::cout << valueNum << "番目の要素の変更する値を入力してください。" << std::endl;

		T changeValue{};
		std::cin >> changeValue;

		list.ChangeValue(changeValue, valueNum);
		std::cout << std::endl;

		std::cout << valueNum << "番目の要素の値が" << '"' << changeValue << '"' << "に変更されました" << std::endl;
	}
	else
	{
		std::cout << valueNum << "番目の要素のが見つかりませんでした。" << std::endl;
	}

	std::cout << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "9.要素操作に戻る" << std::endl;

	std::cin >> operationNum;
	system("cls");

	if (operationNum == 9)
	{
		operationNum = 0;
	}
	else
	{
		operationNum = 3;
	}
}

template<>
void Edit(List<char*>& list, int& operationNum)
{
	std::cout << "[要素の編集]" << std::endl;
	std::cout << std::endl;
	std::cout << "編集したい要素の番号を入力してください" << std::endl;

	int valueNum;
	std::cin >> valueNum;
	std::cout << std::endl;

	if (list.Search(valueNum))
	{
		std::cout << valueNum << "番目の要素の変更する値を入力してください。" << std::endl;

		char changeValue[64];
		std::cin >> changeValue;

		list.ChangeValue(changeValue, valueNum);
		std::cout << std::endl;

		std::cout << valueNum << "番目の要素の値が" << '"' << changeValue << '"' << "に変更されました" << std::endl;
	}
	else
	{
		std::cout << valueNum << "番目の要素のが見つかりませんでした。" << std::endl;
	}

	std::cout << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "9.要素操作に戻る" << std::endl;

	std::cin >> operationNum;
	system("cls");

	if (operationNum == 9)
	{
		operationNum = 0;
	}
	else
	{
		operationNum = 3;
	}
}

template<typename T>
void Delete(List<T>& list, int& operationNum)
{
	std::cout << "[要素の削除]" << std::endl;
	std::cout << std::endl;
	std::cout << "削除したい要素の番号を指定してください" << std::endl;

	int valueNum;
	std::cin >> valueNum;
	std::cout << std::endl;

	if (list.Search(valueNum))
	{
		std::cout << valueNum << "番目の要素" << '"' << list.Getvalue(valueNum) << '"' << "削除しました" << std::endl;

		list.Delete(valueNum);

		std::cout << std::endl;
	}
	else
	{
		std::cout << valueNum << "番目の要素のが見つかりませんでした。" << std::endl;
	}

	std::cout << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "9.要素操作に戻る" << std::endl;

	std::cin >> operationNum;
	system("cls");

	if (operationNum == 9)
	{
		operationNum = 0;
	}
	else
	{
		operationNum = 4;
	}
}

template<typename T>
void Change(List<T>& list, int& operationNum)
{
	std::cout << "[要素の並び替え]" << std::endl;
	std::cout << std::endl;
	std::cout << "並び替え方法を選択してください" << std::endl;
	std::cout << "1.昇順で並び替える" << std::endl;
	std::cout << "2.降順で並び替える" << std::endl;

	int changeOperationNum;

	std::cin >> changeOperationNum;

	switch (changeOperationNum)
	{
	case 1:

		list.Sort();
		std::cout << "リストの要素を昇順で並び替えました" << std::endl;

		break;

	case 2:

		list.Sort(false);
		std::cout << "リストの要素を降順で並び替えました" << std::endl;

		break;

	default:
		break;
	}

	std::cout << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "9.要素操作に戻る" << std::endl;

	std::cin >> operationNum;
	system("cls");

	if (operationNum == 9)
	{
		operationNum = 0;
	}
	else
	{
		operationNum = 5;
	}
}