#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define slab pair<pii, pii>

int N, K;
int grid[1001][1001];
bool used[1001][1001];
vector<slab> possibleSlabs;
int totalSum = 0;
int minVisibleSum = INT_MAX;

bool isValidSlab(slab s) {
    auto [a, b] = s;
    return !used[a.first][a.second] && !used[b.first][b.second];
}

void markSlab(slab s, bool flag) {
    auto [a, b] = s;
    used[a.first][a.second] = flag;
    used[b.first][b.second] = flag;
}

int getSlabSum(slab s) {
    auto [a, b] = s;
    return grid[a.first][a.second] + grid[b.first][b.second];
}

void backtrack(int index, int k, int coveredSum) {
    if (k == K) {
        minVisibleSum = min(minVisibleSum, totalSum - coveredSum);
        return;
    }

    if (index >= possibleSlabs.size()) return;

    // Try placing current slab
    if (isValidSlab(possibleSlabs[index])) {
        markSlab(possibleSlabs[index], true);
        backtrack(index + 1, k + 1, coveredSum + getSlabSum(possibleSlabs[index]));
        markSlab(possibleSlabs[index], false);
    }

    // Skip current slab
    backtrack(index + 1, k, coveredSum);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j) {
            cin >> grid[i][j];
            totalSum += grid[i][j];
        }

    // Generate all valid slabs (adjacent horizontal or vertical cells)
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j) {
            if (j + 1 < N)
                possibleSlabs.push_back({{i, j}, {i, j + 1}});
            if (i + 1 < N)
                possibleSlabs.push_back({{i, j}, {i + 1, j}});
        }

    backtrack(0, 0, 0);
    cout << minVisibleSum << endl;

    return 0;
}