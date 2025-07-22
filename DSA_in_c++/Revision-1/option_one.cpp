#include <bits/stdc++.h>
using namespace std;

// function for printing 
void option_one(int n)
{
	int arr[] = {0,1,2,3,4,5,6,7,8,9};
	do
	{
		int abcde = 10000*arr[0]+1000*arr[1]+100*arr[2]+10*arr[3]+1*arr[4];
		int fghij = 10000*arr[0+5]+1000*arr[1+5]+100*arr[2+5]+10*arr[3+5]+1*arr[4+5];
		if(abcde%fghij==0)
		{
			if(abcde/fghij==n)
			{
				cout<<abcde<<" "<<fghij<<"\n";
			}
		}
	}while(next_permutation(arr,arr+10));
}
int main()
{
	option_one(65);
}