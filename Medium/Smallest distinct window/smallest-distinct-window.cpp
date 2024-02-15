//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here   
        unordered_map<char,int>mpp;
        set<char>st;
        for(int i=0;i<str.size();i++) st.insert(str[i]);
        int s=st.size();
        int i=0,j=0;
        int mini=1e9;
        int n=str.size();
        while(j<n)
        {
            mpp[str[j]]++;
            while(mpp.size()==s and i<n)
            {
                mini=min(mini,j-i+1);
                mpp[str[i]]--;
                if(mpp[str[i]]<=0){
                    mpp.erase(str[i]);
                }
                i++;
            }
            j++;
        }
        return mini;
    }
};


//{ Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}
// } Driver Code Ends