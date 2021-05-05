class TrieNode {
public:
    unordered_map<char, TrieNode*> next;
    int data;
    TrieNode() : data(-1) {};
};

class WordFilter {
public:
    WordFilter(vector<string>& words) {
        const int n = words.size();
        for (int i = 0; i < n; i++) {
            auto& word = words[i];
            
            const int len = word.size();
            for (int j = 0; j <= len; j++) {
                string suf = word.substr(j);
                insert(i, suf + "#" + word);
            }
        }
    }

    int f(string prefix, string suffix) {
        string keyword = suffix + "#" + prefix;
        return query(keyword);
    }
private:
    TrieNode* root = new TrieNode();
    void insert(int idx, const string& str) {
        TrieNode* cur = root;
        
        cur->data = max(cur->data, idx);
        for (char ch : str) {
            if (!cur->next.count(ch)) {
                cur->next[ch] = new TrieNode();
            }
            cur = cur->next[ch];
            cur->data = max(cur->data, idx);
        }
    }
    int query(const string& str) {
        TrieNode* cur = root;
        for (char ch : str) {
            if (!cur->next.count(ch)) {
                return -1;
            }
            cur = cur->next[ch];
        }
        return cur->data;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
