//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void findDivisors(int n,vector<int>&divi,int m)
    {
        if(divi[n]<2){
        for(int j=n;j<=m;j+=n)
        {
            divi[j]++;
        }
        }
    }
    int countSpecialNumbers(int N, vector<int> arr) {
        // Code here
        int maxi=*max_element(arr.begin(),arr.end());
        map<int,int>mpp;
        int c=0;
        vector<int>divi(maxi+1,0);
        for(int i=0;i<arr.size();i++)
        {
            findDivisors(arr[i],divi,maxi);
        }
        //for(auto it:divi) cout<<it<<" ";
        for(int i=0;i<arr.size();i++){
            if(divi[arr[i]]>1) c+=1;
        }
        return c;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.countSpecialNumbers(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends