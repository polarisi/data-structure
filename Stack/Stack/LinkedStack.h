#pragma once
#include <iostream>
#include "ElemType.h"

class LinkedStack
{
private:
    // ��������ڵ�ṹ
    typedef struct Node
    {
        ElemType data;   // �ڵ�����
        Node* next; // ָ����һ���ڵ��ָ��

        Node(ElemType value) : data(value), next(nullptr) {} // �ڵ㹹�캯��
    }Node, * LinkStack;  //�������������������

    LinkStack S;  //����  ջ��ָ��

    //Node* top; // ջ��ָ�� �ȼ��� LinkStack top;

public:
    // ���캯��
    LinkedStack(); //��ʼ��  ����һ����ջ ջ��ָ����Ϊ��

    // �����������ͷ������ڴ�
    ~LinkedStack();

    //�ж��Ƿ�Ϊ��
    bool IsEmpty();
    // ��ջ����
    void push(const ElemType &value);
    // ��ջ����
    void pop();
    //��ȡջ��Ԫ��
    ElemType peek();
    // ��ӡջ�е�����Ԫ�أ���ջ����ջ�ף�
    void printStack() const;
};

