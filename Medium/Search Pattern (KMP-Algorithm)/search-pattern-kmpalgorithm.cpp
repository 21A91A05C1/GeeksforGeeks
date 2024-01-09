//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
//     aylnlfdxfi
// dxfi
        vector <int> search(string pat, string txt)
        {
            //code here
            vector<int>arr;
            for(int i=0;i<txt.size();i++)
            {
                int c=0;
                for(int j=0;j<pat.size();j++)
                {
                    if(txt[i+j]==pat[j]) c++;
                    else break;
                }
                if(c==pat.size()) arr.push_back(i+1);
            }
            return arr;
            
            
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
        if (res.size()==0)
            cout<<-1<<endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends