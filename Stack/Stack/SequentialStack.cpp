#include "SequentialStack.h"

// ���캯��
stack:: stack() : top(nullptr), bottom(nullptr), stackSize(0)  //�����캯�������� �򽫰������г�ʼ��  ��{this->top = nullptr; this->bottom = nullptr; stackSize = 0;}
{
    this->InitStack();
}
//��������
stack::~stack() {
    destroy();
}
//ջ�ĳ�ʼ��
void stack::InitStack()
{
    this->bottom = new ElemType[100];
    if (!this->bottom)
    {
        std::cout << "�洢����ʧ��" << std::endl;
        return;
    }
    this->top = this->bottom;
    this->stackSize = 100;
    std::cout << "��ʼ���ɹ�" << std::endl;
}

// ���ջ�Ƿ�Ϊ��
bool stack::isEmpty() const 
{
    return this->top == this->bottom; //��ջΪ�� ����true  ���򷵻�false                                                
}

// ��ȡջ�ĳ���
int stack::size() const 
{
    return this->top - this->bottom;
}

//���˳��ջ
void stack::clear()
{
    if (this->bottom)
    {
        this->top = this->bottom;
    }
}

//����˳��ջ
void stack::destroy()
{
    if (this->bottom)
    {
        //delete this->bottom;
        delete[] this->bottom; // ʹ�� delete[] �ͷ������ڴ�
        this->stackSize = 0;
        this->bottom = this->top = nullptr;
    }
}

void stack::resize(int newSize) {
    if (newSize <= stackSize) {
        std::cout << "����������С�ڵ�ǰ����" << std::endl;
        return;
    }
    ElemType* newBottom = new ElemType[newSize];
    if (!newBottom) {
        std::cout << "�ڴ����ʧ��" << std::endl;
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
// ��ջ����
void stack::push(const ElemType& elem) 
{
    if (this->top - this->bottom == this->stackSize) //�ж��Ƿ���
    {
        std::cout << "˳��ջ����" << std::endl;
        return;
    }
    else 
    {

        this->top->age = elem.age;
        this->top->name = elem.name;
        this->top++;
    }
}

// ��ջ����
void stack::pop(ElemType& elem)  //��ջ��Ϊ�գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������true ���򷵻�false
{
    if (this->bottom == this->top)
    {
        std::cout << "˳��ջΪ��" << std::endl;
        return;
    }
    else
    {
        this->top--;
        elem.age = this->top->age;
        elem.name = this->top->name;
    }
}

//����	     NULL	                nullptr
//����	     �꣬ͨ��Ϊ 0	        ����Ϊ std::nullptr_t
//����	     ��������	            ר�õ�ָ������
//���Ͱ�ȫ	 �񣬿��ܵ��´���	        �ǣ���ȷ����ָ�������
//ת������	 ����ʽת��Ϊ�κ�ָ��	    ����ʽת��Ϊ�κ�ָ�룬������ת��Ϊ����
//C++11      ֧��	һֱ����	        ��Ҫ C++11 ����߰汾