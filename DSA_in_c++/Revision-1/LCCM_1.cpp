#include<bits/stdc++.h>
using namespace std;
// global variable
int n;
int queens[20];

// LCCM framework i have to implement
// check funciton step 3
bool check(int row, int col)
{
	for(int pr =0;pr<row;pr++)
	{
		int pc = queens[pr];
		if(pc==col || abs(pr-row)==abs(col-pc))
		{
			return 0;
		}
	}
	return 1;
}
// step 1 - level
int rec(int level)
{
	// base case
	if(level==n){
		return 1;
	}

	// recursive check
	int ans = 0;
	for(int ch = 0;ch<n;ch++)
	{
		if(check(level,ch))
		{
			// step 4 move palace
			queens[level] = ch;
			ans += rec(level+1);
			queens[level] = -1;
		}
	}
	return ans;
}

void solve()
{
	// input section
	cin>>n;
	int queens[n];
	memset(queens,-1,sizeof(queens));
	cout<<rec(0)<<endl;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t_=1;
	// cin>>t_;
	for(int i=0;i<t_;i++)
	{
		solve();
	}
	return 0;
}