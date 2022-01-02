class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0;
        for (int i = 0, last = 0; i < bank.size(); i++) {
            int cur = 0;
            for (auto& b : bank[i]) if (b == '1') cur++;
            ans += cur * last;
            if (cur != 0) last = cur;
        }
        return ans;
    }
};
