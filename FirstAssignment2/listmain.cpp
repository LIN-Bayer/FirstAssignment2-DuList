#include<iostream>
using namespace std;
#include"List.h"




int main()
{
	QGList<int> qglist;
	qglist.ShowMenu();
	int select,index;
	cout << "���������ѡ�" << endl;
	cin >> select;
	switch (select)
	{
	case 1:
		cout << "��ʼ���ɹ���" << endl;
		break;
	case 2:     //���ص�һ��Ԫ�ص����� 
		qglist.front();
		break;
	case 3:     //�������һ��Ԫ�ص����� 
		qglist.back();
		break;
	case 4:     //�������в���Ԫ��
	{
		int a;
		cout << "������Ҫ�����λ��" << endl;
		cin >> index;
		cout << "������Ҫ��������ݣ�" << endl;
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
	case 5:     //ɾ�������е�Ԫ�� 
	{
		cout << "������Ҫɾ����λ��" << endl;
		cin >> index;
		if (index == 1)    //ͷɾ
		{
			qglist.pop_front();
		}
		else if (index == qglist.size())     //βɾ
		{
			qglist.pop_back();
		}
		else          //ɾ��
		{
			qglist.erase(index);
		}
		break;
	}
	case 6:     //����Ԫ���Ƿ���� 
	{
		int b;
		cout << "������Ԫ�أ�" << endl;
		cin >> b;
		int& e1 = b;
		qglist.contain(e1);
		break;
	}
	case 7:     //������Ԫ������
		qglist.size();
		break;
	case 8:     //��������
	{
		qglist.traverse(Print);
		break;
	}
	case 9:     //������� 
		qglist.clear();
		break;
	}
	system("pause");
	system("cls");
}