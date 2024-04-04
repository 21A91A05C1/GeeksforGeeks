//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find sum of all possible substrings of the given string.
    long long mod=1e9+7;
    long long sumSubstrings(string s){
        
        // your code here
        long long ans=0;
        long long n =s.size();
        // long long ans=0;
        long long prev=0;
        for(int i=0;i<s.size();i++)
        {
            // cout<<prev<<" ";
            long long k=((s[i]-'0')*(i+1))+(10*(prev));
            ans+=(k)%mod;
            prev=(k)%mod;
        }
        return ans%mod;
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking string
        string s;
        cin>>s;
        Solution ob;
        //calling sumSubstrings() function
        cout << ob.sumSubstrings(s) << endl;
        
    }
    return 0;
}

// } Driver Code Ends