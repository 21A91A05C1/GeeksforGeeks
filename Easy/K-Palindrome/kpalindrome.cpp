//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    // int check(string &s1,string &s2,int i,int j,int )
    int kPalindrome(string str, int n, int k)
    {
        // code here
        string s=str;
        reverse(str.begin(),str.end());
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        // return check(str,n-1,0,k,0,0,dp);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(str[i-1]==s[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        int m=dp[n][n];
        return (n-m)<=k?1:0;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.kPalindrome(str, n, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends