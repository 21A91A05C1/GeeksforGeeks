//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    // Complete the function
	    map<int,int>mpp;
	    int ans=0,sum=0;
	    for(int i=0;i<n;i++)
	    {
	        sum+=arr[i];
	        if(sum%k==0) ans=max(ans,i+1);
	        int di=sum%k;
	        if(di<0) di+=k;
	        if(mpp.find(di)==mpp.end())
	        {
	            mpp[di]=i;
	        }
	        else 
	        {
	            int u=i-mpp[di];
	            ans=max(ans,u);
	        }
	    }
	    
	    return ans;
	   
	}
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}

// } Driver Code Ends