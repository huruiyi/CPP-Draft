#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include<string.h>
#include<Windows.h>
#include<process.h>
#include<rdpencomapi.h>
#include<rdpappcontainerclient.h>
#include<winsock.h>

struct {
	char member[10];
} ma, mb;

union
{
	int i;
	char x[2];
}intc;

typedef struct _str_type
{
	int _len;
	char _s[1];
}str_type;

typedef void(*MYPROC)(LPTSTR);

int IsHELLOORWORLD(const char * src, const char * constval)
{
	if (src == NULL)
	{
		return 0;
	}
	int i = 0;
	int len = strlen(src);
	if (len == 0)
	{
		return 0;
	}
	for (int i = 0; i < len; i++)
	{
		if (constval[i] != src[i])
		{
			return 0;
		}
	}
	return 1;
}
void demo_数组指针()
{
	printf("栈区数组元素的增长方向：\n");

	//整形数组
	int arr[6] = { 123,456,789,147,258,369 };
	for (int i = 0; i < 6; i++)
	{
		printf("arr[%d]：%p---%d\n", i, &arr[i], arr[i]);
	}

	//int(*p)[10]; p即为指向数组的指针，又称数组指针。
	//数组指针
	//int a[4][5];
	//int(*p)[5] = a;
	//
	int arrer[2][3] = { 123,456,789,147,258,369 };
	int(*p)[3] = arrer;
	int(*ppp)[3] = arrer;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%p---%d\n", &p[i][j], p[i][j]);
		}
		printf("\n");
	}
}
void demo_指针数组()
{
	int a = 123;
	int b = 456;
	int c = 789;
	int *arrp[3];
	//可以将指针数组作为二级指针
	int **p = arrp;
	arrp[0] = &a;
	arrp[1] = &c;
	arrp[2] = &b;
	for (int i = 0; i < 3; i++)
	{
		printf("%p--%d\n", arrp[i], *arrp[i]);
		*arrp[i] += 123;
	}

	for (int i = 0; i < 3; i++)
	{
		printf("%p--%d\n", p[i], *p[i]);
	}
	printf("a=%d, b=%d,c=%d\n", a, b, c);

	printf("堆区数组元素的增长方向：\n");
	int * parr = (int *)malloc(sizeof(int) * 6);
	for (int i = 0; i < 6; i++)
	{
		parr[i] = 100 + i;
		printf("parr[%d]：%p\n", i, &parr[i]);
	}
	//指针数组
	//指针数组是数组元素为指针的数组(例如 int *p[3],定义了p[0],p[1],p[2]三个指针)，其本质为数组。
	//char a[3][8] = { "gain","much","strong" };
	//char *n[3] = { "gain","much","strong" };
	int *pp[6];
	for (int i = 0; i < 6; i++)
	{
		pp[i] = &parr[i];
		printf("%p--%d\n", &parr[i], parr[i]);
	}
	system("pause");
}
void demo0(int *a)
{
	*a = 100;
}
void test0()
{
	int a = 10;
	int  p = &a;
	demo0(&a);

	printf("%d\n", a);
}
void demo1(int *a)
{
	*a = 100;
}
void test1()
{
	int a = 10;
	int *p = &a;
	//demo1(&a);
	demo1(p);
	printf("%d\n", a);
}
void demo2(int **a)
{
	**a = 100;
}
void test2()
{
	int a = 10;
	int *p = &a;
	int **pp = &p;
	demo2(pp);
	printf("%d\n", a);
}
void demo3(char * p)
{
	//p为空不能赋值的
	p = malloc(100);
	//	strcpy(p, "Hello");
}
void test3()
{
	char * p = "Hello World";
	p = "Hello";
	//p[0] = 'W'; //此处不能修改
	demo3(p);
	printf(p);

	char arr[100] = "123456789";
	//arr = "456789";//error.
	arr[0] = '9';//ok
	printf(arr);
}
void demo4(char * p)
{
	//strcpy(p, "Hello");
}
void test4()
{
	char arr[100];
	demo4(arr);
	printf(arr);
}
void test5()
{
	char _s[2] = { 0 };
	_s[0] = 's';
	printf("%s\n", _s);
}
void test6()
{
	int a1, b1;
	int * const p1 = &a1;

	*p1 = 123;//指针常量 ，指针的值未被const修饰可以被修改
			  //p1 = &b1;//error 左值指定 const 对象,知不可修改
			  //p1++;//error 左值指定 const 对象,知不可修改

	int a2, b2;
	const int *p2 = &a2;
	//*p2 = 123; //常量指针，指针对应的值是常量，不可修改
	p2 = &b2;
	p2++;
}
void test7()
{
	int str_len = 5;
	str_type *s = (str_type*)malloc(sizeof(str_type) + str_len - 1);
	free(s);
}
void test8()
{
	char *s = "\ta\018bc";
	for (; *s != '\0'; s++)
		printf("*\n");
}
void test9()
{
	//char buf[5] = "12345";
	char buf[5] = { '1','2','3','4','5' };
	//char buf[5] = {0};
	printf("%s\n", buf);
}
void test10()
{
	int a[5] = { 1,2,3,4,5 };
	int *p = (int *)(&a + 1);
	printf("%d", *(p - 1));
}
void test11()
{
	//a[1][1]
	int a[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	int a1 = *(&a[0][0] + 5);
	int a2 = *(*(a + 1) + 1);
	int a3 = *(&a[1] + 1);
	int a4 = *(a[1] + 1);
}
void test12()
{
#define SUB( X,Y ) (X+1)*Y

	int a = 3, b = 4;
	printf("%d\n", SUB(a++, b++));
}
void test13()
{
	int k = 17;
	printf("%d, %o, %x\n", k, k, k);
}
void test14()
{
	int a[5][2] = { 1,2,3,4,5,6,7,8,9,10 };
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			printf("%x,", &a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("%x,%x\n", a, &a);
	printf("%x,%x\n", a + 1, &a + 1);
	printf("%x,%x,%x\n", a[0], &a[0], &a[0][0]);
	printf("%x,%x,%x\n", a[0] + 1, &a[0] + 1, &a[0][0] + 1);
}
void test15()
{
	char *s = "\ta\018bc";
	char ch[20] = { 0 };
	strcpy(ch, s);
}
void test16()
{
	//LPCWSTR lpLibFileName=;
	//HINSTANCE hLib = LoadLibrary(pszDllName);

	//if (hLib < (HINSTANCE)HINSTANCE_ERROR)
	//{
	//	AfxMessageBox(IDS_LOADLIBFAILED); //unable to load DLL
	//	iReturn = FAIL_LOAD;              //unable to load DLL
	//}

	//// Find the entry point.
	//lpDllEntryPoint = GetProcAddress(hLib, "DllRegisterServer");
	//if (lpDllEntryPoint != NULL)
	//	(*lpDllEntryPoint)();
	//else
	//	;// Unable to locate entry point
}
void WinAPI()
{
	LPPOINT lpPoint = (LPPOINT)malloc(sizeof(LPPOINT));
	GetPhysicalCursorPos(lpPoint);//获取物理坐标

	LPSYSTEM_INFO lpSystemInfo = (LPSYSTEM_INFO)malloc(sizeof(LPSYSTEM_INFO));
	GetSystemInfo(lpSystemInfo);

	LPWSTR lpBuffer = (LPWSTR)malloc(sizeof(LPWSTR));
	UINT uSize;
	GetSystemDirectory(lpBuffer, 1);

	char path[MAX_PATH];
	GetSystemDirectory(path, MAX_PATH);

	LANGID lang = GetSystemDefaultLangID();
	switch (lang)
	{
	case 0X0804:
		printf("中文\n");
		break;
	case 0x0409:
		printf("英文\n");
		break;
	}

	HINSTANCE LibHandle = LoadLibrary("user32");

	printf("user32 LibHandle = //x%x\n", LibHandle);
	MYPROC ProcAdd = (MYPROC)GetProcAddress(LibHandle, "MessageBoxA");
	printf("MessageBoxA = //x%x\n", ProcAdd);

	//ScreenOff

	//DWORD dwRecipients = BSM_APPLICATIONS;
	//UINT uMessage = PM_MYMSG;
	//WPARAM wParam = 0;
	//LPARAM lParam = 0;

	//BroadcastSystemMessage(
	//	BSF_IGNORECURRENTTASK, // do not send message to this process
	//	&dwRecipients,         // broadcast only to applications
	//	uMessage,              // registered private message
	//	wParam,                // message-specific value
	//	lParam);              // message-specific value
}
void test17()
{
	int a = 123;
	char buf[200] = { 0 };
	buf[0] = a;

	printf("%d\n", buf);
}
/*
网络字节序IP:2155784384

‭0110 0010
1001 1100‬
0000 0000
0000 0000
*/
void test18()
{
	/*
		int a = 0x12345678;
		printf("%p\n", &a);
		小端存储
		0x00EFFC30  78  x
		0x00EFFC31  56  V
		0x00EFFC32  34  4
		0x00EFFC33  12  .
	1*/

	/*
	‭0110 0010
	1001 1100‬

	0000 0000 buf[0]
	0000 0000 buf[1]
	‭0110 0010 buf[2]
	1001 1100‬ buf[3]
	*/
	/*
	Linux:
			192.168.126.128
十进制：     2155784384
二进制：    1000 0000	0111 1110	1010 1000	1100 0000‬
			128			126			168			192
	*/
	int a = 61234;
	printf("%p\n", &a);
	char *buf = (char *)malloc(sizeof(char) * 4);
	memcpy(buf, &a, sizeof(char) * 4);
	int b = *((int *)buf);
	for (size_t i = 0; i < 4; i++)
	{
		//buf[i]=
	}
}
void test19()
{
	int a = 123456798;
	int b = a;
	int len = 0;
	while ((b % 10) > 0)
	{
		len++;
		printf("%d\n", b % 10);
		b = b / 10;
	}
}
void mymemcpy(char   *dst, char*src, int len)
{
	//for (int i = 0; i < len; i++)
	//{
	//	//*dst++ = *src++;
	//	//dst[i] = src[i];
	//	*(dst + i) = *(src + i);
	//}

	while (len--)
		*dst++ = *src++;
}
void test20()
{
	char dst[128] = { '\0' };
	char src[128] = "hello world";;

	mymemcpy(dst, src, strlen(src));

	printf("%s\n", src);
	printf("%s\n", dst);
}
void test21()
{
	char a[3];
	char b[] = "china";
	//a = b; //error
	printf("%s\n", a);
}
void test22()
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
void test23()
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
void test24()
{
	intc.x[0] = 10;
	intc.x[1] = 1;
	printf("a.i = %d", intc.i);
}
void test25()
{
#define  DOUBLE(X)  1+5+1+5 ;
	int i = 5 * DOUBLE(X);
	printf("%d\n", i);
}
void test26()
{
	char name[50] = "xiaoming";

	char hobby[100];
	//hobby = "1000";
	strcpy_s(hobby, sizeof("Hello World"), "Hello World");

	printf("hobby=%s---sizeof=%d---len=%d\n", hobby, sizeof("Hello World"), strlen("Hello World"));
}
void test27()
{
	char *p = "123456";
	strcpy(p, "789");//p放在常量区是不可以修改的
	p = "789"; //p的地址被修改
	strcpy_s(p, sizeof("Hello World"), "Hello World");//error
	printf("p=%s---sizeof=%d---len=%d\n", p, sizeof("Hello World"), strlen("Hello World"));
}
void test28()
{
	char *p = "123456";
	//strcpy_s(p, sizeof("Hello World"), "Hello World");
	printf("p=%s---sizeof=%d---len=%d\n", p, sizeof("Hello World"), strlen("Hello World"));
}
void test29()
{
	char a[4];//没有初始换
	char *str = &a;
	strcpy(str, "aa");
	strcpy(str, "Hello"); //空间不足
}
void test30()
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
void test31()
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
void test32()
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
char * demo33()
{
	//char p[] = "Hello World";//warning: function returns address of local variable [-Wreturn-local-addr]
	char *p = malloc(100);

	printf("%p\n", p);
	p = "hello";
	printf("%p\n", p);
	//以上printf的p的地址不一样

	return p;
}
void test33()
{
	char *p = demo33();
	printf("%s\n", p);
}
char * demo34()
{
	//char p[] = "Hello World";//warning: function returns address of local variable [-Wreturn-local-addr]
	char *p = malloc(100);

	printf("%p\n", p);
	strcpy_s(p, 6, "hello");
	printf("%p\n", p);
	//以上printf的p的地址不一样

	return p;
}
void test34()
{
	char *p = demo34();
	printf("%s\n", p);
}
void demo35(char **p)
{
	*p = (char *)malloc(100);
}
void test35()
{
	char *p = NULL;
	demo35(&p);
	//demo35(p);//error
	strcpy(p, "Hello World");
	printf("p=%s\n", p);
	free(p);
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
}
void test36()
{
	int y = fn(6);
	printf("%d ", y);
	system("pause");
}
void test37()
{
	//char s1[5];
	//s1 = "abcd"; //编译失败
	//printf("%s", s1);

	char *s2 = "abcd";
	printf("%s", s2);
}
void test62()
{
	//:求0-2000内的所有质数
}

int demo38_sum(int a)
{
	auto int c = 0;
	static int b = 3;
	c += 1;
	b += 2;
	return a + b + c;
}

void test38()
{
	int i = 0;
	int a = 2;
	for (i = 0; i < 5; i++)
	{
		printf("%d\n", demo38_sum(a));
	}
}

void test39()
{
	char * src = "Hello,World";
	char * dest = NULL;
	int len = strlen(src)+1;
	dest = (char *)malloc(len);
	char * d = dest;


	char * s = src;
	d++;
	d++ = s--;//d++和s--结果都是常量?


	int i = 0;
	while (len-- != 0)
	{
		printf("%d\n", i);
		
		d[i++] = *s++;
	}
	d[len] = 0;
	printf("[%s]\n", dest);
}

void test40()
{
	int a = 100;
	int *const p = NULL;
	p = &a;
	*p = a;

	int const *p2 = NULL;
	p2 = &a;
	*p2 = a;

	const int *p3 = NULL;
	p3 = &a;
	*p3 = a;

	const int const * p4 = NULL;
	p4 = &a;
	*p4 = a;

}
void main()
{
	char * src = "Hello,World";
	char * dest = NULL;
	int len = strlen(src);
	dest = (char *)malloc(len + 1);

	memcpy(dest, src, len + 1);
	printf("[%s]\n", dest);

	test39();
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