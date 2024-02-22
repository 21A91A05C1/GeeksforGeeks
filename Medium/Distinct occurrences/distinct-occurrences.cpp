//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
/*You are required to complete this method*/

class Solution
{
    public:
    int mod=1e9+7;
    long long checkDistinct(string &s,string &t,long long n,long long m,long long i,long long j,string &p,
    vector<vector<long long>>&dp)
    {
        if(i>=n or j>=m) {
            if(p==t) return 1;
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j]%mod;
        long long pick=0,notpick=0;
        if(s[i]==t[j]){
            pick=checkDistinct(s,t,n,m,i+1,j+1,p+=s[i],dp);
            p.pop_back();
        }
        notpick=checkDistinct(s,t,n,m,i+1,j,p,dp);
        
        return dp[i][j]=(pick+notpick)%mod;
    }
    int subsequenceCount(string s, string t)
    {
      //Your code here
      long long n=s.size(),m=t.size();
      string p="";
      vector<vector<long long>>dp(n+1,vector<long long>(m+1,-1));
      return checkDistinct(s,t,n,m,0,0,p,dp)%mod;
    }
};
 


//{ Driver Code Starts. 

//  Driver code to check above method
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;
		
		Solution ob;
		cout<<ob.subsequenceCount(s,tt)<<endl;
		
		
	}
  
}
// } Driver Code Ends