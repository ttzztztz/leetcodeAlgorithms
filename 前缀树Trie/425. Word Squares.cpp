class TrieNode {
public:
    vector<int> index;
    unordered_map<char, TrieNode*> next;
    TrieNode() {};
};

class Solution {
public:
    /*
     * @param words: a set of words without duplicates
     * @return: all word squares
     */
    vector<vector<string>> wordSquares(vector<string> &words) {
        if (words.size() <= 0) return answer;
        init();
        for (int i = 0; i < words.size(); i++) insert(words[i], i);
        N = words[0].size();
        current = vector<string>(N, string(N, ' '));
        
        for (const string& word: words) {
            current[0] = word;
            dfs(words, 1);
        }
        
        return answer;
    }
private:
    vector<vector<string>> answer;
    vector<string> current;
    TrieNode* root;
    int N;
    void dfs(const vector<string> &words, int u) {
        if (u == N) {
            answer.push_back(current);
            return;
        }
        
        string prefix;
        for (int i = 0; i < N; i++) current[i][u - 1] = current[u - 1][i];
        for (int i = 0; i < u; i++) prefix += current[i][u];
        
        TrieNode* v = findPrefix(prefix);
        if (v == nullptr) return;
        
        for (auto p : v->index) {
            current[u] = words[p];
            dfs(words, u + 1);
        }
    }
    void init() {
        this->root = new TrieNode();
    }
    void insert(const string& word, const int i) {
        TrieNode* cur = root;
        for (const char& ch : word) {
            if (!cur->next.count(ch)) cur->next[ch] = new TrieNode();
            cur = cur->next[ch];
            cur->index.push_back(i);
        }
    }
    TrieNode* findPrefix(const string& word) {
        TrieNode* cur = root;
        for (const char ch : word) {
            if (!cur->next.count(ch)) return nullptr;
            cur = cur->next[ch];
        }
        return cur;
    }
};
