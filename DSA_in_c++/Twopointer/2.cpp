#include <bits/stdc++.h>
using namespace std;
// global variable
int n,k;
int arr[100100];
// Tow Pointer form 1
void towPointer()
{
	// pointer 
	int head = -1,tail = 0;
	// check for DS - Data Strucutre
	int ans = 0;
	int cnt0 = 0;
	while(tail<n)
	{
		while (head + 1 < n && ((arr[head + 1] == 0 && cnt0 < k) || (arr[head + 1] == 1)))
		{
			head++;
			// maintain DS
			if(arr[head]==0) cnt0++;
		}
		// process Ans
		ans +=head-tail+1;
		if(tail<=head)
		{
			if(arr[tail]==0) cnt0--;
			tail++;
		}
		else
		{
			tail++;
			head = tail-1;
		}
	}
	cout<<ans<<endl;
}
void solve()
{
// input section
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	// logic section
	towPointer();
}

// main fucntion
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
