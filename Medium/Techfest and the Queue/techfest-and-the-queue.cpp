//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
private:
    int primeFactorPower(int n)
    {
        //cout<<n<<" ";
        int k=3,m=n;
        int d=0;
        while(n%2==0)
        {
            n/=2;
            d++;
        }
        while(n>1 and k<=int(sqrt(m))+1)
        {
            if(n%k==0)
            {
                d++;
                n/=k;
            }
            else {
                k+=2;
            }
        }
        if(n>2) d++;
        //if(n==2) d++;
        //cout<<d<<endl;
        return d;
    }
public:
	int sumOfPowers(int a, int b){
	    // Code here
	    int ans=0;
	    for(int i=a;i<=b;i++)
	    {
	        ans+=primeFactorPower(i);
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int a, b;
		cin >>  a >> b;
		Solution obj;
		int ans = obj.sumOfPowers(a, b);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends