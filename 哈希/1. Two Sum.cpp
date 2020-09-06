class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if (nums.size() <= 1) {
            return vector<int>();
        }
        vector<int> answer;
        unordered_map<int, int> hashMap;

        for (int i = 0; i < nums.size(); i++) {
            auto it = hashMap.find(target - nums[i]);
            if (it != hashMap.end()) {
                answer.push_back(it->second);
                answer.push_back(i);
            }
            hashMap.insert(std::make_pair(nums[i], i));
        }

        return answer;
    }
};