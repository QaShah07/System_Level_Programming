#include<bits/stdc++.h>
using namespace std;
// function for calculating all possible subarray
int find_xor_of_subarrays(vector<int>&arr,int n)
{
	int ans = 0;
	for(int i=0;i<n;i++)
	{
		int freq = (i+1)*(n-i);
		if(freq%2)
		{
			ans = ans^arr[i];
		}
	}
	return ans;
}
// solve 
void solve()
{
	// input section
	int n;
	cin>>n;
	vector<int>arr(n);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	// logic section
	int ans = find_xor_of_subarrays(arr,n);
	cout<<ans<<endl;
}
// main fucntion
int main()
{
	solve();
	return 0;
}