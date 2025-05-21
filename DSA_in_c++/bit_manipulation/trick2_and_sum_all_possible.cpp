#include<bits/stdc++.h>
using namespace std;

// solve fucntion for this
void sovle()
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
	// pre calculated step
	int nextz[31][n+1];
	for(int i=n;i>=0;i--)
	{
		for(int j=0;j<31;j++)
		{
			if(i==n||((arr[i]&(1<<j))==0))
			{
				nextz[j][i] = i;
			}
			else
			{
				nextz[j][i]= nextz[j][i+1];
			}
		}
	}
	// now 2nd step
	int ans = 1;
	for(int l=0;l<n;l++)
	{
		int andval = arr[l];
		map<int,int>changepos;
		for(int j=0;j<31;j++)
		{
			if(andval&(1<<j))
			{
				changepos[nextz[j][l]] ^=(1<<j);

			}
		}
		int curpos = l;
		for(auto v: changepos)
		{
			ans* = binpow(andval,v.first-l);
			curpos = v.first;
			andval ^ = v.second;
		}
	}
	cout<<ans<<endl;
}