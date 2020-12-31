class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        unordered_map<string, vector<int>> pos;
        for (size_t i = 0; i < words.size(); i++) {
            pos[words[i]].push_back(i);
        }
        
        int ans = words.size() + 5;
        const vector<int>& v1 = pos[word1];
        const vector<int>& v2 = pos[word2];
        
        for (size_t i = 0, j = 0; i < v1.size() && j < v2.size();) {
            ans = min(ans, abs(v1[i] - v2[j]));
            
            if (v1[i] < v2[j]) i++;
            else j++;
        }
        return ans;
    }
};
