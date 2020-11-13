class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        this->root = new TrieNode();
        for (string& word : words) {
            reverse(word.begin(), word.end());
            insert(word);
        }
        
        dfs(root, 0);
        return answer;
    }
private:
    int answer = 0;
    class TrieNode {
    public:
        bool flag;
        unordered_map<char, TrieNode*> next;
        
        TrieNode() : flag(false) {};
    };
    
    TrieNode* root;
    void insert(const string& str) {
        TrieNode* u = root;
        
        for (const char ch : str) {
            if (!u->next.count(ch)) u->next[ch] = new TrieNode();
            u = u->next[ch];
        }
        
        u->flag = true;
    }
    
    void dfs(TrieNode* u, int cnt) {
        bool isLeaf = true;
        for (auto [_ch, v] : u->next) {
            dfs(v, cnt + 1);
            isLeaf = false;
        }
        
        if (isLeaf) {
            answer += cnt + 1;
        }
    }
};
