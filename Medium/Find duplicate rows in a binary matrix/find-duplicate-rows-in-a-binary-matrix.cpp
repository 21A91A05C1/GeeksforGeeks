//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution
{   
    public:
    int mod=1e9+7;
    vector<int> repeatedRows(vector<vector<int>> &matrix, int M, int N) 
    { 
        // Your code here
        vector<int>a;
        map<int,int>mpp;
        for(int i=0;i<matrix.size();i++)
        {
            int ans=0;
            int c=0;
            for(int j=matrix[0].size()-1;j>=0;j--)
            {
                int k=matrix[i][j];
                if(k==1)
                {
                    ans+=(((2<<c)))%mod;
                   // cout<<ans<<" ";
                }
                c++;
            }
            ans=ans%mod;
            if(mpp.find(ans)==mpp.end()) mpp[ans]++;
            else a.push_back(i);
        }
        return a;
      
    } 
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int row, col;
        cin>> row>> col;
        vector<vector<int> > matrix(row); 
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        Solution ob;
        vector<int> ans = ob.repeatedRows(matrix, row, col);


        for (int i = 0; i < ans.size(); ++i)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}



// } Driver Code Ends