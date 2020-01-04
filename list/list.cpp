/*****************************************
 *   Copyright (C) 2019 All rights reserved.
 *   File: list_tmp.h
 *   Auth: LiuLang
 *   Mail: datuhao@foxmail.com
 *   Date: 2019-12-29 16:38
 *   Desc: 
 *****************************************/
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


node *insert(node *head, node *next)
{
	if(!head)
		return next;

	if(!next)
		return head;

	next->next = head->next;
	head->next = next;

	return head;
}

node *del(node *head, node *del_node)
{
	if(!head || !del_node)
		return head;

	if(head == del_node)
	{
		node *ret = head->next;
		delete head;
		head = NULL;
		return ret;
	}

	node *pre = head;
	node *tmp = head->next;
	while(tmp && (tmp != del_node))
	{
		pre = tmp;
		tmp = tmp->next;	
	}

	if(tmp && (tmp == del_node))
	{
		pre->next = tmp->next;
		delete tmp;
		tmp = NULL;
	}

	return head;
}

node *reverse(node *head)
{
	if(!head)
		return NULL;

	node *pre = NULL;
	node *mid = head;
	node *bak = head->next;
	
	while(bak)
	{
		mid->next = pre;
		pre = mid;
		mid = bak;
		bak = bak->next;
	}

	mid->next = pre;
	pre = mid;

	return pre;
}

node *reverse_by_new(node *head)
{
	node * new_head= new node(1234);

	node *tmp = NULL;
	node *bak = head;
	while(bak)
	{
		tmp = bak;

		bak = bak->next;
		new_head = insert(new_head, tmp);
	}

	
	tmp = new_head->next;
	delete new_head;
	new_head = NULL;

	return tmp;
}


node *quick_sort(node *head)
{
	if(!head || !head->next)
		return head;

	node *big_head; 
	node *big_end;

	node *small_head;
	node *small_end;

	if(head->next->val > head->val)
	{
		big_head = head->next;
		big_end = head->next;

		small_head = head;
		small_end = head;

	}
	else
	{
		big_head = head;
		big_end = head;

		small_head = head->next;
		small_end = head->next;
	}

	head = head->next->next;
	while(head)
	{
		if(big_head->val > head->val)
		{
			small_end->next = head;
			small_end = small_end->next;
		}
		else
		{
			big_end->next = head;
			big_end = big_end->next;
		}	

		head = head->next;
	}

	if(small_end)
		small_end->next= NULL;
	if(big_end)
		big_end->next = NULL;

//	small_head->print();
//	big_head->print();
//printf("========================\n");	
//sleep(1);
//	exit(0);

	//head->print();
	head = quick_sort(big_head);
	big_end->next = quick_sort(small_head);

	return head;
}


node *find_big_node(node *head, node **big_node)
{
	if(!head)
	{
		*big_node = NULL;
		return NULL;
	}
	*big_node = head;
	node *tmp = head->next;
	node *pre = NULL;

	if(!tmp)
		return head;

	if(tmp->val >  head->val)
	{
		*big_node = tmp;
		head->next = tmp->next;
	}
	else
	{
		*big_node = head;

		head = tmp;	
		head->next = tmp->next;
	}

	pre = head;
	pre->next = head->next;
	tmp = tmp->next;
	while(tmp)
	{
		if(tmp->val > (*big_node)->val)
		{
			pre->next = *big_node;
			pre->next->next = tmp->next;
			(*big_node) = tmp;

			pre = pre->next;
			tmp = tmp->next;
		}
		else
		{
			pre = pre->next;
			tmp = tmp->next;
		}

		(*big_node)->next = NULL;
	}

//	(*big_node)->print();
	return head;
}

