#include<bits/stdc++.h>
using namespace std;

// function to conver int x into string 
string getBitStr(int x)
{
	string cur = "";
	while(x)
	{
		if(x%2)
		{
			cur +='1';
		}
		else
		{
			cur+='0';
		}
		x/=2;
	}
	if(cur=="")cur="0";
	reverse(cur.begin(),cur.end());
	return cur;
}
// main function to controll althis
void solve(){
// input section
	string s="";
	int cnt_one =0;
	int cur_num =0;
	while(cnt_one<=100000)
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
		// cout<<cur_num<<" "<<cur_bits<<" "<<new_one<<endl;
		cnt_one+=new_one;
		cur_num++;
	}
// now logic is store position of 1 in pre
	vector<int>pos1;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='1')
		{
			pos1.push_back(i);
		}
	}
	// what question asked perform this
	int q;
	cin>>q;
	while(q--)
	{
		int k;
		cin>>k;
		cout<<pos1[k-1]<<endl;
	}
}
// main
int main()
{
	solve();
	return 0;
}