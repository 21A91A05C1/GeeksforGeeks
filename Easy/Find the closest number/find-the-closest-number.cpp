//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int findClosest( int n, int k,int arr[]) 
    { 
        // Complete the function
        int l=upper_bound(arr,arr+n,k)-arr;
        // int u=lower_bound(arr,arr+n,k)-arr;
        int r=abs(arr[l]-k);
        int t=abs(arr[l-1]-k);
        if(r<=t){
            return arr[l];
        }
        else return arr[l-1];
        // return u;
    } 
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.findClosest(n,k,arr)<<endl;
    }
}

// } Driver Code Ends