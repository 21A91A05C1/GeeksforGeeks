//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int DivisibleByEight(string s){
        //code here
        int n=s.size();
        int k=0;
        if(n<=3)
        {
            return stoi(s)%8?-1:1;
        }
        else
        {
            for(int i=n-3;i<n;i++)
            {
                k=k*10+s[i]-'0';
                // cout<<s[i]<<" ";
            }
            // cout<<k<<" ";
            return k%8?-1:1;
        }
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.DivisibleByEight(S)<<"\n";
    }
}
// } Driver Code Ends