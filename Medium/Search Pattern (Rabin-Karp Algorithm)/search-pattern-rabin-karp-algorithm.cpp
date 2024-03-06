//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string text, string s)
        {
            //code here.
            vector<int>ans;
            int n=s.size(),m=text.size(),i=0;
            string p="";
            for(int i=0;i<m;i++)
            {
                p+=s[i];
            }
            if(p==text)
            {
                ans.push_back(1);
            }
            for(int i=m;i<n;i++)
            {
                p.erase(p.begin());
                p+=s[i];
                if(p==text)
                {
                    ans.push_back(i-m+2);
                }
            }
            return ans;
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends