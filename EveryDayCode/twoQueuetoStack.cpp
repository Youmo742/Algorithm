/*
用两个队列模拟一个栈
 */
#include <iostream>
#include <queue>
using namespace std;

class Stack{
private:
    queue<int> *q1,*q2;
    //qu1 is empty
    int innerpop(queue<int> *qu1, queue<int> *qu2){
        while(qu2->size()>1){
            qu1->push(qu2->front());
            qu2->pop();
        }
        int value=qu2->front();
        qu2->pop();
        return value;
    }
public:
    Stack(){
        q1=new queue<int>();
        q2=new queue<int>();
    }
    int size(){
        return q1->size()+q2->size();
    }
    int insert(int value){
        if(q1->size()){
            q1->push(value);
        }
        else{
            q2->push(value);
        }
        return value;
    }
    int pop(){
        if(!(q1->size()||q2->size())){
            cout<<"empty stack"<<endl;
        }
        if(!q1->size()){
            return innerpop(q1,q2);
        }
        else{
            return innerpop(q2,q1);
        }
    }
};

int main(){
    Stack *s=new Stack();
    s->insert(4);
    s->insert(3);
    s->insert(2);
    while(s->size()){
        cout<<s->pop();
    }
    return 0;
}