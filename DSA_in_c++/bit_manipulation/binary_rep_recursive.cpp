#include<bits/stdc++.h>
using namespace std;
void rec(int n)
{
	if(n >1)
	{
		rec(n/2);
	}
	cout<<(n%2);
}
int main()
{
	unsigned int n;
	cin>>n;
	rec(n);
	return 0;

}