class TrieNode {
public:
    bool flag;
    unordered_map<char, TrieNode*> next;
    TrieNode(): flag(false) {}
};

class StreamChecker {
public:
    TrieNode *root;
    void insert(const string& word) {
        TrieNode* cur = root;
        for (int i = 0; i < word.size(); i++) {
            const char ch = word[i];
            if (!cur->next.count(ch)) {
                cur->next[ch] = new TrieNode();
            }
            cur = cur->next[ch];
        }
        cur->flag = true;
    }
    StreamChecker(vector<string>& words) {
        root = new TrieNode();
        for (string& word : words) {
            reverse(word.begin(), word.end());
            insert(word);
        }
    }

    string history;
    bool query(char letter) {
        TrieNode* cur = root;
        history.push_back(letter);

        for (int i = history.size() - 1; i >= 0; i--) {
            const char ch = history[i];

            if (!cur->next.count(ch)) {
                return false;
            } else {
                cur = cur->next[ch];
                if (cur->flag) {
                    return true;
                }
            }
        }

        return cur->flag;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */