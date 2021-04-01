class Solution {
public:
    string originalDigits(string s) {
        const vector<string> cs = {
            "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
        };
        unordered_map<char, int> a;
        for (const char ch : s) a[ch]++;
        vector<int> cnt(10, 0);
        
        cnt[0] = a['z'];
        cnt[2] = a['w'];
        cnt[4] = a['u'];
        cnt[6] = a['x'];
        cnt[8] = a['g'];
        cnt[3] = a['h'] - cnt[8];
        cnt[5] = a['f'] - cnt[4];
        cnt[7] = a['v'] - cnt[5];
        cnt[9] = a['i'] - cnt[5] - cnt[6] - cnt[8];
        cnt[1] = a['n'] - cnt[9] * 2 - cnt[7];
        
        string ans;
        for (int i = 0; i < 10; i++) {
            string t(cnt[i], '0' + i);
            ans += t;
        }
        return ans;
    }
};
