# include <bits/stdc++.h>

using namespace std;

class Stack{
    public:
    int top;
    int *arr;
    int size;

    Stack(int size)
    {
        arr= new int[size];
        this->size = size;
        top=-1;
    }

    //functions
    void push(int data){

        if(size-top > 1)
        {

            //space avaliable for push
            top++;
            arr[top]=data;
        }
        else
        {
            //Spae not avaliable
            cout<<"Stack Overflow!!\n";
        }
    }

    void pop(){
        if(top==-1)
        {
            //Stack empty
            cout<<"Stack Underflow, can't delete element!!\n";
        }
        else
        {
            //Stack is not empty
            top--;
        }
    }

    int getTop(){
        if(top==-1)
        {
            //Stack empty
            cout<<"Stack is Empty!!\n";
        }
        else
        {
            return arr[top];
        }
    }

    int getSize(){

        return top+1;
    }

    bool isEmpty(){
        if(top==-1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    Stack s(5);

    //Insertion 
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    while (!s.isEmpty())
    {
        cout<<s.getTop()<<" ";
        s.pop();
    }
    

    return 0;
}