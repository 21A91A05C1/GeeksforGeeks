//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    int maxPosPaths(int n,int k,int i,int j,vector<vector<int>>&arr,vector<vector<vector<int>>>&dp)
    {
        if(k<0) return 0;
        if(i<0 || j<0) return 0;
        if(i==0 and j==0)
        {
            if((k-arr[0][0])==0) return 1;
            return 0;
        }
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        int left=0,top=0;
        top=maxPosPaths(n,k-arr[i][j],i-1,j,arr,dp);
        left=maxPosPaths(n,k-arr[i][j],i,j-1,arr,dp);
        return dp[i][j][k]=left+top;
    }
    long long numberOfPath(int n, int k, vector<vector<int>> arr)
    {
        // Code Here
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(n+1,vector<int>(k+1,-1)));
        return maxPosPaths(n,k,n-1,n-1,arr,dp);
    }
};


//{ Driver Code Starts.

int main()
{
    Solution obj;
    int i,j,k,l,m,n,t;
    cin>>t;
    while(t--)
    {
        cin>>k>>n;
        vector<vector<int>> v(n+1, vector<int>(n+1, 0));
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                cin>>v[i][j];
        cout << obj.numberOfPath(n, k, v) << endl;
    }
}
// } Driver Code Ends