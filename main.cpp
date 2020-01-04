/*****************************************
*   Copyright (C) 2019 All rights reserved.
*   File: main.cpp
*   Auth: LiuLang
*   Mail: datuhao@foxmail.com
*   Date: 2019-12-29 16:55
*   Desc: 
*****************************************/

#include "list.h"
#include <unistd.h>
#include <stdlib.h>
#include <time.h>


int main()
{
	int i=0;
	srand(time(NULL));

	node *head = new node(1006);
	for(; i<10; i++)
	{
		int val = (int)rand()%10000;
		node *new_node = new node(val);
		head = insert(head, new_node);
	}
		node *new_node1 = new node(199);
		head = insert(head, new_node1);

		node *new_node2 = new node(99);
		head = insert(head, new_node2);

		node *new_node3 = new node(44);
		head = insert(head, new_node3);

	head->print();
	
	head = reverse(head);
	head->print();

	head = reverse_by_new(head);
	head->print();

	head = sort_insert(head);
	printf("after sort-------------\n");
	head->print();

	node *head1 = new node(1006);
	for(i=0; i<5; i++)
	{
		int val = (int)rand()%10000;
		node *new_node = new node(val);
		head1 = insert(head1, new_node);
	}

	printf("head1-------------:\n");
	head1->print();
	head1 = sort_insert(head1);
	printf("head1 after sort-------------\n");
	head1->print();

	head = sorted_list_merge(head, head1);
	head->print();


	head1 = head;
	for(i=10; i>0; i--)
	{
		//int n = rand()%30;
		head = del_last_n_node(head, i);

		if(head)
		{
			find_mid(head);
			head->print();
		}else
		{
			//printf("head is NULL!\n");
		}
	}


	//head->next->next->next->next = head;
	bool b_cycle = check_cycle(head);
	if(b_cycle)
		printf("head is an cycle!\n");
	else
		printf("head is not an cycle!\n");


	/*
	head = del(head, new_node2);
	head->print();

	head = del(head, new_node3);
	head->print();
	*/

	head = del(head, head);
	head->print();

	head = del(head, new_node1);
	head->print();

	clear(head);
}
