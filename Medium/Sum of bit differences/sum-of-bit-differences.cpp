//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
// 	long long bitdiff(int n,int m)
// 	{
// 	    long long c=0;
// 	    for(int i=31;i>=0;i--)
// 	    {
// 	        if((n&(1<<i))!=(m&(1<<i))) c++;
// 	    }
// 	    return c;
// 	}
	long long sumBitDifferences(int arr[], int n) {
	    // code here
	    long long ans=0;
	    for(int j=0;j<=31;j++)
	    {
	        long long c=0,d=0;
    	    for(int i=0;i<n;i++)
    	    {
    	       if((arr[i]&(1<<j))==0) c++;
    	       else d++;
    	    }
    	    if((c==0 and d==n) or (c==n and d==0)) continue;
    	    else  ans+=((c*d)*2);
    	   // cout<<c<<" "<<d<<"  ";
	    }
	    return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.sumBitDifferences(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends