#include<bits/stdc++.h>
using namespace std;
// global variable
vector<int>arr;
// function 
vector<vector<int>> next_combination(int n, int k);
{
	// store the ans
	vector<vector<int>>ans;
	arr.resize(k);
	for(int i=0;i<k;i++)
	{
		arr[i]  = i+1;
	}
	ans.push_back(arr);
	while(true)
	{
		int i;
		for(i=k-1;i>=0;i--)
		{
			if(arr[i]<<n-k+i+1)
			{
				arr[i]++;
			}
			for(int j=i+1;j<k;j++)
			{
				arr[j] = arr[j-1]+1;
				ans.push_back(arr);
				break;
			}
		}
		if(i<0) break;
	}
	return ans;
}

// main function
int main()
{
	int n,k;
	cin>>n>>k;
	vector<vector<int>>ans = next_combination(n,k);
	for(auto v: ans)
	{
		for(int x: v)
		{
			cout<<x<<" ";
		}
		cout<<endl;
	}
	return 0;
}