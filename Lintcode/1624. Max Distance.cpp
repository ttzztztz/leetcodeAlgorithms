class Solution {
public:
    class TreeNode {
    public:
        bool flag;
        TreeNode* left, *right;
        TreeNode() : flag(false), left(nullptr), right(nullptr) {};
    };
    
    int getAns(vector<string> &str) {
        root = new TreeNode();
        for (const string& s : str) insert(s);
        
        dfs(root);
        return answer;
    }
private:
    TreeNode* root;
    int answer = 0;
    void insert(const string& s) {
        TreeNode* cur = root;
        for (const char ch : s) {
            TreeNode** target = nullptr;
            if (ch == '0') target = &(cur->left);
            else target = &(cur->right);
            
            if (*target == nullptr) *target = new TreeNode();
            cur = *target;
        }
        cur->flag = true;
    }
    int dfs(TreeNode* u) {
        if (u == nullptr) return 0;
        
        int left = dfs(u->left);
        int right = dfs(u->right);
        
        if (left && right) answer = max(answer, left + right);
        if (u->flag && left) answer = max(answer, left);
        if (u->flag && right) answer = max(answer, right);
        
        return max(left, right) + 1;
    }
};
