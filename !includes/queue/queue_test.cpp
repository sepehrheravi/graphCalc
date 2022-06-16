#include "queue_test.h"
#include <iostream>
using namespace std;

void test_queue_app()
{
    cout << endl;
    cout << "=================== QUEUE =====================" << endl;
    cout<<endl;

    srand(time(0));
    cout << endl;
    char input = '\0';
    Queue<int> q;
    int item = 0;
    for(int i=0; i<10; i++)
    {
        q.push(i);
    }

    cout << q << endl;
    cout << endl;
    cout << "[R]andom   [I]nsert   [D]elete   [F]ront    e[X]it: ";

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

                q.push(item);

            break;
        case 'I':
            cout << "?: ";
            cin >> item;
                q.push(item);

            break;
        case 'D':
            if(!q.empty())
            {
                item = q.pop();

            }
            break;
        case 'F':
            if(!q.empty())
            {
            cout << "Front->[" << q.front() << "]" << endl;
            }
            break;

        }
        cout << endl;
        cout << q << endl;
        cout << endl;
        cout << "[R]andom   [I]nsert   [D]elete   [F]ront    e[X]it: ";

        cin >> input;
        cout << endl;
        cout << "---------------------------------------------------"
            "----------------" << endl;
    }

    cout << endl << endl;
    cout << "===================== END =====================" << endl;
    cout << endl;
}

void test_queue_push()
{
    cout << endl;
    Queue<int> q;
    cout << q << endl;
    cout << endl << "Push [2] and [4]" << endl;
    q.push(2);
    q.push(4);

    cout << endl << q << endl;

    q.push(8);
    cout << endl << "Push [8]" << endl;

    cout << endl << q << endl;
    cout << endl;
}

void test_queue_pop()
{
    cout << endl;
    Queue<int> q;
    for(int i=0; i<10; i++)
    {
        q.push(i);
    }

    cout << q << endl;

    for(int i=0; i<8; i++)
    {
        q.pop();
    }

    cout << endl << "Pop first 8: " << q << endl;
    cout << endl;

    cout << "Pop: " << q.pop() << endl;
    cout << q << endl;
    cout << endl;

    cout << "Pop: " << q.pop() << endl;
    cout << q << endl;
    cout << endl;

    cout << "Pop on empty Queue " << endl;
    q.pop();
    cout << q << endl;
    cout << endl;
}

void test_queue_empty()
{
    cout << endl;
    Queue<int> q;
    for(int i=0; i<10; i++)
    {
        q.push(i);
    }
    cout << q << endl;

    if(q.empty()) cout << endl << "Stack is empty" << endl;
    else cout << endl <<"Stack is not empty" << endl;

    cout << endl << "Pop every item" << endl << endl;
    for(int i=0; i<10; i++)
    {
        q.pop();
    }
    cout << q << endl;

    if(q.empty()) cout << endl << "Stack is empty" << endl;
    else cout << endl <<"Stack is not empty" << endl;

    cout << endl;
}

void test_queue_front()
{
    cout << endl;
    Queue<int> q;
    for(int i=0; i<10; i++)
    {
        q.push(i);
    }
    cout << q << endl;

    cout << endl << "Front of the Queue is: [" << q.front() << "]" << endl;
    cout << endl << "Pop [" << q.pop() << "]" << endl << endl;
    cout << q << endl;
    cout << endl << "Front of the Queue is: [" << q.front() << "]" << endl;
    cout << endl << "Push [20]" << endl << endl;
    q.push(20);
    cout << q << endl;
    cout << endl << "Front of the Queue is: [" << q.front() << "]" << endl;
    cout << endl << "Pop everything" << endl << endl;
    for(int i=0; i<10; i++)
    {
        q.pop();
    }
    cout << q << endl;
    cout << endl << "Front of the Queue is:" << endl;
    cout << q.front() <<endl;
}




//big 3 test
//    Queue<int> q,q2;
//    q.push(1);
//    q.push(2);
//    q.push(3);
//    q.push(4);
//    q.pop();
//    q.push(5);

//    cout << endl;
//    cout << endl << "Q: " << q << endl << endl;
//    cout << endl;
//    Queue<int> q1(q);
//    cout << "Q1: " << q1 << endl << endl;

//    q2 = q;
//    cout << "Q2: " << q2 << endl << endl;

//    cout << endl << endl << "AFTER CHANGE" << endl << endl;

//    Queue <int>:: Iterator it = q.begin();
//    it++;
//    it++;
//    *it = 7;
//    cout << "Q:  " << q << endl << endl;
//    cout << "Q1:  " << q1 << endl << endl;
//    cout << "Q2:  " << q2 << endl << endl;



