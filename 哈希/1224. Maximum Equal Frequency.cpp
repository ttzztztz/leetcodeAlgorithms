class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        const int N = nums.size();
        unordered_map<int, int> hashmap;
        map<int, set<int>> occurence;
        
        for (const int num : nums) {
            hashmap[num]++;
        }
        for (const pair<const int, int> p : hashmap) {
            occurence[p.second].insert(p.first);
        }
        
        int ptr = N - 1;
        while (ptr >= 0) {
            if (occurence.size() == 2) {
                auto it1 = occurence.begin();
                auto it2 = it1; it2++;
                
                const int big = it2->first, small = it1->first;
                if (small == 1 && it1->second.size() == 1) {
                    return ptr + 1;
                }
                if (big == small + 1 && it2->second.size() == 1) {
                    return ptr + 1;
                }
            }
            if (occurence.size() == 1) {
                auto it1 = occurence.begin();
                
                if (it1->first == 1 || it1->second.size() == 1) {
                    return ptr + 1;
                }
            }
            
            const int before = hashmap[nums[ptr]];
            hashmap[nums[ptr]]--;
            occurence[before].erase(nums[ptr]);
            if (hashmap[nums[ptr]] > 0) {
                occurence[hashmap[nums[ptr]]].insert(nums[ptr]);
            }
            if (occurence[before].size() == 0) {
                occurence.erase(before);
            }
            ptr--;
        }
        return 0;
    }
};
