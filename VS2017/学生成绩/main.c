#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

typedef struct _tag_Student {
	char name[24];
	int age;
}Student;
typedef struct _listNode {
	Student *stu;
	struct _listNode *next;
}ListNode;
int getStudentInfo(char *studentInfo, Student *stu)
{
	sscanf(studentInfo, "name=%s  age = %d \n", &stu->name, &stu->age);
	if (stu&&stu->name != " "&&stu->age > 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

void BubbleSort(Student *arr, int length)
{
	int flag = 0;
	for (int i = 0; i < length - 1; i++)
	{
		for (int j = 0; j < length - 1 - i; j++)
		{
			if (arr[j].age < arr[j + 1].age)
			{
				flag = 1;
				Student temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
		if (!flag)
		{
			return;
		}
		flag = 0;
	}
}

void main()
{
	Student stus[6] = { 0 };

	FILE * fp = fopen("student.txt", "r");

	char buf[100] = { 0 };
	int index = 0;
	while (!feof(fp))
	{
		Student   stu = { 0 };
		memset(buf, 0, sizeof(buf));
		fgets(buf, sizeof(buf), fp);
		int result = getStudentInfo(buf, &stu);
		if (!result)
		{
			printf("name=%s  age=%d\n", stu.name, stu.age);
			stus[index] = stu;
		}
		index++;
	}

	BubbleSort(stus, 6);

	fclose(fp);

	FILE * fp2 = fopen("student2.txt", "w");
	if (fp2)
	{
		for (int i = 0; i < 6; i++)
		{
			fprintf(fp2, "name=%s age=%d\n", stus[i].name, stus[i].age);
		}
		fclose(fp2);
	}

	system("pause");
}

/*
name=suyu age=20
name= haha  age=23
name= lili age= 22
name= xixi age=27
name=lucy age =18
name=lala age =33
......

������ļ��е���Ϣ��������ÿ�е����ݰ�age�Ӵ�С��˳��д��һ���ļ�student2.txt�С�
��ʾ��
(1) ÿ�е�ѧ����Ϣ����һ���ṹ����б��档
typedef struct _tag_Student {
char name[24];
int age;
}Student;
(2) ��ȡ���ļ��ж�ȡ��ÿһ��ѧ������Ϣ��
����ԭ�ͣ�int getStudentInfo(char *studentInfo, Student *stu);
�������ܣ���studentInfo��ָ����ַ�������ȡ��ѧ�����������䣬�����浽һ���ṹ������С�
����������studentInfo��ָ�����ѧ��name��age��һ���ַ�����
stu��ָ�����ڱ���ѧ����Ϣ�Ľṹ�塣
����ֵ���ɹ�����0��ʧ�ܷ���-1��
(3) ��õ�ÿ��ѧ������Ϣ����������б��档
typedef struct _listNode {
Student *stu;
struct _listNode *next;
}ListNode;
**/