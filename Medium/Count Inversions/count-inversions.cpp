//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long merge(long long arr[],long long low,long long mid,long long high)
    {
        long long d=0;
        vector<long long>temp;
        int l=low,m=mid+1;
        // int i=0;
        while(l<=mid and m<=high)
        {
            if(arr[l]<=arr[m]){
                temp.push_back(arr[l++]);
            }
            else{
                d+=(mid-l+1);
                temp.push_back(arr[m++]);
                
            }
        }
        while(l<=mid){
            temp.push_back(arr[l++]);
        }
        while(m<=high){
            temp.push_back(arr[m++]);
        }
        for(int i=0;i<temp.size();i++)
        {
            arr[low++]=temp[i];
        }
        return d;
    }
    long long mergeSort(long long arr[],long long low,long long high)
    {
        long long cnt=0;
        if(low>=high) return 0;
        long long mid=(low+high)/2;
        cnt+=mergeSort(arr,low,mid);
        cnt+=mergeSort(arr,mid+1,high);
        cnt+=merge(arr,low,mid,high);
        return cnt;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        return mergeSort(arr,0,N-1);
        // for(long long i=0;i<N;i++)
        // {
        //     cout<<arr[i]<<" ";
        // }
        // return 0;
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends