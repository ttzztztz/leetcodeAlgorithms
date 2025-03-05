class TrieNode {
public:
    unordered_map<int, TrieNode*> next;
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        for (int i : arr1) insert(i);
        for (int i : arr2) dfs(root, get_digits(i), 0);
        return ans;
    }
private:
    int ans = 0;
    TrieNode* root = new TrieNode();

    void dfs(TrieNode* node, const vector<int>& d, int len) {
        ans = max(ans, len);
        if (len >= d.size()) return;

        const int t = d[len];
        if (node->next.count(t)) {
            dfs(node->next[t], d, len + 1);
        }
    }

    vector<int> get_digits(int i) {
        if (i == 0) return { 0 };
        vector<int> digits;
        while (i > 0) {
            digits.push_back(i % 10);
            i /= 10;
        }
        reverse(digits.begin(), digits.end());
        return digits;
    }

    void insert(int i) {
        const vector<int> digits = get_digits(i);
        TrieNode* cur = root;
        for (int d : digits) {
            if (!cur->next.count(d)) cur->next[d] = new TrieNode();
            cur = cur->next[d];
        }
    }
};