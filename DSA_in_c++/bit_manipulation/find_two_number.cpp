#include<bits/stdc++.h>
using namespace std;

// find the two number which occurs one time
void find_two_number(vector<int>&arr,int *a, int *b,int n)
{
	int x =0;
	*a = 0;
	*b = 0;
	for(int i=0;i<n;i++)
	{
		x^=arr[i];
	}
	// now find the set_bit bascally using x&(x-1) which is clear rightmost bit
	int set_bit = (x)&(~(x-1));
	// ther is two section where we can find a and b
	for(int i=0;i<n;i++)
	{
		if(set_bit&(arr[i]))
		{
			*a = *a^arr[i];
		}
		else
		{
			*b = *b^arr[i];
		}
	}
	return;
}

// solve function
void solve()
{
	// intput section
	int n;
	cin>>n;
	vector<int>arr(n);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	// logic sectioin
	int *a  = new int[sizeof(int)];
	int *b = new int[sizeof(int)];
	find_two_number(arr,a,b,n);
	cout<<*a<<" "<<*b<<endl;
}
// int main()
int main()
{
	solve();
	return 0;
}