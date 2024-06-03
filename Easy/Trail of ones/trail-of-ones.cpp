//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int mod=1e9+7;
    long long power(long long base,long long expp)
    {
        long long res=1;
        while(expp>0)
        {
            if(expp&1)
            {
                res=((res%mod)*(base%mod))%mod;
            }
            base=((base)%mod*(base)%mod)%mod;
            expp/=2;
        }
        return res%mod;
    }
    long long checkPossible(int n,int i,int prev,vector<vector<long long>>&dp)
    {
        if(i>=n){
            return 1;
        }
        long long pick=0,notpick=0;
        if(dp[i][prev]!=-1) return dp[i][prev];
        if(prev==0){
            pick=checkPossible(n,i+1,1,dp);
        }
        notpick=checkPossible(n,i+1,0,dp);
        dp[i][prev]=(pick+notpick)%mod;
        return dp[i][prev]%mod;
    }
    int numberOfConsecutiveOnes(int n) {
        // code here
        vector<vector<long long>>dp(n+1,vector<long long>(2,-1));
        long long ans=checkPossible(n,0,0,dp);
        long long p=power(2,n);
        return (p-ans+mod)%mod;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.numberOfConsecutiveOnes(N) << endl;
    }
    return 0;
}

// } Driver Code Ends