class Solution {
public:
    int balancedString(string s) {
        vector<int> appear_time(4, 0);
        for (const char ch : s) {
            appear_time[char_to_int_[ch]]++;
        }

        const int n = s.size();
        int ans = n + 1;
        for (int& i : appear_time) {
            i = max(0, i - (n / 4));
        }

        vector<int> cur(4, 0);
        auto should_move = [&](int l) -> bool {
            const int kIndex = char_to_int_[s[l]];
            return (cur[kIndex] - 1 >= appear_time[kIndex]);
        };

        auto ok = [&]() -> bool {
        for (int i = 0; i < 4; i++) {
            if (appear_time[i] > cur[i]) return false;
        }
        return true;
        };

        for (int l = 0, r = 0; r < n; r++) {
        cur[char_to_int_[s[r]]]++;
            while (l <= r && should_move(l)) {
                cur[char_to_int_[s[l]]]--;
                l++;
        }

            if (ok()) ans = min(ans, r - l + 1);
        }

        return ans;
    }
private:
	unordered_map<char, int> char_to_int_ = {
		{'Q', 0}, {'W', 1}, {'E', 2}, {'R', 3}
    };
};


