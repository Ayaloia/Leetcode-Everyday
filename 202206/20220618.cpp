//
// Created by aldlss on 2022/6/18.
//

//剑指 Offer II 029. 排序的循环链表
//循环，还好，就是有些地方可能要特殊处理
//一般来说，如果写出一个在特殊情况不用特判就能应对的程序的话
//我会爽死，这次似乎是写出来了

#include<bits/stdc++.h>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if(!head)
        {
            head=new Node(insertVal);
            head->next=head;
            return head;
        }
        Node* i;
        for(i=head;;i=i->next)
        {
            int temp=i->next->val;
            if((temp>=insertVal&&insertVal>=i->val)||(i->val>temp&&(insertVal>=i->val||insertVal<=temp)))
            {
                i->next=new Node(insertVal,i->next);
                return head;
            }
            if(i->next==head)break;
        }
        i->next=new Node(insertVal,i->next);//可能所有数组都是一个数会触发这个
        return head;
    }
};