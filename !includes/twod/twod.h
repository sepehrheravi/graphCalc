#ifndef TWOD_H
#define TWOD_H

#include <iostream>
using namespace std;

template<typename T>
T** allocate_2d(int* sizes);
//Precondition: sizes is the array of elements that is used for
//allocating space to 2D array
//Postcondition: creating a 2D dynamic array with the rows of numbers
//of elements in sizes pointer and the columns of the value of
//elements in sizes array
//returns the 2D array
template<typename T>
T* allocate_1d(int capacity);
//Precondition: capacity is the space that the new array is going to
//be allocated
//returns the array after being allocated the desired space
template<typename T>
T* read(T** dd, int row, int col);
//Precondition: row and col will be used to show the element in
//row row and column col in dd array to user
//returns the element in row row and column col
template<typename T>
void write(T** dd, int row, int col, T no);
//Precondition: row and col will be used to find the element in
//row row and column col in dd array and no is the
//element that we want replace instead of the element
//already existed in row row and column col
//Postcondition:no will be place in row row and column col instead of
//the previous element
template<typename T>
void print1d(T* sizes, int size_result);
//Precondition: size_result will be used for the size of our array
//Postcondtion: array sizes will be displayed
template<typename T>
void print2d(T** dd, int* sizes);
//Precondition: array sizes and elements inside it will be used for
//the size of our array
//Postcondtion: array dd will be displayed
template<typename T>
T* find_1d(T* p, const T& target, int size);
//Precondition: p is the pointer pointing at one dimensional array
//that we will search
//target is the element that we are looking for in the array
//size is the size of the array
//returns the address of the pointer where the element is found
template<typename T>
T* find_2d(T** dd, const T& target, int* sizes);
//Precondition: p is the pointer pointing at two dimensional array
//that we will search
//target is the element that we are looking for in the array
//sizes is the array of sizes we use to indicate size for each row
//returns the address of the pointer where the element is found
template<typename T>
int get_size(T* sizes);
//Precondition: sizes is the array that we want to know the size of
//returns the size of the sizes array
template<typename T>
void init_debug_1d(T* sizes, int size, int number);
//Precondition: size is the size of our array, number is the number
//that is used to set the elements to it
//Postcondition: initializes the elements in sizes array to different
//values
template<typename T>
void init_debug_2d(T** dd, int* sizes);
//Precondition: sizes is the sizes array that we use the size and
//elements in it for initializing the array
//Postcondition: initializes the elements in 2D dd array to different
//values
template<typename T>
void init_1d(T* sizes, int size, int number);
//Precondition: size is the size of our array, umber is the number
//that is used to set the elements to it
//Postcondition: initializes the elements of sizes array to 0
template<typename T>
void init_2d(T** dd, int* sizes);
//Precondition: sizes is the sizes array that we use the size and
//elements in it for initializing the array
//Postcondition: initializes the elements in 2D dd array to 0
void ask(int& row, int& col);
//Precondition: user is asked to enter row and col and
//Postcondition: row and col will be entered by user
template<typename T>
bool is_valid(T** dd, int* sizes, int row, int col);
//Precondition: row and col are input by user and sizes array will be
//used to find the number of rows and columns
//returns true if row and col are zero or greater than the actual
//number of rows and columns
template<typename T>
void deallocate_1d(int* sizes);
//Postcondition: sizes array will be deallocated
template<typename T>
void deallocate_2d(T** dd, int* sizes);
//Precondition: sizes array will be used to find the rows and columns
//Postcondition: dd array will be deallocated
template<typename T>
T* get(T** dd, int row, int col);
//Precondition: dd is the pointer pointing at out two D array
//row and col are the location that we look for the item there
//Returns the address of the element in row and col



//=================================================================






template<typename T>
T** allocate_2d(int* sizes)
{
    int size = get_size(sizes);    //find the sizes array's size
    T** array = new T*[size];      //allocates a 2D dynamic array
    T** w2d = array;       //w2d is the walker walks through 2D array
    for(int i=0; i<size; i++)
    {
       T* w1d = allocate_1d<T>(*sizes);//allocates a 1D dynamic array
         //with the size of elements in sizes array
        *w2d = w1d;        //pointer w1d's address is w2d's element
        sizes++;//increment sizes pointer so it points to next element
        w2d++;
        //increment double pointer w2d so it points at the next row
    }
    return array;
}

template<typename T>
T* allocate_1d(int capacity)
{
    return new T[capacity];         //allocates a 1D dynamic array
}

template<typename T>
bool is_valid(T** dd, int* sizes, int row, int col)
{
    T** w2d = dd;
    w2d += (row-1);        //w2d pointer points at the row-1 position
    T* w1d = *w2d;
    int size_col = get_size(w1d);
    int size_row = get_size(sizes);
    bool valid = false;
    if(row > size_row || row < 0 || col > size_col || col < 0)
    {
        valid = true;   //if all the size and col are not within the
        //range then it returns true
    }
    else
        valid = false; //if all the size and col are within the
    //range then it returns false
    return valid;
}

template<typename T>
T* get(T** dd, int row, int col)
{
    T** w2d = dd;        //double pointer w2d is a walker in dd array
    w2d += (row-1);      //w2d pointer points at the row-1 position
    T* w1d = *w2d;       //w1d pointer's adress is stored in w2d
    w1d += (col-1);      //w1d pointer points at col-1 position
    return w1d;
}

