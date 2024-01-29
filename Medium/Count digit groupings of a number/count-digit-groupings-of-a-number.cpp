//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    // long long check(string &m)
    // {
    //     long long p=stoll(m);
    //     long long c=0;
    //     while(p>0)
    //     {
    //         int r=p%10;
    //         c+=r;
    //         p=p/10;
    //     }
    //     return c;
    //     // return 0;
    // }
    int checkValid(string &s,int j,int n,long long prev,vector<vector<int>>&dp)
    {
        if(j==n){
            return 1;
        }
        long long cur=0;
        int ans=0;
        if(dp[j][prev]!=-1) return dp[j][prev];
        for(int i=j;i<n;i++)
        {
            cur+=(s[i]-'0');
            if(cur>=prev)
            {
                ans+=checkValid(s,i+1,n,cur,dp);
            }
        }
        return dp[j][prev]=ans;
    }
	public:
	int TotalCount(string str){
	    int n=str.size();
	    int ans=0;
	    //vector<vector<int>>dp(n+1,vector<int>(50,-1));
	    vector<vector<int>>dp(n,vector<int>(901,-1));
	    return checkValid(str,0,n,0,dp);
	    //return ans;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution ob;
		int ans = ob.TotalCount(str);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends