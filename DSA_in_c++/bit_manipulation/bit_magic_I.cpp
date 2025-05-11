#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve()
{
    bitset<60> bits;
    int q;
    cin >> q;
    while (q--)
    {
        int type;
        cin >> type;
        switch (type)
        {
            case 1:
            {
                int i;
                cin >> i;
                cout << bits.test(i) << endl;
                break;
            }
            case 2:
            {
                int i;
                cin >> i;
                bits.set(i);
                break;
            }
            case 3:
            {
                int i;
                cin >> i;
                bits.reset(i);
                break;
            }
            case 4:
            {
                int i;
                cin >> i;
                bits.flip(i);
                break;
            }
            case 5:
            {
                cout << bits.all() << endl;
                break;
            }
            case 6:
            {
                cout << bits.any() << endl;
                break;
            }
            case 7:
            {
                cout << bits.none() << endl;
                break;
            }
            case 8:
            {
                cout << bits.count() << endl;
                break;
            }
            case 9:
            {
                cout << bits.to_ulong() << endl;
                break;
            }
            default:
            {
                cerr << "Invalid query type!" << endl;
                break;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
