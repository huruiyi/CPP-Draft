#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include<string.h>

struct Node
{
	int Id;
	struct Node *next;
};
typedef struct Node LinkNode;
LinkNode * InitLinkNode()
{
	LinkNode * node = (LinkNode *)malloc(sizeof(LinkNode));
	node->Id = 0;
	node->next = NULL;
}

void insert_node_int(LinkNode * head, int id, int insertval)
{
	if (!head)
	{
		return;
	}
	LinkNode *pre = head;
	LinkNode *next = pre->next;

	LinkNode *   current = (LinkNode *)malloc(sizeof(LinkNode));
	current->Id = insertval;
	while (pre)
	{
		if (pre->Id == id)
		{
			break;
		}
		pre = pre->next;

		if (pre)//����λ��Id������ʱ
		{
			next = pre->next;
		}
	}
	if (pre)
	{
		pre->next = current;
	}
	current->next = next;
}

void insert_node_nodep(LinkNode * head, int pos, LinkNode * insertnode)
{
	if (!head)
	{
		return;
	}

#pragma region ���û�д˴����жϣ�ԭʼ�ı�ṹ�ᱻ�ƻ���������ĳһ�ڵ㱻�жϣ�,insertnode֮��Ľڵ���head�ڵ�Ͽ�
	LinkNode * node = head;
	while (node)
	{
		if (node == insertnode)
		{
			printf("\t\t�Ѳ���Ľڵ�,��ֹ����(Address:%p  id:%d  next:%p)\n", node, node->Id, node->next);
			return;
		}
		node = node->next;
	}
#pragma endregion

	LinkNode *pre = head;
	LinkNode *next = pre->next;

	while (pre)
	{
		if (pre->Id == pos)
		{
			break;
		}
		pre = pre->next;

		if (pre)//����λ��Id������ʱ
		{
			next = pre->next;
		}
	}
	if (pre)
	{
		pre->next = insertnode;
	}
	insertnode->next = next;
}

void push_back_int(LinkNode * head, int val)
{
	if (!head)
	{
		return;
	}
	LinkNode * newNode = (LinkNode *)malloc(sizeof(LinkNode));
	newNode->Id = val;
	newNode->next = NULL;

	LinkNode * pre = head;
	LinkNode *current = pre->next;
	while (current)
	{
		pre = current;
		current = pre->next;
	}
	pre->next = newNode;
}

void push_back_linknodep(LinkNode * head, LinkNode * node)
{
	if (!head)
	{
		return;
	}
	LinkNode * pre = head;
	LinkNode *current = pre->next;
	while (current)
	{
		pre = current;
		current = pre->next;
	}
	pre->next = node;
}

void delete_node_int(LinkNode * head, int deleteval)
{
	if (!head)
	{
		return;
	}
	LinkNode *pre = head;
	LinkNode *current = pre->next;

	while (current)
	{
		if (current->Id == deleteval)
		{
			break;
		}
		pre = pre->next;
		current = pre->next;
	}

	pre->next = current->next;
	free(current);
	current = NULL;
}

void for_each(LinkNode * node)
{
	if (!node)
	{
		return;
	}
	printf("***********************��ʼ��������***********************\n");
	while (node)
	{
		printf("\t\tAddress:%p  id:%d  next:%p\n", node, node->Id, node->next);
		node = node->next;
	}
	printf("***********************������������***********************\n\n");
}

void free_linknode(LinkNode * node)
{
	if (!node)
	{
		return;
	}
	LinkNode * current = node;
	printf("***********************��ʼ�ͷŶѿռ�***********************\n");
	while (current)
	{
		LinkNode * deleteNode = current;
		current = current->next;
		printf("\t\tAddress:%p  ���ͷ�\n", deleteNode);
		free(deleteNode);
		deleteNode = NULL;
	}
	printf("***********************�����ͷŶѿռ�***********************\n");
}

void test_insert_foreach()
{
	LinkNode * hNode = InitLinkNode();

#if 0  push_back_linknodep ����1
	for_each(hNode);
	LinkNode * node1 = (LinkNode *)malloc(sizeof(LinkNode));
	node1->Id = 2;
	node1->next = NULL;
	push_back_linknodep(hNode, node1);
	for_each(hNode);
#endif
#if 0   push_back_linknodep ����2
	for_each(hNode);
	LinkNode * node2 = (LinkNode *)malloc(sizeof(LinkNode));
	node2->Id = 3;
	node2->next = NULL;
	push_back_linknodep(hNode, node2);
	for_each(hNode);
#endif

	for_each(hNode);

	push_back_int(hNode, 1);
	push_back_int(hNode, 2);
	push_back_int(hNode, 3);
	push_back_int(hNode, 4);
	push_back_int(hNode, 5);
	push_back_int(hNode, 6);

	insert_node_int(hNode, 2, 2233);
	insert_node_int(hNode, 6, 7);
	insert_node_int(hNode, 7, 8);

	LinkNode * node3 = (LinkNode *)malloc(sizeof(LinkNode));
	node3->Id = 333;
	node3->next = NULL;
	insert_node_nodep(hNode, 3, node3);

	insert_node_nodep(hNode, 8, node3);

	for_each(hNode);

	free_linknode(hNode);
}

void test_delete_node()
{
	LinkNode * hNode = InitLinkNode();

	push_back_int(hNode, 1);
	push_back_int(hNode, 2);
	push_back_int(hNode, 3);
	push_back_int(hNode, 4);
	push_back_int(hNode, 5);
	push_back_int(hNode, 6);

	delete_node_int(hNode, 6);

	for_each(hNode);

	free_linknode(hNode);
}

void ReseveLinkNode(LinkNode * hNode)
{
	LinkNode * prev = NULL;
	LinkNode * current = hNode;
	LinkNode * next = current->next;
	/*while (next->next)
	{
		next = next->next;
	}*/

	current->next = prev;
	next->next = prev;
}

void reservelink()
{
	LinkNode * hNode = InitLinkNode();
	push_back_int(hNode, 1);
	push_back_int(hNode, 2);
	push_back_int(hNode, 3);
	push_back_int(hNode, 4);
	push_back_int(hNode, 5);
	push_back_int(hNode, 6);
	for_each(hNode);
	ReseveLinkNode(hNode);
}


int main()
{
	printf("%d\n", *fp);
	reservelink();

	system("pause");
	return 0;
}