//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
private:
    void generatePrimes(vector<int>&primes,int b){
        primes[0]=0;
        primes[1]=1;
        for(int i=0;i<=b;i++) primes[i]=i;
        for(int i=2;i*i<=b+1;i++)
        {
            if(primes[i]==i)
            {
                primes[i]=i;
                for(int j=i*i;j<=b+1;j+=i)
                {
                    if(primes[j]==j)
                        primes[j]=i;
                }
            }
        }
    }
public:
	int sumOfPowers(int a, int b){
	    // Code here
	    vector<int>primes(b+1,1);
	    generatePrimes(primes,b);
	    int ans=0;
	    for(int i=a;i<=b;i++)
	    {
	        //map<int,int>mpp;
	        int m=i,s=0;
	        //cout<<"for "<<i<<endl;
	        while(m>1){
	            int p=primes[m];
	            //cout<<p<<" ";
	            s++;
	            m/=p;
	            //cout<<m<<" ";
	        }
	        //cout<<s<<" ";
	        ans+=s;
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