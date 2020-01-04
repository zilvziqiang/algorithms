/*****************************************
 *   Copyright (C) 2019 All rights reserved.
 *   File: list_tmp.h
 *   Auth: LiuLang
 *   Mail: datuhao@foxmail.com
 *   Date: 2019-12-29 16:38
 *   Desc: 
 *****************************************/

#ifndef __LIST_H__
#define __LIST_H__

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <set>

typedef struct _node{
	int val;
	struct _node *next;

	void print()
	{
		printf("val:");

		struct _node *tmp = this;
		while(tmp)
		{
			printf("%d\t", tmp->val);
			tmp = tmp->next;
		}

		printf("\n");
	}

	_node(const int v)
	{
		val = v;
		next = NULL;
	}
	
	~_node()
	{
		printf("delete val = %d\n", val);
	}

}node;

node *insert(node *head, node *next);

node *del(node *head, node *del_node);

node *reverse(node *head);

node *sort_insert(node *head);

node *sorted_list_merge(node *first, node* second);

node *del_last_n_node(node *head, int n);

node *find_mid(node *head);

bool check_cycle(node *head);

int clear(node *head);

node *reverse_by_new(node *head);

node *find_big_node(node *head, node **big_node);

#endif
//
