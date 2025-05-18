#include<bits/stdc++.h>
using namespace std;


// finding single elemet other occurance k times
int find_single_element(vector<int>&arr,int k)
{
	int n = arr.size();
	int ans;
	for(int i=0;i<32;i++) // looping through each bit of 4bytes
	{
		int sum = 0;
		for(int j=0;j<n;j++)
		{
			sum+=(arr[j]&(1<<i));
		}
		if(sum%k)
		{
			ans|=(1<<i);
		}
	}
	return ans;
}

void solve()
{
	// input section
	int k;
	cin>>k;
	vector<int>arr= { 23,5,23,4,23,4,5,7,5,4};
	int ans = find_single_element(arr,k);
	cout<<ans<<endl;
}
// main function
int main()
{
	solve();
	return 0;
}