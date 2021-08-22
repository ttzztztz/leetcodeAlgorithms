class Solution {
public:
    int findGCD(vector<int>& nums) {
        const int mi = *min_element(nums.begin(), nums.end());
        const int ma = *max_element(nums.begin(), nums.end());
        return __gcd(mi, ma);
    }
};