node *sort_insert(node *head)
{
	node *big = NULL; 
	node *new_head;
	node *ret_node;

	head = find_big_node(head, &big);	
	if(head)
	{
		new_head = big;	
	}
	else
		return head;

	ret_node = new_head;
	ret_node->next = NULL;
	new_head->next = NULL;

	while(head)
	{
		head = find_big_node(head, &big);
		if(head)
		{
			new_head->next = big;	
		}
		else
		{
			printf("some thing error!\n");
		}

		if(head == big)
		{
			new_head = new_head->next;
			new_head->next = NULL;
			break;
		}

		new_head = new_head->next;
		new_head->next = NULL;
	}

	return ret_node;
}


node *sorted_list_merge(node *first, node* second)
{
	if(!first)
		return second;
	if(!second)
		return first;

	node *head = NULL;
	node *next = head;

	if(first->val > second->val)
	{
		head = first;
		first = first->next;
		next = head;
	}
	else
	{
		head = second;
		second = second->next;
		next = head;
	}

	while(first && second)
	{
		if(first->val > second->val)
		{
			next->next = first;
			first = first->next;
			next = next->next;
		}
		else
		{
			next->next = second;
			second = second->next;
			next = next->next;
		}
	}

	if(first)
		next->next = first;

	if(second)
		next->next = second;

	return head;
}


node *del_last_n_node(node *head, int n)
{
	if(!head || n<1)
	{
		return head;
	}

	node *next = head;
	node *next_n = head;
	node *next_pre = NULL;

	int i=0;
	for(i=1; i<n; i++)
	{
		next_n = next_n->next;
		if(!next_n)
			break;
	}

	if(!next_n)
	{
		return head;
	}

	//n=1
	while(next_n->next)
	{
	//	printf("next_n_val:%d\n", next_n->val);
	//	printf("next_pre val:%d\n", next_pre->val);
	//	printf("next val:%d\n", next->val);
		next_n = next_n->next;

		if(next_pre)
			next_pre = next_pre->next;
		else
			next_pre = head;

		next = next->next;
	}

	//n == list length
	if(!next_pre)
	{
		if(n == 1)
		{
			if(head->next)
			{
				printf("something error! exit!\n");	
				exit(-1);
			}
			delete head;
			head = NULL;
		}
		else
		{
			if(next != head)
			{
				printf("list length != %d something error! exit!\n", n);	
				exit(-1);
			}

			printf("delete last n = %d:", n);
			head = head->next;	
			//head->next = head->next->next;
			delete next;
			next = NULL;
		}

		return head;
	}

	if(next)
	{
		next_pre->next = next->next;
		printf("delete last n = %d:", n);
		delete next;
		next = NULL;
	}
	else
	{
		printf("delete last n = %d:", n);
		printf("some thing error!\n");
		return head;
	}

	return head;
}

node *find_mid(node *head)
{
	if(!head)
		return head;

	if(!head->next)
	{
		printf("mid Value:%d\n", head->val);
		return head;
	}


	node *end = head;
	node *pre = NULL;
	node *mid = head;

	bool double_list = false;
	while(end->next)
	{
		if(!pre)
			pre=head;
		else
			pre=pre->next;
		mid = mid->next;
		end = end->next;
		if(!end->next)
		{
			double_list = true;
			break;
		}

		end = end->next;
	}

	if(double_list)
		printf("mid values:%d, %d\n", pre->val, mid->val);
	else
		printf("mid value:%d\n", mid->val);

	return pre;
}

bool check_cycle(node *head)
{
	typedef std::set<long> n_set;
	n_set node_set;

	if(!head)
		return false;
	
	size_t size = 0;

	node *tmp = head;
	while(tmp->next)
	{
		tmp = tmp->next;	
		node_set.insert((long)tmp);
		size++;
		
		if(size > node_set.size())
		{
			return true;
			break;
		}
	}

	return false;
}

int clear(node *next)
{
	if(!next)
		return 0;

	while(next)
	{
		node * tmp = next;
		next = next->next;
		delete tmp;
	}

	printf("\n");

	return 0;
}
