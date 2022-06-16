#include "node_test.h"


node<int>* _get_list1(){
    node<int>* head_ptr=nullptr;
    for (int i=0; i<10; i++){
        _insert_head(head_ptr, i*10);
    }
    return head_ptr;
}
node<int>* _get_list2(){
    node<int>* head_ptr=nullptr;
    for (int i=9; i>=0; i--)
    {
        _insert_head(head_ptr, i*10);
    }
    return head_ptr;
}
void _test_insert_head()
{
    cout<<"--------- _TEST_INSERT_HEAD ------------"<<endl;
    cout<<endl<<endl;

    node<int>* head_ptr=nullptr;
    head_ptr = _get_list2();
     cout<<"Inserting 9...0 into list head: 0-10-20....80-90"<<endl;
    _print_list(head_ptr);

    cout<<endl<<endl;
    cout<<"--------- END _TEST_INSERT_HEAD ------------"<<endl;
}

void _test_remove_head()
{
    cout<<"--------- _TEST_REMOVE_HEAD ------------"<<endl;
    cout<<endl<<endl;

    node<int>* head_ptr=nullptr;
    head_ptr = _get_list2();
    _print_list(head_ptr);

    cout << endl << "Removed Head which is: "
                    "[" << _remove_head(head_ptr) << "]" << endl;
     _print_list(head_ptr);

     node<int>* head_ptr1 = nullptr;
     head_ptr1=_insert_head(head_ptr1, 5);
     _print_list(head_ptr1);

     cout << endl << "Removed Head which is: "
                     "[" << _remove_head(head_ptr1) << "]" << endl;
     _print_list(head_ptr1);

    cout<<endl<<endl;
    cout<<"--------- END _TEST_REMOVE_HEAD ------------"<<endl;
}

void _test_insert_after()
{
    cout<<"--------- _TEST_INSERT_AFTER ------------"<<endl;
    cout<<endl<<endl;

    node<int>* head_ptr=nullptr;
    head_ptr = _get_list2();
    _print_list(head_ptr);

    _insert_after(head_ptr, head_ptr, 5);
    cout << endl << "Inserting [5] after "<< *head_ptr << endl;
    _print_list(head_ptr);

    node<int>* mark = _search_list(head_ptr, 60);
    _insert_after(head_ptr, mark, 65);
    cout << endl << "Inserting [65] after "<< *mark << endl;
    _print_list(head_ptr);

    mark = _search_list(head_ptr, 65);
    _insert_after(head_ptr, mark, 68);
    cout << endl << "Inserting [68] after "<< *mark << endl;
    _print_list(head_ptr);

    mark = _search_list(head_ptr, 90);
    _insert_after(head_ptr, mark, 98);
    cout << endl << "Inserting [98] after "<< *mark << endl;
    _print_list(head_ptr);

    cout<<endl<<endl;
    cout<<"--------- END _TEST_INSERT_AFTER ------------"<<endl;

}

void _test_insert_before()
{
    cout<<"--------- _TEST_INSERT_BEFORE ------------"<<endl;
    cout<<endl<<endl;

    node<int>* head_ptr=nullptr;
    head_ptr = _get_list2();
    _print_list(head_ptr);

    _insert_before(head_ptr, head_ptr, -2);
    cout << endl << "Inserting [2] at the head " << endl;
    _print_list(head_ptr);

    node<int>* mark = _search_list(head_ptr, 50);
    _insert_before(head_ptr, mark, 45);
    cout << endl << "Inserting [45] before "<< *mark << endl;
    _print_list(head_ptr);

    mark = _search_list(head_ptr, 45);
    _insert_before(head_ptr, mark, 42);
    cout << endl << "Inserting [42] before "<< *mark << endl;
    _print_list(head_ptr);

    mark = _search_list(head_ptr, 90);
    _insert_before(head_ptr, mark, 85);
    cout << endl << "Inserting [85] before "<< *mark << endl;
    _print_list(head_ptr);


    cout<<endl<<endl;
    cout<<"--------- END _TEST_INSERT_BEFORE ------------"<<endl;

}

void _test_search_list()
{
    cout<<"--------- _TEST_SEARCH_LIST ------------"<<endl;
    cout<<endl<<endl;

    node<int>* head_ptr=nullptr;
    head_ptr = _get_list2();
    _print_list(head_ptr);

    int item = 80;
     cout << endl << "Searching for [" << item << "]";
     if (_search_list(head_ptr,item) == NULL)
        cout << endl << "The item we are looking for is does not exist"
                        " "<< endl;
    else if(_search_list(head_ptr,item) == head_ptr)
        cout << endl << "Item is the head and it's "
             << *_search_list(head_ptr,item) << endl;
    else if(_search_list(head_ptr,item) == last_node(head_ptr))
        cout << endl << "Item is the tail and it's "
             << *_search_list(head_ptr,item) << endl;
    else
        cout << endl << "The item we are looking for is "<<
                *_search_list(head_ptr,item) << endl;

    item = 0;
    cout << endl << "Searching for [" << item << "]";
    if (_search_list(head_ptr,item) == NULL)
       cout << endl << "The item we are looking for is does not exist"
                       " "<< endl;
   else if(_search_list(head_ptr,item) == head_ptr)
       cout << endl << "Item is the head and it's "
            << *_search_list(head_ptr,item) << endl;
   else if(_search_list(head_ptr,item) == last_node(head_ptr))
       cout << endl << "Item is the tail and it's "
            << *_search_list(head_ptr,item) << endl;
   else
       cout << endl << "The item we are looking for is "<<
               *_search_list(head_ptr,item) << endl;

    item = 36;
    cout << endl << "Searching for [" << item << "]";
    if (_search_list(head_ptr,item) == NULL)
       cout << endl << "The item we are looking for is does not exist"
                       " "<< endl;
   else if(_search_list(head_ptr,item) == head_ptr)
       cout << endl << "Item is the head and it's "
            << *_search_list(head_ptr,item) << endl;
   else if(_search_list(head_ptr,item) == last_node(head_ptr))
       cout << endl << "Item is the tail and it's "
            << *_search_list(head_ptr,item) << endl;
   else
       cout << endl << "The item we are looking for is "<<
               *_search_list(head_ptr,item) << endl;

    item = 90;
    cout << endl << "Searching for [" << item << "]";
    if (_search_list(head_ptr,item) == NULL)
       cout << endl << "The item we are looking for is does not exist"
                       " "<< endl;
   else if(_search_list(head_ptr,item) == head_ptr)
       cout << endl << "Item is the head and it's "
            << *_search_list(head_ptr,item) << endl;
   else if(_search_list(head_ptr,item) == last_node(head_ptr))
       cout << endl << "Item is the tail and it's "
            << *_search_list(head_ptr,item) << endl;
   else
       cout << endl << "The item we are looking for is "<<
               *_search_list(head_ptr,item) << endl;


    cout<<endl<<endl;
    cout<<"--------- END _TEST_SEARCH_LIST ------------"<<endl;
}

void _test_next_node()
{
    cout<<"--------- _TEST_NEXT_NODE ------------"<<endl;
    cout<<endl<<endl;

    node<int>* head_ptr=nullptr;
    head_ptr = _get_list2();
    _print_list(head_ptr);

    node<int>* mark = head_ptr;
    cout << endl << "Pointer is pointing at the beginning of list "
         << *mark << endl;
    while(mark->_next != nullptr)
    {
        mark = _next_node(head_ptr, mark);
        cout << endl << "After moving pointer to next node, "
                    "pointer is pointing at "<< *mark << endl;
    }
    cout << endl << "Pointer reached to the end of the list" << endl;

     cout<<endl<<endl;
     cout<<"--------- END _TEST_SEARCH_LIST ------------"<<endl;
}

void _test_previous_node()
{
    cout<<"--------- _TEST_PREVIOUS_NODE ------------"<<endl;
    cout<<endl<<endl;

    node<int>* head_ptr=nullptr;
    head_ptr = _get_list2();
    _print_list(head_ptr);

    node<int>* mark = head_ptr;
    while(mark->_next != nullptr)
    {
        mark = mark ->_next;
    }
    cout << endl << "Pointer is pointing at end of list: " << *mark <<
            endl;
    cout << endl;
    while(mark != head_ptr)
    {
        mark = _previous_node(head_ptr, mark);
        cout << endl << "After moving pointer to previous node, "
                    "pointer is pointing at "<< *mark << endl;
    }
    cout << endl << "Pointer reached to the beginning of the list"
         << endl;

    cout<<endl<<endl;
    cout<<"--------- END _TEST_PREVIOUS_NODE ------------"<<endl;
}

void _test_delete_node()
{
    cout<<"--------- _TEST_DELETE_NODE ------------"<<endl;
    cout<<endl<<endl;

    node<int>* head_ptr=nullptr;
    head_ptr = _get_list2();
    _print_list(head_ptr);

    node<int>* mark = _search_list(head_ptr, 90);
    cout << endl << "Delete tail which is ["
         <<  _delete_node(head_ptr, mark) << "]" << endl;
    _print_list(head_ptr);

    cout << endl << "Delete head which is ["
         <<  _delete_node(head_ptr, head_ptr) << "]" << endl;
    _print_list(head_ptr);

    mark = _search_list(head_ptr, 60);
    cout << endl << "Delete ["
         <<  _delete_node(head_ptr, mark) << "]" << endl;
    _print_list(head_ptr);

//test assert
//    mark = _search_list(head_ptr, 99);
//    cout << endl<< "Mark is pointing at NULL (item does not exist)"
//         << endl;
//    cout << endl <<  _delete_node(head_ptr, mark) << endl;
//    _print_list(head_ptr);


    cout<<endl<<endl;
    cout<<"--------- END _TEST_DELETE_NODE ------------"<<endl;
}

void _test_at()
{
    cout<<"--------- TEST_AT ------------"<<endl;
    cout<<endl<<endl;

    node<int>* head_ptr=nullptr;
    head_ptr = _get_list2();
    _print_list(head_ptr);

    int pos = 0;
    cout << endl << "At position "<< pos << " item is " <<
            at(head_ptr, pos) << endl;

    pos = 5;
    cout << endl << "At position "<< pos << " item is " <<
            at(head_ptr, pos) << endl;

    pos = 6;
    cout << endl << "At position "<< pos << " item is " <<
            at(head_ptr, pos) << endl;

    pos = 9;
    cout << endl << "At position "<< pos << " item is " <<
            at(head_ptr, pos) << endl;

//test assert
//    pos = 10;
//    cout << endl << "Position of out size" << endl;
//    cout << endl << "At position "<< pos << " item is " <<
//            at(head_ptr, pos) << endl;

    cout<<endl<<endl;
    cout<<"--------- END TEST_AT ------------"<<endl;

}

void _test_copy_list()
{
    cout<<"--------- TEST_COPY_LIST ------------"<<endl;
    cout<<endl<<endl;

    node<int>* head_ptr=nullptr;
    head_ptr = _get_list1();
    _print_list(head_ptr);

    node<int>* n = copy_list(head_ptr);


    cout << endl << "Copy completed" << endl;
    cout << "Initial list:" << endl;
    _print_list(head_ptr);
    cout << "Copied list:" << endl;
    _print_list(n);

    cout << endl;
    cout << "Head_ptr loc: " << head_ptr << endl;
    cout << "Copy_ptr loc: " << n << endl;

    int pos = 5;
    cout << endl << "Head_ptr: At position "<< pos << " item is " <<
            at(head_ptr, pos) << endl;

    cout << endl << "Copy_ptr: At position "<< pos << " item is " <<
            at(n, pos) << endl;

    cout<<endl<<endl;
    cout<<"--------- END TEST_COPY_LIST ------------"<<endl;
}

void _test_clear_list()
{
    cout<<"--------- TEST_CLEAR_LIST ------------"<<endl;
    cout<<endl<<endl;

    node<int>* head_ptr=nullptr;
    head_ptr = _get_list2();
    _print_list(head_ptr);

    clear_list(head_ptr);
    cout << endl << "After deleting all the nodes" << endl;
    cout << endl;
    _print_list(head_ptr);

    cout<<endl<<endl;
    cout<<"--------- END TEST_CLEAR_LIST ------------"<<endl;

}

void _test_insert_sorted()
{
    cout<<"--------- _TEST_insert_sorted ------------"<<endl;
    cout<<endl<<endl;

    node<int>* head_ptr=nullptr;

    cout<<"--------- ASCENDING LIST ------------"<<endl;
    cout << endl;
    head_ptr = _get_list2();
    _print_list(head_ptr);
    cout<<endl;

    bool ascending = true;
    int item = 8;
    cout << endl << "If we insert:["<< item <<"]" << endl;
    cout << "It goes after "
         << *where_this_goes(head_ptr, item, ascending) << endl;
    _insert_sorted(head_ptr, item, ascending);
    _print_list(head_ptr);

    item = 25;
    cout << endl << "If we insert:["<< item <<"]" << endl;
    cout << "It goes after "
         << *where_this_goes(head_ptr, item, ascending) << endl;
    _insert_sorted(head_ptr, item, ascending);
    _print_list(head_ptr);

    item = 85;
    cout << endl << "If we insert:["<< item <<"]" << endl;
    cout << "It goes after "
         << *where_this_goes(head_ptr, item, ascending) << endl;
    _insert_sorted(head_ptr, item, ascending);
    _print_list(head_ptr);

    item = -8;
    cout << endl << "If we insert:["<< item <<"]" << endl;
    cout << "It goes at head" << endl;
    _insert_sorted(head_ptr, item, ascending);
    _print_list(head_ptr);

    item = 120;
    cout << endl << "If we insert:["<< item <<"]" << endl;
    cout << "It goes after "
         << *where_this_goes(head_ptr, item, ascending) << endl;
    _insert_sorted(head_ptr, item, ascending);
    _print_list(head_ptr);

    item = 0;
    cout << endl << "If we insert:["<< item <<"]" << endl;
    cout << "It goes after "
         << *where_this_goes(head_ptr, item, ascending) << endl;
    _insert_sorted(head_ptr, item, ascending);
    _print_list(head_ptr);

    item = 50;
    cout << endl << "If we insert:["<< item <<"]" << endl;
    cout << "It goes after "
         << *where_this_goes(head_ptr, item, ascending) << endl;
    _insert_sorted(head_ptr, item, ascending);
    _print_list(head_ptr);

    item = 100;
    cout << endl << "If we insert:["<< item <<"]" << endl;
    cout << "It goes after "
         << *where_this_goes(head_ptr, item, ascending) << endl;
    _insert_sorted(head_ptr, item, ascending);
    _print_list(head_ptr);

    item = 120;
    cout << endl << "If we insert:["<< item <<"]" << endl;
    cout << "It goes after "
         << *where_this_goes(head_ptr, item, ascending) << endl;
    _insert_sorted(head_ptr, item, ascending);
    _print_list(head_ptr);
    cout<<endl << endl;

    cout<<"--------- DESCENDING LIST ------------"<<endl;
    cout << endl;
    head_ptr = _get_list1();
    _print_list(head_ptr);
    cout<<endl;

    ascending = false;
    item = 8;
    cout << endl << "If we insert:["<< item <<"]" << endl;
    cout << "It goes after "
         << *where_this_goes(head_ptr, item, ascending) << endl;
    _insert_sorted(head_ptr, item, ascending);
    _print_list(head_ptr);

    item = 25;
    cout << endl << "If we insert:["<< item <<"]" << endl;
    cout << "It goes after "
         << *where_this_goes(head_ptr, item, ascending) << endl;
    _insert_sorted(head_ptr, item, ascending);
    _print_list(head_ptr);

    item = 85;
    cout << endl << "If we insert:["<< item <<"]" << endl;
    cout << "It goes after "
         << *where_this_goes(head_ptr, item, ascending) << endl;
    _insert_sorted(head_ptr, item, ascending);
    _print_list(head_ptr);

    item = -8;
    cout << endl << "If we insert:["<< item <<"]" << endl;
    cout << "It goes after "
         << *where_this_goes(head_ptr, item, ascending) << endl;
    _insert_sorted(head_ptr, item, ascending);
    _print_list(head_ptr);

    item = 120;
    cout << endl << "If we insert:["<< item <<"]" << endl;
    cout << "It goes at head" << endl;
    _insert_sorted(head_ptr, item, ascending);
    _print_list(head_ptr);

    item = 0;
    cout << endl << "If we insert:["<< item <<"]" << endl;
    cout << "It goes after "
         << *where_this_goes(head_ptr, item, ascending) << endl;
    _insert_sorted(head_ptr, item, ascending);
    _print_list(head_ptr);

    item = 50;
    cout << endl << "If we insert:["<< item <<"]" << endl;
    cout << "It goes after "
         << *where_this_goes(head_ptr, item, ascending) << endl;
    _insert_sorted(head_ptr, item, ascending);
    _print_list(head_ptr);

    item = 100;
    cout << endl << "If we insert:["<< item <<"]" << endl;
    cout << "It goes after "
         << *where_this_goes(head_ptr, item, ascending) << endl;
    _insert_sorted(head_ptr, item, ascending);
    _print_list(head_ptr);

    item = 120;
    cout << endl << "If we insert:["<< item <<"]" << endl;
    cout << "It goes at head" << endl;
    _insert_sorted(head_ptr, item, ascending);
    _print_list(head_ptr);

    cout<<endl<<endl;
    cout<<"--------- END _TEST_insert_sorted ------------"<<endl;

}

void _test_where_it_goes()
{
    cout<<"--------- TEST_WHERE_IT_GOES ------------"<<endl;
    cout<<endl<<endl;

    node<int>* head_ptr=nullptr;

    cout<<"--------- ASCENDING LIST ------------"<<endl;
    cout << endl;
    head_ptr = _get_list2();
    _print_list(head_ptr);
    cout<<endl;

    bool ascending = true;
    int item = 8;
    cout << endl << "If we insert:["<< item <<"]" << endl;
    cout << "It goes after "
         << *where_this_goes(head_ptr, item, ascending) << endl;
    _insert_sorted(head_ptr, item, ascending);
    _print_list(head_ptr);

    item = 25;
    cout << endl << "If we insert:["<< item <<"]" << endl;
    cout << "It goes after "
         << *where_this_goes(head_ptr, item, ascending) << endl;
    _insert_sorted(head_ptr, item, ascending);
    _print_list(head_ptr);

    item = 85;
    cout << endl << "If we insert:["<< item <<"]" << endl;
    cout << "It goes after "
         << *where_this_goes(head_ptr, item, ascending) << endl;
    _insert_sorted(head_ptr, item, ascending);
    _print_list(head_ptr);

    item = -8;
    cout << endl << "If we insert:["<< item <<"]" << endl;
    cout << "It goes at head" << endl;
    _insert_sorted(head_ptr, item, ascending);
    _print_list(head_ptr);

    item = 120;
    cout << endl << "If we insert:["<< item <<"]" << endl;
    cout << "It goes after "
         << *where_this_goes(head_ptr, item, ascending) << endl;
    _insert_sorted(head_ptr, item, ascending);
    _print_list(head_ptr);

    item = 0;
    cout << endl << "If we insert:["<< item <<"]" << endl;
    cout << "It goes after "
         << *where_this_goes(head_ptr, item, ascending) << endl;
    _insert_sorted(head_ptr, item, ascending);
    _print_list(head_ptr);

    item = 50;
    cout << endl << "If we insert:["<< item <<"]" << endl;
    cout << "It goes after "
         << *where_this_goes(head_ptr, item, ascending) << endl;
    _insert_sorted(head_ptr, item, ascending);
    _print_list(head_ptr);

    item = 100;
    cout << endl << "If we insert:["<< item <<"]" << endl;
    cout << "It goes after "
         << *where_this_goes(head_ptr, item, ascending) << endl;
    _insert_sorted(head_ptr, item, ascending);
    _print_list(head_ptr);

    item = 120;
    cout << endl << "If we insert:["<< item <<"]" << endl;
    cout << "It goes after "
         << *where_this_goes(head_ptr, item, ascending) << endl;
    _insert_sorted(head_ptr, item, ascending);
    _print_list(head_ptr);
    cout<<endl << endl;

    cout<<"--------- DESCENDING LIST ------------"<<endl;
    cout << endl;
    head_ptr = _get_list1();
    _print_list(head_ptr);
    cout<<endl;

    ascending = false;
    item = 8;
    cout << endl << "If we insert:["<< item <<"]" << endl;
    cout << "It goes after "
         << *where_this_goes(head_ptr, item, ascending) << endl;
    _insert_sorted(head_ptr, item, ascending);
    _print_list(head_ptr);

    item = 25;
    cout << endl << "If we insert:["<< item <<"]" << endl;
    cout << "It goes after "
         << *where_this_goes(head_ptr, item, ascending) << endl;
    _insert_sorted(head_ptr, item, ascending);
    _print_list(head_ptr);

    item = 85;
    cout << endl << "If we insert:["<< item <<"]" << endl;
    cout << "It goes after "
         << *where_this_goes(head_ptr, item, ascending) << endl;
    _insert_sorted(head_ptr, item, ascending);
    _print_list(head_ptr);

    item = -8;
    cout << endl << "If we insert:["<< item <<"]" << endl;
    cout << "It goes after "
         << *where_this_goes(head_ptr, item, ascending) << endl;
    _insert_sorted(head_ptr, item, ascending);
    _print_list(head_ptr);

    item = 120;
    cout << endl << "If we insert:["<< item <<"]" << endl;
    cout << "It goes at head" << endl;
    _insert_sorted(head_ptr, item, ascending);
    _print_list(head_ptr);

    item = 0;
    cout << endl << "If we insert:["<< item <<"]" << endl;
    cout << "It goes after "
         << *where_this_goes(head_ptr, item, ascending) << endl;
    _insert_sorted(head_ptr, item, ascending);
    _print_list(head_ptr);

    item = 50;
    cout << endl << "If we insert:["<< item <<"]" << endl;
    cout << "It goes after "
         << *where_this_goes(head_ptr, item, ascending) << endl;
    _insert_sorted(head_ptr, item, ascending);
    _print_list(head_ptr);

    item = 100;
    cout << endl << "If we insert:["<< item <<"]" << endl;
    cout << "It goes after "
         << *where_this_goes(head_ptr, item, ascending) << endl;
    _insert_sorted(head_ptr, item, ascending);
    _print_list(head_ptr);

    item = 120;
    cout << endl << "If we insert:["<< item <<"]" << endl;
    cout << "It goes at head" << endl;
    _insert_sorted(head_ptr, item, ascending);
    _print_list(head_ptr);

    cout<<endl<<endl;
    cout<<"--------- END TEST_WHERE_IT_GOES ------------"<<endl;

}

void _test_last_node()
{
    cout<<"--------- TEST_LAST_NODE ------------"<<endl;
    cout<<endl<<endl;

    node<int>* head_ptr=nullptr;
    head_ptr = _get_list2();
    _print_list(head_ptr);

    cout << "End of List: " << *last_node(head_ptr) << endl;

    cout<<endl<<endl;
    cout<<"--------- END TEST_LAST_NODE ------------"<<endl;
}

void _test_print_list()
{
    cout<<"--------- _TEST_PRINT_LIST ------------"<<endl;
    cout<<endl<<endl;

    node<int>* head_ptr=nullptr;
    head_ptr = _get_list2();
    cout<<"Print list"<<endl;
    _print_list(head_ptr);

    cout<<endl<<endl;
    cout<<"--------- END _TEST_PRINT_LIST ------------"<<endl;
}


