#include <iostream>
using namespace std;
#include <string>
//数据的定义
typedef struct
{
	string num;
	char name[8];
	int score;
}ElemType;

//链表的定义
typedef struct LNode   
{
	ElemType  data;//结点的数据域
	//int  data;//结点的数据域

	LNode* next;//结点的指针域
}LNode, *LinkList;            //将结构体重新定义为Londe 和 *LinkList  两个都可以用



//初始化链表
bool InitList(LinkList& L)//插入题外话：LinkList &L等价于 Lnode *&L，Lnode *&L是一个指向指针的引用
{
	L = new LNode; //堆区开辟一个头结点，结点的数据类型为Lnode
	//L->next = nullptr;  //空表，也就是说头结点的指针指向为空
	L->next = NULL;
	return true;
}

//判断链表是否为空
bool ListEmpty(LinkList L)  
{
	if (L->next)
	{
		return 0;
	}
	else
		return 1;
}

//销毁单链表
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

//清空单链表
bool ClearList(LinkList& L)
{
	LNode* p ,*q;
	p = L->next;
	while (p)   //没到表尾
	{
		q = p->next;
		delete p;
		p = q;
	}
	L->next = NULL; //头结点指针域置为空
	return 1;
}

//求链表的表长
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

//带头结点的单链表 回顾
//变量定义 LinkList L; LNode *p, *s;
// 重要操作 p = L; 指向头结点
//         s = L->next; s指向首元结点
//         p = p->next; p指向下一结点

//取值 取单链表中的第i个元素    引用比传值更好
bool GetElem(const LinkList &L, int &i, ElemType &e)//获取线性表中的某个数据元素的内容 通过变量e返回
{
	LNode* p;
	p = L->next;
	int j = 1;
	while (p&&j<i) //向后扫描 直到p指向第i个元素或p为空
	{
		p = p->next;
		++j;        //这里j++和++j一样

	}
	if (!p || j>i)
	{
		return 0;   //第i个元素不存在
	}
	e = p->data;
	return 1;

}

//运算符!=重载
bool operator!=(const ElemType &e1, const ElemType &e2)
{
	if (e1.name == e2.name && e1.num == e2.num && e1.score == e2.score)
		return 1;
	else
		return 0;
}

//按值查找 根据指定数据获取该数据所在的位置（地址）   时间复杂度 O(n)
LNode* LocateElem(const LinkList &L, const ElemType &e)//在线性表L中查找值为e的数据元素  找到，则返回L中值为e的数据元素的地址，查找失败返回NULL
{
	LNode* p = L->next;
	while (p && p->data != e) //向后扫描 直到p指向第i个元素或p为空
	{
		p = p->next;
		return p;
	}
}

//插入--在第i个结点前插入值为e的新结点!     需要查找，的时间复杂度是O(n)
bool InsertElem(const LinkList& L, const int& i, const ElemType& e)
{
	LNode* p;
	p = L;
	int j;
	j = 0;
	while (p && j < i-1) //向后扫描 直到p指向第i-1个元素或p为空
	{
		p = p->next;              //寻找第i-1个结点，p指向i-1结点
		++j;        //这里j++和++j一样
	}
	if (!p || j > i-1)
	{
		return 0;   //第i个元素不存在
	}
	//LinkList s = new LNode;
	LNode *s = new LNode;  //定义一个新的结点空间
	s->data = e;           //生成新结点s，将结点s的数据域置为e
	s->next = p->next;     //将结点s插入L中
	p->next = s;
	return 1;
}

//删除--删除第i个结点!        需要查找，的时间复杂度是O(n)
bool InsertElem(const LinkList& L, const int& i, ElemType& e)
{
	LNode* p;
	p = L;
	int j;
	j = 0;
	while (p && j < i - 1) //向后扫描 直到p指向第i-1个元素或p为空
	{
		p = p->next;              //寻找第i-1个结点，p指向i-1结点
		++j;        //这里j++和++j一样
	}
	if (!p || j > i - 1)
	{
		return 0;   //第i个元素不存在
	}
	LNode* q = p->next;          //临时保存被删结点的地址已备释放
	p->next = p->next->next;     //改变删除结点前驱结点的指针域
	//p->next = q->next;     //改变删除结点前驱结点的指针域   两个都可
	e = q->data; //保存删除结点的数据
	delete q;
	return 1;
}


//头插法创建单向链表   插在链表的头部 时间 复杂度是O(n)
void CreatListHead(LinkList& L, const int & n)
{
	L = new LNode;
	L->next = NULL;         //先建立一个带有头结点的单链表
	//for (int i = 0; i < n; ++i)

	for (int i = n; i > 0; --i)
	{
		LNode* p = new LNode;  // C语言写法 p = (LinkList)malloc(sizeof(LNode))
		cin >> p->data.num;
		cin >> p->data.name;
		cin >> p->data.score;
		//cin >> p->data;
		p->next = L->next; //插入到表头
		L->next = p;
	}
}

 //尾插法--元素插入在链表尾部  正位序插入n个元素的值    时间复杂度O(n)
void CreatListEnd(LinkList& L, const int& n)
{
	L = new LNode;
	L->next = NULL;         //先建立一个带有头结点的单链表
	LNode* r = L;           //尾指针r指向头结点
	for (int i = 0; i < n; i++)
	{
		LNode* p = new LNode;  // C语言写法 p = (LinkList)malloc(sizeof(LNode))
		cin >> p->data.num;
		cin >> p->data.name;
		cin >> p->data.score;
		//cin >> p->data;
		p->next = NULL;
		r->next = p;         //插入到表尾
		r = p;               //r指向新的尾结点
	}
}

//线性表的合并
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