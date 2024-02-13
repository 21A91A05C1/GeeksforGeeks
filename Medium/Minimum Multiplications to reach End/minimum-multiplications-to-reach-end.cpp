//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    // int mod=1e9+7;
    // int findMin(vector<int>&arr,int start,int end,int i,int mul)
    // {
    //     if(mul>end) return 1e9;
    //     if(i>=arr.size())
    //     {
    //         if(mul==end) return 0;
    //         return 1e9;
    //     }
    //     int pick=1e9,notpick=1e9;
    //     pick=1+findMin(arr,start,end,i,mul*arr[i]%mod);
    //     // cout<<pick<<" ";
    //     notpick=findMin(arr,start,end,i+1,mul%mod);
    //     // cout<<notpick<<" ";
    //     // return 0;
    //     return min(pick,notpick)%mod;
        
    // }
    int mod=1e5;
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        // return findMin(arr,start,end,0,1);
        queue<pair<int,int>>qu;
        qu.push({start,0});
        if(start==end) return 0;
        vector<int>vis(100000,0);
        vis[start]=1;
        while(!qu.empty())
        {
            int m=qu.front().first;
            int c=qu.front().second;
            qu.pop();
            for(int i=0;i<arr.size();i++)
            {
                
                // m=((m%mod)*(arr[i]%mod))%mod;
                if(((m%mod)*(arr[i]%mod))%mod==end) return c+1;
                if(!vis[((m%mod)*(arr[i]%mod))%mod])
                {
                    qu.push({((m%mod)*(arr[i]%mod))%mod,c+1});
                    vis[((m%mod)*(arr[i]%mod))%mod]=1;
                }
            }
        }
        return -1;
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends