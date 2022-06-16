final_last#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <cassert>
using namespace std;


template <typename T>
struct node
{
  T _item;
  node<T>* _next;

  node():_item(0), _next(NULL)
  {
     //blannk
      //default ctor
  }
  node(const T& item=T(), node<T>* next = nullptr):
                    _item(item), _next(next)
  {
    //blank
      //ctor
  }
    //overloading insertion operator
    friend ostream& operator<<(ostream& outs, const node<T>& n)
    {
        outs<< n._item;
        //show item stored in nodes
        return outs;
    }
};

template<typename T>
node<T>* _insert_head(node<T>*& head_ptr, const T& item);
//Precondition: head_ptr points at head of list
//item is the item we are inserting
//Postcondition: item gets inserted at the pos head
//Returns the new ptr pointing at head
template<typename T>
T _remove_head(node<T>*& head_ptr);
//Precondition: head_ptr points at head of list
//Postcondition: head gets removed
//Returns the item that got removed
template<typename T>
node<T>* _insert_after(node<T>*& head_ptr, node<T>* mark,
                       const T& item);
//Precondition: head_ptr points at head of list
//mark is pos where item inserted after
//item is the item we are inserting
//Postcondition: item gets inserted after the pos mark
//Returns the address of node with item
template <typename T>
node<T>* _insert_before(node<T>*& head_ptr, node<T>* mark,
                        const T& item);
//Precondition: head_ptr points at head of list
//mark is pos where item inserted before
//item is the item we are inserting
//Postcondition: item gets inserted before the pos mark
//Returns the address of node with item
template <typename T>
node<T>* _search_list(node<T>* head_ptr, const T& item);
//Precondition: head_ptr points at head of list
//item is the item we are looking for
//Postcondition: finds the item
//Returns the new ptr pointing at item or NULL if not found
template <typename T>
node<T>* _next_node(node<T>* head_ptr, node<T>* mark);
//Precondition: head_ptr points at head of list
//mark is pos where we want the node after
//Postcondition: next node will be gotten
//Returns the ptr pointing at next node
template <typename T>
node<T>* _previous_node(node<T>* head_ptr, node<T>* mark);
//Precondition: head_ptr points at head of list
//mark is pos where we want the node before
//Postcondition: previous node will be gotten
//Returns the ptr pointing at previous node
template <typename T>
T _delete_node(node<T>*& head_ptr,  node<T>* mark);
//Precondition: head_ptr points at head of list
//mark is pos where we want to delete the node
//Postcondition: remove the item at mark
//Returns the item removed
template <typename T>
node<T>* copy_list(node<T>* head_ptr);
//Precondition: head_ptr points at head of list
//Postcondition: list will get duplicated
//Returns the ptr pointing at duplicated list
template <typename T>
void clear_list(node<T>*& head_ptr);
//Precondition: head_ptr points at head of list
//Postcondition: all the nodes will be removed from list
template <typename T>
T& at(node<T>* head_ptr, int pos);
//Precondition: head_ptr points at head of list
//pos is position in the list
//Postcondition: finds the item at pos in the list
//Returns the item at pos
template <typename T>
node<T>* _insert_sorted(node<T>*& head_ptr, const T& item,
                        bool ascending=true);
//Precondition: head_ptr points at head of list
//ascending shows the if list is ascending or descending
//item is the item we are inserting
//Postcondition: item gets inserted in order of the list
//Returns the address of node with item
template<typename T>
node<T>* _insert_sorted_add(node<T>*& head_ptr, const T& item,
                        bool ascending=true, bool unique=true);
//Precondition: head_ptr points at head of list
//ascending shows the if list is ascending or descending
//item is the item we are inserting
//Postcondition: item gets inserted in order of the list
//Returns the address of node with item
template <typename T>
node<T>* where_this_goes(node<T>* head_ptr, const T& item,
                         bool ascending=true);
//Precondition: head_ptr points at head of list
//ascending shows if list is ascending or descending
//item is the item we are inserting
//Postcondition: find where the item goes
//Returns the address of place where item will be inserted after
template <typename T>
bool check_ascend_descend(node<T>* head_ptr);
//Precondition: head_ptr points at head of list
//Postcondition: shows if list is ascending or descending
//Returns the ture if ascending false otherwise
template <typename T>
node<T>* last_node(node<T>* head_ptr);
//Precondition: head_ptr points at head of list
//Postcondition: finds the last item in the list
//Returns the location of last item
template<typename T>
ostream& _print_list(node<T>* head_ptr, ostream& outs = cout);
//Precondition: head_ptr points at head of list
//Postcondition: prints the list
//Returns ostream

