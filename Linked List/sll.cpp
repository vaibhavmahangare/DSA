# include <bits/stdc++.h>

using namespace std;

class Node{
    
    public:
        int data;
        Node* next;

        Node(int data)          //Constructor
        {
            this->data = data;
            this->next = NULL;
        }
};

void InsertAtHead(Node* &head,int data)
{
    Node* temp = new Node(data);
    temp->next = head;
    head=temp;
}

void PrintList(Node* &head)
{
    Node* temp=head;

    while(temp!=NULL)
    {
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }
    cout<<"Null\n";

}

void InsertAtTail(Node* tail,int data)
{
    Node* temp = new Node(data);
    tail->next = temp;
    tail=tail->next;

}

void InsertATPosition(int position,int data,Node*head,Node* tail)
{
    Node* temp=new Node(data);

    if(position==1)
    {
        InsertAtHead(head,data);
        return;
    }

    Node* ptr=head;
    for(int i=1;i<position-1;i++)
    {
        ptr=ptr->next;
    }

    if(ptr->next==NULL)
    {
        InsertAtTail(tail,data);
        return;
    }

    temp->next=ptr->next;
    ptr->next=temp;

}
int main()
{
    //create a node
    Node* node1=new Node(10);

    //point head & tail to node1
    Node* head=node1;
    Node* tail=node1;

    PrintList(head);

    InsertAtHead(head,12);

    PrintList(head);

    InsertAtTail(tail,15);

    PrintList(head);

    InsertATPosition(2,20,head,tail);
    PrintList(head);
    return 0;
}