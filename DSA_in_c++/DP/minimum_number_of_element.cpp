#include<bits/stdc++.h>
using namespace std;
// global variable
const int INF = 1e9;
int n;
int arr[1010];
int dp[1001][1001];

// recursive function
int rec(int index, int x)
{
	// pruning 
	if(x<0) return INF;
	// base case
	if(index == n)
	{
		if(x==0) return 0;
		else return INF;
	}
	// chache checked 
	if(dp[index][x]!=-1)
	{
		return dp[index][x];
	}
	// calculate
	int ans = min(rec(index+1,x),1+ec(index+1,x-arr[index]);
	// save and return 
		return dp[index][x] = ans;

}

void solve()
{
	// input section
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int x;
	cin>>x;
	memset(dp,-1,sizeof(dp));
	// logic section
	cout<<rec(0,x)<<endl;
}

// main function
int main()
{
	solve();
	return 0;
}