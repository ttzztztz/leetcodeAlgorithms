class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        const int n = nums.size();
        const int idmin = min_element(nums.begin(), nums.end()) - nums.begin();
        const int idmax = max_element(nums.begin(), nums.end()) - nums.begin();
        
        const int l = min(idmin, idmax);
        const int r = max(idmin, idmax);
        // ([1),2,4,(3])
        // n=4 l=0 r=3
        return min(
            r + 1,
            min(
                n - l,
                l + 1 + n - r
            )
        );
    }
};
