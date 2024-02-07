//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    // int MCM(int arr[],int n,vector<vector<int>>&dp)
    // {
    //     for(int i=1;i<=n;i++)
    //     {
    //         for(int j=i;j<=n;j++)
    //         {
    //             if(i==j)
    //             {
    //                 dp[i][j]=0;
    //             }
    //             else
    //             {
    //                 int mini=1e9;
    //                 for(int k=i;k<=j-1;k++)
    //                 {
    //                     mini=min((dp[i][k]+dp[k+1][j]+(arr[i-2]*arr[k-1]*arr[j-1])),mini);
    //                 }
    //                 dp[i][j]=mini;
    //             }
    //         }
    //     }
    //     return 0;
    // }
    int mcm(int arr[],int i,int j,vector<vector<int>>&dp)
    {
        if(i==j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mini=1e9;
        for(int k=i;k<j;k++)
        {
            //cout<<"hi"<<" ";
            int p=mcm(arr,i,k,dp);
            int np=mcm(arr,k+1,j,dp);
            mini=min(mini,p+np+(arr[i-1]*arr[k]*arr[j]));
        }
        return dp[i][j]=mini;
    }
    
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        vector<vector<int>>dp(N+1,vector<int>(N+1,-1));
        return mcm(arr,1,N-1,dp);
        //return 0;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends