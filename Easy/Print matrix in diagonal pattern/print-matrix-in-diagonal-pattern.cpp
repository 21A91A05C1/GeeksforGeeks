//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    vector<int> matrixDiagonally(vector<vector<int>>&mat)
    {
         //Your code here
        map<int,vector<int>>mpp;
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat.size();j++)
            {
                int k=i+j;
                mpp[k].push_back(mat[i][j]);
            }
        }
        int c=0;
        vector<int>ans;
        for(auto it:mpp)
        {
            if(c%2)
            {
                for(auto i:it.second)
                {
                    ans.push_back(i);
                }
            }
            else
            {
                vector<int>b;
                for(auto i:it.second)
                {
                    b.push_back(i);
                }
                reverse(b.begin(),b.end());
                for(auto i:b)
                {
                    ans.push_back(i);
                }
            }
            c++;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n;
        int k=0;
        //cin>>k;
        cin>>n;
        vector<vector<int>>mat(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> mat[i][j];
            }
        }
        Solution obj;
        vector<int>ans = obj.matrixDiagonally(mat);
        for(auto i: ans)cout << i << " ";
        cout << "\n";
        
       
    }
}
// } Driver Code Ends