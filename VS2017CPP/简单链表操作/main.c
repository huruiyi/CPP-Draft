#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct LinkNode {
	int data; //数据域
	struct LinkNode *next; //指针域
}lianbiao;

void Foreach_LinkList(lianbiao *header)//链表遍历打印 （ 头）
{
	if (NULL == header)//判断是否导入链表头部节点
	{
		return;
	}
	lianbiao *pcurrent = header->next; //创建辅助指针讲头部连接下一个的节点指针导入
	int i = 1;

	while (pcurrent != NULL)//判断是否到达结尾
	{
		printf("[%d]:%d\t ", i++, pcurrent->data);//打印本次循环的节点data域

		pcurrent = pcurrent->next;	//指针后移到下一个节点
	}
	printf("\n");
}

void Remove_LinkList(lianbiao *header, int val)//根据值删除 （ 头 被删除数值）
{
	if (NULL == header)//判断是否导入链表头部节点
	{
		return;
	}

	lianbiao *pPrev = header;//创建辅助指针导入头节点地址
	lianbiao *pCurrent = pPrev->next;//创建辅助指针2导入下一个节点的位置

	while (pCurrent != NULL)//遍历判断是否到达结尾
	{
		if (pCurrent->data == val)//判断是否是所找的数值找到直接退出
		{
			break;
		}
		pPrev = pCurrent;//找不到后移指针  找到了则存储当前节点前的节点地址
		pCurrent = pPrev->next;//找不到后移指针  找到了则存储当前节点的地址
	}

	if (pCurrent == NULL)//如果辅助指针到达结尾没找到则打印节点不存在
	{
		printf("值为%d的节点不存在！\n", val);
		return;
	}

	lianbiao *pNext = pCurrent->next;//缓存删除节点的下一节点地址

	free(pCurrent);//释放被删除节点空间

	pPrev->next = pNext;//将被删除节点连接到删除节点下一节点
}

void Insert_LinkList(lianbiao *header, int val, int newvalue)////在指定的值后面插入 （  头节点，数值，插入的数值）
{
	if (NULL == header)//判断是否导入链表头部节点
	{
		return;
	}

	lianbiao *pPrev = header;//创建辅助指针导入头节点地址
	lianbiao *pCurrent = pPrev->next;//创建辅助指针2导入下一个节点的位置

	while (pCurrent != NULL)//判断是否到达结尾
	{
		if (pCurrent->data == val)//判断是否是所找的数值找到直接退出
		{
			pPrev = pCurrent;
			pCurrent = pPrev->next;
			break;
		}

		pPrev = pCurrent;//找不到后移指针  找到了则存储当前节点前的节点地址
		pCurrent = pPrev->next;//找不到后移指针  找到了则存储当前节点的地址
	}

	lianbiao *newnode = (lianbiao *)malloc(sizeof(lianbiao));//创建节点空间
	newnode->data = newvalue;//新节点空间DATA域存储插入的数值
	newnode->next = NULL;//将next域初始化滞空

	newnode->next = pCurrent;//将插入值next域连接到找到节点的地址
	pPrev->next = newnode;//讲前面的值连接到插入值
}

void Destroy_LinkList(lianbiao *header)//链表的销毁（头）
{
	if (NULL == header)//判断是否导入链表头部节点
	{
		return;
	}

	lianbiao *pCurrent = header;//创建辅助指针存储头部节点
	while (pCurrent != NULL)//判断链表是否结束
	{
		lianbiao *pNext = pCurrent->next;//缓存本轮释放节点的下一节点地址
		free(pCurrent);//释放本轮节点

		pCurrent = pNext;	//辅助指针移动到下一节点
	}
}

int main()
{
	lianbiao *header = NULL;//创建节点头部

	header = (lianbiao*)malloc(sizeof(lianbiao));//开辟头部节点内存堆空间

	header->data = -1;//给头部节点data域赋值
	header->next = NULL;//将头部节点next域质控

	struct LinkNode *p1 = (struct LinkNode*)malloc(sizeof(struct LinkNode));
	struct LinkNode *p2 = (struct LinkNode*)malloc(sizeof(struct LinkNode));
	struct LinkNode *p3 = (struct LinkNode*)malloc(sizeof(struct LinkNode));
	struct LinkNode *p4 = (struct LinkNode*)malloc(sizeof(struct LinkNode));
	struct LinkNode *p5 = (struct LinkNode*)malloc(sizeof(struct LinkNode));
	struct LinkNode *p6 = (struct LinkNode*)malloc(sizeof(struct LinkNode));

	p1->data = 3;
	p2->data = 1;
	p3->data = 10;
	p4->data = 7;
	p5->data = 6;
	p6->data = 5;

	header->next = p1;//建立节点关系
	p1->next = p2;
	p2->next = p3;
	p3->next = p4;
	p4->next = p5;
	p5->next = p6;
	p6->next = NULL;
	printf("查看链表\n");
	Foreach_LinkList(header);//打印链表查看是否成功

	Remove_LinkList(header, 6);//删除链表中数据为6的节点
	printf("删除后查看链表\n");
	Foreach_LinkList(header);//打印链表查看是否删除成功

	Insert_LinkList(header, 3, 9);////在指定的值后面插入 （  头节点，数值，插入的数值）
	printf("添加查看链表\n");
	Foreach_LinkList(header);//打印链表查看是否插入成功

	Destroy_LinkList(header);//销毁链表

	system("pause");
	return EXIT_SUCCESS;
}