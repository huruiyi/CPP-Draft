#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
#include <vector>
#include <list>
#include <numeric>
#include <algorithm>

using namespace std;

int main()
{
	int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 99 };
	/*
	��1����ia���Ƶ�һ��vector����vec�к�һ��list������lst�С�
	��2����vec�����е�����ֵԪ��ɾ����
	��3��ʹ�������㷨(accumulate)����vec��������Ԫ�صĺ͡�
	��4��ʹ�������㷨(count_if)����lst�����д���5��Ԫ�صĸ�����
	 */

	vector<int> vec;
	int len = sizeof(ia) / sizeof(ia[0]);
	cout << " ��1����ia���Ƶ�һ��vector����vec�к�һ��list������lst�С�" << endl;
	for (int i = 0; i < len; i++)
	{
		vec.push_back(ia[i]);
	}
	//list<int> lst;
	//for (int i = 0; i < len; i++)
	//{
	//    lst.push_back(ia[i]);
	//}
	//cout << "��vec�����е�����ֵԪ��ɾ����" << endl;
	int vecSize = vec.size();

	vector<int>::iterator itr = vec.begin();

	for (vector<int>::iterator itr = vec.begin(); itr != vec.end(); itr++)
	{
		cout << "before----------" << *itr << endl;
	}
	for (int i = vecSize - 1; i >= 0; i--)
	{
		if (*(itr + i) % 2 == 1)
		{
			cout << "delete---------" << *(itr + i) << endl;
			vec.erase(itr + i);
		}
	}

	for (vector<int>::iterator itr = vec.begin(); itr != vec.end(); itr++)
	{
		cout << "after" << *itr << endl;
	}
	//cout << "��3��ʹ�������㷨(accumulate)����vec��������Ԫ�صĺ͡�" << endl;
	//int sum = accumulate(vec.begin(), vec.end(), 0);
	//cout << sum << endl;

	//cout << "��4��ʹ�������㷨(count_if)����lst�����д���5��Ԫ�صĸ�����" << endl;

	//int count = count_if(lst.begin(), lst.end(), [](int val) {return val > 5; });
	//cout << "����5��Ԫ�ظ���:" << count << endl;
	system("pause");
	return 0;
}