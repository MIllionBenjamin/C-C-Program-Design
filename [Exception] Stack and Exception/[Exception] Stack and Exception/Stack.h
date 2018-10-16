//
//  Stack.h
//  [Exception] Stack and Exception
//
//  Created by MillionBenjamin on 2018/7/3.
//  Copyright © 2018年 中山大学. All rights reserved.
//

#ifndef Stack_h
#define Stack_h

#include <stdexcept>
#include <iostream>
using namespace std;

const int MAX_LEN = 5;

template<class T>

class Stack

{
    
public:
    
    explicit Stack()
    {
        stack_size=0;
        for(int i=0;i<5;i++)
            data[i]=T(0);
    };
    
    bool empty() const
    {
        if(stack_size==0)
            return true;
        else
            return false;
    };
    
    int size() const
    {
        return stack_size;
    };
    

    const T& top() const
    {
        if(stack_size==0)
        {
            runtime_error tp(int);
            throw -1;
        }
            else
                return data[stack_size-1];

    };
    
    void push(const T& x)
    {
        if(stack_size<5)
        {
            data[stack_size]=x;
            stack_size++;
        }
        else
            if(x>top())
                data[stack_size-1]=x;
    };
    
    void pop()
    {
        try
        {
        if(stack_size==0)
        {
            runtime_error pp(double);
            throw 1.1;
        }
        else
            stack_size--;
        }
        catch (double)
        {
            
            cout << "pop failed" << endl;
            
        }
    };
    
private:
    
    T data[MAX_LEN];
    
    int stack_size;
    
};


#endif /* Stack_h */
