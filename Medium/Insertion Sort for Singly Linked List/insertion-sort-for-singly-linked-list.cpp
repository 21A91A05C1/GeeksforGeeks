//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};

/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}




// } Driver Code Ends
//User function Template for C++

/*Link list node
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

class Solution
{
    public:
    // Node* merge(Node* n1,Node* n2)
    // {
    //     Node* head1=NULL;
    //     Node* temp=head1;
    //     while(n1!=NULL and n2!=NULL)
    //     {
    //         if(n1->data > n2->data)
    //         {
    //             temp->next=n2;
    //             temp=temp->next;
    //             n2=n2->next;
    //         }
    //         else
    //         {
    //             temp->next=n1;
    //             temp=temp->next;
    //             n1=n1->next;
    //         }
    //     }
    //     if(n1) temp=n1;
    //     else temp=n2;
        
    //     return head1->next;
    // }
    // Node* hairAndTortoise(Node* head)
    // {
    //     Node* slow=head;
    //     Node* fast=head->next;
    //     while(fast and fast->next)
    //     {
    //         fast=fast->next->next;
    //         slow=slow->next;
    //     }
    //     return slow;
    // }
    Node* insertionSort(struct Node* head)
    {
        //code here
        // if(head==NULL || head->next==NULL) return head;
        // Node* middle=hairAndTortoise(head);
        // Node* left=insertionSort(head);
        // Node* right=insertionSort(middle->next);
        
        // return merge(left,right);
        
        
        
        vector<int>arr;
        while(head)
        {
            arr.push_back(head->data);
            head=head->next;
        }
        sort(arr.begin(),arr.end());
        Node* head1=new Node(-1);
        Node* prev=head1;
        for(auto it:arr)
        {
            Node* temp=new Node(it);
            prev->next=temp;
            prev=prev->next;
        }
        return head1->next;
        
    }
    
};

//{ Driver Code Starts.
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int n;
		cin >> n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < n; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

        Solution ob;

		head = ob.insertionSort(head);
		printList(head);

		cout << "\n";



	}
	return 0;
}
// } Driver Code Ends