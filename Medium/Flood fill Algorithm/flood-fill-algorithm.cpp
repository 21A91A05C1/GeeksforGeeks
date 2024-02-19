//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& image,vector<vector<int>>& vis,int newColor,int n,int m,int req)
    {
        if(i<0 || j<0 || i>=n || j>=m) return;
        
        if(vis[i][j]!=1 and image[i][j]==req)
        {
            image[i][j]=newColor;
            vis[i][j]=1;
        }
        else return ;
        dfs(i+1,j,image,vis,newColor,n,m,req);
        dfs(i-1,j,image,vis,newColor,n,m,req);
        dfs(i,j+1,image,vis,newColor,n,m,req);
        dfs(i,j-1,image,vis,newColor,n,m,req);
        
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int n=image.size(),m=image[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int l=image[sr][sc];
        dfs(sr,sc,image,vis,newColor,n,m,l);
        
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends