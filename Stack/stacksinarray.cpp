//Implementation of 2 stacks in a single array

# include <iostream>
using namespace std;

class Stack{

    public:
    int *arr;
    int top1;
    int top2;
    int size;

    Stack(int size)
    {
        this->size=size;
        arr = new int[size];
        top1=-1;
        top2=size;
    }

    void push1(int data){
        if(top2-top1==1)
        {
            cout<<"Stack Overflow\n";
        }
        else
        {
            top1++;
            arr[top1]=data;
        }
    }

    void push2(int data){
        if(top2-top1==1)
        {
            cout<<"Stack Overflow\n";
        }
        else
        {
            top2--;
            arr[top2]=data;
        }
    }

    void pop1(){

        if(top1==-1)
        {
            cout<<"Stack Underflow\n";
        }
        else
        {
            top1--;
        }
    }

    void pop2(){
        if(top2==size)
        {
            cout<<"Stack Underflow\n";
        }
        else
        {
            top2++;
        }
    }



    
};

int main()
{

    Stack s(10);
    //insertion

    s.push1(10);
    s.push1(20);
    s.push1(30);
    s.push1(40);

    s.push2(100);
    s.push2(90);
    s.push2(80);

    while(s.top1!=-1)
    {
        cout<<s.arr[s.top1]<<" ";
        s.pop1();
    }
    cout<<"\n";
    while(s.top2!=10)
    {
        cout<<s.arr[s.top2]<<" ";
        s.pop2();
    }

    return 0;
}