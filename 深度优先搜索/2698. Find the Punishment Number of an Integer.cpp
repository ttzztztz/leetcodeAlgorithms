class Solution {
public:
    int punishmentNumber(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (dfs(get_digits(i * i), i, 0)) ans += i * i;
        }
        return ans;
    }
private:
    vector<int> get_digits(int i) {
        vector<int> res;
        while (i > 0) {
            res.push_back(i % 10);
            i /= 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }

    bool dfs(const vector<int>& digits, const int target, int idx) {
        if (idx >= digits.size()) return target == 0;
        if (target < 0) return false;

        int buf = 0;
        for (int j = idx; j < digits.size(); j++) {
            if (buf == 0 && j > idx) break;
            buf = buf * 10 + digits[j];

            if (dfs(digits, target - buf, j + 1)) {
                return true;
            }
        }
        return false;
    }
};