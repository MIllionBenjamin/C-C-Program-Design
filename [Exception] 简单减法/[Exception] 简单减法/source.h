//
//  source.h
//  [Exception] 简单减法
//
//  Created by MillionBenjamin on 2018/7/3.
//  Copyright © 2018年 中山大学. All rights reserved.
//

#ifndef source_h
#define source_h

#include <iostream>
#include <stdexcept>
using namespace std;

int calc(int a, int b) throw(logic_error)
{
    if (a<0) throw out_of_range("Out of range exeception");
        else if (b<0) throw out_of_range("Out of range exeception");
            else if (a<b) throw logic_error("Minuend smaller than subtrahend");
                return a-b;
}
void test(int a, int b)
{
    try
    {
        int x;
        x=calc(a, b);
        cout<<x<<endl;
    }
    catch(out_of_range ex)
    {
        cout << ex.what() << endl;
    }
    catch(logic_error ex2)
    {
        cout << ex2.what() << endl;
    }
}

#endif /* source_h */
