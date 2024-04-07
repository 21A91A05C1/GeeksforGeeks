//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		
	public:
	int nihira(int n,int m,int arr[],int brr[],int i,int j,vector<vector<int>>&dp)
	{
	    if(i==n and j<m) return -1e9;
	    if(i>=n or j>=m){
	        return 0;
	    }
	    if(dp[i][j]!=-1) return dp[i][j];
	    int pick=0,notpick=0;
	    pick=arr[i]*brr[j]+nihira(n,m,arr,brr,i+1,j+1,dp);
	    
	    notpick=nihira(n,m,arr,brr,i+1,j,dp);
	    return dp[i][j]=max(pick,notpick);
	}
	int maxDotProduct(int n, int m, int a[], int b[]) 
	{ 
		// Your code goes here
		vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
		return nihira(n,m,a,b,0,0,dp);
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int a[n], b[m];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

        for(int i = 0; i < m; i++)
        	cin >> b[i];

       

	    Solution ob;
	    cout << ob.maxDotProduct(n, m, a, b) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends