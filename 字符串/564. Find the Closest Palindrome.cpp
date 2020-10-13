class Solution {
public:
    string nearestPalindromic(string s) {
        const int n = s.size();
        if (n == 1) return to_string(stoll(s) - 1);
        
        f = stoll(s);
        if (n % 2 == 1) { // odd
            search(stoll(s.substr(0, n / 2)));
            search(stoll(s.substr(0, (n / 2) + 1)));
        } else { // even
            search(stoll(s.substr(0, n / 2)));
        }
        
        return to_string(ans);
    }
private:
    typedef long long ll;
    ll ans = 0, f;
    void search(ll tmp) {
        for (int d = -1; d <= 1; d++) {
            for (int m = 0; m <= 11; m++) {
                const ll cur = tmp + d;
                string s = cur == 0 ? "" : to_string(cur);
                    
                if (m == 10 && !s.empty()) s.pop_back();
                if (m <= 9) s += to_string(m);

                string t = cur == 0 ? "" : to_string(cur);
                reverse(t.begin(), t.end());
                s += t;

                if (s.size() > 18 || s.empty()) continue;
                const ll g = stoll(s);
                if (g == f) continue;
                if (ans == 0 || abs(f - g) < abs(ans - f) || (abs(f - g) == abs(ans - f) && g < ans)) ans = g;
            }
        }
    }
};