//======================
template<typename T>
node<T>* _insert_head(node<T>*& head_ptr, const T& item){
    //insert the item at the head_ptr of the list: make it the first
    //      link in the chain.

    //1: create a new node:
    node<T>* temp = new node<T>(item);
    //2. point (the next field of) this new node to where head_ptr is
    //pointing to
    temp->_next = head_ptr;

    //3. point head_ptr to this new node:
    head_ptr = temp;

    return head_ptr;
}

template<typename T>
T _remove_head(node<T>*& head_ptr)
{
    //1.point a pointer to node being removed
    node<T>* remove = head_ptr;
    //2.point head_ptr to next node
    if(head_ptr-> _next != NULL) //if there is next node
    {
        head_ptr = head_ptr->_next; //new head is next pos
    }
    else //new head is NULL
    {
        head_ptr = NULL;
    }
    //3.hold on to item in remove node
    T hold = remove->_item;
    //4.delete the remove node
    delete remove;
    //5.return item we held
    return hold;
}

template <typename T>
node<T>* _insert_after(node<T>*& head_ptr, node<T>* mark,
                       const T& item)
{
    //1.check if first is empty
    if(head_ptr == NULL)
    {
         //2.insert head if list is empty
        return _insert_head(head_ptr, item);
    }
    else
    {
        //asserts if mark is not pointing at anything
        assert(mark != NULL);
        //3.insert head at position after mark
        return _insert_head(mark->_next, item);
    }
}

template <typename T>
node<T>* _insert_before(node<T>*& head_ptr, node<T>* mark,
                        const T& item)
{
    //1.check if list is empty
    if(head_ptr == NULL)
    {
         //insert head if list is empty
        return _insert_head(head_ptr, item);
    }
    else
    {
        //2.move to previous node before where we want to add item
        node<T>* pos = _previous_node(head_ptr, mark);
        if(pos == NULL)
        //if that is the start of the list just insert head
        return _insert_head(head_ptr, item);
        else
        //if not just insert after pos that will be before mark
        return _insert_after(head_ptr, pos, item);
    }
}

template <typename T>
node<T>* _search_list(node<T>* head_ptr, const T& item)
{
    //1.get a walker to point at the first node
    node<T>* w = head_ptr;
    if(w == NULL)
    {
        return NULL; //like the book said for empty list case
    }
    else
    {
        //2.check to see if node's item matches the key
        while(w->_item != item && w->_next != NULL)
        {
            w = w->_next; //hop to next node nad repeat
        }
        if(w->_item == item) //if it does return walker
            return w;
        else
            return NULL; //return nullptr if nothing is found
    }
}

template <typename T>
node<T>* _next_node(node<T>* head_ptr, node<T>* mark)
{
    //1.check if mark is pointing at no where
    assert(mark != NULL);//includes empty list

    //2.get a walker to point at the first node
    node<T>* w = head_ptr;

    //3.w is node after mark
    w = mark->_next;
    return w;
}

template <typename T>
node<T>* _previous_node(node<T>* head_ptr, node<T>* mark)
{
    node<T>* w = head_ptr;
    //1.check if mark is pointing at no where
    assert(mark != NULL);//includes empty list

    //2.if mark is poinitng at the head return NULL
    if(mark == head_ptr)
    {
        return NULL;
    }
    else
    {
        //3.go to position before mark and return it
        while(w->_next != mark)
        {
            w = w->_next; //get to pos beofre mark
        }
        return w;
    }
}

template <typename T>
T _delete_node(node<T>*& head_ptr,  node<T>* mark)
{
    assert(mark != NULL);

    //1.get a walker
    node<T>* w = head_ptr;

    while(w!= mark)
    {
        w = w->_next; //2.get to pos mark
    }

    //3.get to pos before mark
    node<T>* prev = _previous_node(head_ptr, w);

    if(prev == NULL)//if there is no pos before mark
    {
        //remove head
        return _remove_head(head_ptr);
    }
    else
    {
        //prev is pointing at where w(mark) is pointing at
        prev->_next = w->_next;
        //remove at pos w
        return _remove_head(w);
    }
}

template <typename T>
node<T>* copy_list(node<T>* head_ptr)
{
    //1.create a new pointer;
    node<T>* copy = NULL;
    //2.assign a walker to head_ptr
    node<T>* w = head_ptr;
    //3.insert first item of head_ptr list to new list
    _insert_after(copy, copy, w->_item);
    //4.move w to last element in list
    w = last_node(head_ptr);
    while(w != head_ptr)
    {
        //5.insert last item of head_ptr list to new list in second
        //pos by calling insert after
         _insert_after(copy, copy, w->_item);
         //6.move walker to item previous to the last item
         w = _previous_node(head_ptr, w);
    }
    //last item in copy will be NULL
    last_node(copy)->_next = NULL;

    //my code didn't work for simply putting it from starting head_ptr
    //that's why I started from the end
    return copy;
}


