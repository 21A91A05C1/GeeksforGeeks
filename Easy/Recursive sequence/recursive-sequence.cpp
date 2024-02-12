//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int mod=1e9+7;
    long long sequence(int n){
        // code here
        long long ans=0;
        long long c=1;
        for(int i=1;i<=n;i++)
        {
            long long mul=1;
            long long e=i;
            while(e--)
            {
                mul=(mul%mod*c%mod)%mod;
                c++;
            }
            ans+=mul;
        }
        return ans%mod;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.sequence(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends