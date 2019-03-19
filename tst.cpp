#include<iostream>

using namespace std;
class MinStack {
   
public:
    /** initialize your data structure here. */
     struct Node{
      double num;
      Node *next;
      Node *nextbig;
    };
    Node *head;
    Node *tail;
    Node *min;
    double min;

    MinStack() {
        Node node;
        head=&node;
        tail=&node;
        min=node.num;
    }
    
    void push(int x) {
        Node *p;
        p->num=x;
        p->next=nullptr;
        tail->next=p;
        if(min>x)
        
    }
    
    void pop() {
        Node *p=tail;
        tail=tail->next;
        delete p;
    }
    
    int top() {
        
    }
    
    int getMin() {
        
    }
};