template<typename T>
T* read(T** dd, int row, int col)
{
    return get(dd, row, col); //returns the location of the element
}

template<typename T>
void write(T** dd, int row, int col, T no)
{

    T* w1d = get(dd, row, col);//w1d will be used to store the return
                               //pointer from get function

    *w1d = no; //the element that w1d points at will be replaced by no
}

template<typename T>
int get_size(T* sizes)
{
    T* w = sizes;                  //pointer w points at array sizes
    int count = 0;           //count is used to count the elements
    while(*w > 0) //while the pointer hasn't pointed at a negative
                    //element
    {
        count++;
        w++;             //increment count everytime pointer moves
    }
    return count;
}
template<typename T>
void print1d(T* sizes, int size_result)
{
    for(int i=0; i<size_result; i++)
    {
        cout << *sizes<< " ";  //prints the element pointer sizes is
                                //pointing at
        sizes++;         //move the pointer position to next element
    }
    cout << endl;
}

template<typename T>
void print2d(T** dd, int* sizes)
{
    T** w2d = dd;            //double pointer w2d points at array 2d
    
    int size = get_size(sizes);  //using function get size, find the
                                 //size of array sizes
    for (int i=0; i<size; i++)
    {
        T*  w1d = *w2d;  //pointer w1d address is stored in double
                         //pointer w2d
        print1d(w1d, *sizes);  //using print1d function point each row
                               //of array
        sizes++;  //move pointer sizes to next element in array sizes
        w2d++;  //increment double pointer w2d so it points at the
                //next row
    }
    
}
template<typename T>
T* find_1d(T* p, const T& target, int size)
{
    bool found = false;   //returns true if target found and false if

    while(!found && p < p + size)

    {
       if(*p == target)

           found = true;           //returns true if target is found
        else
            p++;        //continue to search if target is not found
    }
    if(found)
        return p;   //if the target get found it returns the address
                    //of the pointer
    else
        return nullptr;     //otherwise it keeps giong until it
                        //reaches the end and returns nullptr
}

template<typename T>
T* find_2d(T** dd, const T& target, int* sizes)
{
    T** w2d = dd;  //set w2d to point at dd array
    T* p = nullptr; //pointer p will be set to nullptr

    while(*sizes>0)     //stops before we reach the negative number
    {
        T* w1d = *w2d;    //w1d points at each row of array
        p = find_1d(w1d, target, *sizes); //search each row
        if(p != nullptr)
        {
            return p;  //returns p if the target is found
        }
        else
        {
            sizes++;  //move the pointer to next row
            w2d++;
        }
    }
    if(p != nullptr)
    {
        return p;   //if p is anything other than nullptr
    }
    else
    {
        return nullptr;    //means that we didn't find the item
    }
    return 0;

}



template<typename T>
void init_debug_1d(T* sizes, int size, int number)
{
    for(int i=0; i<size; i++)
    {
        *sizes = number;        //pointer sizes points at elements in
                        //sizes array and set their values to number
        number++;
   //increment number since we want different values for each element
        sizes++;                 //move the pointer to next element
    }
}

template<typename T>
void init_debug_2d(T** dd, int* sizes)
{
    
    int digit = 0;   //digit is the number that get multiplied by ten
                  //and indicates each row starts with what number ex:
                                    //10 11 12
                                    //20 21 22
    T** w2d = dd;            //double pointer w2d points at array 2d
    
    int size = get_size(sizes);
    for (int i=0; i<size; i++)
    {
        int number = 0;
        //number indicates the other columns elements using digit
        number += (10 * digit);  //each element's value
        T* w1d = *w2d;
        init_debug_1d(w1d, *sizes, number);
   //using function init_debug_1d all the values on each row to number
        sizes++;  //moves the pointer to next element in sizes array
                 //for columns
        w2d++;  //double pointer w2d moves to next element in dd array
        digit++;             //increments digit for next row
    }
    
}

template<typename T>
void init_1d(T* sizes, int size, int number)
{
    for(int i=0; i<size; i++)
    {
        *sizes = number;    //pointer sizes points at elements in
                          //sizes array and set their values to number
        sizes++;              //move the pointer to next element
    }
}

template<typename T>
void init_2d(T** dd, int* sizes)
{
    
    T** w2d = dd;           //double pointer w2d points at array 2d
    
    int size = get_size(sizes);
    for (int i=0; i<size; i++)
    {
        int number = 0;             //all the elements are gonna be 0
        T* w1d = *w2d;
        init_1d(w1d, *sizes, number);   //using function inti_1d
                        //initialize all the values on each row to 0
        sizes++;     //moves the pointer to next element in sizes
                    //array for columns
        w2d++;
    }           //double pointer w2d moves to next element in dd array
    
}

void ask(int& row, int& col)
{
    cout << "Enter row and column " << endl;
    cout << "row:";
    cin >> row;                     //user enters the number of rows
    cout << "column:";
    cin >> col;                 //user enters the number of columns
}


template<typename T>
void deallocate_1d(int* sizes)
{
    delete [] sizes;       //deallocates the space for sizes array
}

template<typename T>
void deallocate_2d(T** dd, int* sizes)
{
    T** w2d = dd;
    int size = get_size(sizes);
    for(int i=0; i<size; i++)
    {
        deallocate_1d<T>(*w2d);  //deallocates each row of dd array
        w2d++;                  //points to the next row
    }
    delete [] dd;       //deallocates the space for dd array
}


#endif // TWOD_H
