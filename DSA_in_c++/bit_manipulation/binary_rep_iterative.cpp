#include<bits/stdc++.h>
using namespace std;
void solve()
{
	// intput section
	unsigned int x;
	cin>>x;
	for(int i=31;i>=0;i--)
	{
		if(x&(1<<i))
		{
			cout<<'1';
		}
		else
		{
			cout<<'0';
		}
	}
	cout<<endl;

}
int main()
{
	solve();
	return 0;
}