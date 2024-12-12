#include "SequentialStack.h"

// 构造函数
stack:: stack() : top(nullptr), bottom(nullptr), stackSize(0)  //若构造函数无内容 则将按照这行初始化  即{this->top = nullptr; this->bottom = nullptr; stackSize = 0;}
{
    this->InitStack();
}
//析构函数
stack::~stack() {
    destroy();
}
//栈的初始化
void stack::InitStack()
{
    this->bottom = new ElemType[100];
    if (!this->bottom)
    {
        std::cout << "存储分配失败" << std::endl;
        return;
    }
    this->top = this->bottom;
    this->stackSize = 100;
    std::cout << "初始化成功" << std::endl;
}

// 检查栈是否为空
bool stack::isEmpty() const 
{
    return this->top == this->bottom; //若栈为空 返回true  否则返回false                                                
}

// 获取栈的长度
int stack::size() const 
{
    return this->top - this->bottom;
}

//清空顺序栈
void stack::clear()
{
    if (this->bottom)
    {
        this->top = this->bottom;
    }
}

//销毁顺序栈
void stack::destroy()
{
    if (this->bottom)
    {
        //delete this->bottom;
        delete[] this->bottom; // 使用 delete[] 释放数组内存
        this->stackSize = 0;
        this->bottom = this->top = nullptr;
    }
}

void stack::resize(int newSize) {
    if (newSize <= stackSize) {
        std::cout << "新容量不能小于当前容量" << std::endl;
        return;
    }
    ElemType* newBottom = new ElemType[newSize];
    if (!newBottom) {
        std::cout << "内存分配失败" << std::endl;
        return;
    }
    int currentSize = this->size();
    for (int i = 0; i < currentSize; ++i) {
        newBottom[i] = this->bottom[i];
    }
    delete[] this->bottom;
    this->bottom = newBottom;
    this->top = this->bottom + currentSize;
    this->stackSize = newSize;
}
// 入栈操作
void stack::push(const ElemType& elem) 
{
    if (this->top - this->bottom == this->stackSize) //判断是否满
    {
        std::cout << "顺序栈已满" << std::endl;
        return;
    }
    else 
    {

        this->top->age = elem.age;
        this->top->name = elem.name;
        this->top++;
    }
}

// 出栈操作
void stack::pop(ElemType& elem)  //若栈不为空，则删除S的栈顶元素，用e返回其值，并返回true 否则返回false
{
    if (this->bottom == this->top)
    {
        std::cout << "顺序栈为空" << std::endl;
        return;
    }
    else
    {
        this->top--;
        elem.age = this->top->age;
        elem.name = this->top->name;
    }
}

//特性	     NULL	                nullptr
//定义	     宏，通常为 0	        类型为 std::nullptr_t
//类型	     整数常量	            专用的指针类型
//类型安全	 否，可能导致错误	        是，明确区分指针和整数
//转换能力	 可隐式转换为任何指针	    可隐式转换为任何指针，但不能转换为整数
//C++11      支持	一直可用	        需要 C++11 或更高版本