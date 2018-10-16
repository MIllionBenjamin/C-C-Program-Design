//
//  main.cpp
//  [Exception] Binary to decimal
//
//  Created by MillionBenjamin on 2018/7/3.
//  Copyright © 2018年 中山大学. All rights reserved.
//

#include <iostream>
#include "source.h"
using namespace std;

void f()
{
    try
    {
        cout << parseBinary("10001") << endl;
        cout << parseBinary("11111111") << endl;
        cout << parseBinary("21111111") << endl;
    }
    catch (runtime_error ex)
    {
        cout << ex.what() << endl;
    }
}

int main()
{
    f();
    return 0;
}

