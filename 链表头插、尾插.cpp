#include<iostream>
using namespace std;
struct node* head; //ȫ�ֱ���
struct node* tail;
struct node
{
	int data;
	struct node* link;//node *link (c++)
};
void Insert_H(int x) 
{
	struct node* temp = new node;//�ڶ��￪��һ��node�ṹ��Ŀռ䣬tempָ��node�ĵ�ַ��
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
	cout << "����Ϊ��";
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
void Delete(int n)//ɾ��ָ��λ�õ�����
{
	struct node* temp1 = head;
	if (n == 1)
	{
		head = temp1->link;
		delete(temp1);
		return;
	}
	for (int i = 0; i < n - 2; i++)//temp1ָ��n-1���
	{
		temp1 = temp1->link;
	}
	struct node* temp2 = temp1->link;
	temp1->link = temp2->link;
	delete(temp2);
}
void DeleteAllValue(int record)//ɾ������ָ��ֵ
{
	struct node* temp1 = head;
	int i = 1;
	int sign = 1;//���б��
	while (temp1->link != NULL)//����ȱ�ݣ��޷������һ��n�����м���
	{
		if (temp1->data == record)
		{	
			sign = 0;
			temp1 = temp1->link;
			Delete(i);
			continue;//continueɾ������recordֵ��breakɾ����һ��recordֵ
		}
		temp1 = temp1->link;
		i++;
	}
	if (temp1->data == record)//�����һ�����n���м���
	{
			Delete(i);
	}
}
void DeleteFirstValue(int record)//ɾ����һ��ָ��ֵ
{
	struct node* temp1 = head;
	int i = 1;
	int sign = 1;//���б��
	while (temp1->link != NULL)//����ȱ�ݣ��޷������һ��n�����м���
	{
		if (temp1->data == record)
		{
			sign = 0;
			temp1 = temp1->link;
			Delete(i);
			break;//continueɾ������recordֵ��breakɾ����һ��recordֵ
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
	cout << "***********************************1������*********************************" << endl;
	cout << "***********************************2��ɾ��*********************************" << endl;
	cout << "***********************************3��ȡֵ*********************************" << endl;
	cout << "***********************************4������*********************************" << endl;
	cout << "***********************************5���п�*********************************" << endl;
	cout << "***********************************6����*********************************" << endl;
	cout << "***********************************7�����*********************************" << endl;
	cout << "***********************************8������*********************************" << endl;
	cout << "***********************************9����ӡ*********************************" << endl;
	cout << "***********************************10��ɾ������ָ��ֵ**********************" << endl;
	cout << "***********************************11��ɾ����һ��ָ��ֵ********************" << endl;
	cout << "***********************************0���˳�*********************************" << endl;
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
	cout << "���ȴ���������1��ǰ�巨 ��2��β�巨 !"<<endl;
	cin >> select;
	switch(select)
	{
		case(1):
			cout << "��������ĳ���Ϊ:";
			cin >> n;
			cout << "*****************ͷ�巨*****************" << endl;
			for (int i = 0; i < n; i++)
			{
				cout << "�������" << i + 1 << "��ֵΪ��";
				cin >> x;
				Insert_H(x);
				Print();
				cout << "*****************" << endl;
			}
			break;
		case(2):
			cout << "��������ĳ���Ϊ:";
			cin >> n;
			cout << "*****************β�巨*****************" << endl;
			for (int i = 0; i < n; i++)
			{
				cout << "�������" << i + 1 << "��ֵΪ��";
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
		cout << "������˵��ţ� ";
		cin >> select;
		switch (select)
		{
			case(1):
				int data;
				int loaction;
				cout << "�����λ��Ϊ��";
				cin >> loaction;
				cout << "�����ֵΪ��";
				cin >> data;
				insert(data, loaction);
				break;
			case(2):
				cout << "����Ҫɾ�����ݵ�λ�ã�";
				cin >> n;
				Delete(n);
				break;
			case(9):
				Print();
				break;
			case(10):
				cout << "ɾ����ֵΪ��";
				cin >> data;
				DeleteAllValue(data);
				break;
			case(11):
				cout << "ɾ����ֵΪ��";
				cin >> data;
				DeleteFirstValue(data);
				break;
		}

	}
}