class Solution {
public:
    long long wonderfulSubstrings(string word) {
        typedef long long ll;
        const int n = word.size();
        ll cnt[(1 << 10) + 5];
        memset(cnt, 0, sizeof cnt);
        cnt[0] = 1;
        
        ll ans = 0;
        int cur = 0;
        for (int i = 0; i < n; i++) {
            const int t = word[i] - 'a';
            cur ^= (1 << t);
            
            ans += cnt[cur];
            for (int j = 0; j < 10; j++) {
                const int state = (1 << j);
                ans += cnt[state ^ cur];
            }
            // cout << cnt[cur] << "," << ans << endl;
            cnt[cur]++;
        }
        // cout << endl;
        return ans;
    }
};