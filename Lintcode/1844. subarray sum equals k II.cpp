class Solution {
public:
    /**
     * @param nums: a list of integer
     * @param k: an integer
     * @return: return an integer, denote the minimum length of continuous subarrays whose sum equals to k
     */
    int subarraySumEqualsKII(vector<int> &nums, int k) {
        vector<int> prefix{0};
        const int N = nums.size();
        
        int answer = -1;
        for (int i = 0; i < N; i++) prefix.push_back(prefix[i] + nums[i]);
        
        unordered_map<int, vector<int>> hash;
        for (int i = 0; i <= N; i++) {
            hash[prefix[i]].push_back(i);
        }
        
        for (int i = 1; i <= N; i++) {
            const int f = prefix[i] - k;
            
            for (int p : hash[f]) {
                if (p >= i) break;
                if (answer == -1 || answer > (i - p)) {
                    answer = i - p;
                }
            }
        }
        
        return answer;
    }
};
