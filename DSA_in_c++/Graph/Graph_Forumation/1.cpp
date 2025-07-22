#include <bits/stdc++.h>
using namespace std;

// Type aliases for convenience
#define ll long long
#define ld long double
#define F first
#define S second

using State = pair<int, int>;
using VI = vector<int>;
using VVI = vector<vector<int>>;

const int MOD = 1e9 + 7;

void solve() {
    int sizeA, sizeB;
    cin >> sizeA >> sizeB;

    set<int> setA, setB;
    set<int> unionSet;
    map<int, int> frequencyMap;
    set<int> differenceSet;

    // Input for Set A
    for (int i = 0; i < sizeA; i++) {
        int element;
        cin >> element;
        setA.insert(element);
        unionSet.insert(element);
        frequencyMap[element]++;
    }

    // Input for Set B
    for (int i = 0; i < sizeB; i++) {
        int element;
        cin >> element;
        setB.insert(element);
        unionSet.insert(element);
        frequencyMap[element]++;
    }

    // Print union
    for (auto val : unionSet) {
        cout << val << " ";
    }
    cout << '\n';

    // Print intersection
    for (auto &entry : frequencyMap) {
        if (entry.second > 1) {
            cout << entry.first << " ";
        }
    }
    cout << '\n';

    // Print difference (A - B)
    for (auto val : setA) {
        if (setB.find(val) == setB.end()) {
            differenceSet.insert(val);
        }
    }
    for (auto val : differenceSet) {
        cout << val << " ";
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t_ = 1;
    cin >> t_;

    while (t_--) {
        solve();
    }

    return 0;
}
