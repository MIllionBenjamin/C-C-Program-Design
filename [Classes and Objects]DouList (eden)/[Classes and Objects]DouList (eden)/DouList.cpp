//
//  DouList.cpp
//  [Classes and Objects]DouList (eden)
//
//  Created by MillionBenjamin on 2018/6/8.
//  Copyright © 2018年 中山大学. All rights reserved.
//

#include "DouList.h"
DouList::DouList()
{
    m_head=NULL;
    m_tail=NULL;
}
DouList::DouList(const DouList &src)
{
    if (src.m_head == NULL)
    {
        m_head = NULL;
        m_tail = NULL;
    }
    else
    {
        m_head = new DouListNode;
        m_head->elem=src.m_head->elem;
        DouListNode *current = m_head;
        DouListNode *other = src.m_head->next;
        while (other!=NULL)
        {
            current->next = new DouListNode;
            current->next->elem=other->elem;
            other = other->next;
            current->prev = current;
            current = current->next;
        }
    }
}
DouList::~DouList()
{
    clear();
}
void DouList::clear()
{
    DouListNode *p;
    p=m_head;
    while(m_head!=NULL)
    {
        p=m_head;
        m_head=m_head->next;
        delete p;
    }
}
bool DouList::empty() const
{
    if(m_head!=NULL)
        return false;
    else
        return true;
}
std::string DouList::to_str() const
{
    DouListNode *current;
    std::string s = "[";
    if (m_head != NULL)
    {
        current = m_head->next;
        s += std::to_string(m_head->elem);
        while (current != NULL)
        {
            s += ", ";
            s += std::to_string(current->elem);
            current = current->next;
        }
        s += "]";
    }
    else
    {
        s += "]";
    }
    return s;
}
int DouList::front() const
{
    if (m_head!=NULL)
        return m_head->elem;
    else
        return -1;
}
int  DouList::back() const
{
    if(m_tail!=NULL)
        return m_tail->elem;
    else
        return -1;
}
void DouList::push_front(const int &e)
{
    if(empty())
    {
        m_head=new DouListNode(e);
        m_tail=m_head;
        return;
    }
    DouListNode *p=new DouListNode(e);
    DouListNode *p2=m_head;
    p->next=p2;
    m_head=p;
}
void DouList::push_back(const int &e){
    DouListNode *toPush = new DouListNode(e,m_tail,0);
    if(empty()) m_head = m_tail = toPush;
    else m_tail->next = toPush;
    m_tail = toPush;
}
void DouList::pop_front()
{
    if(m_head==NULL)
        return;
    DouListNode *p=m_head;
    m_head=m_head->next;
    delete p;
    p=NULL;
}
void DouList::pop_back() {
    if (!this->m_tail)
        return;
    DouListNode *tmp;
    tmp = this->m_tail;
    this->m_tail = this->m_tail->prev;
    this->m_tail->next = NULL;
    //this->m_head == this->m_tail ? NULL : this->m_head;
    delete tmp;
}

DouList& DouList::operator = (const DouList &src) {
    if (m_head != src.m_head)
        clear();
    else
        return *this;
    if (src.m_head == NULL)
        this->m_head = m_tail = NULL;
    else {
        this->m_head = new DouListNode(src.m_head->elem);
        //this->m_tail = new DouListNode(src.m_tail->elem);
        DouListNode *current = this->m_head;
        DouListNode *other = src.m_head->next;
        while (other) {
            current->next = new DouListNode(other->elem);
            other = other->next;
            current->prev = current;
            current = current->next;
        }
    }
    return *this;
}

std::ostream& operator << (std::ostream & os, const DouList& list) {
    os<<list.to_str();
    return os;
}
