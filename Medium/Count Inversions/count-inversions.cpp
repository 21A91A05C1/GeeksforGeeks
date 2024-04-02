//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    long long merge(long long low,long long  mid,long long high,long long arr[])
    {
        long long  i=low,k=low,d=0,j=mid+1;
        vector<long long>temp;
        while(i<=mid && j<=high)
        {
            if(arr[i]<=arr[j]) 
            {
                temp.push_back(arr[i]);
                i++;
            }
            else
            {
                temp.push_back(arr[j]);
                j++;
                d+=(mid-i+1);
            }
        }
        while(i<=mid)
        {
            temp.push_back(arr[i]);
            i++;
        }
        while(j<=high)
        {
            temp.push_back(arr[j]);
            j++;
        }
        for(long long  i = 0; i<temp.size() ; i++)  arr[k++]=temp[i];
        return d;
    }
    long long mergesort(long long  low,long long high,long long arr[])
    {
        long long c=0;
        if(low==high) return 0;
        long long mid=(low+high)/2;
        long long lid=(low+high)/2;
        c+=mergesort(low,mid,arr);
        c+=mergesort(mid+1,high,arr);
        c+=merge(low,mid,high,arr);
        return c;
    }
    long long int inversionCount(long long arr[], long long n)
    {
        return mergesort(0,n-1,arr);
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