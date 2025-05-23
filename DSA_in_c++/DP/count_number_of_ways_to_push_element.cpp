#include<bits/stdc++.h>
using namespace std;
// global variable
const int INF = 1e9;
int n;
string s;
int dp[100100][4][4];

// recursive function
int rec(int index, int prev, int first)
{ 
	// pruning 

	// base case
	if(index==n)
	{
		if(prev==first && n!=1) return 0;
		return 1;
	}
	// chache checked 
	if(prev != -1 && (dp[index][prev][first]!=-1))
	{
		return dp[index][prev][first];
	}
	// calculate
	int ans = 0;
	if(s[index]=='?'){
		for(int ch = 0;ch<4;ch++)
		{
			if(ch==prev) continue;
			if(index==0)
			{
				ans +=rec(index+1,ch,ch);
			}
			else
			{
				ans += rec(index+1,ch,first);
			}
		}
	}
	else
	{
		if((s[index]-'A')==prev)
		{
			return 0;
		}
		else
		{
			if(index==0)
			{
				ans +=rec(index+1,(s[index]-'A'),(s[index]-'A'));
			}
			else
			{
				ans += rec(index+1,(s[index]-'A'),first);
			}
		}
	}
	// save and return 
	if(prev!=-1) dp[index][prev][first] = ans;
	return ans;
}

void solve()
{
	// input section
	cin>>n;
	cin>>s;
	memset(dp,-1,sizeof(dp));
	// logic section
	cout<<rec(0,-1,-1)<<endl;
}

// main function
int main()
{
	solve();
	return 0;
}