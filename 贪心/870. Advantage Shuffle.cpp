class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        vector<int> ans;
        const int n = A.size();
        
        multiset<int> nums(A.begin(), A.end());
        for (int i = 0; i < n; i++) {
            auto it = nums.upper_bound(B[i]);
            if (it == nums.end()) {
                const int t = *nums.begin();
                ans.push_back(t);
                nums.erase(nums.lower_bound(t));
            } else {
                ans.push_back(*it);
                nums.erase(it);
            }
        }
        
        return ans;
    }
};
