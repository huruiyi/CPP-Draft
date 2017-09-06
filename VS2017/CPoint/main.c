#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include<string.h>
#include<Windows.h>
#include<process.h>
#include<rdpencomapi.h>
#include<rdpappcontainerclient.h>
#include<winsock.h>

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

typedef struct _str_type
{
	int _len;
	char _s[1];
}str_type;

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
typedef void(*MYPROC)(LPTSTR);

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
	//:求0-2000内的所有质数
}
void main()
{
	test20();
	system("pause");
	return 0;
}