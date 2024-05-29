//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findGeekWinner(int n,int x,int y,int s,int turn,vector<int>&dp)
    {
        if(s>=n) return 0;
        // if((n-s==1 or n-s==x or n-s==y) ){
        //     cout<<turn<<" ";
        //     return turn;
        // }
        if(dp[s]!=-1) return dp[s];
        int one=0,xx=0,yy=0;
        if((s+1)<=n){
            one=1+findGeekWinner(n,x,y,s+1,!turn,dp);
        }
        if((s+x)<=n){
            xx=1+findGeekWinner(n,x,y,s+x,!turn,dp);
        }
        if((s+y)<=n){
            yy=1+findGeekWinner(n,x,y,s+y,!turn,dp);
        }
        if(one%2 or yy%2 or xx%2){
            return dp[s]=1;
        }
        return dp[s]=0;
    }
    int findWinner(int n, int x, int y) 
    {
        // vector<vector<int>>dp(n+1,vector<int>(3,-1));
        vector<int>dp(n+1,-1);
        return findGeekWinner(n,x,y,0,1,dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        int y;
        scanf("%d", &y);

        Solution obj;
        int res = obj.findWinner(n, x, y);

        cout << res << endl;
    }
}

// } Driver Code Ends