class TrieNode {
public:
    bool flag;
    unordered_map<int, TrieNode*> next;
    TrieNode() : flag(false) {};
    TrieNode(bool flag) : flag(flag) {};
};

class Solution {
public:
    /**
     * @param words: List[str]
     * @return: return List[str]
     */
    vector<string> findAllConcatenatedWordsInADict(vector<string> &words) {
        // write your code here
        root = new TrieNode(false);
        for (auto& s : words) insert(s);
        
        vector<string> ans;
        for (auto& s : words) {
            if (dfs(s, 0, 0)) ans.push_back(s);
        }
        return ans;
    }
private:
    TrieNode* root;
    
    void insert(string word) {
        TrieNode* curr = root;
        for (const char ch : word) {
            if (!curr->next.count(ch)) {
                curr->next[ch] = new TrieNode();
            }
            curr = curr->next[ch];
        }
        curr->flag = true;
    }
    
    bool dfs(const string& word, int idx, int cnt) {
        if (idx > word.size()) return false;
        if (idx == word.size()) return cnt >= 2;
        
        TrieNode* u = root;
        for (int i = idx; i < word.size(); i++) {
            if (!u->next.count(word[i])) return false;
            u = u->next[word[i]];
            if (u->flag && dfs(word, i + 1, cnt + 1)) return true;
        }
        return false;
    }
};
