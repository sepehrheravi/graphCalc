#include "list_test.h"


void test_insert_head()
{
    cout<<"--------- TEST_INSERT_HEAD ------------"<<endl;
    cout << endl << endl;

    List<int> l;
    for (int i=0; i<10; i++)
    {
        l.insert_head(i*10);
    }
    cout<<"Inserting 0..10 into list head: 90-80..20-10-0"<<endl;
    cout<<l;

    cout << endl << endl;
    cout<<"--------- END_TEST_INSERT_HEAD ------------"<<endl;
}

void test_insert_after()
{
    cout<<"--------- TEST_INSERT_AFTER ------------"<<endl;
    cout << endl << endl;

    List<int> l;
    for (int i=0; i<10; i++)
    {
        l.insert_head(i*10);
    }
    cout<<l;

    l.insert_after(38, l.search_list(40));
    cout << endl << "Inserting [38] after "<< *l.search_list(40)
         << endl;
    cout <<l;

    l.insert_after(34, l.search_list(38));
    cout << endl << "Inserting [34] after "<< *l.search_list(38)
         << endl;
    cout <<l;

    cout << endl << endl;
    cout<<"--------- END_TEST_INSERT_AFTER ------------"<<endl;

}

void test_insert_before()
{
    cout<<"--------- TEST_INSERT_BEFORE ------------"<<endl;
    cout << endl << endl;

    List<int> l;
    for (int i=0; i<10; i++)
    {
        l.insert_head(i*10);
    }
    cout<<l;

    l.insert_before(5, l.search_list(0));
    cout << endl << "Inserting [5] before "<< *l.search_list(0)
         << endl;
    cout <<l;

    l.insert_before(8, l.search_list(5));
    cout << endl << "Inserting [8] before "<< *l.search_list(5)
         << endl;
    cout <<l;

    l.insert_before(88, l.search_list(80));
    cout << endl << "Inserting [88] before "<< *l.search_list(80)
         << endl;
    cout <<l;

    cout << endl << endl;
    cout<<"--------- END_TEST_INSERT_BEFORE ------------"<<endl;
}

void test_search_list()
{
    cout<<"--------- TEST_SEARCH_LIST ------------"<<endl;
    cout<<endl<<endl;

    List<int> l;
    for (int i=0; i<10; i++)
    {
        l.insert_head(i*10);
    }
    cout<<l;

    int item = 80;
     cout << endl << "Searching for [" << item << "]";
     if (l.search_list(item) == NULL)
        cout << endl << "The item we are looking for is does not exist"
                        " "<< endl;
    else if(l.search_list(item) == l.begin())
        cout << endl << "Item is the head and it's "
             << *l.search_list(item) << endl;
    else if(l.search_list(item) == l.end())
        cout << endl << "Item is the tail and it's "
             << *l.search_list(item) << endl;
    else
        cout << endl << "The item we are looking for is "<<
                *l.search_list(item) << endl;

    item = 0;
     cout << endl << "Searching for [" << item << "]";
    if (l.search_list(item) == NULL)
        cout << endl << "The item does not exist in the list "<< endl;
    else if(l.search_list(item) == l.begin())
        cout << endl << "Item is the head and it's "
             << *l.search_list(item) << endl;
    else if(l.search_list(item) == l.end())
        cout << endl << "Item is the tail and it's "
             << *l.search_list(item) << endl;
    else
        cout << endl << "The item we are looking for is "<<
                *l.search_list(item) << endl;

    item = 36;
     cout << endl << "Searching for [" << item << "]";
    if (l.search_list(item) == NULL)
        cout << endl << "The item we are looking for is does not exist"
                        " "<< endl;
    else if(l.search_list(item) == l.begin())
        cout << endl << "Item is the head and it's "
             << *l.search_list(item) << endl;
    else if(l.search_list(item) == l.end())
        cout << endl << "Item is the tail and it's "
             << *l.search_list(item) << endl;
    else
        cout << endl << "The item we are looking for is "<<
                *l.search_list(item) << endl;

    item = 90;
    cout << endl << "Searching for [" << item << "]";
    if (l.search_list(item) == NULL)
        cout << endl << "The item we are looking for is does not exist"
                        " "<< endl;
    else if(l.search_list(item) == l.begin())
        cout << endl << "Item is the head and it's "
             << *l.search_list(item) << endl;
    else if(l.search_list(item) == l.end())
        cout << endl << "Item is the tail and it's "
             << *l.search_list(item) << endl;
    else
        cout << endl << "The item we are looking for is "<<
                *l.search_list(item) << endl;




    cout<<endl<<endl;
    cout<<"--------- END TEST_SEARCH_LIST ------------"<<endl;
}

void test_next_node()
{
    cout<<"--------- TEST_NEXT_NODE ------------"<<endl;
    cout<<endl<<endl;

    List<int> l;
    for (int i=0; i<10; i++)
    {
        l.insert_head(i*10);
    }
    cout<<l;

    node<int>* mark = l.search_list(90);
    cout << endl << "Pointer is pointing at the beginning of list "
         << *mark << endl;
    while(mark->_next != nullptr)
    {
        mark = l.next_node(mark);
        cout << endl << "After moving pointer to next node, "
                    "pointer is pointing at "<< *mark << endl;
    }
    cout << endl << "Pointer reached to the end of the list" << endl;

     //tried using (mark != nullptr) but a problem occured

     cout<<endl<<endl;
     cout<<"--------- END TEST_SEARCH_LIST ------------"<<endl;
}

void test_previous_node()
{
    cout<<"--------- TEST_PREVIOUS_NODE ------------"<<endl;
    cout<<endl<<endl;

    List<int> l;
    for (int i=0; i<10; i++)
    {
        l.insert_head(i*10);
    }
    cout<<l;

    node<int>* mark = l.search_list(90);
    while(mark->_next != nullptr)
    {
        mark = mark ->_next;
    }
    cout << endl << "Pointer is pointing at end of list: " << *mark <<
            endl;
    cout << endl;
    while(mark != l.search_list(90))
    {
    mark = l.previous_node(mark);
    cout << endl << "After moving pointer to previous node, "
                    "pointer is pointing at "<< *mark << endl;
    }
    cout << endl << "Pointer reached to the beginning of the list"
         << endl;


    cout<<endl<<endl;
    cout<<"--------- END TEST_PREVIOUS_NODE ------------"<<endl;
}

void test_print_list()
{
    cout<<"--------- TEST_PRINT_LIST ------------"<<endl;
    cout<<endl<<endl;

    List<int> l;
    for (int i=0; i<10; i++)
    {
        l.insert_head(i*10);
    }
    cout<<"Print list"<<endl;
    cout<<l;

    cout<<endl<<endl;
    cout<<"--------- END TEST_PRINT_LIST ------------"<<endl;
}

void test_insert_sorted()
{
    cout<<"--------- TEST_INSERT_SORTED ------------"<<endl;
    cout<<endl<<endl;

    List<int> l;
    for (int i=9; i>=0; i--)
    {
        l.insert_head(i*10);
    }
    cout<<l << endl;
    cout << endl <<"Inser, if inserting a negative number that would "
                   "be the last item to get inserted" << endl;
    int item;
    cout << "?" << endl;
    cin >> item;
    l.insert_sorted(item);
    cout << l << endl;
    while(item >= 0)
    {
        cout << "?" << endl;
        cin >> item;
        l.insert_sorted(item);
        cout << l << endl;
    }

    cout<<endl<<endl;
    cout<<"--------- END TEST_INSERT_SORTED ------------"<<endl;
}
void test_delete_node()
{
    cout<<"--------- TEST_DELETE_NODE ------------"<<endl;
    cout<<endl<<endl;

    List<int> l;
    for (int i=0; i<10; i++)
    {
        l.insert_head(i*10);
    }
    cout<<l;

    node<int>* mark = l.search_list(60);
    cout << endl << "Deleting " << *mark << endl;
    l.delete_node(mark);
    cout << endl;
    cout << l;

    cout << endl << "Deleting last item: " << *l.end() << endl;
    l.delete_node(l.end());
    cout << endl;
    cout << l;

    cout << endl << "Deleting first item: " << *l.begin() << endl;
    l.delete_node(l.begin());
    cout << endl;
    cout << l;

    cout<<endl<<endl;
    cout<<"--------- END TEST_DELETE_NODE ------------"<<endl;
}
void test_operator_bracket()
{
    cout<<"--------- TEST_OPERATOR_BRACKET ------------"<<endl;
    cout<<endl<<endl;

    List<int> l;
    for (int i=0; i<10; i++)
    {
        l.insert_head(i*10);
    }
    cout<< l << endl;

    for (int i=0; i<10; i++)
    {
        cout << "Item [" << i << "] = " << l[i] << endl;
    }

    cout<<endl<<endl;
    cout<<"--------- END TEST_OPERATOR_BRACKET ------------"<<endl;
}
void test_begin()
{
    cout<<"--------- TEST_BEGIN ------------"<<endl;
    cout<<endl<<endl;

    List<int> l;
    for (int i=0; i<10; i++)
    {
        l.insert_head(i*10);
    }
     cout<< l << endl;

    cout << "HEAD: " << *l.begin() << endl;

    cout<<endl<<endl;
    cout<<"--------- END TEST_BEGIN ------------"<<endl;
}
void test_end()
{
    cout<<"--------- TEST_END ------------"<<endl;
    cout<<endl<<endl;

    List<int> l;
    for (int i=0; i<10; i++)
    {
        l.insert_head(i*10);
    }
    cout<< l << endl;

    cout << "END: " << *l.end() << endl;

    cout<<endl<<endl;
    cout<<"--------- END TEST_END ------------"<<endl;
}

