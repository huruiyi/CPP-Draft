#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

void test1()
{
	//char s1[5];
	//s1 = "abcd"; //����ʧ��
	//printf("%s", s1);

	char *s2 = "abcd";
	printf("%s", s2);
}

int fn(int x)
{
	int f1;
	int f2;
	if (x == 1 || x == 2)
	{
		return 1;
	}
	else
	{
		f1 = fn(x - 1);
	}
	f2 = fn(x - 2);
	return f1 + f2;

	/*
	int y = fn(6);
	printf("%d ", y);
	system("pause");
	**/
}

void Demo1()
{
	//�ַ�������
	char str1[] = { "hello" };
	str1[2] = 8;
	printf("%p��%s\n", str1, str1);

	//char *�洢���ַ�������������ֵ�ǲ������޸ĵ�
	//�ַ������������Զ���������д
	const char const *  str2 = { "world" };
	const  char *str3 = { "world" };
	const  char *str4 = { "world" };
	//printf("�ַ�������-----�޸�ǰ");

	//str2, str3, str4,�ĵ�ַ��ֵ��һ����
	printf("%p��%s\n", str2, str2);
	printf("%p��%s\n", str3, str3);
	printf("%p��%s\n", str4, str4);

	str2 = "789456";
	str3 = "hello";
	char*p = str2;
	//str2[2] = 8;//����ɹ�������ʧ��

	printf("%p��%s\n", str2, str2);
	printf("%p��%s\n", str3, str3);
	printf("%p��%s\n", str4, str4);

	system("pause");
}

struct {
	char member[10];
} ma, mb;

void Demo2()
{
	printf("%s\n", ma.member);
	printf("%s\n", mb.member);
	int i;
	for (i = 0; i < 10; i++)
	{
		mb.member[i] = 'a';
	}

	//a.member = b.member; error
	printf("%s\n", ma.member);
	printf("%s\n", mb.member);
	system("pause");

	unsigned int x = 3, y = -2, z = 2;
	if (x > y)
		if (y < 0)
			z = 0;
		else
			z += 1;
	printf("%d", z);
	system("pause");
}

union
{
	int i;
	char x[2];
}a;

void Demo3()
{
	a.x[0] = 10;
	a.x[1] = 1;
	printf("a.i = %d", a.i);
}

void Demo4()
{
#define  DOUBLE(X)  1+5+1+5 ;
	int i = 5 * DOUBLE(X);
	printf("%d\n", i);
}

char * Dmeo5()
{
	//char p[] = "Hello World";//warning: function returns address of local variable [-Wreturn-local-addr]
	char *p = malloc(100);

	printf("%p\n", p);
	p = "hello";
	printf("%p\n", p);
	//����printf��p�ĵ�ַ��һ��

	return p;
}

void Demo5Test()
{
	char *p = Dmeo5();
	printf("%s\n", p);
}

char * Dmeo6()
{
	//char p[] = "Hello World";//warning: function returns address of local variable [-Wreturn-local-addr]
	char *p = malloc(100);

	printf("%p\n", p);
	strcpy_s(p, 6, "hello");
	printf("%p\n", p);
	//����printf��p�ĵ�ַ��һ��

	return p;
}

void Demo6Test()
{
	char *p = Dmeo6();
	printf("%s\n", p);
}

void Demo7()
{
	char name[50] = "xiaoming";

	char hobby[100];
	//hobby = "1000";
	strcpy_s(hobby, sizeof("Hello World"), "Hello World");

	printf("hobby=%s---sizeof=%d---len=%d\n", hobby, sizeof("Hello World"), strlen("Hello World"));
}

void Demo8()
{
	char *p = "123456";
	strcpy(p, "789");//p���ڳ������ǲ������޸ĵ�
	p = "789"; //p�ĵ�ַ���޸�
	strcpy_s(p, sizeof("Hello World"), "Hello World");//error
	printf("p=%s---sizeof=%d---len=%d\n", p, sizeof("Hello World"), strlen("Hello World"));
}

void Demo9()
{
	char *p = "123456";
	//strcpy_s(p, sizeof("Hello World"), "Hello World");
	printf("p=%s---sizeof=%d---len=%d\n", p, sizeof("Hello World"), strlen("Hello World"));
}

void Demo10()
{
	char a[4];//û�г�ʼ��
	char *str = &a;
	strcpy(str, "aa");
	strcpy(str, "Hello"); //�ռ䲻��
}

void Demo11(char **p)
{
	*p = (char *)malloc(100);
}

