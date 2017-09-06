#include<stdlib.h>
#include<stdio.h>

struct Person
{
	int Id;
	struct Person *next;
};
typedef struct Person PPerson;

void InitPersonLinkList1(PPerson** conp)
{
	*conp = malloc(sizeof(PPerson));
	(*conp)->Id = 0;
	(*conp)->next = NULL;
}

 
PPerson * InitPersonLinkList2()
{
	PPerson * p = malloc(sizeof(PPerson));;
	p->Id = 0;
	p->next = NULL;
	return p;
}

void main()
{
	PPerson *p1 = NULL;
	InitPersonLinkList1(&p1);

	PPerson *p2 = InitPersonLinkList2();

	system("pause");
}