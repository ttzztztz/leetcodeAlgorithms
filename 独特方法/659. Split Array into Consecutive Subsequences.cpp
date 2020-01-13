class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> occurence, tail;
        for (int num : nums) occurence[num]++;
        
        for (int num : nums) {
            
            if (occurence[num] == 0) continue;
            else if (tail[num] > 0) {
                tail[num + 1]++;
                tail[num]--;
            } else if (occurence[num + 1] > 0 && occurence[num + 2] > 0) {
                occurence[num + 1]--;
                occurence[num + 2]--;
                tail[num + 3]++;
            } else {
                return false;
            }
            
            occurence[num]--;
        }
        
        return true;
    }
};
