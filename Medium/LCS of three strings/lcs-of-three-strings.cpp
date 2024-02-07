//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int checklcs(string &a,string &b,string &c,int n,int m,int p,int i,int j,int k,
    vector<vector<vector<int>>>&dp)
    {
        if(i>=n or j>=m or k>=p) return 0;
        int pick=0,notpick=0;
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        if(a[i]==b[j] and b[j]==c[k])
        {
            pick=1+checklcs(a,b,c,n,m,p,i+1,j+1,k+1,dp);
        }
        else
        {
            int q=checklcs(a,b,c,n,m,p,i+1,j,k,dp);
            int w=checklcs(a,b,c,n,m,p,i,j+1,k,dp);
            int e=checklcs(a,b,c,n,m,p,i,j,k+1,dp);
            notpick+=max(q,max(w,e));
        }
        return dp[i][j][k]=max(pick,notpick);
    }
    int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
    {
            // your code here
            vector<vector<vector<int>>>dp(n1,vector<vector<int>>(n2,vector<int>(n3,-1)));
            return checklcs(A,B,C,n1,n2,n3,0,0,0,dp);
            
    }
};




//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        Solution obj;
        cout << obj.LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends