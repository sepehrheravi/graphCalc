#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "../../!includes/node/node.h"
#include <cassert>

using namespace std;

template <typename T>
class Stack
{
public:
    class Iterator
    {
    public:
        friend class Stack;
        Iterator(node<T>* p = NULL): _ptr(p)
        {
           //default ctor
        }

        Iterator next()
        {
            assert(_ptr);
            return Iterator(_ptr = _ptr->_next);
           //return an iterator to the next location in the list
        }

//        T& operator *()
//        {
//            assert(_ptr);
//            return _ptr->_item;
//        }
          //do not give outsiders access to alter anything
        const T& operator *()const
        {
            assert(_ptr);
            return _ptr->_item;
            //returns the item where iterator points at
        }

//        T* operator ->()
//        {
//            assert(_ptr);         
//            return &(_ptr->_item);
//        }
          //do not give outsiders access to alter anything

        const T* operator ->()const
        {
            assert(_ptr);
            return &(_ptr->_item);
            //returns the address of the item where iterator points at
        }

        //true if _ptr is NULL
        bool is_null()
        {
            return (_ptr == NULL);
        }

        const T& operator[](int index)const
        {
            assert(_ptr);
            //call at function
           return at(_ptr, index);
           //return item at index
        }

        //friend operator: it++
        friend Iterator operator ++(Iterator& it, int unused)
        {
            assert(it._ptr);
            Iterator hold;
            hold = it;
            it.next();
            return hold;
        }

        //member operator: ++it
        Iterator& operator ++()
        {
            assert(_ptr);
           _ptr = _ptr->_next;
           return *this;
        }

        //true if left != right
        friend bool operator !=(const Iterator& left,
                                const Iterator& right)
        {
            return left._ptr != right._ptr;
        }

        //true if left == right
        friend bool operator ==(const Iterator& left,
                                const Iterator& right)
        {
            return left._ptr == right._ptr;
        }

    private:
        node<T>* _ptr;
        //pointer being encapsulated

    };

    Stack();
    //default ctor

    //big 3 functions:
    Stack(const Stack<T>& copy_this);
    //copy ctor
    Stack& operator =(const Stack& rhs);
    //assignment operator
    ~Stack();
    //dtor

    Iterator begin()const;
    //Returns Iterator to the head node
    Iterator end()const;
    //Returns Iterator points at NULL
    Iterator push(const T& item);
    //Precondition: item to insert
    //Postcondition: item will be inserted in Stack
    //Returns Iterator at item
    T pop();
    //Postcondition: top item will be removed fronm Stack
    //Returns removed item
    T top();
    //Returns top of the Stack
    bool empty()const;
    //Returns true if list is empty

    //overloading insertion operator
    friend ostream& operator <<(ostream& outs, const Stack<T>& s)
    {
        outs<<"[F]";
        for(Iterator it=s.begin(); it!=s.end(); it++)
        {

            outs<< "<-[" << *it <<"]";
        }
        outs << "<-[END]";
        return outs;
    }
private:
    node<T>* _top;
};

//=========================Definition================================

template <typename T>
Stack<T>::Stack():_top(NULL)
{
    //blank
}

template<typename T>
Stack<T>::Stack(const Stack<T>& copy_this)
{
     //2. dealloate existing space;
    _top = copy_list(copy_this._top);
}

template<typename T>
Stack<T>& Stack<T>::operator =(const Stack& rhs)
{
    //1. check for self-reference
    if (this == &rhs)
    {
        return *this;
    }
    //2. dealloate existing space;
    clear_list(_top);

   //3. allocate space and copy everything over
   _top = copy_list(rhs._top);

    //4. return this object
    return *this;
}

template<typename T>
Stack<T>::~Stack()
{
    clear_list(_top);
//dealloate existing space;
}

template<typename T>
typename Stack<T>:: Iterator Stack<T>::begin()const
{
    return Iterator(_top);
}

template<typename T>
typename Stack<T>:: Iterator Stack<T>::end()const
{
    return Iterator(NULL);
}

template<typename T>
typename Stack<T>:: Iterator Stack<T>::push(const T& item)
{
    if(_top == NULL)
    {
        return Iterator(_insert_head(_top,item));
    }
    else
    {
        return Iterator(_insert_after(_top,last_node(_top),item));
    }
}
template<typename T>
T Stack<T>::pop()
{
    assert(!empty());

    return _delete_node(_top,last_node(_top));
}

template<typename T>
T Stack<T>::top()
{
    assert(_top);
    return (last_node(_top))->_item;
}


template<typename T>
bool Stack<T>::empty()const
{
    if(_top == NULL)
        return true;
    else
        return false;
}



#endif // STACK_H
