//
//  source.h
//  [Exception] Binary to decimal
//
//  Created by MillionBenjamin on 2018/7/3.
//  Copyright © 2018年 中山大学. All rights reserved.
//

#ifndef source_h
#define source_h

#include <math.h>
#include <stdexcept>
#include <string.h>
using namespace std;

int parseBinary(const char * const binaryString)
{
    int dec=0;
    int len;
    len=strlen(binaryString);
    for(int i=len-1;i>=0;i--)
    {
        if(binaryString[i]=='1'||binaryString[i]=='0')
        {
            switch (binaryString[i])
            {
                case '1':
                    dec+=pow(2,len-1-i);
                    break;
                default:
                    break;
            }
            continue;
        }
        else
        {
            runtime_error cao("Binary number format error");
            throw cao;
        }
    }
    return dec;
};

#endif /* source_h */
