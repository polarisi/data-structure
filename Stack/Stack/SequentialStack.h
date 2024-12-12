#pragma once
#include <iostream>
#include "ElemType.h"


class stack
{
private:
	ElemType* top;
	ElemType* bottom;
	int stackSize;


	//重新设置栈长
	void resize(int newSize);
public:
	//构造函数
	stack();
	//析构函数
	~stack();
	//栈的初始化
	void InitStack();

	//栈是否为空
	bool isEmpty() const;
	//获取栈的长度
	int size() const;
	//清空顺序栈
	void clear();
	//销毁顺序栈
	void destroy();

	// 入栈操作
	void push(const ElemType& elem);
	// 出栈操作
	void pop(ElemType& elem);

};