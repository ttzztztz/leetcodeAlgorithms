class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        root = new TrieNode();
        for (int i : nums) insert(i);
        
        int answer = 0;
        for (int i : nums) {
            TrieNode* u = root;
            int val = 0;
            for (int j = 31; j >= 0; j--) {
                const int t = (i & (1 << j)) ? 1 : 0;
                
                if (u->nxt[t ^ 1]) {
                    val |= 1 << j;
                    u = u->nxt[t ^ 1];
                } else {
                    u = u->nxt[t];
                }
            }
            answer = max(answer, val);
        }
        return answer;
    }
private:
    class TrieNode {
    public:
        TrieNode* nxt[2];
        TrieNode() {
            memset(nxt, 0, sizeof nxt);
        }
    };
    
    TrieNode* root;
    void insert(int val) {
        TrieNode* cur = root;
        for (int j = 31; j >= 0; j--) {
            const int nxt = (val & (1 << j)) ? 1 : 0;
            
            if (cur->nxt[nxt] == nullptr) cur->nxt[nxt] = new TrieNode();
            cur = cur->nxt[nxt];
        }
    }
};
