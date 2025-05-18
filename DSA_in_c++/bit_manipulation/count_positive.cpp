#include<bits/stdc++.h>
using namespace std;
// function for calculating 
int calculateCount(int n)
{
	int count_unset =0;
	while(n>0)
	{
		if((n&1)==0)
		{
			count_unset++;
		}
		n>>=1;
	}
	return (1<<count_unset);
}
// void solve
void solve(){
	// input setcion
	int n;
	cin>>n;
	int ans = calculateCount(n);
	cout<<ans<<endl;
}
// main function
int main(){
	solve();
	return 0;
}