#pragma once
#include <iostream>
#include "ElemType.h"

class LinkedStack
{
private:
    // 定义链表节点结构
    typedef struct Node
    {
        ElemType data;   // 节点数据
        Node* next; // 指向下一个节点的指针

        Node(ElemType value) : data(value), next(nullptr) {} // 节点构造函数
    }Node, * LinkStack;  //两个都是新起的类型名

    LinkStack S;  //定义  栈顶指针

    //Node* top; // 栈顶指针 等价于 LinkStack top;

public:
    // 构造函数
    LinkedStack(); //初始化  构造一个空栈 栈顶指针置为空

    // 析构函数，释放链表内存
    ~LinkedStack();

    //判断是否为空
    bool IsEmpty();
    // 入栈操作
    void push(const ElemType &value);
    // 出栈操作
    void pop();
    //获取栈顶元素
    ElemType peek();
    // 打印栈中的所有元素（从栈顶到栈底）
    void printStack() const;
};

