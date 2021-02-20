class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int a = 0;
        const int n = nums.size();
        int i = 0;
        while (i < n) {
            if (a >= groups.size()) return true;

            if (cmp(nums, i, groups[a])) {
                i += groups[a].size();
                a++;
            } else {
                i++;
            }
        }
        return a == groups.size();
    }
private:
    bool cmp(const vector<int>& v1, int i, const vector<int>& v2) {
        for (int j = 0; j < v2.size(); j++) {
            if (i + j >= v1.size()) return false;
            if (v1[i + j] != v2[j]) return false;
        }
        return true;
    }
};
