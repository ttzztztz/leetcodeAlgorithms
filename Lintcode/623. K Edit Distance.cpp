class TrieNode {
public:
    bool flag;
    unordered_map<char, TrieNode*> next;
    TrieNode() : flag(false) {};
};

class Solution {
public:
    /**
     * @param words: a set of stirngs
     * @param target: a target string
     * @param k: An integer
     * @return: output all the strings that meet the requirements
     */
    vector<string> kDistance(vector<string> &words, string &target, int k) {
        init(words);
        const int N = target.size();
        vector<int> f(N + 1);
        for (int i = 0; i <= N; i++) f[i] = i;
        
        dfs("", target, k, f, root);
        return answer;
    }
private:
    TrieNode* root;
    vector<string> answer;
    void dfs(const string& cur, const string& target, const int k, const vector<int>& f, const TrieNode* u) {
        const int N = target.size();
        if (u->flag && f[N] <= k) {
            answer.push_back(cur);
        }
        
        for (const auto& p : u->next) {
            char ch;
            TrieNode* nxt;
            tie(ch, nxt) = p;
            
            vector<int> g(N + 1, 99999999);
            for (int i = 0; i <= N; i++) {
                if(i >= 1) g[i] = min(g[i], g[i - 1] + 1);
                g[i] = min(g[i], f[i] + 1);
                if(i >= 1) g[i] = min(g[i], f[i - 1] + 1);
                
                if (i >= 1 && ch == target[i - 1]) {
                    g[i] = min(g[i], f[i - 1]);
                }
            }
            
            dfs(cur + ch, target, k, g, nxt);
        }
    }
    void init(const vector<string> &words) {
        root = new TrieNode();
        for (const string& word : words) {
            insert(word);
        }
    }
    void insert(const string& word) {
        const int N = word.size();
        TrieNode* cur = root;
        for (int i = 0; i < N; i++) {
            if (!cur->next.count(word[i])) {
                cur->next[word[i]] = new TrieNode();
            }
            cur = cur->next[word[i]];
        }
        cur->flag = true;
    }
};
