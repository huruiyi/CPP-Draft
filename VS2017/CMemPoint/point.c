#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

void test1()
{
	//char s1[5];
	//s1 = "abcd"; //编译失败
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
	//字符串变量
	char str1[] = { "hello" };
	str1[2] = 8;
	printf("%p：%s\n", str1, str1);

	//char *存储于字符串常量区，其值是不可以修改的
	//字符串常量，可以读，不可以写
	const char const *  str2 = { "world" };
	const  char *str3 = { "world" };
	const  char *str4 = { "world" };
	//printf("字符串常量-----修改前");

	//str2, str3, str4,的地址和值是一样的
	printf("%p：%s\n", str2, str2);
	printf("%p：%s\n", str3, str3);
	printf("%p：%s\n", str4, str4);

	str2 = "789456";
	str3 = "hello";
	char*p = str2;
	//str2[2] = 8;//编译成功，运行失败

	printf("%p：%s\n", str2, str2);
	printf("%p：%s\n", str3, str3);
	printf("%p：%s\n", str4, str4);

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
	//以上printf的p的地址不一样

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
	//以上printf的p的地址不一样

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
	strcpy(p, "789");//p放在常量区是不可以修改的
	p = "789"; //p的地址被修改
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
	char a[4];//没有初始换
	char *str = &a;
	strcpy(str, "aa");
	strcpy(str, "Hello"); //空间不足
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

//指针数组：array of pointers，即用于存储指针的数组，也就是数组元素都是指针

//数组指针：a pointer to an array，即指向数组的指针
void Demo13()
{
	int c1[5] = { 65,66,67,68,69 };

	//指针数组,表示数组的元素都是int型指针
	int *c2[5];

	c2[0] = &c1[0];
	c2[1] = &c1[1];
	c2[2] = &c1[2];
	c2[3] = &c1[3];
	c2[4] = &c1[4];

	int d2[2][3] = { 10,20,30,40,50,60 };

	//数组指针，表示指向数组的指针
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
	int *a[4]; //指针数组
	int(*b)[4]; //数组指针
	printf("sizeof(a)=%d\n", sizeof(a));
	printf("sizeof(b)=%d\n", sizeof(b));

	//a++; //error
	//a + 1; //ok
	//b++; //ok  步长 为4
	//b + 1; //ok

	b = &c;
	//将数组c中元素赋给数组a

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
//返回指向dest的void *指针
//dest,source分别为目标串和源串的首地址。count为要移动的字符的个数
//!!!memmove用于从source拷贝count个字符到dest，如果目标区域和源区域有重叠的话，memmove能够保证源串在被覆盖之
//前将重叠区域的字节拷贝到目标区域中。

2.memcpy

void *memcpy(void *dest, const void *source, size_t count);
//返回指向dest的void *指针
//memcpy功能和memmove相同，但是memcpy中dest和source中的区域不能重叠，否则会出现未知结果。

3.两者区别
函数memcpy()   从source  指向的区域向dest指向的区域复制count个字符，如果两数组重叠，不定义该函数的行为。  而memmove(),如果两函数重叠，赋值仍正确进行。

memcpy函数假设要复制的内存区域不存在重叠，如果你能确保你进行复制操作的的内存区域没有任何重叠，可以直接用memcpy； 如果你不能保证是否有重叠，为了确保复制的正确性，你必须用memmove。
memcpy的效率会比memmove高一些，如果还不明白的话可以看一些两者的实现：
*/