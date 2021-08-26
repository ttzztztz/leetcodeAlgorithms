class Solution {
public:
    bool isValidSerialization(string preorder) {
        tree = split(preorder);
        return dfs() && idx == tree.size();;
    }
private:
    vector<string> tree;
    int idx;
    
    bool dfs() {
        if (idx >= tree.size()) return false;
        const string& cur = tree[idx++];
        if (cur == "#") return true;
        
        return dfs() && dfs();
    }
    
    vector<string> split(const string& str) {
        string tmp;
        vector<string> ans;
        for (const char ch : str) {
            if (ch == ',') {
                ans.push_back(tmp);
                tmp.clear();
            } else {
                tmp += ch;
            }
        }
        
        if (!tmp.empty()) ans.push_back(tmp);
        return ans;
    }
};