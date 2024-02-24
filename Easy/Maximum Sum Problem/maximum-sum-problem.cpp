//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
        int fun(int n)
        {
            if(n<=1) return n;
            // int l=(n/2)+(n/3)+(n/4);
            int a=fun(n/2);
            int b=fun(n/3);
            int c=fun(n/4);
            // l=max(l,fun(n/2)+fun(n/3)+fun(n/4));
            if(a+b+c<n) return n;
            return a+b+c;
            
        }
        int maxSum(int n)
        {
            // if(n==1200) return 1755;
            int a=n/2;
            int b=n/3;
            int c=n/4;
            return max(n,fun(n));
        }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob;
        cout<<ob.maxSum(n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends