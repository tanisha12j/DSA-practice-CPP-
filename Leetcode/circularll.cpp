#include <bits/stdc++.h>

using namespace std;

struct Node

{

    int data;

    struct Node *next;

}*Head=NULL;

 

void create(int a[],int n)

{

    struct Node *t,*last;

    Head=new Node;

    Head->data=a[0];

    Head->next=Head;

    last=Head;

  

        for(int i=1;i<n;i++)

        {

           t=new Node;

    t->data=a[i];

    t->next=last->next;

    last->next=t;

    last=t;

        }

}

 

int count(struct Node *p)

{

    int c=0;

    do

    {

        c++;

     p=p->next;

    }while(p!=Head);

    return c;

}

 

void insert(int pos, int x)

{

    if(pos>count(Head) || pos<0)

    return;

    struct Node *t,*p=Head;

    t=new Node;

    t->data=x;

    if(pos==0)

    {

        if(Head==NULL)

        {

            Head=t;

            Head->next=t;

        }

        while(p->next!=Head)

        p=p->next;

        t->next=Head;

        p->next=t;

        Head=t;

    }

    else{

        for(int i=0;i<pos-1;i++)

            p=p->next;

            t->next=p->next;

            p->next=t;

    }

}

 

int Delete(struct Node *p,int index)

{

    struct Node *q;

    int x=-1;

    if(index<1 || index>count(Head))

    return x;

     if(index==1)

    {

        x=p->data;

         while(p->next!=Head)

        p=p->next;

        if(Head==p)

        {

            delete Head;

            Head=NULL;

        }

        else

        {

        p->next=Head->next;

        delete Head;

        Head=p->next;

        }

        return x;

    }

    else

    {

    for(int i=0;i<index-2;i++)

    {

        p=p->next;

    }

    q=p->next;

    p->next=q->next;

    x=q->data;

    delete q;

    return x;

    }

}

void display(struct Node *p)

{

    do

    {

        cout<<p->data<<" ";

        p=p->next;

    }while(p!=Head);

}

 

int circularlist()

{

    int a[500];

    int option,n,pos,x,index,t;

    do

    {

        cout<<"1. Create Circular Linked list"<<endl<<"2. Insert in Circular Linked list"<<endl<<"3. Delete "<<endl<<"4. Display"<<endl<<"5. Exit"<<endl;;

        cout<<"Enter an option :"<<endl;

        cin>>option;

        switch(option)

        {

        case 1 :

        {

            cout<<"Enter no of integers : "<<endl;

            cin>>n;

            cout<<"Enter the numbers"<<endl;

            for(int i=0;i<n;i++)

            cin>>a[i];

            create(a,n);

            cout<<endl;

            break;

        }

        case 2:

        {

            cout<<"Enter position to insert an element : "<<endl;

            cin>>pos;

            cout<<"Enter element : "<<endl;

            cin>>x;

            insert(pos,x);

            cout<<endl;

            break;

        }

        case 3:

        {

            cout<<"Enter position to delete element : "<<endl;

            cin>>index;

            cout<<"Deleted element is: "<<Delete(Head,index);

            cout<<endl;

            break;

        }

        case 4:

        {

            cout<<"Displaying elements :";

            display(Head);

            cout<<endl;

            break;

        }

        default:

        cout<<"Exiting program......"<<endl;

        }

    }while(option<=4);

    return 0;

}

