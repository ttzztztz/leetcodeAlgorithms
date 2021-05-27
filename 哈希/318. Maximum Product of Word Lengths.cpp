class Solution {
public:
    int maxProduct(vector<string>& words) {
        const int n = words.size();
        
        vector<int> mask(n, 0);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int state = 0;
            for (int j = 0; j < words[i].size(); j++) state |= (1 << (words[i][j] - 'a'));
            mask[i] = state;
        }
        
        for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) {
            if (!(mask[i] & mask[j])) ans = max<int>(ans, words[i].size() * words[j].size());
        }
        return ans;
    }
};