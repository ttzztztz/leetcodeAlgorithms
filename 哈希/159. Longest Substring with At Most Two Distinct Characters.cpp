class Solution {
public:
    /**
     * @param s: a string
     * @return: the length of the longest substring T that contains at most 2 distinct characters
     */
    int lengthOfLongestSubstringTwoDistinct(string &s) {
        int answer = 0;
        
        int left = 0, right = 0;
        const int N = s.size();
        unordered_map<int, int> hashmap;
        while (right < N) {
            hashmap[s[right]]++;
            
            while (hashmap.size() > 2) {
                hashmap[s[left]]--;
                if (hashmap[s[left]] == 0) {
                    hashmap.erase(s[left]);
                }
                left++;
            }
            
            answer = max(answer, right - left + 1);
            right++;
        }
        
        return answer;
    }
};
