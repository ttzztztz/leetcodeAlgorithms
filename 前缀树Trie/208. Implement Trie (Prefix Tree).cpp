class TrieNode {
public:
    bool flag;
    unordered_map<int, TrieNode*> next;
    TrieNode() : flag(false) {};
    TrieNode(bool flag) : flag(flag) {};
};

class Trie {
public:
    TrieNode* root;
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode(false);
    }

    /** Inserts a word into the trie. */
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

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* curr = root;
        for (const char ch : word) {
            if (!curr->next.count(ch)) {
                return false;
            } else {
                curr = curr->next[ch];
            }
        }
        return curr->flag;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (const char ch : prefix) {
            if (!curr->next.count(ch)) {
                return false;
            } else {
                curr = curr->next[ch];
            }
        }
        return curr != nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */