#ifndef SORTED_LIST_H
#define SORTED_LIST_H

#include <iostream>
#include "../../!includes/node/node.h"

using namespace std;

template <typename T>
class Sorted_List
{
public:
    class Iterator
    {
    public:
        friend class Sorted_List;
        //give access to list to access _ptr

        Iterator(): _ptr(NULL)
        {
            //def ctor
        }

        Iterator(node<T>* p): _ptr(p)
        {
            //ctor
        }

        Iterator next()
        {
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

        const T& operator[](int index)const
        {
            assert(_ptr);
            //call at function
           return at(_ptr, index);
           //return item at index
        }

        //true if _ptr is NULL
        bool is_null()
        {
            return (_ptr == NULL);
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

       //member operator: ++it
        Iterator& operator++()
        {
           _ptr = _ptr->_next;
           return *this;
        }

        //friend operator: it++
        friend Iterator operator++(Iterator& it,int unused)
        {
            Iterator hold;
            hold = it;
            it.next();
            return hold;
        }

    private:
        node<T>* _ptr;
        //pointer being encapsulated
    };

    Sorted_List(bool order=true, bool unique=true);
    //defualt ctor
    //order is to see if sorted list is ascending/descending


    //Big 3
    ~Sorted_List();
    //dtor
    Sorted_List(const Sorted_List<T> &copyThis);
    //copy ctor
    Sorted_List& operator =(const Sorted_List& RHS);
    //assignment operator

    Iterator insert(const T& item);
    //Precondition: item is the item will be inserted
    //Postcondition: item will be inserted in sorted manner
    //Returns Iterator points at item
    T remove(Sorted_List<T>::Iterator mark);
    //Precondition: mark is Iterator pointing at node to delete
    //Postcondition: node gets deleted
    //Returns deleted item
    void print() const;
    //Postcondition: prints list
    Iterator search(const T &key) const;
    //Precondition: key to find at list
    //Return Iterator to node [key]
    Iterator prev(Iterator mark);
    //Precondition: mark is place where we want previous node to
    //Postcondition: get to previous node to mark
    //Returns Iterator to previous node
    Iterator next(Iterator mark);
    //Precondition: mark is place where we want next node to
    //Postcondition: get to next node to mark
    //Returns Iterator to next node
    const T& operator[](int index) const;
    //Precondition: index of the item in list
    //Return item at position index
    T& operator[](int index);
    //Precondition: index of the item in list
    //Return item at position index
    Iterator begin() const;
    //Returns Iterator to the head node
    Iterator end() const;
    //Returns Iterator points at NULL
    Iterator last() const;
    //Returns the Iterator pointing at the last node on list
    bool empty() const;
    //Returns true if list is empty


    //overloading insertion operator
    friend ostream& operator <<(ostream& outs, const Sorted_List<T>& l)
    {
    for(Iterator it=l.begin(); it!=l.end(); it++)
    {
        outs<< *it<<"|";
    }
    return outs;
    }
private:
    node<T>* _head_ptr;
    bool _order;
    bool _unique;
};

//=============================Definition============================

template <typename T>
Sorted_List<T>::Sorted_List(bool order, bool unique):_head_ptr(NULL),
    _order(order), _unique(unique)
{
    //blank
}

template<typename T>
Sorted_List<T>::Sorted_List(const Sorted_List<T>& copy_this)
{
     //2. dealloate existing space;
    _head_ptr = copy_list(copy_this._head_ptr);
}

template<typename T>
Sorted_List<T>& Sorted_List<T>::operator =(const Sorted_List& rhs)
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
Sorted_List<T>::~Sorted_List()
{
    clear_list(_head_ptr);
//dealloate existing space;
}


template<typename T>
typename Sorted_List<T>:: Iterator Sorted_List<T>::begin()const
{
    return Iterator(_head_ptr);
}

template<typename T>
typename Sorted_List<T>:: Iterator Sorted_List<T>::end()const
{
    return Iterator(NULL);
}


template<typename T>
typename Sorted_List<T>:: Iterator Sorted_List<T>::insert(const T& item)
{
    return Iterator(_insert_sorted_add(_head_ptr, item, _order, _unique));
}

template<typename T>
T Sorted_List<T>::remove(Sorted_List<T>::Iterator mark)
{
    return _delete_node(_head_ptr, mark._ptr);
}

template<typename T>
void Sorted_List<T>:: print()const
{
    _print_list(_head_ptr);
}

template<typename T>
typename Sorted_List<T>:: Iterator Sorted_List<T>::search(const T &key)
                                                            const
{
    return Iterator(_search_list(_head_ptr, key));
}

template<typename T>
typename Sorted_List<T>:: Iterator Sorted_List<T>::prev(Iterator mark)
{
    return Iterator(_previous_node(_head_ptr, mark._ptr));
}

template<typename T>
typename Sorted_List<T>:: Iterator Sorted_List<T>::next(Iterator mark)
{
    return Iterator(_next_node(_head_ptr, mark._ptr));
}

template<typename T>
typename Sorted_List<T>:: Iterator Sorted_List<T>::last()const
{
    return Iterator(last_node(_head_ptr));
}

template<typename T>
bool Sorted_List<T>::empty()const
{
    if(_head_ptr == NULL)
        return true;
    else
        return false;
}

template <typename T>
const T& Sorted_List<T>::operator[](int index)const
{
    //call at function
   return at(_head_ptr, index);
}

template <typename T>
T& Sorted_List<T>::operator[](int index)
{
    //call at function
   return at(_head_ptr, index);
}

#endif // SORTED_LIST_H
