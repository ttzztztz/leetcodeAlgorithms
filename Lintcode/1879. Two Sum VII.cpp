class Solution {
public:
    /**
     * @param nums: the input array
     * @param target: the target number
     * @return: return the target pair
     */
    vector<vector<int>> twoSumVII(vector<int> &nums, int target) {
        vector<vector<int>> answer;
        vector<pair<int, int>> numbers;
        for (int i = 0; i < nums.size(); i++) numbers.emplace_back(nums[i], i);
        sort(numbers.begin(), numbers.end(), [](const auto& $1, const auto& $2) -> bool {
            return $1.first < $2.first;
        });
        
        int ptr1 = 0, ptr2 = nums.size() - 1;
        while (ptr1 < ptr2) {
            if (numbers[ptr1].first + numbers[ptr2].first == target) {
                int l = numbers[ptr1].second, r = numbers[ptr2].second;
                
                answer.push_back(l < r ? vector<int>{l, r} : vector<int>{r, l});
                ptr1++, ptr2--;
            } else if (numbers[ptr1].first + numbers[ptr2].first > target) {
                ptr2--;
            } else {
                ptr1++;
            }
        }
        
        return answer;
    }
};
