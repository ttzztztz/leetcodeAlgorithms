class WordDistance {
public:
    WordDistance(vector<string>& words) {
        for (size_t i = 0; i < words.size(); i++) {
            pos[words[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        int ans = numeric_limits<int>::max();
        const vector<int>& v1 = pos[word1];
        const vector<int>& v2 = pos[word2];
        
        for (size_t i = 0, j = 0; i < v1.size() && j < v2.size();) {
            ans = min(ans, abs(v1[i] - v2[j]));
            
            if (v1[i] < v2[j]) i++;
            else j++;
        }
        return ans;
    }
private:
    unordered_map<string, vector<int>> pos;
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(words);
 * int param_1 = obj->shortest(word1,word2);
 */
