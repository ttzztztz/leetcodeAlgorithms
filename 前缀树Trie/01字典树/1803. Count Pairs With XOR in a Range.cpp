class TrieNode {
public:
    int cnt;
    vector<TrieNode*> next;
    
    TrieNode() {
        cnt = 0;
        next = vector<TrieNode*>(2, nullptr);
    }
};

class Solution {
public:
    int countPairs(vector<int>& nums, int low, int high) {
        ll ans = 0;
        for (int i : nums) {
            ans += f(i, high + 1) - f(i, low);
            insert(i);
        }
        return ans;
    }
private:
    typedef long long ll;
    TrieNode* root = new TrieNode();
    void insert(int t) {
        TrieNode* cur = root;
        for (int i = 29; i >= 0; i--) {
            cur->cnt++;
            const int x = (t & (1 << i)) ? 1 : 0;
            if (!cur->next[x]) {
                cur->next[x] = new TrieNode();
            }
            cur = cur->next[x];
        }
        cur->cnt++;
    }
    
    ll f(int num, int upper) {
        ll ans = 0;
        TrieNode* cur = root;
        for (int i = 29; i >= 0 && cur; i--) {
            const int x = (num & (1 << i)) ? 1 : 0;
            const int y = (upper & (1 << i)) ? 1 : 0;
            
            if (y == 1) {
                if (cur->next[x]) {
                    ans += cur->next[x]->cnt;
                }
                cur = cur->next[x ^ 1];
            } else {
                cur = cur->next[x];
            }
        }
        return ans;
    }
};
