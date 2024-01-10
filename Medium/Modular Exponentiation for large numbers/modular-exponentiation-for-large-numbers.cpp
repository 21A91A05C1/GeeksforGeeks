//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    //long long mod=1e18+7;
		long long int PowMod(long long int x,long long int n,long long int mod)
		{
		    // Code here
		    long long int ans=1;
		    while(n)
		    {
		        if(n&1)
		        {
		            n--;
		            ans=(ans)%mod*(x)%mod;
		        }
		        else
		        {
		            n/=2;
		            x=((x)%mod*(x)%mod)%mod;
		        }
		    }
		    return (ans%mod)%mod;
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	long long int x, n, m;
    	cin >> x >> n >> m;
    	Solution ob;
    	long long int ans = ob.PowMod(x, n, m);
    	cout << ans <<"\n";
    }
	return 0;
}

// } Driver Code Ends