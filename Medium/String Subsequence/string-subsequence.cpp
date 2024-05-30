//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int mod=1e9+7;
    int noOfStrings(string &s1,string &s2,int i,int j,vector<vector<int>>&dp)
    {
        if(i>=s1.size()) return 1;
        if(j>=s2.size()) return 0;
        int pick=0,notpick=0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]){
            pick=noOfStrings(s1,s2,i+1,j+1,dp);
        }
        notpick=noOfStrings(s1,s2,i,j+1,dp);
        return dp[i][j]=(pick+notpick)%mod;
    }
    int countWays(string s1, string s2) {
        int n=s2.size(),m=s1.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return noOfStrings(s2,s1,0,0,dp)%mod;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        Solution obj;
        int res = obj.countWays(s1, s2);

        cout << res << endl;
    }
}

// } Driver Code Ends