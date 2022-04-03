int gid = 0;
int memo[105][10005];

class TrieNode {
public:
    bool flag;
    int id;
    TrieNode* next[26];
    TrieNode() : flag(false) {
        memset(next, 0, sizeof next);
        id = ++gid;
    };
    TrieNode(bool flag) : flag(flag) {
        memset(next, 0, sizeof next);
        id = ++gid;
    };
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode(false);
    }

    void insert(string word) {
        TrieNode* curr = root;
        for (const char ch : word) {
            if (curr->next[ch - 'a'] == nullptr) {
                curr->next[ch - 'a'] = new TrieNode();
            }
            curr = curr->next[ch - 'a'];
        }
        curr->flag = true;
    }
};

class Encrypter {
public:
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        gid = 0;
        v = values;
        
        for (int i = 0; i < keys.size(); i++) {
            kIdx[keys[i]] = i;
        }
        
        for (int i = 0; i < keys.size(); i++) {
            valChar[values[i]].push_back(keys[i]);
        }
        
        for (auto& w : dictionary) {
            trie.insert(w);
        }
    }
    
    string encrypt(string word1) {
        string ans;
        for (const char ch : word1) {
            ans += v[kIdx[ch]];
        }
        return ans;
    }
    
    int decrypt(string word2) {
        vector<vector<char>> possible;
        for (int i = 0; i + 1 < word2.size(); i += 2) {
            string t{word2[i], word2[i + 1]};
            possible.push_back(valChar[t]);
        }
        
        memset(memo, 0xff, sizeof memo);
        return fn(possible, 0, trie.root);
    }
private:
    vector<string> v;
    unordered_map<char, int> kIdx;
    unordered_map<string, vector<char>> valChar;
    Trie trie;
    
    int fn(const vector<vector<char>>& possible, int offset, TrieNode* node) {
        if (offset == possible.size()) {
            return node->flag ? 1 : 0;
        }
        
        if (memo[offset][node->id] != -1) {
            return memo[offset][node->id];
        }
        
        int ans = 0;
        for (const char c : possible[offset]) {
            if (node->next[c - 'a'] != nullptr) {
                ans += fn(possible, offset + 1, node->next[c - 'a']);
            }
        }
        return memo[offset][node->id] = ans;
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */
