//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int findSwapValues(int a[], int n, int b[], int m) {
        // Your code goes here
        // 4 1 2 1 1 2  ->
        // 3 6 3 3      ->15
        int asum=0,bsum=0;
        map<int,int>mpp1,mpp2;
        for(int i = 0 ;i  <  n ; i++)
        {
            asum+=a[i];
            mpp1[a[i]]++;
        }
        for(int j= 0 ; j < m ;j++)
        {
            bsum+=b[j];
            mpp2[b[j]]++;
        }
        for(auto it:mpp2)
        {
            for(auto itt:mpp1)
            {
                if(bsum-it.first+itt.first==asum-itt.first+it.first){
                    return 1;
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
        int n, m;
        cin >> n >> m;
        int a[n];
        int b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        Solution ob;
        cout << ob.findSwapValues(a, n, b, m);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends