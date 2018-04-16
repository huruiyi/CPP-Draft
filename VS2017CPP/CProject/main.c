#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

void ºº×Ö×ÖÄ¸()
{
	char ch[3] = "ÖÐ";
	printf("%c%c\n", ch[0], ch[1]);
	printf("%d-%d\n", ch[0], ch[1]);
	printf("%d\n", strlen(ch));

	char b[3] = "a";
	printf("%c \n", b[0]);
	printf("%d \n", b[0]);
	printf("%d\n", strlen(b));
	getchar();
}
int main()
{
	int a = 10;
	printf("%d---%d---%d---%d", a++, ++a, a++, ++a);
	system("pause");
	return 0;
}