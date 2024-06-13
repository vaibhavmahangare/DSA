# include<bits/stdc++.h>
using namespace std;

class Node{
        
        public:
        int data;
        Node* prev;
        Node* next;

        Node(int data){
            this->data = data;
            this->prev =NULL;
            this->next =NULL;
        }

        ~Node()
        {
            int val=this->data;
            if(next!=NULL)
            {
                delete next;
                next=NULL;
            }
            cout<<"Memory free for node with data "<<val<<endl;

        }

};

void print(Node* head)
{
    Node* temp=head;

    while(temp!=NULL)
    {
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }
    cout<<"NULL\n";
}

int getlength(Node* head)
{
    Node* temp=head;
    int len=0;
    while(temp!=NULL)
    {
       len++;
        temp=temp->next;
    }
    return len;
}

void InsertAtHead(Node* &head,Node* &tail,int data)
{
    if(head==NULL)
    {
        Node* temp=new Node(data);
        head=temp;
        tail=temp;


    }
    else{
    Node* temp=new Node(data);
    temp->next=head;
    head->prev=temp;
    head=temp;
    }
}

void InsertAtTail(Node* &head,Node* &tail,int data)
{
    if(tail==NULL)
    {
        Node* temp=new Node(data);
        tail=temp;
        head=temp;

    }
    else{
    Node* temp=new Node(data);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
    }
}

void InsertAtPosition(Node* &head,Node* &tail,int position,int data)
{
    if(position==1)
    {
        InsertAtHead(head,tail,data);
    }
    else
    {
        Node * temp=new Node(data);
        Node* ptr=head;

        int cnt=1;
        while(cnt<position-1)
        {
            ptr=ptr->next;
            cnt++;
        }

        if(ptr->next==NULL)
        {
            InsertAtTail(head,tail,data);
        }
        else{
            temp->next=ptr->next;
            temp->prev=ptr;
            ptr->next=temp;
            ptr->next->prev=temp;
        }

    }
}

void DeleteNode(int position, Node* &head)
{
    //deleting first node
    if(position==1)
    {
        Node* temp=head;
        temp->next->prev=NULL;
        head=temp->next;
        temp->next=NULL;
        delete temp;


        //free memory of start node
        temp->next=NULL;
        delete temp;
        
    }
    else
    {
        Node* curr=head;
        
        Node* prev=NULL;

        int cnt=1;
        while(cnt<position)
        {
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        curr->prev=NULL;
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
       

}

int main()
{
    Node* node1= new Node(10);
    

    Node* head=node1;
    Node* tail=node1;
    print(head);
    

    InsertAtHead(head,tail,15);
    print(head);

    InsertAtHead(head,tail,20);
    print(head);

    InsertAtHead(head,tail,25);
    print(head);

    InsertAtTail(tail,tail,5);
    print(head);

    InsertAtPosition(head,tail,3,18);
    print(head);
    InsertAtPosition(head,tail,7,0);
    print(head);
    



    return 0;
}