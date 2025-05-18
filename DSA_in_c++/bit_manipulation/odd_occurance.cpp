#include<bits/stdc++.h>
using namespace std;

// finding odd occurance elemenet
int find_odd_occurance_element(vector<int>&arr,int n)
{
	int ans = 0;
	for(int i=0;i<n;i++)
	{
		ans=(ans^arr[i]);
	}
	return ans;
}
// sovle function
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
	int ans = find_odd_occurance_element(arr,n);
	cout<<ans<<endl;
}
// main function
int main()
{
	solve();
	return 0;
}