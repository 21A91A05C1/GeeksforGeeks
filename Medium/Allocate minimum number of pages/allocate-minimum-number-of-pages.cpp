//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    int isPossible(vector<int>&arr,int i,int m){
    int c=1,summ=0;
    for(int j=0;j<arr.size();j++){
        if((summ+arr[j])<=i){
            summ+=arr[j];
        }
        else{
            c++;
            summ=arr[j];
        }
    }
            if(c>m){
                return 1;
            }
            
            return 0;
        }
    int findPages(int a[], int n, int m) 
    {
        vector<int>arr;
        for(int i=0;i<n;i++)
        {
            arr.push_back(a[i]);
        }
        int low=*max_element(arr.begin(),arr.end());
        int high=accumulate(arr.begin(),arr.end(),0);
        if(m>n) return -1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            int l=isPossible(arr,mid,m);
            if(l==0) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends