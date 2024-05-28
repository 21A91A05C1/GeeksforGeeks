//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int getMinCost(int n,int w,vector<int>&cost,int i,int s,vector<vector<int>>&dp)
    {
        if(s>w) return 1e9;
        if(s==w) return 0;
        if(i>=n){
            if(w==s){
                return 1e9;
            }
            else return 1e9;
        }
        if(dp[i][s]!=-1) return dp[i][s];
        int pick=1e9,notpick=1e9;
        if(s+i+1<=w)
            pick=cost[i]+getMinCost(n,w,cost,i,s+i+1,dp);
        
        notpick=getMinCost(n,w,cost,i+1,s,dp);
        
        return dp[i][s]=min(pick,notpick);
    }
    int minimumCost(int n, int w, vector<int> &cost) {
        // code here
        vector<vector<int>>dp(n+1,vector<int>(w+1,-1));
        int ans=getMinCost(n,w,cost,0,0,dp);
        return ans>0?ans:-1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int w;
        scanf("%d", &w);

        vector<int> cost(n);
        Array::input(cost, n);

        Solution obj;
        int res = obj.minimumCost(n, w, cost);

        cout << res << endl;
    }
}

// } Driver Code Ends