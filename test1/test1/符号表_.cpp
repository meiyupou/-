
//Date��2021/11/20

#include<iostream>
using namespace std;
#define ElemType char

//************************������Ĵ洢�ṹ********************
typedef struct LNode
{
	ElemType data;//����������
	int ID;//���ı��
	struct LNode* next;//����ָ����
}LNode, * LinkList;//LinkListΪָ��ṹ��LNode��ָ������

//***********************������Ļ�����������******************

//������ĳ�ʼ��
void InitList(LinkList& L)
{
	//����һ���յĵ�����
	L = new LNode;
	L->next = NULL;
	L->ID = 0;
}
//������Ĵ���
void CreateList_H(LinkList& L)//ǰ�巨����������
{
	//����һ������Ϊn�ĵ�����L,����λ����
	int n;
	LNode* p;
	cout << "�����봴���ĵ������ȣ�" << endl;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		p = new LNode;
		cout << "���������ĵ�" << i + 1 << "������ֵ" << endl;
		cin >> p->data;
		p->ID = i;
		p->next = L->next;
		L->next = p;
	}
}

void CreateList_R(LinkList& L)//��巨����������
{
	//����һ������Ϊn�ĵ�����L,����λ����
	int n;
	LNode* p, * r;
	r = L;//βָ��rָ��ͷ���
	cout << "�����봴���ĵ������ȣ�" << endl;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		p = new LNode;
		cout << "���������ĵ�" << i + 1 << "������ֵ" << endl;
		cin >> p->data;
		p->ID = i;
		p->next = NULL;
		r->next = p;
		r = p;
	}
}

//������Ĳ���
bool ListInsert(LinkList& L, int i, ElemType e)
{
	//�ڴ�ͷ���ĵ�����L�ĵ�i�����ǰ�����½��
	LinkList p = L;
	LNode* s;
	int j = 0;
	while (p && j < i - 1)//pָ���i-1�����
	{
		p = p->next;
		j++;
	}
	if (!p || i < 1)//i���ڱ�+1��С��1������λ�ò��Ϸ�
	{
		return false;
	}
	s = new LNode;
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}

//�������ɾ��
bool ListDelete(LinkList& L, int i, ElemType& e)
{
	//��������ĵ�i�����ɾ��
	LinkList p = L;
	LNode* q;
	int j = 0;
	while (p->next && j < i - 1)//pָ���i-1�����
	{
		p = p->next;
		j++;
	}
	if (!(p->next) || i < 1)//i���ڱ���С��1��ɾ��λ�ò��Ϸ�
	{
		return false;
	}
	q = p->next;//��ʱ���汻ɾ���ĵ�ַ�Ա��ͷ�
	p->next = q->next;
	e = q->data;//���汻ɾ��������
	delete q;//�ͷű�ɾ���Ŀռ�
	return true;
}

//�������ȡֵ
bool GetElem(LinkList L, int i, ElemType& e)
{
	//��ȡ�������е�i����������
	LinkList p = L;
	int j = 0;
	while (p->next && j < i - 1)//pָ���i-1�����
	{
		p = p->next;
		j++;
	}
	if (!(p->next) || i < 1)//i���ڱ���С��1����i����㲻����
	{
		return false;
	}
	e = p->next->data;//��ȡ��i����������
	return true;
}

//������Ĳ���
bool LocateElem(LinkList L, LNode*& p, ElemType e)
{
	//�ڵ������в��ҵ�һ������Ϊe�Ľ��
	p = L->next;//pָ����Ԫ���
	while (p && p->data != e)
	{
		p = p->next;
	}
	if (p)
	{
		return true;
	}
	return false;
}

//*********************************������Ļ������ܺ���******************************

//1������
void ListInsert(LinkList& L)
{

	ElemType e;
	int i;
	bool flag;
	cout << "������Ҫ��������ݣ�" << endl;
	cin >> e;
	cout << "������Ҫ�����λ�ã�" << endl;
	cin >> i;
	flag = ListInsert(L, i, e);
	if (flag)
		cout << "����ɹ�!" << endl;
	else
		cout << "λ�ò��ԣ�����ʧ�ܣ�" << endl;
}

