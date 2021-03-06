/**
 * 作者:QG
 **/


#ifndef __QGLIST_H__
#define __QGLIST_H__

 /*
  * 双向链表
  */
template<typename T>
class QGList {

protected:
	struct Node {
		T data;
		struct Node* prior;
		struct Node* next;
	};

	int count;  //记录节点数
	Node* head;
	Node* tail;

public:

	/*
	 * 显示菜单
	 */
	void ShowMenu();

	/*
	 * 初始化链表
	 */
	QGList();

	/*
	 * 销毁链表
	 */
	~QGList();

	/*
	 * 返回链表中第一个元素的引用
	 */
	T& front();

	/*
	 * 返回链表中最后一个元素的引用
	 */
	T& back();

	/*
	 * 在链表第一个元素前添加元素e
	 */
	bool push_front(T& e);

	/*
	 * 删除链表第一个元素
	 */
	bool pop_front();

	/*
	 * 在链表最后一个元素后添加元素e
	 */
	bool push_back(T& e);

	/*
	 * 删除链表最后一个元素
	 */
	bool pop_back();

	/*
	 * 在链表的第index + 1个元素前插入元素e
	 */
	bool insert(unsigned int index, T& e);

	/*
	 * 删除任意位置元素
	 */
	bool erase(unsigned int index);

	/*
	 * 清空链表
	 */
	bool clear();

	/*
	 * 查找元素是否存在
	 */
	bool contain(T& e);

	/*
	 * 返回链表中元素的数量
	 */
	unsigned int size();

	/*
	 * 遍历链表, 对每个元素调用visit指向的函数
	 */
	bool traverse(void (*visit)(T& e));
};



//list.cpp

template<typename T>
void QGList<T>::ShowMenu()
{
	cout << "********************************" << endl;
	cout << "*        1.初始化链表          *" << endl;
	cout << "*    2.返回第一个元素的引用    *" << endl;
	cout << "*    3.返回第一个元素的引用    *" << endl;
	cout << "*      4.在链表中插入元素      *" << endl;
	cout << "*      5.删除链表中的元素      *" << endl;
	cout << "*      6.查找元素是否存在      *" << endl;
	cout << "*       7.链表中元素数量       *" << endl;
	cout << "*          8.遍历链表          *" << endl;
	cout << "*          9.清空链表          *" << endl;
	cout << "********************************" << endl;
}

template<typename T>
QGList<T>::QGList()
{
	count = 0;      // 初始化链表节点数
	head = NULL;//让头结点为空
	Node* newnode = new Node;//开辟内存
	tail = newnode;
	cout << "请按提示初始化链表：" << endl;
	cout << "请输入第一个数据(非0)：" << endl;
	cin >> newnode->data;
	while (newnode->data != 0)
	{
		count++;
		if (count == 1)
		{
			head = newnode;//头指针指向首节点
			head->next = head->prior = NULL;//使得指向为空
			tail = newnode;//加入新节点
		}
		else
		{
			newnode->next = NULL;//新节点指针为空
			tail->next = newnode;//原来的尾节点指向新节点
			tail = newnode;
			Node* p = head;
			while (p->next != tail)
			{
				p = p->next;
			}
			tail->prior = p;
		}
		newnode = new Node;//再次给新节点分配新的内存空间
		cout << "请输入第" << count + 1 << "个数据：(提示，输入‘0’可终止输入)" << endl;
		cin >> newnode->data;
		if (newnode->data == 0)
		{
			break;
		}
	}
}


//销毁链表
template<typename T>
QGList<T>::~QGList()
{
	Node* p;
	if (head != NULL)
	{
		while (head)
		{
			p = head->next;
			free(head);
			head = p;
		}
	}
	cout << "链表已销毁！" << endl;
}


//返回链表中第一个元素的引用
template<typename T>
T& QGList<T>::front()
{
	if (count == 0)
	{
		cout << "不存在链表！请先创建一个链表" << endl;
	}
	else
	{
		cout << "第一个元素为：" << head->data << endl;
		return head->data;

	}
	system("pause");
	system("cls");
}

//返回链表中最后一个元素的引用
template<typename T>
T& QGList<T>::back()
{
	if (count == 0)
	{
		cout << "不存在链表！请先创建一个链表" << endl;
	}
	else
	{
		cout << "最后一个元素为：" << tail->data << endl;
		return tail->data;

	}
	system("pause");
	system("cls");
}

