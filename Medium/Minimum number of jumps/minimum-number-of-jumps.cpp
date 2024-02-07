//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        int l=0,r=0,ans=0;
        while(r<n-1)
        {
            int far=0;
            for(int i=l;i<=r;i++)
            {
                
                if(i+arr[i]>far) far=i+arr[i];
            }
            // cout<<far<<" ";
            if(far==0) return -1;
            // cout
            ans++;
            l=r+1;
            r=far;
            
        }
        return ans;
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends