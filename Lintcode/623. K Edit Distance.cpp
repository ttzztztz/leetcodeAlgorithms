class TrieNode {
public:
    bool flag;
    unordered_map<char, TrieNode*> next;
    TrieNode(): flag(false) {};
};

class Solution {
public:
    /**
     * @param words: a set of stirngs
     * @param target: a target string
     * @param k: An integer
     * @return: output all the strings that meet the requirements
     */
    int k;
    vector<string> kDistance(vector<string> &words, string &target, int k) {
        this->k = k;
        TrieNode* root = new TrieNode();
        for (int i = 0; i < words.size(); i++) {
            build(words[i], root);
        }
        
        vector<int> f(target.size() + 1);
        for (int i = 0; i <= target.size(); i++) f[i] = i;
        
        dfs(target, "", root, f);
        return answer;
    }
private:
    void build(const string& s, TrieNode* root) {
        TrieNode* current = root;
        for (int i = 0; i < s.size(); i++) {
            if (!current->next.count(s[i])) {
                current->next[s[i]] = new TrieNode();
            }
            current = current->next[s[i]];
        }
        current->flag = true;
    }
    void dfs(const string& target, const string& str, TrieNode* root, const vector<int>& f) {
        if (root->flag && f[target.size()] <= k) {
            answer.push_back(str);
        }
        
        for (auto& p : root->next) {
            char ch;
            TrieNode* n;
            tie(ch, n) = p;
            
            vector<int> g = f;
            for (int i = 0; i < g.size(); i++) g[i]++;
            for (int i = 0; i < g.size(); i++) {
                if (i >= 1) {
                    g[i] = min(g[i], f[i - 1] + 1);
                }
                g[i] = min(g[i], f[i] + 1);
            }
            for (int i = 1; i < g.size(); i++) {
                g[i] = min(g[i], g[i - 1] + 1);
                if (target[i - 1] == ch) {
                    g[i] = min(g[i], f[i - 1]);
                }
            }
            
            dfs(target, str + ch, n, g);
        }
    }
    vector<string> answer;
};
