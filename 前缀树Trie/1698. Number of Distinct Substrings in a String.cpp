class TrieNode {
public:
    TrieNode* next[26];
    TrieNode() {
        memset(next, 0, sizeof next);
    }
};

class Solution {
public:
    int countDistinct(string s) {
        root = all + (ptr++);
        int ans = 0;
        const int n = s.size();
        for (int i = 0; i < n; i++) {
            TrieNode* cur = root;
            for (int j = i; j < n; j++) {
                if (!cur->next[s[j] - 'a']) {
                    cur->next[s[j] - 'a'] = all + (ptr++);
                    ans++;
                }
                
                cur = cur->next[s[j] - 'a'];
            }
        }
        return ans;
    }
private:
    TrieNode all[250000];
    int ptr = 0;
    TrieNode* root = nullptr;
};
