//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution{
    public:
    long long findMaxAmt(int i,int j,int arr[],int c,vector<vector<int>>&dp)
    {
        if(i==j){
            if(c==0) return arr[i];
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        long long pickleft=0,pickright=0;
        if(c==0) pickleft=arr[i]+findMaxAmt(i+1,j,arr,1,dp);
        else pickleft=min(findMaxAmt(i+1,j,arr,0,dp),findMaxAmt(i,j-1,arr,0,dp));
        if(c==0) pickright=arr[j]+findMaxAmt(i,j-1,arr,1,dp);
        else pickright=min(findMaxAmt(i,j-1,arr,0,dp),findMaxAmt(i+1,j,arr,0,dp));
        
        // cout<<max(pickleft,pickright)<<" ";
        return dp[i][j]=max(pickleft,pickright);
    }
    long long maximumAmount(int n, int arr[]){
        // Your code here
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return findMaxAmt(0,n-1,arr,0,dp);
    }
};

//{ Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(n,a)<<endl;
	}
	return 0;
}
// } Driver Code Ends