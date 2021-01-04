class TrieNode {
public:
    unordered_map<char, TrieNode*> next;
};

class Solution {
public:
    int longestRepeatingSubstring(string S) {
        int ans = 0;
        const int n = S.size();
        TrieNode* root = new TrieNode();
        for (int i = 0; i < n; i++) {
            TrieNode* cur = root;
            for (int j = i; j < n; j++) {
                if (cur->next.count(S[j])) {
                    ans = max(ans, j - i + 1);
                } else {
                    cur->next[S[j]] = new TrieNode();
                }
                
                cur = cur->next[S[j]];
            }
        }
        
        return ans;
    }
};
