#include "LinkedStack.h"
//���캯��
LinkedStack::LinkedStack() : S(nullptr) {} //��ʼ��
//��������
LinkedStack::~LinkedStack() 
{
	while (!IsEmpty()) 
	{
		pop();
	}
}

//�ж��Ƿ�Ϊ��
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


// ��ջ����
void LinkedStack::push(const ElemType &value) 
{
	Node* newNode = new Node(value); // �����½ڵ�  
	newNode->next = S;            // �½ڵ�� next ָ��ǰջ��
	S = newNode;                  // ����ջ��ָ��
}

// ��ջ����
void LinkedStack::pop() 
{
	if (IsEmpty()) 
	{
		throw std::runtime_error("Stack is empty. Cannot pop.");
	}

	Node* temp = S;   // ��ʱ����ջ���ڵ�
	S = S->next;      // ����ջ��ָ��
	delete temp;      // �ͷ�ջ���ڵ�
}

// ��ȡջ��Ԫ��
ElemType LinkedStack::peek()  
{
	if (IsEmpty()) 
	{
		throw std::runtime_error("Stack is empty. No top element.");
	}
	return S->data;
}
// ��ӡջ�е�����Ԫ�أ���ջ����ջ�ף�
void LinkedStack::printStack() const {
	Node* current = S;
	std::cout << "Stack elements: ";
	while (current) {
		std::cout << current->data.age << " " << current->data.name << std::endl;
		current = current->next;
	}

}