//2��ɾ��
void ListDelete(LinkList& L)
{
	ElemType e;
	int i;
	bool flag;
	cout << "������Ҫɾ�����ݵ�λ�ã�" << endl;
	cin >> i;
	flag = ListDelete(L, i, e);
	if (flag)
		cout << "ɾ���ɹ���ɾ��������Ϊ��" << e << endl;
	else
		cout << "λ�ò��ԣ�ɾ��ʧ�ܣ�" << endl;
}

//3��ȡֵ
void GetElem(LinkList L)
{
	ElemType e;
	int i;
	bool flag;
	cout << "������Ҫ��ȡ���ݵ�λ�ã�" << endl;
	cin >> i;
	flag = GetElem(L, i, e);
	if (flag)
		cout << "��ȡ������Ϊ��" << e << endl;
	else
		cout << "λ�ò��ԣ���ȡ����ʧ�ܣ�" << endl;
}

//4������
void LocateElem(LinkList L)
{
	ElemType e;
	LNode* p = NULL;
	bool flag;
	cout << "������Ҫ���ҵ����ݣ�" << endl;
	cin >> e;
	flag = LocateElem(L, p, e);
	if (flag)
	{
		cout << "���ҳɹ��������ݵı��Ϊ��" << p->ID << endl;
		cout << "���ҳɹ��������ݵĵ�ַΪ��" << p << endl;
	}
	else
		cout << "����ʧ�ܣ�" << endl;
}

//5���п�
void ListEmpty(LinkList L)
{
	if (L->next)
		cout << "����Ϊ�գ�" << endl;
	else
		cout << "����Ϊ�գ�" << endl;
}

//6����
void ListLength(LinkList L)
{
	LinkList p = L->next;//pָ���һ�����
	int i = 0;
	while (p)//����������ͳ�ƽ����
	{
		i++;
		p = p->next;
	}
	cout << "����ĳ���Ϊ��" << i << endl;
}

//7�����
void ClearList(LinkList& L)
{
	LNode* p, * q;
	p = L->next;
	while (p)//����Ԫ��㿪ʼ������ɾ��
	{
		q = p->next;
		delete p;
		p = q;
	}
	L->next = NULL;//ͷ���ָ�����ÿ�
}

//8������
void DestroyList(LinkList& L)
{
	LNode* p;
	while (L)//��ͷ��㿪ʼ����ɾ��
	{
		p = L;
		L = L->next;
		delete p;
	}
}

//9����ӡ
void PrintList(LinkList L)
{
	LinkList p = L->next;//pָ���һ�����
	int i = 0;
	while (p)//����������
	{
		i++;
		cout << "�����" << i << "������Ϊ��" << p->data << endl;
		p = p->next;
	}
}

//�˵�
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
	cout << "***********************************0���˳�*********************************" << endl;
	cout << "***************************************************************************" << endl;
}

int main()
{
	LinkList L;
	InitList(L);
	int select;
	cout << "���ȴ���������1��ǰ�巨��  2����巨��" << endl;
	cin >> select;
	switch (select)
	{
	case 1://����
		CreateList_H(L);
		system("pause");//�����������
		break;
	case 2://ɾ��
		CreateList_R(L);
		system("pause");
		break;
	default:
		cout << "��������,����ʧ�ܣ�" << endl;
		system("pause");
		break;
	}
	while (1)
	{
		system("CLS");//��������
		menu();
		cout << "������˵���ţ�" << endl;
		cin >> select;
		switch (select)
		{
		case 1://����
			ListInsert(L);
			system("pause");//�����������
			break;
		case 2://ɾ��
			ListDelete(L);
			system("pause");
			break;
		case 3://ȡֵ
			GetElem(L);
			system("pause");
			break;
		case 4://����
			LocateElem(L);
			system("pause");
			break;
		case 5://�ж������Ƿ�Ϊ��
			ListEmpty(L);
			system("pause");
			break;
		case 6://������ĳ���
			ListLength(L);
			system("pause");
			break;
		case 7://���
			ClearList(L);
			system("pause");
			break;
		case 8://����
			DestroyList(L);
			system("pause");
			return 0;
			break;
		case 9://��ӡ
			PrintList(L);
			system("pause");
			break;
		case 0:
			cout << "��ӭ�´�ʹ��!" << endl;//�˳�
			system("pause");
			return 0;
			break;
		default:
			cout << "�˵������������" << endl;
			system("pause");
			break;
		}
	}
	system("pause");
	return 0;
}