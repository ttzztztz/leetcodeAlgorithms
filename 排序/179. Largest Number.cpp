class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string ans;
        vector<string> str_nums;
        for (auto i : nums) str_nums.push_back(to_string(i));
        sort(str_nums.begin(), str_nums.end(), [](const auto& $1, const auto& $2) -> bool {
            return $1 + $2 > $2 + $1;
        });
        for (auto& i : str_nums) ans += i;
        
        const int n = ans.size();
        for (int i = 0; i < n - 1; i++) {
            if (ans[0] == '0') ans.erase(ans.begin());
        }
        return ans;
    }
};
