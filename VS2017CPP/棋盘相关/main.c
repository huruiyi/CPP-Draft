#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

/*
1)  传入一个n 在堆空间中产生n*n方格的棋盘
int ** createBoard(int n);
int   createBoard1(int ***p,int n);
2)  N颗棋子随机落在棋盘上<需要防止落在同一位置>
int  initBoard(int **p,int n);
3)  打印棋盘
int  printBoard(int **p,int n);
如果有两颗棋子落同一行或者同一列 输出好棋
否则 输出 不是好棋
将棋局中的棋子打印出来 空位用O
有旗子的用X表示
4)  销毁棋盘
int  destroyBoard(int **p,int n);
int  destroyBoard1(int ***p,int n);
*/

int ** createBoard(int n)
{
	int **p = (int **)malloc(sizeof(int *)*n*n);
	return p;
}

//下满旗子
void  fillborad(int **p, int n)
{
	for (int i = 0; i < n*n; i++)
	{
		*(*p + i) = 123;
	}
}

int  initBoard(int **p, int n)
{
	for (int i = 0; i < 100; i++)
	{
		//大于零，说明此处已下棋子
		if (*(p + n) > 0)
		{
			return 0;
		}
	}

	*(*p + n) = 123;
	return 1;
}

int  printBoard(int **p, int n)
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			int step = (i) * 10 + j;
			if (*(p + step) > 0)
			{
				printf("X \t");
			}
			else
			{
				printf("O \t");
			}
		}
		printf("\n\n\n");
	}
	return 0;
}

int  destroyBoard1(int **p, int n)
{
	if (p)
	{
		free(p);
		p = NULL;
	}
	return 1;
}

void main()
{
	int n = 10;
	int ** p = createBoard(n);
	memset(p, 0, n * n * sizeof(int));

	fillborad(p, n);

	*(*p + 99) = 5;
	int r = initBoard(p, 99);
	if (r)
	{
		printf("success");
	}
	else
	{
		printf("fail");
	}
	printf("\n");
	printBoard(p, 1);

	destroyBoard1(p, 10);
	system("pause");
}