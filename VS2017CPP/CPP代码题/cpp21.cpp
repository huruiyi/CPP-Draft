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
	（1）将ia复制到一个vector容器vec中和一个list容器中lst中。
	（2）将vec容器中的奇数值元素删除。
	（3）使用内置算法(accumulate)计算vec窗器所有元素的和。
	（4）使用内置算法(count_if)计算lst容器中大于5的元素的个数。
	 */

	vector<int> vec;
	int len = sizeof(ia) / sizeof(ia[0]);
	cout << " （1）将ia复制到一个vector容器vec中和一个list容器中lst中。" << endl;
	for (int i = 0; i < len; i++)
	{
		vec.push_back(ia[i]);
	}
	//list<int> lst;
	//for (int i = 0; i < len; i++)
	//{
	//    lst.push_back(ia[i]);
	//}
	//cout << "将vec容器中的奇数值元素删除。" << endl;
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
	//cout << "（3）使用内置算法(accumulate)计算vec窗器所有元素的和。" << endl;
	//int sum = accumulate(vec.begin(), vec.end(), 0);
	//cout << sum << endl;

	//cout << "（4）使用内置算法(count_if)计算lst容器中大于5的元素的个数。" << endl;

	//int count = count_if(lst.begin(), lst.end(), [](int val) {return val > 5; });
	//cout << "大于5的元素个数:" << count << endl;
	system("pause");
	return 0;
}