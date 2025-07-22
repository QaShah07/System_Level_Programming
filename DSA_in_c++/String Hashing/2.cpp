#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<string> grid(N);
    for (int i = 0; i < N; i++) {
        cin >> grid[i];
        for (int j = 0; j < N; j++) {
            grid[i][j] = tolower(grid[i][j]);
        }
    }

    string word;
    cin >> word;
    int L = word.size();
    for (char &c : word) {
        c = tolower(c);
    }

    // 8 directions: right, down, left, up, down-right, down-left, up-right, up-left
    const int dx[8] = { 0, 1,  0, -1,  1,  1, -1, -1 };
    const int dy[8] = { 1, 0, -1,  0,  1, -1,  1, -1 };

    long long count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] != word[0]) continue;
            for (int dir = 0; dir < 8; dir++) {
                int x = i, y = j;
                int k;
                for (k = 0; k < L; k++) {
                    int nx = i + k * dx[dir];
                    int ny = j + k * dy[dir];
                    if (nx < 0 || nx >= N || ny < 0 || ny >= N
                        || grid[nx][ny] != word[k]) {
                        break;
                    }
                }
                if (k == L) {
                    count++;
                }
            }
        }
    }

    cout << count << "\n";
    return 0;
}