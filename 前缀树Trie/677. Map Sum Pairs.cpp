class TrieNode {
public:
    int sum, raw;
    map<char, TrieNode*> next;
    TrieNode() : sum(0), raw(0) {};
    TrieNode(int s) : sum(0), raw(0) {};
};

class MapSum {
public:
    /** Initialize your data structure here. */
    TrieNode* root;
    MapSum() {
        root = new TrieNode();
    }

    void insert(string key, int val) {
        dfs(key, val, 0, root);
    }

    int sum(string prefix) {
        TrieNode* current = root;
        for (const char ch : prefix) {
            if (current->next.count(ch)) {
                current = current->next[ch];
            } else {
                return 0;
            }
        }
        return current->sum;
    }
private:
    void dfs(const string& key, const int increment, int index, TrieNode* cur) {
        if (index == key.size()) {
            cur->sum = cur->raw = increment;
            for (const pair<const char, TrieNode*> p : cur->next) {
                cur->sum += p.second->sum;
            }

            return;
        }
        const char ch = key[index];
        if (!cur->next.count(ch)) {
            cur->next[ch] = new TrieNode();
        }

        dfs(key, increment, index + 1, cur->next[ch]);
        cur->sum = cur->raw;
        for (const pair<const char, TrieNode*> p : cur->next) {
            cur->sum += p.second->sum;
        }
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */