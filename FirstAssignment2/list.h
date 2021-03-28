/**
 * ����:QG
 **/


#ifndef __QGLIST_H__
#define __QGLIST_H__

 /*
  * ˫������
  */
template<typename T>
class QGList {

protected:
	struct Node {
		T data;
		struct Node* prior;
		struct Node* next;
	};

	int count;  //��¼�ڵ���
	Node* head;
	Node* tail;

public:

	/*
	 * ��ʾ�˵�
	 */
	void ShowMenu();

	/*
	 * ��ʼ������
	 */
	QGList();

	/*
	 * ��������
	 */
	~QGList();

	/*
	 * ���������е�һ��Ԫ�ص�����
	 */
	T& front();

	/*
	 * �������������һ��Ԫ�ص�����
	 */
	T& back();

	/*
	 * ��������һ��Ԫ��ǰ����Ԫ��e
	 */
	bool push_front(T& e);

	/*
	 * ɾ��������һ��Ԫ��
	 */
	bool pop_front();

	/*
	 * ���������һ��Ԫ�غ�����Ԫ��e
	 */
	bool push_back(T& e);

	/*
	 * ɾ���������һ��Ԫ��
	 */
	bool pop_back();

	/*
	 * �������ĵ�index + 1��Ԫ��ǰ����Ԫ��e
	 */
	bool insert(unsigned int index, T& e);

	/*
	 * ɾ������λ��Ԫ��
	 */
	bool erase(unsigned int index);

	/*
	 * �������
	 */
	bool clear();

	/*
	 * ����Ԫ���Ƿ����
	 */
	bool contain(T& e);

	/*
	 * ����������Ԫ�ص�����
	 */
	unsigned int size();

	/*
	 * ��������, ��ÿ��Ԫ�ص���visitָ��ĺ���
	 */
	bool traverse(void (*visit)(T& e));
};



//list.cpp

template<typename T>
void QGList<T>::ShowMenu()
{
	cout << "********************************" << endl;
	cout << "*        1.��ʼ������          *" << endl;
	cout << "*    2.���ص�һ��Ԫ�ص�����    *" << endl;
	cout << "*    3.���ص�һ��Ԫ�ص�����    *" << endl;
	cout << "*      4.�������в���Ԫ��      *" << endl;
	cout << "*      5.ɾ�������е�Ԫ��      *" << endl;
	cout << "*      6.����Ԫ���Ƿ����      *" << endl;
	cout << "*       7.������Ԫ������       *" << endl;
	cout << "*          8.��������          *" << endl;
	cout << "*          9.�������          *" << endl;
	cout << "********************************" << endl;
}

template<typename T>
QGList<T>::QGList()
{
	count = 0;      // ��ʼ�������ڵ���
	head = NULL;//��ͷ���Ϊ��
	Node* newnode = new Node;//�����ڴ�
	tail = newnode;
	cout << "�밴��ʾ��ʼ��������" << endl;
	cout << "�������һ������(��0)��" << endl;
	cin >> newnode->data;
	while (newnode->data != 0)
	{
		count++;
		if (count == 1)
		{
			head = newnode;//ͷָ��ָ���׽ڵ�
			head->next = head->prior = NULL;//ʹ��ָ��Ϊ��
			tail = newnode;//�����½ڵ�
		}
		else
		{
			newnode->next = NULL;//�½ڵ�ָ��Ϊ��
			tail->next = newnode;//ԭ����β�ڵ�ָ���½ڵ�
			tail = newnode;
			Node* p = head;
			while (p->next != tail)
			{
				p = p->next;
			}
			tail->prior = p;
		}
		newnode = new Node;//�ٴθ��½ڵ�����µ��ڴ�ռ�
		cout << "�������" << count + 1 << "�����ݣ�(��ʾ�����롮0������ֹ����)" << endl;
		cin >> newnode->data;
		if (newnode->data == 0)
		{
			break;
		}
	}
}


//��������
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
	cout << "���������٣�" << endl;
}


