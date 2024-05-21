//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        // code here
        vector<int>ans;
        int p=upper_bound(arr.begin(),arr.end(),x)-arr.begin();
        int j=p;
        int i=0;
        if(arr[p-1]==x) i=p-2;
        else i=p-1;
        while(i>=0 and j<n and k)
        {
            int right=abs(arr[i]-x);
            int left=abs(arr[j]-x);
            if(right<left){
                ans.push_back(arr[i]);
                i--;
            }
            else if(right>=left){
                ans.push_back(arr[j]);
                j++;
            }
            k--;
        }
        while(i>=0 and k){
            ans.push_back(arr[i]);
            i--;
            k--;
        }
        while(j<n and k){
            ans.push_back(arr[j]);
            j++;
            k--;
        }
        // cout<<p<<" ";
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, x;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> k >> x;
        Solution ob;
        auto ans = ob.printKClosest(arr, n, k, x);
        for (auto e : ans) {
            cout << e << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends