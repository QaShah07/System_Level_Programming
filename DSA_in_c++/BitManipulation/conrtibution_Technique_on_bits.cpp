#include <bits/stdc++.h>
using namespace std;

// Self use terminology
#define ll long long
#define ld long double
#define F first
#define S second

using state = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;

const int MOD = 1e9 + 7;

// Global variables (if any)
string getBitStr(int x)
{
    string cur = "";
    while(x)
    {
        if(x%2)cur+='1';
        else cur+='0';
        x/=2;
    }
    reverse(cur.begin(),cur.end());
    return cur;
}
// sum of 1's bint 0...to...x
ll sum_of_bits(ll x)
{
	ll ans = 0;
	ll tot = x+1;
	for(int i=0;i<60;i++)
	{
		ll full = (tot/(1LL<<(i+1)));
		ll left = tot%(1LL<<(i+1));
		ll extra = max(left-(1LL<<i),0LL);
		ans += full*(1LL<<i)+extra;
	}
	return ans;
}
// for finding exact index we are using Binary Search Concept
ll find_kth_index(ll k)
{
	ll lo = 0, hi = k,ans= -1;
    while(lo<=hi)
    {
        ll mid = (lo+hi)/2;
        if(sum_of_bits(mid)>=k)
        {
            ans = mid;
            hi = mid-1;
        }
        else
        {
            lo = mid+1;
        }
    }
    return ans;
}
// pos of kth
int get_kth_pos_in_num(int x,int k)
{
    int cnt = 0;
    string num = getBitStr(x);
    for(int i=0;i<num.size();i++)
    {
        if(num[i]=='1')
        {
            cnt++;
        }
        if(cnt==k)
        {
            return i;
        }
    }
}
void solve() {
    // Input section
    ll q;
    cin>>q;
    while(q--)
    {
    	ll k;
    	cin>>k;
        ll num = find_kth_index(k);
        ll pos_in_num = k-sum_of_bits(num-1);
        cout<<pos_in_num<<" :"<<get_kth_pos_in_num(num,pos_in_num)<<endl;
    }


    // Logic section
    // cout<<sum_of_bits(7)<<endl;

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t_ = 1;
    // cin >> t_;
    for (int i = 0; i < t_; i++) {
        solve();
    }

    return 0;
}