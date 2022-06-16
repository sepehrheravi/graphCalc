#include "stack_test.h"
#include <iostream>
using namespace std;

void test_stack_app()
{
    cout << endl;
    cout << "=================== STACK =====================" << endl;
    cout<<endl;

    srand(time(0));
    cout << endl;
    char input = '\0';
    Stack<int> s;
    int item = 0;
    for(int i=0; i<10; i++)
    {
        s.push(i);
    }

    cout << s << endl;
    cout << endl;
    cout << "[R]andom   [I]nsert   [D]elete   [T]op    e[X]it: ";

    cin >> input;
    cout << endl;
    cout << "---------------------------------------------------"
        "----------------" << endl;

    while(toupper(input) != 'X')
    {
        switch (toupper(input))
        {
        case 'R':
            item = rand() % 100;

                s.push(item);

            break;
        case 'I':
            cout << "?: ";
            cin >> item;
                s.push(item);

            break;
        case 'D':
            if(!s.empty())
            {
                item = s.pop();

            }
            break;
        case 'T':
            if(!s.empty())
            {
            cout << "Top->[" << s.top() << "]" << endl;
            }
            break;

        }
        cout << endl;
        cout << s << endl;
        cout << endl;
        cout << "[R]andom   [I]nsert   [D]elete   [T]op    e[X]it: ";

        cin >> input;
        cout << endl;
        cout << "---------------------------------------------------"
            "----------------" << endl;
    }

    cout << endl << endl;
    cout << "===================== END =====================" << endl;
    cout << endl;


}

void test_stack_push()
{
    cout << endl;
    Stack<int> s;
    cout << s << endl;
    cout << endl << "Push [2] and [4]" << endl;
    s.push(2);
    s.push(4);

    cout << endl << s << endl;

    s.push(8);
    cout << endl << "Push [8]" << endl;

    cout << endl << s << endl;
    cout << endl;
}

void test_stack_pop()
{
    cout << endl;
    Stack<int> s;
    for(int i=0; i<10; i++)
    {
        s.push(i);
    }

    cout << s << endl;

    for(int i=0; i<8; i++)
    {
        s.pop();
    }

    cout << endl << "Pop first 8: " << s << endl;
    cout << endl;

    cout << "Pop: " << s.pop() << endl;
    cout << s << endl;
    cout << endl;

    cout << "Pop: " << s.pop() << endl;
    cout << s << endl;
    cout << endl;

    cout << "Pop on empty Stack " << endl;
    s.pop();
    cout << s << endl;
    cout << endl;
}

void test_stack_empty()
{
    cout << endl;
    Stack<int> s;
    for(int i=0; i<10; i++)
    {
        s.push(i);
    }
    cout << s << endl;

    if(s.empty()) cout << endl << "Stack is empty" << endl;
    else cout << endl <<"Stack is not empty" << endl;

    cout << endl << "Pop every item" << endl << endl;
    for(int i=0; i<10; i++)
    {
        s.pop();
    }
    cout << s << endl;

    if(s.empty()) cout << endl << "Stack is empty" << endl;
    else cout << endl <<"Stack is not empty" << endl;

    cout << endl;
}

void test_stack_top()
{
    cout << endl;
    Stack<int> s;
    for(int i=0; i<10; i++)
    {
        s.push(i);
    }
    cout << s << endl;

    cout << endl << "Top of the Stack is: [" << s.top() << "]" << endl;
    cout << endl << "Pop [" << s.pop() << "]" << endl << endl;
    cout << s << endl;
    cout << endl << "Top of the Stack is: [" << s.top() << "]" << endl;
    cout << endl << "Push [20]" << endl << endl;
    s.push(20);
    cout << s << endl;
    cout << endl << "Top of the Stack is: [" << s.top() << "]" << endl;
    cout << endl << "Pop everything" << endl << endl;
    for(int i=0; i<10; i++)
    {
        s.pop();
    }
    cout << s << endl;
    cout << endl << "Top of the Stack is:" << endl;
    cout << s.top() <<endl;
}