template <typename T>
void clear_list(node<T>*& head_ptr)
{
    //1.get w pointer points at list
    node<T>* w = head_ptr;
    while(w != NULL)
    {
        //call _delete_node to delete at pos w
        _delete_node(head_ptr, w);
        //3.move w to next node
        w = w->_next;
        //4.delet previous node
    }
}

template <typename T>
T& at(node<T>* head_ptr, int pos)
{
    int size = 0;
    for(node<T>* ptr = head_ptr; ptr!=NULL; ptr=ptr->_next)
    {
        size++;
    }
    assert(pos<size && pos >= 0);
    node<T>* w = head_ptr;
    for(int i=0; i<pos; i++)
    {
        w = w->_next; //get to pos
    }
    return w->_item; //return item in node at pos
}

template <typename T>
node<T>* _insert_sorted(node<T>*& head_ptr, const T& item,
                        bool ascending)
{
    if(_search_list(head_ptr, item) == NULL){
    if(ascending == true){
    //2.find the pos where item goes after
     node<T>* pos = where_this_goes(head_ptr, item, true);
    if(pos == NULL)
        return _insert_head(head_ptr, item);
    else
        return _insert_after(head_ptr, pos, item);
    }
    else{
    //2.find the pos where item goes after
     node<T>* pos = where_this_goes(head_ptr, item, false);
    if(pos == NULL)
        return _insert_head(head_ptr, item);
    else
        return _insert_after(head_ptr, pos, item);
    }
    }
    else
    {
        return _search_list(head_ptr, item);
    }
}

template <typename T>
node<T>* _insert_sorted_add(node<T>*& head_ptr, const T& item,
                        bool ascending, bool unique)
{
    {
        if(_search_list(head_ptr, item) == NULL){
        if(ascending == true){
        //2.find the pos where item goes after
         node<T>* pos = where_this_goes(head_ptr, item, true);
        if(pos == NULL)
            return _insert_head(head_ptr, item);
        else
            return _insert_after(head_ptr, pos, item);
        }
        else{
        //2.find the pos where item goes after
         node<T>* pos = where_this_goes(head_ptr, item, false);
        if(pos == NULL)
            return _insert_head(head_ptr, item);
        else
            return _insert_after(head_ptr, pos, item);
        }
        }
        else
        {
            node<T>* found = _search_list(head_ptr, item);
            if(unique == true)
            {
                found->_item = found->_item + item;
                return found;
            }
            else
            {
                return _insert_after(head_ptr, found, item);
            }

        }
    }
}
template <typename T>
node<T>* where_this_goes(node<T>* head_ptr, const T& item,
                         bool ascending)
{
    if(head_ptr == NULL)
    {
        return NULL;
    }
    //1.assign a follower
    node<T>* f = head_ptr;
    //2.assign a follower
    node<T>* w = f->_next;
    node<T>* last = last_node(head_ptr);
    if(ascending == true) //in an ascending list
    {
        //check if item is greater that last item
        if(item > (last->_item))
        {
            //last is the place that item goes after
            return last;
        }
        else if(item < head_ptr->_item)
        {
            return NULL;
        }
        else //if item is not greater than last item
        {
          //when item that w points becomes greater than item it stops
            while(w->_item < item)
            {
                //move both w and f
                w = w->_next;
                f = f->_next;
            }
            //return follower which item goes after
            return f;
        }
    }
    else //for a descending list
    {
        //check if item is less that last item
        if(item < (last->_item))
        {
            //last is the place that item goes after
            return last;
        }
        else if(item > head_ptr->_item)
        {
            return NULL;
        }
        else //if item is not less than last item
        {
          //when item that w points becomes less than item it stops
            while(w->_item > item)
            {
                //move both w and f
                w = w->_next;
                f = f->_next;
            }
            //return follower which item goes after
            return f;
        }

    }
}
template <typename T>
node<T>* last_node(node<T>* head_ptr)
{
    //1.get a walker
    node<T>* w = head_ptr;

    //2.go to last node
    while(w->_next != NULL)
    {
        w = w->_next;
    }

    //3.return last node
    return w;
}

template<typename T>
ostream& _print_list(node<T>* head_ptr, ostream& outs)
{
    outs<<"H->";
    for (node<T>* w = head_ptr; w!=nullptr; w =w->_next)
    {
        //puts bracket over item
        outs<< "[" << *w << "]->";
    }
    outs<<"|||";
    cout << endl;
    return outs;
}



#endif // NODE_H
