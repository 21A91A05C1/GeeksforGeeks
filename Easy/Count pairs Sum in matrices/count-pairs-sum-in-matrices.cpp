//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++
class Solution{
public:	
// 	int check(int v,vector<vector<int>> &mat2,int x)
// 	{
// 	     int q=0,z=0,p=0,n=mat2.size();
// 	       for(int s=0;s<n*n;s++)
// 	       {
// 	           int u=mat2[q][p%n];
// 	           //cout<<u<<" ";
// 	           if(u+v==x) return 1;
// 	           else if((u+v)<x) return 0;
// 	           z++;
// 	           p++;
// 	           if(z>=n)
// 	           {
// 	               q++;
// 	               z=0;
// 	           }
// 	       }
// 	       return 0;
// 	}
	int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int n, int x)
	{
	    // Your code goes here
	   // vector<vector<int>>mat(n,vector<int>(n,0));
	   // for(int i=0;i<n;i++)
	   // {
	   //     for(int j=0;j<n;j++)
	   //     {
	   //         mat[i][j]=mat2[n-i-1][n-j-1];
	   //     }
	   // }
	   // int ans=0,c=0,m=0,d=0,j=0,f=0;
	   //for(int i=0;i<n*n;i++)
	   //{
	   //    int v=mat1[m][j%n];
	   //    //cout<<mat1[m][j%n]<<" ";
	   //    if(v>x) break;
	   //    if(check(v,mat,x)) ans++;
	   //    d++;
	   //    j++;
	   //    if(d>=n)
	   //    {
	   //        m++;
	   //        d=0;
	   //        //cout<<endl;
	   //    }
	   //}
	   //return ans;
	   int c=0;
	   unordered_map<int,int>mpp;
	   for(int i=0;i<n;i++)
	   {
	       for(int j=0;j<n;j++)
	       {
	           mpp[x-mat1[i][j]]++;
	       }
	   }
	   for(int i=0;i<n;i++)
	   {
	       for(int j=0;j<n;j++)
	       {
	           if(mpp.find(mat2[i][j])!=mpp.end()) c++;
	       }
	   }
	   return c;
	}
};

//{ Driver Code Starts.


int main() 
{

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;

        vector<vector<int>> mat1(n, vector<int>(n, -1));
        vector<vector<int>> mat2(n, vector<int>(n, -1));

        for(int i = 0; i < n; i++)
        {
        	for(int j = 0; j < n; j++)
        	{
        		cin >> mat1[i][j];
        	}
        }

        for(int i = 0; i < n; i++)
        {
        	for(int j = 0; j < n; j++)
        	{
        		cin >> mat2[i][j];
        	}
        }

        Solution ob;

        cout << ob.countPairs(mat1, mat2, n, x) << "\n";

    }

    return 0;
}
// } Driver Code Ends