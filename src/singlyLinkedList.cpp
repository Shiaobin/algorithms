/*
 * 單向鍊結串列練習
 *
 *  Created on: 2013/12/10
 *      Author: Shiaobin <Shiaobin@gmail.com>
 */
#include <iostream>
#include <cstdlib>
#include "singlyLinkedList.h"

using std::cout;
using std::cerr;
using std::endl;

/* 測試串列 */
int main(int argc, char *argv[])
{
	List x;

	/* 測試 addFirst() */
	x.addFirst(3);
	x.addFirst(2);
	x.addFirst(1);
	cout << x << endl;

	/* 串列非空，測試 getFirst() */
	cout << "get " << x.getFirst() << endl;
	cout << "get " << x.getFirst() << endl;
	cout << x << endl;

	/* 串列非空，測試 removeFirst() */
	cout << "remove " << x.removeFirst() << endl;
	cout << "remove " << x.removeFirst() << endl;
	cout << x << endl;

	/* 串列空，測試 removeFirst() */
	cout << "remove " << x.removeFirst() << endl;
	cout << "remove " << x.removeFirst() << endl;
	cout << x << endl;

	return 0;
}

/* 讓串列可以用 cout 輸出 */
ostream &operator<<(ostream &output, const List &that)
{
	Node *toPrint = that.head;

	while (toPrint != NULL)
	{
		output << toPrint->data << " -> ";
		toPrint = toPrint->next;
	}
	output << "NULL";

	return output;
}

/* 串列初始化 */
List::List()
{
	head = NULL;
}

/* 清除串列 */
List::~List()
{
	Node *toRemove = NULL;
	while (head != NULL)
	{
		toRemove = head;
		head = head->next;
		delete toRemove;
	}
}

/* 檢查串列是不是空的 */
bool List::isEmpty(void)
{
	return head == NULL;
}

/* 在開頭加入資料 */
void List::addFirst(int dataIn)
{
	Node *newNode = new Node;
	newNode->data = dataIn;
	newNode->next = head;
	head = newNode;
}

/* 取出第一個節點的資料，不刪除節點 */
int List::getFirst(void)
{
	int dataOut = 0;

	try
	{
		if (isEmpty())
		{
			throw "Unable to get, list is empty.";
		}
		dataOut = head->data;
	} catch (const char *errmsg)
	{
		cerr << errmsg << endl;
		abort();
	}

	return dataOut;
}

/* 取出第一個節點的資料，並刪除節點 */
int List::removeFirst(void)
{
	Node *toRemove = head;
	int dataOut = 0;

	try
	{
		if (isEmpty())
		{
			throw "Unable to remove, list is empty.";
		}
		dataOut = toRemove->data;
		head = head->next;
		delete toRemove;
	} catch (const char *errmsg)
	{
		cerr << errmsg << endl;
		abort();
	}

	return dataOut;
}
