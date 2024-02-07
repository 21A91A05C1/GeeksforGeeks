//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string>ans;
    void findDirection(vector<vector<int>>&arr,int n,int i,int j,string &temp,
    vector<vector<int>>&vis)
    {
        //cout<<"ji ";
        if(i>=n or j>=n or i<0 or j<0 or vis[i][j]==1 or arr[i][j]==0) return;
        if(i==n-1 and j==n-1)
        {
            //cout<<temp<<" ";
            ans.push_back(temp);
            return;
        }
        temp+='D';
        vis[i][j]=1;
        findDirection(arr,n,i+1,j,temp,vis);
        vis[i][j]=-1;
        temp.pop_back();
        temp+='R';
        vis[i][j]=1;
        findDirection(arr,n,i,j+1,temp,vis);
        vis[i][j]=-1;
        temp.pop_back();
        temp+='L';
        vis[i][j]=1;
        findDirection(arr,n,i,j-1,temp,vis);
        vis[i][j]=-1;
        temp.pop_back();
        temp+='U';
        vis[i][j]=1;
        findDirection(arr,n,i-1,j,temp,vis);
        vis[i][j]=-1;
        temp.pop_back();
        // vis[i][j] = 1;
        // findDirection(arr,n,i-1,j,temp+'U',vis);
        // findDirection(arr,n,i+1,j,temp+'D',vis);
        // findDirection(arr,n,i,j-1,temp+'L',vis);
        // findDirection(arr,n,i,j+1,temp+'R',vis);
        // vis[i][j] = -1;
        
        
    }
    vector<string>findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        //vector<string>ans;
        vector<vector<int>>vis(n,vector<int>(n,-1));
        string temp="";
        findDirection(m,n,0,0,temp,vis);
        
        return ans;
    }
};

    



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends