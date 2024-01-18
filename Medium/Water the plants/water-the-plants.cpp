//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int min_sprinklers(int gallery[], int n)
    {
        // code here
        vector<int>vis(n,-1);
        for(int i=0;i<n;i++)
        {
            int r=i+gallery[i];
            r=min(r,n-1);
            int l=max(0,i-gallery[i]);
            for(int j=l;j<=r;j++)
            {
                vis[j]=max(vis[j],r);
            }
        }
        int i=0,ans=0;
        for(auto it:vis) if(it==-1) return -1;
        //for(auto it:vis) cout<<it<<" ";
        //cout<<endl;
        while(i<n)
        {
            //cout<<i<<" ";
            ans++;
            //int k=i;
            i=vis[i]+1;
            //i+=j;
        }
        //cout<<i<<" ";
        return ans;
        //return 0;
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
        
        int gallery[n];
        for(int i=0; i<n; i++)
            cin>> gallery[i];
        Solution obj;
        cout<< obj.min_sprinklers(gallery,n) << endl;
    }
	return 1;
}

// } Driver Code Ends