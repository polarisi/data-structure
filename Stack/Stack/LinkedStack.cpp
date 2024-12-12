#include "LinkedStack.h"
//构造函数
LinkedStack::LinkedStack() : S(nullptr) {} //初始化
//析构函数
LinkedStack::~LinkedStack() 
{
	while (!IsEmpty()) 
	{
		pop();
	}
}

//判断是否为空
bool LinkedStack::IsEmpty()
{
	if (S == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}


// 入栈操作
void LinkedStack::push(const ElemType &value) 
{
	Node* newNode = new Node(value); // 创建新节点  
	newNode->next = S;            // 新节点的 next 指向当前栈顶
	S = newNode;                  // 更新栈顶指针
}

// 出栈操作
void LinkedStack::pop() 
{
	if (IsEmpty()) 
	{
		throw std::runtime_error("Stack is empty. Cannot pop.");
	}

	Node* temp = S;   // 临时保存栈顶节点
	S = S->next;      // 更新栈顶指针
	delete temp;      // 释放栈顶节点
}

// 获取栈顶元素
ElemType LinkedStack::peek()  
{
	if (IsEmpty()) 
	{
		throw std::runtime_error("Stack is empty. No top element.");
	}
	return S->data;
}
// 打印栈中的所有元素（从栈顶到栈底）
void LinkedStack::printStack() const {
	Node* current = S;
	std::cout << "Stack elements: ";
	while (current) {
		std::cout << current->data.age << " " << current->data.name << std::endl;
		current = current->next;
	}

}