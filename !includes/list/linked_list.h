#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include "../../!includes/node/node.h"

using namespace std;

template <typename T>
class List{
public:
    List();
    //default ctor

    //big 3 functions:
    List(const List<T>& copy_this);
    //copy ctor
    List& operator =(const List& rhs);
    //assignment operator
    ~List();
    //dtor

    node<T>* insert_head(const T& item);
    //Precondition: item is the item we are inserting
    //Postcondition: item gets inserted at the pos head
    //Returns the new ptr pointing at head
    T remove_head();
    //Postcondition: head will get removed
    //Returns the item that was removed
    node<T>* insert_after(const T& item, node<T>* mark);
    //Precondition: mark is pos where item inserted after
    //item is the item we are inserting
    //Postcondition: item gets inserted after the pos mark
    //Returns the address of node with item
    node<T>* insert_before(const T& item, node<T>* mark);
    //Precondition: mark is pos where item inserted before
    //item is the item we are inserting
    //Postcondition: item gets inserted before the pos mark
    //Returns the address of node with item
    node<T>* insert_sorted(const T& item);
    //Precondition: item is the item we are inserting
    //Postcondition: item gets inserted in order of the list
    //Returns address of node item got inserted in
    T delete_node(node<T>* mark);
    //Precondition: mark is pos where we want to delete the node
    //Postcondition: remove the item at mark
    //Returns the item removed
    node<T>* search_list(const T& key);
    //Precondition: key is the item we are looking for
    //Postcondition: finds the key
    //Returns the address for node with item or NULL if not found
    node<T>* next_node(node<T>* mark);
    //Precondition: mark is pos where we want the node after
    //Postcondition: next node will be gotten
    //Returns the ptr pointing at next node
    node<T>* previous_node(node<T>* mark);
    //Precondition: mark is pos where we want the node before
    //Postcondition: previous node will be gotten
    //Returns the ptr pointing at previous node
    T& operator[](int index);
    //Precondition:index is position in the list
    //Postcondition: finds the item at index in the list
    //Returns the item at index
    node<T>* begin() const;
    //Postcondition: finds the head in the list
    //Returns the location of last item
    node<T>* end() const;
    //Postcondition: finds the tail in the list
    //Returns the location of last item
    node<T>* not_empty() const;
    //Return NULL if list is empty
    ostream& print_list(ostream& outs = cout);
    //Postcondition: prints the list
    //Returns ostream

    //overloading insertion operator
    template <class U>
    friend ostream& operator<<(ostream& outs, const List<U> l);


private:
    node<T>* _head_ptr;
};

template <typename T>
List<T>::List():_head_ptr(NULL)
{
    //blank
}

template<typename T>
List<T>::List(const List<T>& copy_this)
{
     //2. dealloate existing space;
    _head_ptr = copy_list(copy_this._head_ptr);
}

template<typename T>
List<T>& List<T>::operator =(const List& rhs)
{
    //1. check for self-reference
    if (this == &rhs)
    {
        return *this;
    }
    //2. dealloate existing space;
    clear_list(_head_ptr);

   //3. allocate space and copy everything over
   _head_ptr = copy_list(rhs._head_ptr);

    //4. return this object
    return *this;
}

template<typename T>
List<T>::~List()
{
    clear_list(_head_ptr);
//dealloate existing space;
}

template <typename T>
node<T>* List<T>::insert_head(const T& item)
{
    //call _insert_head function
    return _insert_head(_head_ptr, item);
}

template <typename T>
T List<T>::remove_head()
{
    //call _remove_head function
    return _remove_head(_head_ptr);
}

template <typename T>
node<T>* List<T>::insert_after(const T& item, node<T>* mark)
{
    //call _insert_after function
    return _insert_after(_head_ptr, mark, item);
}

template <typename T>
node<T>* List<T>::insert_before(const T& item, node<T>* mark)
{
    //call _insert_before function
    return _insert_before(_head_ptr, mark, item);
}

template <typename T>
node<T>* List<T>::insert_sorted(const T& item)
{
    //call _insert_sorted function
    return _insert_sorted(_head_ptr, item);
}

template <typename T>
T List<T>::delete_node(node<T>* mark)
{
    //call _delete_node function
    return _delete_node(_head_ptr, mark);
}

template <typename T>
node<T>* List<T>::search_list(const T& key)
{
    //call _search_list function
    return _search_list(_head_ptr, key);
}

template <typename T>
node<T>* List<T>::next_node(node<T>* mark)
{
    //call _next_node function
    return _next_node(_head_ptr, mark);
}

template <typename T>
node<T>* List<T>::previous_node(node<T>* mark)
{
    //call _previous_node function
    return _previous_node(_head_ptr, mark);
}

template <typename T>
T& List<T>::operator[](int index)
{
    //call at function
   return at(_head_ptr, index);
}

template <typename T>
node<T>* List<T>:: begin() const
{
    //return head of list
    return _head_ptr;
}

template <typename T>
node<T>* List<T>:: end() const
{
    //call last_node function
    return last_node(_head_ptr);
}

template <typename T>
node<T>* List<T>::not_empty() const
{
    //check if head is null
    if(_head_ptr == NULL)
        return NULL;
    else
        return _head_ptr;
}


template <typename T>
ostream& List<T>::print_list(ostream& outs)
{
    //call print function
   return _print_list(_head_ptr,outs);
}

template <class U>
ostream& operator<<(ostream& outs, const List<U> l)
{
    //call print function
   return _print_list(l._head_ptr, outs);
}



#endif // LINKED_LIST_H
