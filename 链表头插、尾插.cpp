#include<iostream>
using namespace std;
struct node* head; //全局变量
struct node* tail;
struct node
{
	int data;
	struct node* link;//node *link (c++)
};
void Insert_H(int x) 
{
	struct node* temp = new node;//在堆里开辟一个node结构体的空间，temp指向node的地址；
	(*temp).data = x;//temp->data =x ;(c++);
	(*temp).link = head;
	head = temp;
}
void Insert_T(int x)
{
	struct node* temp = new node;
	temp->data = x;
	temp->link = NULL;
	if (tail == NULL)
	{
		head = temp;
		tail = temp;
		return;
	}
	tail->link = temp;
	tail = temp;
}
void  Print()
{
	struct node* temp;
	temp = head;
	cout << "链表为：";
	while (temp != NULL)
	{
		cout <<(*temp).data<<" ";
		temp = (*temp).link;
	}
	cout << endl;
}
void insert(int data, int n)
{
	struct node* temp = new node;
	temp->data = data;
	temp->link = NULL;
	if (n == 1)
	{
		temp->link = head;
		head = temp;
		return;
	}
	struct node* temp2 = head;
	for (int i = 0; i < n - 2; i++)
	{
		temp2 = temp2->link;
	}
	temp->link = temp2->link;
	temp2->link = temp;
}
void Delete(int n)//删除指定位置的数据
{
	struct node* temp1 = head;
	if (n == 1)
	{
		head = temp1->link;
		delete(temp1);
		return;
	}
	for (int i = 0; i < n - 2; i++)//temp1指向n-1结点
	{
		temp1 = temp1->link;
	}
	struct node* temp2 = temp1->link;
	temp1->link = temp2->link;
	delete(temp2);
}
void DeleteAllValue(int record)//删除所有指定值
{
	struct node* temp1 = head;
	int i = 1;
	int sign = 1;//进行标记
	while (temp1->link != NULL)//存在缺陷，无法对最后一个n结点进行检验
	{
		if (temp1->data == record)
		{	
			sign = 0;
			temp1 = temp1->link;
			Delete(i);
			continue;//continue删除所有record值，break删除第一个record值
		}
		temp1 = temp1->link;
		i++;
	}
	if (temp1->data == record)//对最后一个结点n进行检验
	{
			Delete(i);
	}
}
void DeleteFirstValue(int record)//删除第一个指定值
{
	struct node* temp1 = head;
	int i = 1;
	int sign = 1;//进行标记
	while (temp1->link != NULL)//存在缺陷，无法对最后一个n结点进行检验
	{
		if (temp1->data == record)
		{
			sign = 0;
			temp1 = temp1->link;
			Delete(i);
			break;//continue删除所有record值，break删除第一个record值
		}
		temp1 = temp1->link;
		i++;
	}
	if (temp1->data == record)
	{
		if (sign == 1)
		{
			Delete(i);
		}
	}
}
void menu()
{
	cout << "***************************************************************************" << endl;
	cout << "***********************************1、插入*********************************" << endl;
	cout << "***********************************2、删除*********************************" << endl;
	cout << "***********************************3、取值*********************************" << endl;
	cout << "***********************************4、查找*********************************" << endl;
	cout << "***********************************5、判空*********************************" << endl;
	cout << "***********************************6、求长*********************************" << endl;
	cout << "***********************************7、清空*********************************" << endl;
	cout << "***********************************8、销毁*********************************" << endl;
	cout << "***********************************9、打印*********************************" << endl;
	cout << "***********************************10、删除所有指定值**********************" << endl;
	cout << "***********************************11、删除第一个指定值********************" << endl;
	cout << "***********************************0、退出*********************************" << endl;
	cout << "***************************************************************************" << endl;
}
int main()
{
	head = NULL;
	tail = NULL;
	tail = head;
	int n;
	int select;
	int x;
	cout << "请先创建单链表：1、前插法 ！2、尾插法 !"<<endl;
	cin >> select;
	switch(select)
	{
		case(1):
			cout << "创建链表的长度为:";
			cin >> n;
			cout << "*****************头插法*****************" << endl;
			for (int i = 0; i < n; i++)
			{
				cout << "链表里第" << i + 1 << "个值为：";
				cin >> x;
				Insert_H(x);
				Print();
				cout << "*****************" << endl;
			}
			break;
		case(2):
			cout << "创建链表的长度为:";
			cin >> n;
			cout << "*****************尾插法*****************" << endl;
			for (int i = 0; i < n; i++)
			{
				cout << "链表里第" << i + 1 << "个值为：";
				cin >> x;
				Insert_T(x);
				Print();
				cout << "*****************" << endl;
			}
			break;
	}
	while (1)
	{
		menu();
		cout << "请输入菜单号： ";
		cin >> select;
		switch (select)
		{
			case(1):
				int data;
				int loaction;
				cout << "插入的位置为：";
				cin >> loaction;
				cout << "插入的值为：";
				cin >> data;
				insert(data, loaction);
				break;
			case(2):
				cout << "输入要删除数据的位置：";
				cin >> n;
				Delete(n);
				break;
			case(9):
				Print();
				break;
			case(10):
				cout << "删除的值为：";
				cin >> data;
				DeleteAllValue(data);
				break;
			case(11):
				cout << "删除的值为：";
				cin >> data;
				DeleteFirstValue(data);
				break;
		}

	}
}