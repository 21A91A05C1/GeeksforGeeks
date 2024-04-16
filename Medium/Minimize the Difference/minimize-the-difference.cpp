//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int minimizeDifference(int n, int k, vector<int> &arr) {
        // code here
        vector<int>suffixMin(n,0),suffixMax(n,0);
        suffixMin[n-1]=arr[n-1];
        suffixMax[n-1]=arr[n-1];
        //storing the min and max at each and every position from the back end
        for(int i=n-2;i>=0;i--)
        {
            suffixMin[i]=min(suffixMin[i+1],arr[i]);
            suffixMax[i]=max(suffixMax[i+1],arr[i]);
        }
        int ans=1e9;
        int preMin=1e9,preMax=0;
        for(int i=0;i<n-k;i++)
        {
            int l=max(preMax,suffixMax[i+k])-min(preMin,suffixMin[i+k]);
            // cout<<l<<" ";
            ans=min(ans,l);
            preMin=min(preMin,arr[i]);
            preMax=max(preMax,arr[i]);
            
        }
        ans=min(ans,preMax-preMin);
        return ans;
        
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        int k;
        scanf("%d",&k);
        
        
        vector<int> arr(n);
        Array::input(arr,n);
        
        Solution obj;
        int res = obj.minimizeDifference(n, k, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends