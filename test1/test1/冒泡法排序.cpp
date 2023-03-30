#include<iostream>
#include<cmath>
using namespace std;
int upcompare (int* a, int *b) //比较函数（升序排列）
{
	if (*a >* b)
		return 1;
	else
		return 0;
}
int downcompare(int* a, int* b)//比较函数（降序排列）
{
	if (*a < *b)
		return 1;
	else
		return 0;
}
int abscompare(int* a, int* b)//比较函数)(绝对值排序)
{
	if(abs(*a)>abs(*b))
		return 1;
	else
		return 0;
}
void bubblesort(int* a,int n ,int (*compare)(int*,int*) ) //函数指针
{
	int swap;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (compare(a+j,a+j+1) >0)
			{
				swap = *(a + j);
				*(a + j) = *(a + j + 1);
				*(a + j + 1) = swap;
			}
		}
	}
}
int main()
{
	int a[] = { -1,3,-4,-5,6,2};
	bubblesort(a, 6,&upcompare);
	for (int i = 0; i < 6; i++)
		cout  <<" " <<* (a + i);
	cout << endl;
	bubblesort(a, 6, downcompare);
	for (int i = 0; i < 6; i++)
		cout << " " << *(a + i);
	cout << endl;
	bubblesort(a, 6, &abscompare);
	for (int i = 0; i < 6; i++)
		cout << " " << *(a + i);
	cout << endl;
	return 0;

;}