 #include <bits/stdc++.h>
using namespace std;
using ll = long long;

int evaluate(string s) {
    // If expression starts with + or -, treat it as binary by prefixing a 0:
    if (!s.empty() && (s[0] == '+' || s[0] == '-'))
        s = "0" + s;

    vector<ll> nums;
    vector<char> ops;
    int n = s.size();
    for (int i = 0; i < n; ) {
        char c = s[i];
        if (c=='+' || c=='-' || c=='*' || c=='/') {
            ops.push_back(c);
            i++;
        }
        else if (isdigit(c)) {
            ll val = 0;
            while (i<n && isdigit(s[i])) {
                val = val*10 + (s[i]-'0');
                i++;
            }
            // skip variable names if any
            while (i<n && isalpha(s[i])) i++;
            nums.push_back(val);
        }
        else if (isalpha(c)) {
            // implicit coefficient of 1 for a standalone variable
            nums.push_back(1);
            while (i<n && isalpha(s[i])) i++;
        }
        else {
            // any other character (spaces, etc.)
            i++;
        }
    }

    // First pass: handle * and / immediately
    vector<ll> nums2;
    vector<char> ops2;
    nums2.push_back(nums[0]);
    for (int i = 0; i < (int)ops.size(); i++) {
        char op = ops[i];
        ll cur = nums[i+1];
        if (op == '*') {
            nums2.back() = nums2.back() * cur;
        } else if (op == '/') {
            nums2.back() = nums2.back() / cur;  // integer division
        } else {
            ops2.push_back(op);
            nums2.push_back(cur);
        }
    }

    // Second pass: do + and -
    ll result = nums2[0];
    for (int i = 0; i < (int)ops2.size(); i++) {
        if (ops2[i] == '+')      result += nums2[i+1];
        else /* '-' */           result -= nums2[i+1];
    }

    return static_cast<int>(result);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    getline(cin, S);
    cout << evaluate(S);
    return 0;
}