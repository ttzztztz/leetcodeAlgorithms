class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_map<int, int> hashmap;
        for (int i : nums) hashmap[i]++;
        
        const int n = nums.size();
        vector<int> answer;
        for (int i = 1; i <= n; i++) {
            if (!hashmap.count(i)) answer.push_back(i);
        }
        return answer;
    }
};