//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};

void print(struct Node *Node)
{
    while (Node!=NULL)
    {
        cout << Node->data << " ";
        Node = Node->next;
    }
}


Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}


// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
};

*/
class Solution
{
    public:
    Node* reverse(Node* head){
        Node* pre = NULL;
        Node* temp = head;
        while(head != NULL){
            temp = temp->next;
            head->next = pre;
            pre = head;
            head = temp;
        }
        return pre;
    }
    struct Node* mergeResult(Node *node1,Node *node2)
    {
        Node* head = NULL;
        Node* temp = head;
        while(node1 != NULL and node2 != NULL){
            if(node1->data <= node2->data){
                if(head == NULL) head = temp = node1;
                else{
                    temp->next = node1;
                    temp = temp->next;
                }
                node1 = node1->next;
            }
            else{
                if(head == NULL) head = temp = node2;
                else{
                    temp->next = node2;
                    temp = temp->next;
                }
                node2 = node2->next;
            }
        }
        if(node1 == NULL){
            if(head == NULL) head = node2;
            else temp->next = node2;
        }
        if(node2 == NULL){
            if(head == NULL) head = node1;
            else temp->next = node1;
        }
        return reverse(head);
        // your code goes here
        // Node *prev1=node1;
        // Node *prev2=node2;
        // Node* cur1=prev1->next;
        // Node* cur2=prev2->next;
        // Node* next1=cur1->next;
        // Node* next2=cur2->next;
        // prev1->next=NULL;
        // prev2->next=NULL;
        // while(cur1!=NULL)
        // {
        //     next1=cur1->next;
        //     cur1->next=prev1;
        //     prev1=cur1;
        //     cur1=next1;
            
        // }
        // while(cur2!=NULL)
        // {
        //     next2=cur2->next;
        //     cur2->next=prev2;
        //     prev2=cur2;
        //     cur2=next2;
        // }
        
        
        // Node* ans=NULL;
        // Node* temp= NULL;
        // Node* p1=prev1;
        // Node* p2=prev2;
        // while(p1!=NULL and p2!=NULL)
        // {
        //     if(p1->data>=p2->data)
        //     {
        //         if(ans==NULL)
        //         {
                    
        //             temp=ans=p1;
        //             p1=p1->next;
        //         }
        //         else
        //         {
        //             //ans=p1;
        //             ans->next = p1;
        //             ans = ans->next;
        //             //ans->next=NULL;
        //             p1=p1->next;
        //             // ans->next=NULL;
        //         }
        //     }
        //     else
        //     {
        //         if(ans==NULL)
        //         {
        //             temp=ans=p2;
        //             //ans->next=NULL;
        //             p2=p2->next;
        //             // ans->next=NULL;
        //         }
        //         else
        //         {
        //             //ans=p1;
        //             ans->next = p2;
        //             ans = ans->next;
        //             //ans->next=NULL;
        //             p2=p2->next;
        //             // ans->next=NULL;
        //         }
        //     }
        // }
        // if(p1!=NULL)
        // {
        //     if(ans==NULL)
        //         {
        //             temp=ans=p1;
        //             //ans->next=NULL;
        //             // p1=p1->next;
        //             // ans->next=NULL;
        //         }
        //         else
        //         {
        //             //ans=p1;
        //             ans->next = p1;
        //             // ans = ans->next;
        //         }
        // }
        // if(p2!=NULL)
        // {
        //     if(ans==NULL)
        //         {
        //             temp=ans=p2;
        //             //ans->next=NULL;
        //             // p2=p2->next;
        //             // ans->next=NULL;
        //         }
        //         else
        //         {
        //             //ans=p1;
        //             ans->next = p2;
        //             // ans = ans->next;
        //             // //ans->next=NULL;
        //             // p2=p2->next;
        //             // ans->next=NULL;
        //         }
        // }
        Node* x = NULL;
        return x;
    }  
};


//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int nA;
        cin>>nA;
        int nB;
        cin>>nB;

        struct Node* headA=NULL;
        struct Node* tempA = headA;

        for(int i=0;i<nA;i++)
        {
            int ele;
            cin>>ele;
            if(headA==NULL)
            {
                headA=tempA=newNode(ele);

            }else{
                tempA->next = newNode(ele);
				tempA=tempA->next;
            }
        }

        struct Node* headB=NULL;
        struct Node* tempB = headB;


        for(int i=0;i<nB;i++)
        {
            int ele;
            cin>>ele;
            if(headB==NULL)
            {
                headB=tempB=newNode(ele);

            }else{
                tempB->next = newNode(ele);
				tempB=tempB->next;
            }
        }
        
        Solution ob;
        struct Node* result = ob.mergeResult(headA,headB);

        print(result);
        cout<<endl;


    }
}

// } Driver Code Ends