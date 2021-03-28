#include<iostream>
using namespace std;
#include"List.h"




int main()
{
	QGList<int> qglist;
	qglist.ShowMenu();
	int select,index;
	cout << "请输入你的选项：" << endl;
	cin >> select;
	switch (select)
	{
	case 1:
		cout << "初始化成功！" << endl;
		break;
	case 2:     //返回第一个元素的引用 
		qglist.front();
		break;
	case 3:     //返回最后一个元素的引用 
		qglist.back();
		break;
	case 4:     //在链表中插入元素
	{
		int a;
		cout << "请输入要插入的位置" << endl;
		cin >> index;
		cout << "请输入要插入的内容：" << endl;
		cin >> a;
		int& e = a;
		if (index == 1)
		{
			qglist.push_front(e);
		}
		else if (index == qglist.size())
		{
			qglist.push_back(e);
		}
		else
		{
			qglist.insert(index, e);
		}
		break;
	}
	case 5:     //删除链表中的元素 
	{
		cout << "请输入要删除的位置" << endl;
		cin >> index;
		if (index == 1)    //头删
		{
			qglist.pop_front();
		}
		else if (index == qglist.size())     //尾删
		{
			qglist.pop_back();
		}
		else          //删除
		{
			qglist.erase(index);
		}
		break;
	}
	case 6:     //查找元素是否存在 
	{
		int b;
		cout << "请输入元素：" << endl;
		cin >> b;
		int& e1 = b;
		qglist.contain(e1);
		break;
	}
	case 7:     //链表中元素数量
		qglist.size();
		break;
	case 8:     //遍历链表
	{
		qglist.traverse(Print);
		break;
	}
	case 9:     //清空链表 
		qglist.clear();
		break;
	}
	system("pause");
	system("cls");
}