//在链表第一个元素前添加元素e
template<typename T>
bool QGList<T>::push_front(T& e)
{
	Node* newnode = new Node;
	newnode->data = e;
	newnode->next = head;
	newnode->prior = NULL;
	head->prior = newnode;
	head = newnode;
	count++;
	cout << "插入成功！" << endl;
	return head;
	delete(newnode);
	system("pause");
	system("cls");
}

//删除链表第一个元素
template<typename T>
bool QGList<T>::pop_front()
{
	Node* p;
	p = head;
	head = head->next;
	head->prior = NULL;
	delete(p);
	count--;
	cout << "删除成功！" << endl;
	return 1;
	system("pause");
	system("cls");
}

//在链表最后一个元素后添加元素e
template<typename T>
bool QGList<T>::push_back(T& e)
{
	Node* p = new Node;
	p->data = e;
	tail->next = p;
	p->prior = tail;
	tail = tail->next;
	tail->next = NULL;
	count++;
	cout << "插入成功！" << endl;
	delete(p);
	return 1;
	system("pause");
	system("cls");
}

//删除链表最后一个元素
template<typename T>
bool QGList<T>::pop_back()
{
	Node* p, * pre = head;
	p = tail;
	for (unsigned int i = 1; i < count - 1; i++)  //利用for循环让指针指在第index个结点上
	{
		pre = pre->next;
	}
	pre->next = tail;
	tail->prior = pre;
	tail = pre;
	tail->next = NULL;
	pre = NULL;
	free(p);
	count--;
	cout << "删除成功！" << endl;
	return 1;
	system("pause");
	system("cls");
}

//在链表的第index + 1个元素前插入元素e
template<typename T>
bool QGList<T>::insert(unsigned int index, T& e)
{
	Node* p = head, * pre = NULL;
	Node* newnode = new Node; //开辟新结点内存
	newnode->data = e;   //把e赋值进数据域里
	for (unsigned int i = 1; i < index + 1; i++)  //利用for循环让指针p指在第index+1个结点上
	{
		p = p->next;
		pre = p->prior;
	}
	newnode->next = p;  //新结点的next指向第index+1个结点
	p->prior = newnode;  //第index+1个结点的prior指向新结点
	pre->next = newnode;   //第index个结点的next指向新结点
	newnode->prior = pre;   //新结点的prior指向第index个结点
	count++;    //链表节点增加
	cout << "插入成功！" << endl;
	delete(newnode);
	return head;
	system("pause");
	system("cls");
}

//删除任意位置元素
template<typename T>
bool QGList<T>::erase(unsigned int index)
{
	Node* p = head, * pre = p, * p2 = p->next;
	for (unsigned int i = 1; i < index; i++)
	{
		pre = p;
		p = p->next;
		pre = p->prior;
	}
	p2->prior = pre;
	pre->next = p2;
	free(p);
	count--;
	cout << "删除成功！" << endl;
	return 1;
	system("pause");
	system("cls");
}

//清空链表
template<typename T>
bool QGList<T>::clear()
{
	Node* p, * q;
	if (head == NULL)
		return 0;
	p = head->next;
	while (p != NULL)
	{
		q = p->next;
		free(p);
		p = q;
	}
	head->next = NULL;
	cout << "链表已清空！" << endl;
	return 1;
	system("pause");
	system("cls");
	cout << "链表已清空！" << endl;
	return 1;
	system("pause");
	system("cls");
}

//查找元素是否存在
template<typename T>
bool QGList<T>::contain(T& e)
{
	Node* p = head;

	for (int i = 1; i <= count; i++)
	{
		if (p->data == e)
		{
			cout << "存在该元素！" << endl;
			break;
		}
		else
		{
			if (i == count)
			{
				cout << "查不到该元素！" << endl;
				break;
			}
			p = p->next;
		}
	}
	return 1;
	system("pause");
	system("cls");
}

//返回链表中元素的数量
template<typename T>
unsigned int QGList<T>::size()
{
	cout << "元素数量为：" << count << endl;
	return count;
	system("pause");
	system("cls");
}


template<typename T>
void Print(T& e)
{
	cout << e << endl;
}

//遍历链表, 对每个元素调用visit指向的函数
template<typename T>
bool QGList<T>::traverse(void (*visit)(T& e))
{
	Node* p = head;
	while (p != NULL)
	{
		(*visit)(p->data);
		p = p->next;
	}
	return 1;
	system("pause");
	system("cls");
}



#endif
#pragma once




