#include <iostream>
using namespace std;

#include "SequentialStack.h"
#include "LinkedStack.h"

void test01()
{
    stack s;
    ElemType e1 = { 25, "Alice" };
    ElemType e2 = { 30, "Bob" };
    //s.InitStack();
    s.push(e1);
    s.push(e2);

    ElemType out;
    s.pop(out);
    cout << "Popped: " << out.name << ", " << out.age << endl;

    cout << "Stack size: " << s.size() << endl;
}

void test02()
{
    LinkedStack stack;
    ElemType e1 = { 25, "Alice" };
    ElemType e2 = { 30, "Bob" };
    // 入栈操作
    stack.push(e1);
    stack.push(e2);

    // 打印栈中的元素
    stack.printStack();

    // 获取栈顶元素
    std::cout << "Top element: " << stack.peek().age << " " << stack.peek().name << std::endl;

    // 出栈操作
    stack.pop();
    std::cout << "After pop, top element: " << stack.peek().age << " " << stack.peek().name << std::endl;

    // 再次打印栈中的元素
    stack.printStack();
}
int main()
{

	//test01();
    test02();

	system("pause");
	system("cls");
	return 0;
}