class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        const int n = nums.size();
        int m1 = numeric_limits<int>::max(), m2 = numeric_limits<int>::max();
        for (int i = 0; i < n; i++) {
            const int t = nums[i];
            
            if (m1 < m2 && m2 < t) return true;
            if (t <= m1) m1 = t;
            else m2 = min(m2, t);
        }
        
        return false;
    }
};
