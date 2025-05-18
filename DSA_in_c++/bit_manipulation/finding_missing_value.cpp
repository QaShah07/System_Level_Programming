#include<bits/stdc++.h>
using namespace std;

// find the missing number
int find_missing_number(vector<int>&arr,int n)
{
	int ans1 = 0;
	int ans2 = 0;
	for(int i=1;i<=(n+1);i++)
	{
		ans1 = ans1&i;
	}
	for(int i=0;i<n;i++)
	{
		ans2 = ans2^arr[i];
	}
	int final_ans = ans1^ans2;
	return final_ans;
}
// solve function
void sovle()
{
	int n;
	cin>>n;
	vector<int>arr(n);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	// logic section
	int ans = find_missing_number(arr,n);
	cout<<ans<<endl;
}
// main function
int main()
{
	sovle();
	return 0;
}
