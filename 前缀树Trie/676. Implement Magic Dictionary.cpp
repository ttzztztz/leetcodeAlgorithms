class TrieNode {
public:
    bool flag;
    map<char, TrieNode*> next;
    TrieNode() : flag(false) {};
    TrieNode(bool f) : flag(f) {};
};

class MagicDictionary {
public:
    /** Initialize your data structure here. */
    TrieNode* root;
    MagicDictionary() {
        root = new TrieNode();
    }

    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for (const string& word : dict) {
            TrieNode* curr = root;
            for (const char& ch : word) {
                if (!curr->next.count(ch)) {
                    curr->next[ch] = new TrieNode();
                }

                curr = curr->next[ch];
            }
            curr->flag = true;
        }
    }

    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        return dfs(word, 0, false, root);
    }
private:
    bool dfs(const string& word, int offset, bool changed, TrieNode* current) {
        if (offset == word.size() && changed) {
            return current->flag;
        }

        const char ch = word[offset];
        if (current->next.count(ch) && dfs(word, offset + 1, changed, current->next[ch])) {
            return true;
        }
        if (!changed) {
            for (const pair<const char, TrieNode*> next : current->next) {
                if (next.first == ch) continue;

                if (dfs(word, offset + 1, true, next.second)) {
                    return true;
                }
            }
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dict);
 * bool param_2 = obj->search(word);
 */