//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int getSequence(int m,int n,int i,int prev)
    {
        if(i==n) return 1;
    
        int pick=0,notpick=0;
        for(int j=prev*2;j<=m;++j)
        {
            pick+=getSequence(m,n,i+1,j);
            //notpick+=getSequence(m,n,i,j+1);
        }
        return pick+notpick;
        
    }
    int numberSequence(int m, int n){
        // code here
        int ans=0;
        for(int k=1;k<=m;k++){
            ans+= getSequence(m,n,1,k);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int m, n;
        cin>>m>>n;
        
        Solution ob;
        cout<<ob.numberSequence(m, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends