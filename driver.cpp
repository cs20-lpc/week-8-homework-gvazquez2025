#include <iostream>
#include <string>
#include "StackFactory.hpp"

using namespace std;

template <typename T>
void basicTests(Stack<T>* s, const string& name)
{
    cout << "\n===== BASIC TESTS FOR " << name << " =====\n";

    cout << "Is empty? " << s->isEmpty() << endl;

    s->push(1);
    s->push(2);
    s->push(3);

    cout << "After pushing 1,2,3\n";
    s->print();

    cout << "Peek: " << s->peek() << endl;

    s->pop();
    cout << "After pop\n";
    s->print();

    cout << "Length: " << s->getLength() << endl;

    s->clear();
    cout << "After clear\n";
    s->print();
}

void rotateTests(Stack<int>* s, const string& name)
{
    cout << "\n===== ROTATION TESTS FOR " << name << " =====\n";

    s->push(1);
    s->push(2);
    s->push(3);
    s->push(4);

    cout << "Original stack:\n";
    s->print();

    s->rotate(Stack<int>::RIGHT);
    cout << "After RIGHT rotation:\n";
    s->print();

    s->rotate(Stack<int>::LEFT);
    cout << "After LEFT rotation:\n";
    s->print();

    s->clear();
}

void exceptionTests(Stack<int>* s, const string& name)
{
    cout << "\n===== EXCEPTION TESTS FOR " << name << " =====\n";

    try {
        s->pop();
    }
    catch (string& e) {
        cout << e << endl;
    }

    try {
        s->peek();
    }
    catch (string& e) {
        cout << e << endl;
    }

    try {
        s->rotate(Stack<int>::LEFT);
    }
    catch (string& e) {
        cout << e << endl;
    }
}

void stringTests()
{
    cout << "\n===== STRING STACK TEST =====\n";
    Stack<string>* s = StackFactory<string>::GetStack();

    s->push("Alice");
    s->push("Bob");
    s->push("Charlie");

    s->print();
    cout << "Peek: " << s->peek() << endl;

    s->rotate(Stack<string>::RIGHT);
    cout << "After RIGHT rotation:\n";
    s->print();

    delete s;
}

void copyTests()
{
    cout << "\n===== COPY TESTS =====\n";

    LinkedListStack<int> original;
    original.push(10);
    original.push(20);
    original.push(30);

    cout << "Original:\n";
    original.print();

    LinkedListStack<int> copy(original);
    cout << "Copy (copy constructor):\n";
    copy.print();

    LinkedListStack<int> assigned;
    assigned = original;
    cout << "Assigned (operator=):\n";
    assigned.print();
}

int main()
{
    // LinkedListStack via factory
    Stack<int>* llStack = StackFactory<int>::GetStack();
    basicTests(llStack, "LinkedListStack");
    rotateTests(llStack, "LinkedListStack");
    exceptionTests(llStack, "LinkedListStack");

    delete llStack;

    // ArrayStack via factory
    Stack<int>* arrStack = StackFactory<int>::GetStack(10);
    basicTests(arrStack, "ArrayStack");
    rotateTests(arrStack, "ArrayStack");
    exceptionTests(arrStack, "ArrayStack");

    delete arrStack;

    stringTests();
    copyTests();

    cout << "\n===== ALL TESTS COMPLETED SUCCESSFULLY =====\n";
    return 0;
}
