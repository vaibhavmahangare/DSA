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

        ~Node() //Destructor
        {
            int value =this->data;
            if(this->next!=NULL)
            {
                delete next;
                this->next=NULL;
            }
            cout<<"Memory is now free with data"<<value<<endl;
        }
};

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

void InsertAtHead(Node* &head,int data)
{
    Node* temp = new Node(data);
    temp->next = head;
    head=temp;
}


void InsertAtTail(Node* &tail,int data)
{
    Node* temp = new Node(data);
    tail->next = temp;
    tail=temp;

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


void DeleteNode(int position, Node* &head)
{
    //deleting first node
    if(position==1)
    {
        Node* temp=head;
        head=head->next;


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
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
       

}

int main()
{
    //create a node
    Node* node1=new Node(10);

    //point head & tail to node1
    Node* head=node1;
    Node* tail=node1;

    PrintList(head);

    cout<<head->data<< " " <<tail->data<<endl;
    InsertAtHead(head,12);

    PrintList(head);

    cout<<head->data<< " " <<tail->data<<endl;

    InsertAtTail(tail,15);

    PrintList(head);

    cout<<head->data<< " " <<tail->data<<endl;

    InsertATPosition(2,20,head,tail);
    PrintList(head);

    cout<<head->data<< " " <<tail->data<<endl;

    DeleteNode(1,head);
    PrintList(head);
    cout<<head->data<< " " <<tail->data;
    return 0;
}