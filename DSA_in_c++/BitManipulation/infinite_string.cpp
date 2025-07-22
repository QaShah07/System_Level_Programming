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

void solve() {
    // Input section
    string s;
    int cnt_one = 0;
    int cur_num = 0;
    while(cnt_one<=1000000)
    {
    	string cur_bits = getBitStr(cur_num);
    	int new_one = 0;
    	for(auto v: cur_bits)
    	{
    		if(v=='1')
    		{
    			new_one++;
    		}
    	}
    	s +=cur_bits;
    	cnt_one +=new_one;
    	cur_num++;
    }

    // Logic section
    // cout<<s<<endl;
    vector<int>pos1;
    for(inti=0;i<s.length();i++)
    {
    	if(s[i]=='1')
    	{
    		pos1.push_back(i);
    	}
    }
    int q;
    cin>>q;
    while(q--)
    {
    	int k;
    	cin>>k;
    	cout<<pos1[k-1]<<endl;
    }
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