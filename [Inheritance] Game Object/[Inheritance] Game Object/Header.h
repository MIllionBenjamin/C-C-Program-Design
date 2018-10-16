//
//  Header.h
//  [Inheritance] Game Object
//
//  Created by MillionBenjamin on 2018/6/18.
//  Copyright © 2018年 中山大学. All rights reserved.
//

#ifndef Header_h
#define Header_h

#include <iostream>
#include <sstream>
using namespace std;

class gameobject
{
private:
    double x;
    double y;
    double dx;
    double dy;
    int atk=1;
    int hp=10;
public:
    gameobject()
    {
        x=0;
        y=0;
        dx=0;
        dy=0;
    };
    gameobject(double _x, double _y, double _dx, double _dy)
    {
        x=_x;
        y=_y;
        dx=_dx;
        dy=_dy;
    };
    int get_hp()
    {
        return hp;
    };
    void sethp(int _hp)
    {
        hp=_hp;
    }
    void setatk(int _atk)
    {
        atk=_atk;
    };
    void movepos()
    {
       x+=dx;
       y+=dy;
    };
    double getx()
    {
        return x;
    };
    double gety()
    {
        return y;
    }
    virtual void select()=0;
    virtual void move()=0;
    virtual void attack(gameobject* G)
    {
                G->sethp(G->get_hp()-1);
    };
};

class zealot: public gameobject
{
private:
public:
    zealot(): gameobject()
    {
    };
    zealot(double _x, double _y): gameobject(_x, _y, 2, 2)
    {
    };
    virtual void select()
    {
        cout<<"My life for Aiur!"<<endl;
    };
    virtual void move()
    {
        movepos();
        cout<<"Zealot moves to ("<<getx()<<", "<<gety()<<")"<<endl;
    };
    virtual void attack(gameobject* G)
    {
        G->sethp(G->get_hp()-1);
    };
};
class tower: public gameobject
{
private:
public:
    tower(): gameobject(){};
    tower(double _x, double _y): gameobject(_x, _y, 0, 0)
    {
    };
    virtual void select()
    {
        cout<<"~"<<endl;
    };
    virtual void move()
    {
        movepos();
        cout<<"Tower cannot move"<<endl;
    };
    virtual void attack(gameobject* G)
    {
        G->sethp(G->get_hp()-1);
    };
};
class worker: public gameobject
{
private:
public:
    worker(): gameobject()
    {
    };
    worker(double _x, double _y): gameobject(_x, _y, 1, 1)
    {
    };
    virtual void select()
    {
        cout<<"Scv good to go, sir!"<<endl;
    };
    virtual void move()
    {
        movepos();
        cout<<"Worker moves to ("<<getx()<<", "<<gety()<<")"<<endl;
    };
    virtual void attack(gameobject* G)
    {
        G->sethp(G->get_hp()-1);
    };
    void repair(gameobject* G)
    {
        G->sethp(10);
    }
    void build(int h)
    {
        int i;
        int j;
        int k,m,n;
        j=2*h-1;
        for(i=1;i<=h;i++)
        {
            k=2*i-1;
            for(m=1;m<=j;m++)
            {
                if(m<=(j-k)/2)
                    cout<<" ";
                else
                    if(m>=(j-k)/2+1&&m<=(j-k)/2+k)
                    cout<<"*";
                    else
                    cout<<" ";
            }
            cout<<endl;
        }
    }
};
#endif /* Header_h */
