#include <iostream>
using namespace std;
#include <string>
//���ݵĶ���
typedef struct
{
	string num;
	char name[8];
	int score;
}ElemType;

//����Ķ���
typedef struct LNode   
{
	ElemType  data;//����������
	//int  data;//����������

	LNode* next;//����ָ����
}LNode, *LinkList;            //���ṹ�����¶���ΪLonde �� *LinkList  ������������



//��ʼ������
bool InitList(LinkList& L)//�������⻰��LinkList &L�ȼ��� Lnode *&L��Lnode *&L��һ��ָ��ָ�������
{
	L = new LNode; //��������һ��ͷ��㣬������������ΪLnode
	//L->next = nullptr;  //�ձ�Ҳ����˵ͷ����ָ��ָ��Ϊ��
	L->next = NULL;
	return true;
}

//�ж������Ƿ�Ϊ��
bool ListEmpty(LinkList L)  
{
	if (L->next)
	{
		return 0;
	}
	else
		return 1;
}

//���ٵ�����
bool DestroyList(LinkList& L)
{
	LNode* p;
	while (L)
	{
		p = L;
		L = L->next;
		delete p;
	}
	return 1;
}

//��յ�����
bool ClearList(LinkList& L)
{
	LNode* p ,*q;
	p = L->next;
	while (p)   //û����β
	{
		q = p->next;
		delete p;
		p = q;
	}
	L->next = NULL; //ͷ���ָ������Ϊ��
	return 1;
}

//������ı�
int LengthList(LinkList L)
{
	int i = 0;
	LNode* p;
	p = L->next;
	while (p)
	{
		i++;
		p = p->next;
	}
	return i;
}

//��ͷ���ĵ����� �ع�
//�������� LinkList L; LNode *p, *s;
// ��Ҫ���� p = L; ָ��ͷ���
//         s = L->next; sָ����Ԫ���
//         p = p->next; pָ����һ���

//ȡֵ ȡ�������еĵ�i��Ԫ��    ���ñȴ�ֵ����
bool GetElem(const LinkList &L, int &i, ElemType &e)//��ȡ���Ա��е�ĳ������Ԫ�ص����� ͨ������e����
{
	LNode* p;
	p = L->next;
	int j = 1;
	while (p&&j<i) //���ɨ�� ֱ��pָ���i��Ԫ�ػ�pΪ��
	{
		p = p->next;
		++j;        //����j++��++jһ��

	}
	if (!p || j>i)
	{
		return 0;   //��i��Ԫ�ز�����
	}
	e = p->data;
	return 1;

}

//�����!=����
bool operator!=(const ElemType &e1, const ElemType &e2)
{
	if (e1.name == e2.name && e1.num == e2.num && e1.score == e2.score)
		return 1;
	else
		return 0;
}

//��ֵ���� ����ָ�����ݻ�ȡ���������ڵ�λ�ã���ַ��   ʱ�临�Ӷ� O(n)
LNode* LocateElem(const LinkList &L, const ElemType &e)//�����Ա�L�в���ֵΪe������Ԫ��  �ҵ����򷵻�L��ֵΪe������Ԫ�صĵ�ַ������ʧ�ܷ���NULL
{
	LNode* p = L->next;
	while (p && p->data != e) //���ɨ�� ֱ��pָ���i��Ԫ�ػ�pΪ��
	{
		p = p->next;
		return p;
	}
}

//����--�ڵ�i�����ǰ����ֵΪe���½��!     ��Ҫ���ң���ʱ�临�Ӷ���O(n)
bool InsertElem(const LinkList& L, const int& i, const ElemType& e)
{
	LNode* p;
	p = L;
	int j;
	j = 0;
	while (p && j < i-1) //���ɨ�� ֱ��pָ���i-1��Ԫ�ػ�pΪ��
	{
		p = p->next;              //Ѱ�ҵ�i-1����㣬pָ��i-1���
		++j;        //����j++��++jһ��
	}
	if (!p || j > i-1)
	{
		return 0;   //��i��Ԫ�ز�����
	}
	//LinkList s = new LNode;
	LNode *s = new LNode;  //����һ���µĽ��ռ�
	s->data = e;           //�����½��s�������s����������Ϊe
	s->next = p->next;     //�����s����L��
	p->next = s;
	return 1;
}

//ɾ��--ɾ����i�����!        ��Ҫ���ң���ʱ�临�Ӷ���O(n)
bool InsertElem(const LinkList& L, const int& i, ElemType& e)
{
	LNode* p;
	p = L;
	int j;
	j = 0;
	while (p && j < i - 1) //���ɨ�� ֱ��pָ���i-1��Ԫ�ػ�pΪ��
	{
		p = p->next;              //Ѱ�ҵ�i-1����㣬pָ��i-1���
		++j;        //����j++��++jһ��
	}
	if (!p || j > i - 1)
	{
		return 0;   //��i��Ԫ�ز�����
	}
	LNode* q = p->next;          //��ʱ���汻ɾ���ĵ�ַ�ѱ��ͷ�
	p->next = p->next->next;     //�ı�ɾ�����ǰ������ָ����
	//p->next = q->next;     //�ı�ɾ�����ǰ������ָ����   ��������
	e = q->data; //����ɾ����������
	delete q;
	return 1;
}


//ͷ�巨������������   ���������ͷ�� ʱ�� ���Ӷ���O(n)
void CreatListHead(LinkList& L, const int & n)
{
	L = new LNode;
	L->next = NULL;         //�Ƚ���һ������ͷ���ĵ�����
	//for (int i = 0; i < n; ++i)

	for (int i = n; i > 0; --i)
	{
		LNode* p = new LNode;  // C����д�� p = (LinkList)malloc(sizeof(LNode))
		cin >> p->data.num;
		cin >> p->data.name;
		cin >> p->data.score;
		//cin >> p->data;
		p->next = L->next; //���뵽��ͷ
		L->next = p;
	}
}

 //β�巨--Ԫ�ز���������β��  ��λ�����n��Ԫ�ص�ֵ    ʱ�临�Ӷ�O(n)
void CreatListEnd(LinkList& L, const int& n)
{
	L = new LNode;
	L->next = NULL;         //�Ƚ���һ������ͷ���ĵ�����
	LNode* r = L;           //βָ��rָ��ͷ���
	for (int i = 0; i < n; i++)
	{
		LNode* p = new LNode;  // C����д�� p = (LinkList)malloc(sizeof(LNode))
		cin >> p->data.num;
		cin >> p->data.name;
		cin >> p->data.score;
		//cin >> p->data;
		p->next = NULL;
		r->next = p;         //���뵽��β
		r = p;               //rָ���µ�β���
	}
}

//���Ա�ĺϲ�
void unionLinkList(LinkList& La, const LinkList& Lb)
{
	int La_len = LengthList(La);
	int Lb_len = LengthList(Lb);
	for (int i = 1; i <= Lb_len; i++)
	{
		ElemType e;
		GetElem(Lb, i, e);
		if (!LocateElem(La, e))
		{
			InsertElem(La, ++La_len, e);
		}

	}
}


void DeleteList(LinkList& L) {
	LNode* p = L;
	while (p) {
		LNode* temp = p;
		p = p->next;
		delete temp;
	}
	L = nullptr;
}



void test01()
{
	LinkList pp;

	InitList(pp);
	CreatListHead(pp, 5);
	ElemType E;
	int i = 1;
	GetElem(pp, i, E);
	cout << E.name << " " << E.num << " " << E.score;
	DeleteList(pp);
}

int main()
{
	test01();
	system("pause");
	system("cls");
	return 0;

}