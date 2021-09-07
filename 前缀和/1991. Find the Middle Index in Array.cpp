class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        pref = {0};
        for (int i : nums) pref.push_back(pref.back() + i);
        
        const int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (sum(0, i - 1) == sum(i + 1, n - 1)) {
                return i;
            }
        }
        return -1;
    }
private:
    vector<int> pref;
    int sum(int i, int j) {
        if (i > j) return 0;
        return pref[j + 1] - pref[i];
    }
};