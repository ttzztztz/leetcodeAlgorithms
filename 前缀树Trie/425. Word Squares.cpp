class TrieNode {
public:
    vector<int> idx;
    unordered_map<char, TrieNode*> next;
};

class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        if (words.empty()) return ans_;
        
        root_ = new TrieNode();
        n_ = words[0].size();
        words_ = words;
        
        for (int i = 0; i < words.size(); i++) {
            insert(words[i], i);
        }
        
        for (const string& word : words) {
            cur_ = vector<string>(n_, string(n_, ' '));
            fill_cur(word, 0);
            dfs(1);
        }
        
        return ans_;
    }
private:
    int n_;
    vector<string> cur_, words_;
    vector<vector<string>> ans_;
    
    TrieNode* root_;
    
    void dfs(int i) {
        if (i == n_) {
            ans_.push_back(cur_);
            return;
        }
        
        string pref;
        for (int j = 0; j < i; j++) pref += cur_[i][j];
        TrieNode* cur = find_prefix(pref);
        if (cur == nullptr) return;
        
        for (const int j : cur->idx) {
            fill_cur(words_[j], i);
            dfs(i + 1);
        }
    }
    
    void fill_cur(const string& word, int idx) {
        cur_[idx] = word;
        for (int i = 0; i < n_; i++) cur_[i][idx] = word[i];
    }
    
    void insert(const string& str, int i) {
        TrieNode* cur = root_;
        for (const char ch : str) {
            if (!cur->next.count(ch)) {
                cur->next[ch] = new TrieNode();
            }
            cur->idx.push_back(i);
            cur = cur->next[ch];
        }
        cur->idx.push_back(i);
    }
    
    TrieNode* find_prefix(const string& str) {
        TrieNode* cur = root_;
        for (const char ch : str){
            cur = cur->next[ch];
            if (cur == nullptr) return nullptr;
        }
        return cur;
    }
};