void Demo11Test()
{
	char *p = NULL;
	Demo11(&p);
	//Demo11(p);//error
	strcpy(p, "Hello World");
	printf("p=%s\n", p);
	free(p);
}

void Demo12()
{
	char *str = "Hello World";
	int len = strlen(str);
	//char *dest = (char *)malloc(len);//error
	char *dest = (char *)malloc(len + 1);

	char * d = dest;
	//char * s = str[len];//error
	char * s = str;
	printf("d=%s\n", d);
	printf("s=%s\n", s);
	printf("\n");
	while (len--)
	{
	}
	printf("d=%s\n", d);
	printf("s=%s\n", s);

	char *p = "Hello World";
}

//ָ�����飺array of pointers�������ڴ洢ָ������飬Ҳ��������Ԫ�ض���ָ��

//����ָ�룺a pointer to an array����ָ�������ָ��
void Demo13()
{
	int c1[5] = { 65,66,67,68,69 };

	//ָ������,��ʾ�����Ԫ�ض���int��ָ��
	int *c2[5];

	c2[0] = &c1[0];
	c2[1] = &c1[1];
	c2[2] = &c1[2];
	c2[3] = &c1[3];
	c2[4] = &c1[4];

	int d2[2][3] = { 10,20,30,40,50,60 };

	//����ָ�룬��ʾָ�������ָ��
	int(*c3)[3] = d2;

	int(*c4)[3] = d2;
	c4[0][0] = d2[0][0];
	c4[0][1] = d2[0][1];
	c4[0][2] = d2[0][2];

	c4[1][0] = d2[1][0];
	c4[1][1] = d2[1][1];
	c4[1][2] = d2[1][2];

	int i = 0;
	for (i = 0; i < 5; i++)
	{
		printf("c1[%d]=%c---%d\n", i, c1[i], c1[i]);
	}
	printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	for (i = 0; i < 5; i++)
	{
		printf("c2[%d]=%c---%d\n", i, *c2[i], *c2[i]);
	}
	printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

	for (size_t i = 0; i < 2; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			printf("%d\t", c3[i][j]);
		}
		printf("\n");
	}
	printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

	for (size_t i = 0; i < 2; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			printf("%d\t", c4[i][j]);
		}
		printf("\n");
	}
}

void Demo14()
{
	int c[4] = { 1,2,3,4 };
	int *a[4]; //ָ������
	int(*b)[4]; //����ָ��
	printf("sizeof(a)=%d\n", sizeof(a));
	printf("sizeof(b)=%d\n", sizeof(b));

	//a++; //error
	//a + 1; //ok
	//b++; //ok  ���� Ϊ4
	//b + 1; //ok

	b = &c;
	//������c��Ԫ�ظ�������a

	int i = 0;
	for (i = 0; i < 4; i++)
	{
		a[i] = &c[i];
	}

	for (i = 0; i < 4; i++)
	{
		printf("%p\t%d\n", a[i], *a[i]);
	}

	for (i = 0; i < 4; i++)
	{
		printf("%d\n", b[0][i]);
	}
}
int main()
{
	Demo14();

	system("pause");
	return 0;
}
/*

1.memmove

void *memmove(void *dest, const void *source, size_t count)
//����ָ��dest��void *ָ��
//dest,source�ֱ�ΪĿ�괮��Դ�����׵�ַ��countΪҪ�ƶ����ַ��ĸ���
//!!!memmove���ڴ�source����count���ַ���dest�����Ŀ�������Դ�������ص��Ļ���memmove�ܹ���֤Դ���ڱ�����֮
//ǰ���ص�������ֽڿ�����Ŀ�������С�

2.memcpy

void *memcpy(void *dest, const void *source, size_t count);
//����ָ��dest��void *ָ��
//memcpy���ܺ�memmove��ͬ������memcpy��dest��source�е��������ص�����������δ֪�����

3.��������
����memcpy()   ��source  ָ���������destָ���������count���ַ�������������ص���������ú�������Ϊ��  ��memmove(),����������ص�����ֵ����ȷ���С�

memcpy��������Ҫ���Ƶ��ڴ����򲻴����ص����������ȷ������и��Ʋ����ĵ��ڴ�����û���κ��ص�������ֱ����memcpy�� ����㲻�ܱ�֤�Ƿ����ص���Ϊ��ȷ�����Ƶ���ȷ�ԣ��������memmove��
memcpy��Ч�ʻ��memmove��һЩ������������׵Ļ����Կ�һЩ���ߵ�ʵ�֣�
*/