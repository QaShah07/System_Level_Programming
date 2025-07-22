#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N+1);
        for (int i = 1; i <= N; i++) {
            cin >> A[i];
        }

        const int B = 31; // bits 0..30
        // pref[b][i] = # of ones at bit b among A[1..i]
        vector<vector<int>> pref(B, vector<int>(N+1, 0));
        for (int b = 0; b < B; b++) {
            for (int i = 1; i <= N; i++) {
                pref[b][i] = pref[b][i-1] + ((A[i] >> b) & 1);
            }
        }

        int Q;
        cin >> Q;
        while (Q--) {
            int L, R;
            cin >> L >> R;
            int len = R - L + 1;

            ll X1 = 0, X2 = 0, X3 = 0;
            for (int b = 0; b < B; b++) {
                int c1 = pref[b][R] - pref[b][L-1];
                int c0 = len - c1;
                // XOR-sum max: flip bit if zeros > ones
                if (c0 > c1) X1 |= (1LL << b);
                // OR-sum max: set bit if any zero
                if (c0 > 0)  X2 |= (1LL << b);
                // AND-sum max: set bit if any one
                if (c1 > 0)  X3 |= (1LL << b);
            }

            cout << (X1 + X2 + X3) << "\n";
        }
    }
    return 0;
}
