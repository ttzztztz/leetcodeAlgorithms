class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        const int basen = 5e4+5;
        vector<int> cnt(basen * 2 + 1, 0);
        for (int i : nums) cnt[basen + i]++;

        vector<int> ans;
        for (int i = 0; i <= basen * 2; i++) {
            for (int k = 0; k < cnt[i]; k++) ans.push_back(i - basen);
        }
        return ans;
    }
};