/*
 * 單向鍊結串列練習
 *
 *  Created on: 2013/12/10
 *      Author: Shiaobin <Shiaobin@gmail.com>
 */

#ifndef SINGLYLINKEDLIST_H_
#define SINGLYLINKEDLIST_H_

#include <iostream>

using std::ostream;

/* 節點資料結構 */
struct Node
{
	int data;
	Node *next;
};

/* 串列類別 */
class List
{
public:
	friend ostream &operator<<(ostream &output, const List &that);
	List();
	~List();
	bool isEmpty(void);
	void addFirst(int data);
	int getFirst(void);
	int removeFirst(void);
private:
	Node *head;
};

#endif /* SINGLYLINKEDLIST_H_ */
