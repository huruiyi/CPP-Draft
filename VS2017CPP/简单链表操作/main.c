#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct LinkNode {
	int data; //������
	struct LinkNode *next; //ָ����
}lianbiao;

void Foreach_LinkList(lianbiao *header)//���������ӡ �� ͷ��
{
	if (NULL == header)//�ж��Ƿ�������ͷ���ڵ�
	{
		return;
	}
	lianbiao *pcurrent = header->next; //��������ָ�뽲ͷ��������һ���Ľڵ�ָ�뵼��
	int i = 1;

	while (pcurrent != NULL)//�ж��Ƿ񵽴��β
	{
		printf("[%d]:%d\t ", i++, pcurrent->data);//��ӡ����ѭ���Ľڵ�data��

		pcurrent = pcurrent->next;	//ָ����Ƶ���һ���ڵ�
	}
	printf("\n");
}

void Remove_LinkList(lianbiao *header, int val)//����ֵɾ�� �� ͷ ��ɾ����ֵ��
{
	if (NULL == header)//�ж��Ƿ�������ͷ���ڵ�
	{
		return;
	}

	lianbiao *pPrev = header;//��������ָ�뵼��ͷ�ڵ��ַ
	lianbiao *pCurrent = pPrev->next;//��������ָ��2������һ���ڵ��λ��

	while (pCurrent != NULL)//�����ж��Ƿ񵽴��β
	{
		if (pCurrent->data == val)//�ж��Ƿ������ҵ���ֵ�ҵ�ֱ���˳�
		{
			break;
		}
		pPrev = pCurrent;//�Ҳ�������ָ��  �ҵ�����洢��ǰ�ڵ�ǰ�Ľڵ��ַ
		pCurrent = pPrev->next;//�Ҳ�������ָ��  �ҵ�����洢��ǰ�ڵ�ĵ�ַ
	}

	if (pCurrent == NULL)//�������ָ�뵽���βû�ҵ����ӡ�ڵ㲻����
	{
		printf("ֵΪ%d�Ľڵ㲻���ڣ�\n", val);
		return;
	}

	lianbiao *pNext = pCurrent->next;//����ɾ���ڵ����һ�ڵ��ַ

	free(pCurrent);//�ͷű�ɾ���ڵ�ռ�

	pPrev->next = pNext;//����ɾ���ڵ����ӵ�ɾ���ڵ���һ�ڵ�
}

void Insert_LinkList(lianbiao *header, int val, int newvalue)////��ָ����ֵ������� ��  ͷ�ڵ㣬��ֵ���������ֵ��
{
	if (NULL == header)//�ж��Ƿ�������ͷ���ڵ�
	{
		return;
	}

	lianbiao *pPrev = header;//��������ָ�뵼��ͷ�ڵ��ַ
	lianbiao *pCurrent = pPrev->next;//��������ָ��2������һ���ڵ��λ��

	while (pCurrent != NULL)//�ж��Ƿ񵽴��β
	{
		if (pCurrent->data == val)//�ж��Ƿ������ҵ���ֵ�ҵ�ֱ���˳�
		{
			pPrev = pCurrent;
			pCurrent = pPrev->next;
			break;
		}

		pPrev = pCurrent;//�Ҳ�������ָ��  �ҵ�����洢��ǰ�ڵ�ǰ�Ľڵ��ַ
		pCurrent = pPrev->next;//�Ҳ�������ָ��  �ҵ�����洢��ǰ�ڵ�ĵ�ַ
	}

	lianbiao *newnode = (lianbiao *)malloc(sizeof(lianbiao));//�����ڵ�ռ�
	newnode->data = newvalue;//�½ڵ�ռ�DATA��洢�������ֵ
	newnode->next = NULL;//��next���ʼ���Ϳ�

	newnode->next = pCurrent;//������ֵnext�����ӵ��ҵ��ڵ�ĵ�ַ
	pPrev->next = newnode;//��ǰ���ֵ���ӵ�����ֵ
}

void Destroy_LinkList(lianbiao *header)//��������٣�ͷ��
{
	if (NULL == header)//�ж��Ƿ�������ͷ���ڵ�
	{
		return;
	}

	lianbiao *pCurrent = header;//��������ָ��洢ͷ���ڵ�
	while (pCurrent != NULL)//�ж������Ƿ����
	{
		lianbiao *pNext = pCurrent->next;//���汾���ͷŽڵ����һ�ڵ��ַ
		free(pCurrent);//�ͷű��ֽڵ�

		pCurrent = pNext;	//����ָ���ƶ�����һ�ڵ�
	}
}

int main()
{
	lianbiao *header = NULL;//�����ڵ�ͷ��

	header = (lianbiao*)malloc(sizeof(lianbiao));//����ͷ���ڵ��ڴ�ѿռ�

	header->data = -1;//��ͷ���ڵ�data��ֵ
	header->next = NULL;//��ͷ���ڵ�next���ʿ�

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

	header->next = p1;//�����ڵ��ϵ
	p1->next = p2;
	p2->next = p3;
	p3->next = p4;
	p4->next = p5;
	p5->next = p6;
	p6->next = NULL;
	printf("�鿴����\n");
	Foreach_LinkList(header);//��ӡ����鿴�Ƿ�ɹ�

	Remove_LinkList(header, 6);//ɾ������������Ϊ6�Ľڵ�
	printf("ɾ����鿴����\n");
	Foreach_LinkList(header);//��ӡ����鿴�Ƿ�ɾ���ɹ�

	Insert_LinkList(header, 3, 9);////��ָ����ֵ������� ��  ͷ�ڵ㣬��ֵ���������ֵ��
	printf("��Ӳ鿴����\n");
	Foreach_LinkList(header);//��ӡ����鿴�Ƿ����ɹ�

	Destroy_LinkList(header);//��������

	system("pause");
	return EXIT_SUCCESS;
}