//���������е�һ��Ԫ�ص�����
template<typename T>
T& QGList<T>::front()
{
	if (count == 0)
	{
		cout << "���������������ȴ���һ������" << endl;
	}
	else
	{
		cout << "��һ��Ԫ��Ϊ��" << head->data << endl;
		return head->data;

	}
	system("pause");
	system("cls");
}

//�������������һ��Ԫ�ص�����
template<typename T>
T& QGList<T>::back()
{
	if (count == 0)
	{
		cout << "���������������ȴ���һ������" << endl;
	}
	else
	{
		cout << "���һ��Ԫ��Ϊ��" << tail->data << endl;
		return tail->data;

	}
	system("pause");
	system("cls");
}

//��������һ��Ԫ��ǰ����Ԫ��e
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
	cout << "����ɹ���" << endl;
	return head;
	delete(newnode);
	system("pause");
	system("cls");
}

//ɾ��������һ��Ԫ��
template<typename T>
bool QGList<T>::pop_front()
{
	Node* p;
	p = head;
	head = head->next;
	head->prior = NULL;
	delete(p);
	count--;
	cout << "ɾ���ɹ���" << endl;
	return 1;
	system("pause");
	system("cls");
}

//���������һ��Ԫ�غ�����Ԫ��e
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
	cout << "����ɹ���" << endl;
	delete(p);
	return 1;
	system("pause");
	system("cls");
}

//ɾ���������һ��Ԫ��
template<typename T>
bool QGList<T>::pop_back()
{
	Node* p, * pre = head;
	p = tail;
	for (unsigned int i = 1; i < count - 1; i++)  //����forѭ����ָ��ָ�ڵ�index�������
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
	cout << "ɾ���ɹ���" << endl;
	return 1;
	system("pause");
	system("cls");
}

//�������ĵ�index + 1��Ԫ��ǰ����Ԫ��e
template<typename T>
bool QGList<T>::insert(unsigned int index, T& e)
{
	Node* p = head, * pre = NULL;
	Node* newnode = new Node; //�����½���ڴ�
	newnode->data = e;   //��e��ֵ����������
	for (unsigned int i = 1; i < index + 1; i++)  //����forѭ����ָ��pָ�ڵ�index+1�������
	{
		p = p->next;
		pre = p->prior;
	}
	newnode->next = p;  //�½���nextָ���index+1�����
	p->prior = newnode;  //��index+1������priorָ���½��
	pre->next = newnode;   //��index������nextָ���½��
	newnode->prior = pre;   //�½���priorָ���index�����
	count++;    //�����ڵ�����
	cout << "����ɹ���" << endl;
	delete(newnode);
	return head;
	system("pause");
	system("cls");
}

//ɾ������λ��Ԫ��
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
	cout << "ɾ���ɹ���" << endl;
	return 1;
	system("pause");
	system("cls");
}

//�������
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
	cout << "��������գ�" << endl;
	return 1;
	system("pause");
	system("cls");
	cout << "��������գ�" << endl;
	return 1;
	system("pause");
	system("cls");
}

//����Ԫ���Ƿ����
template<typename T>
bool QGList<T>::contain(T& e)
{
	Node* p = head;

	for (int i = 1; i <= count; i++)
	{
		if (p->data == e)
		{
			cout << "���ڸ�Ԫ�أ�" << endl;
			break;
		}
		else
		{
			if (i == count)
			{
				cout << "�鲻����Ԫ�أ�" << endl;
				break;
			}
			p = p->next;
		}
	}
	return 1;
	system("pause");
	system("cls");
}

//����������Ԫ�ص�����
template<typename T>
unsigned int QGList<T>::size()
{
	cout << "Ԫ������Ϊ��" << count << endl;
	return count;
	system("pause");
	system("cls");
}


template<typename T>
void Print(T& e)
{
	cout << e << endl;
}

//��������, ��ÿ��Ԫ�ص���visitָ��ĺ���
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



