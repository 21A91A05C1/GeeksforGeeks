//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next, *prev;

    Node(int x) {
        data = x;
        next = NULL;
        prev = NULL;
    }
};


// } Driver Code Ends

/* Structure of the node of the list is as
struct Node
{
    int data;
    struct Node *next, *prev;
    Node (int x){
        data = x;
        next = prev = NULL;
    }
};
*/

class Solution {
  public:
    // Function to sort the given doubly linked list using Merge Sort.
    int findLength(Node* temp,vector<int>&arr)
    {
        int c=0;
        while(temp)
        {
            c++;
            arr.push_back(temp->data);
            temp=temp->next;
        }
        return c;
    }
    void Merge(vector<int>&arr,int low,int mid,int high)
    {
        int l=low,m=mid+1;
        vector<int>temp;
        while(l<=mid and m<=high){
            if(arr[l]<=arr[m]){
                temp.push_back(arr[l]);
                l++;
            }
            else{
                temp.push_back(arr[m]);
                m++;
            }
        }
        while(l<=mid){
            temp.push_back(arr[l]);
            l++;
        }
        while(m<=high){
            temp.push_back(arr[m]);
            m++;
        }
        for(int i=0;i<temp.size();i++)
        {
            arr[low++]=temp[i];
        }
        
    }
    void MergeSort(vector<int>&arr,int low,int high){
        
        if(low>=high) return ;
        // while(low<=high)
        // {
            int mid=(low+high)/2;
            MergeSort(arr,low,mid);
            MergeSort(arr,mid+1,high);
            Merge(arr,low,mid,high);
        // }/
    }
    
    struct Node *sortDoubly(struct Node *head) {
        // Your code here
        Node* temp=head;
        vector<int>arr;
        int n=findLength(temp,arr);
        // cout<<n<<" ";
        MergeSort(arr,0,n-1);
        // for(auto it:arr){
        //     cout<<it<<" ";
        // }
        int i=0;
        Node* ans=head;
        while(head){
            head->data=arr[i++];
            head=head->next;
        }
        return ans;
    }
};


//{ Driver Code Starts.

void insert(struct Node **head, int data) {
    struct Node *temp = new Node(data);
    if (!(*head))
        (*head) = temp;
    else {
        temp->next = *head;
        (*head)->prev = temp;
        (*head) = temp;
    }
}

void print(struct Node *head) {
    struct Node *temp = head;
    while (head) {
        cout << head->data << ' ';
        temp = head;
        head = head->next;
    }
    cout << endl;
    while (temp) {
        cout << temp->data << ' ';
        temp = temp->prev;
    }
    cout << endl;
}

// Utility function to swap two integers
void swap(int *A, int *B) {
    int temp = *A;
    *A = *B;
    *B = temp;
}

// Driver program
int main(void) {
    long test;
    cin >> test;
    while (test--) {
        int n, tmp;
        struct Node *head = NULL;
        cin >> n;
        while (n--) {
            cin >> tmp;
            insert(&head, tmp);
        }
        Solution ob;
        head = ob.sortDoubly(head);
        print(head);
    }
    return 0;
}

// } Driver Code Ends