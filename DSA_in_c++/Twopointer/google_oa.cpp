#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
int main()
{
	// logic section
	int n,m;
	cin>>n>>m;
	int arr[n][m];
	vector<pair<int,int>>vals;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>arr[i][j];
			vals.push_back({arr[i][j],i});
		}
	}

	// logic section
	sort(vals.begin(),vals.end());
	int ans = 1e9;
	// two pointer form 1
	int tail = 0, head = -1;
	// maintain Data Strucutre
	int freq[n];
	memset(freq,0,sizeof(freq));
	int dcnt = 0;
	while(tail<n*m)
	{
		while(head+1<n*m && dcnt<n) 
		{
			head++;
			freq[vals[head].S]++;
			if(freq[vals[head].S]==1) dcnt++;
		}
		// maintaing the answer
		if(dcnt == n)
		{
			ans = min(ans, vals[head].F-vals[tail].F);
		}
		if(tail<=head)
		{
			if(freq[vals[tail].S]==1) dcnt--;
			freq[vals[tail].S]--;
			tail++;
		}
		else
		{
			tail++;
			head = tail-1;
		}
	}
	cout<<ans<<endl;
	return 0;
}