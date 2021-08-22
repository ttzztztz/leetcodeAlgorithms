class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<int> a;
        
        const int m = nums[0].size();
        for (auto& i : nums) {
            int cur = 0;
            reverse(i.begin(), i.end());
            for (int j = 0; j < m; j++) {
                if (i[j] == '1') cur |= (1 << j);
            }
            a.insert(cur);
        }
        
        for (int i = 0; i < (1 << m); i++) {
            if (!a.count(i)) {
                string cur;
                for (int j = m - 1; j >= 0; j--) {
                    if (i & (1 << j)) cur += "1";
                    else cur += "0";
                }
                return cur;
            }
        }
        return "";
    }
};