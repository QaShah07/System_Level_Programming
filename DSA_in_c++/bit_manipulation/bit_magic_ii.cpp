#include<bits/stdc++.h>
using namespace std;
#define ll long long int
// global variable 
// fuction for the msb
int msb_index(int64_t n) {
    if (n == 0) return -1;
    return 63 - __builtin_clzll(n); // for 64-bit integers
}

// now for the rightmost bit
int rightmost_set_bit(int64_t n)
{
	if(n==0)
	{
		return -1;
	}
	int index = 0;
	while((n&1)==0)
	{
		n>>=1;
		index++;
	}
	return index;
}
int64_t largest_power_of_two_divisor(int64_t n) {
    if (n == 0) return -1;
    return 1LL << __builtin_ctzll(n);
}

int64_t smallest_power_of_two_ge_n(int64_t n) {
    if (n <= 1) return 2;
    int64_t power = 1;
    while (power < n) power <<= 1;
    return power;
}
// checking the power of 
bool is_power_of_two(int64_t n)
{
	if(n<=1) return 0;
	return ((n&(n-1))==0) ? 1: 0;
}
void solve()
{
	// input section
    int64_t n;
    cin>>n;
    // now come to the implementation section
    // case 1:
    bitset<64>bits(static_cast<uint64_t>(n));
    cout<<bits<<endl;
    // case 2:
    cout<<msb_index(n)<<endl;
    // case 3:
    cout<<rightmost_set_bit(n)<<endl;
    // case 4:
    cout<<is_power_of_two(n)<<endl;
    // case 5:
    cout<<largest_power_of_two_divisor(n)<<endl;
    // case 6:
    cout<<smallest_power_of_two_ge_n(n)<<endl;

}

int  main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		solve();
	}
    return 0;
}
