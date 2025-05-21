#include<bits/stdc++.h>
using namespace std;
// solve function
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
	// Logic section
	set<int>allands;
	set<in>last_possible;
	for(int i=0;i<n;i++)
	{
		set<int>cur_possible;
		cur_possible.insert(arr[i]);
		for(auto v: last_possible)
		{
			cur_possible.insert(v&arr[i]);
		}
		for(auto v: cur_possible)
		{
			allands.insert(v);
		}
		last_possible = cur_possible;
	}
	cout<<allands.size()<<endl;

}
// main function 
int main()
{
	sovle();
	return 0;
}