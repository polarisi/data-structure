#pragma once
#include <iostream>
#include "ElemType.h"


class stack
{
private:
	ElemType* top;
	ElemType* bottom;
	int stackSize;


	//��������ջ��
	void resize(int newSize);
public:
	//���캯��
	stack();
	//��������
	~stack();
	//ջ�ĳ�ʼ��
	void InitStack();

	//ջ�Ƿ�Ϊ��
	bool isEmpty() const;
	//��ȡջ�ĳ���
	int size() const;
	//���˳��ջ
	void clear();
	//����˳��ջ
	void destroy();

	// ��ջ����
	void push(const ElemType& elem);
	// ��ջ����
	void pop(ElemType& elem);

};