class TrieNode {
public:
    bool flag;
    map<char, TrieNode*> next;
    TrieNode() : flag(false) {};
    TrieNode(bool f) : flag(f) {};
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* curr = root;
        for (const char& ch : word) {
            if (!curr->next.count(ch)) {
                curr->next[ch] = new TrieNode();
            }

            curr = curr->next[ch];
        }
        curr->flag = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool dfs(const string& word, int offset, TrieNode* root) {
        const char ch = word[offset];
        if (offset == word.size()) {
            return root->flag;
        }

        if (word[offset] != '.') {
            if (!root->next.count(ch)) {
                return false;
            } else {
                root = root->next[ch];
                return dfs(word, offset + 1, root);
            }
        } else {
            for (const pair<const char, TrieNode*> n : root->next) {
                if (dfs(word, offset + 1, n.second)) {
                    return true;
                }
            }
            return false;
        }
    }

    bool search(string word) {
        return dfs(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */