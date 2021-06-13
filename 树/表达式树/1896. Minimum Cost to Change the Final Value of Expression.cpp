class TNode {
public:
    char cur;
    TNode* left, *right;
    TNode(char c) {
        cur = c;
        left = right = nullptr;
    }
};

class Solution {
public:
    int minOperationsToFlip(string expression) {
        postfix = convert(expression);
        ptr = postfix.size() - 1;
        // for (auto& x : postfix) cout << x << " ";
        // cout << endl;
        
        TNode* root = build(expression);
        const int a = dfs0(root), b = dfs1(root);
        // cout << a << "," << b << endl;
        return abs(a - b);
    }
private:
    unordered_map<TNode*, int> f0, f1;
    const int maxn = numeric_limits<int>::max() / 2;
    
    int dfs1(TNode* root) {
        if (f1.count(root)) return f1[root];
        
        int ans = maxn;
        if (root->cur == '&') {
            ans = dfs1(root->left) + dfs1(root->right);
            
            ans = min(ans, 1 + min(
                dfs1(root->left) + dfs1(root->right), 
                min(
                    dfs1(root->left) + dfs0(root->right), 
                    dfs0(root->left) + dfs1(root->right)
                ))); // |
        } else if (root->cur == '|') {
            ans = min(ans, 1 + dfs1(root->left) + dfs1(root->right));
            
            ans = min(ans, min(
                dfs1(root->left) + dfs1(root->right), 
                min(
                    dfs1(root->left) + dfs0(root->right), 
                    dfs0(root->left) + dfs1(root->right)
                )));
        } else if (root->cur == '0') {
            ans = 1;
        } else if (root->cur == '1') {
            ans = 0;
        } else {
            // cout << root->cur << endl;
        }
        return f1[root] = ans; 
    }
    
    int dfs0(TNode* root) {
        if (f0.count(root)) return f0[root];
        
        int ans = maxn;
        if (root->cur == '&') {
            ans = 1 + dfs0(root->left) + dfs0(root->right);
            ans = min(ans, min(
                dfs0(root->left) + dfs0(root->right), 
                min(
                    dfs1(root->left) + dfs0(root->right), 
                    dfs0(root->left) + dfs1(root->right)
                )));
        } else if (root->cur == '|') {
            ans = dfs0(root->left) + dfs0(root->right);
            
            ans = min(ans, 1 + min(
                dfs0(root->left) + dfs0(root->right), 
                min(
                    dfs1(root->left) + dfs0(root->right), 
                    dfs0(root->left) + dfs1(root->right)
                )));
        } else if (root->cur == '0') {
            ans = 0;
        } else if (root->cur == '1') {
            ans = 1;
        } else {
            // cout << root->cur << endl;
        }
        return f0[root] = ans; 
    }
    
    
    vector<char> postfix;
    int ptr = 0;
    TNode* build(const string& expr) {
        const char& str = postfix[ptr--];
        TNode* node = new TNode(str);
        
        if (operation.count(str)) {
            node->right = build(expr);
            node->left = build(expr);
        }
        return node;
    }
    
    unordered_map<char, int> operation = {
        {'&', 1},
        {'|', 1},
    };
    vector<char> convert(const string& expr) {
        vector<char> answer;
        
        vector<char> stk;
        for (const char& s : expr) {
            if (operation.count(s)) {
                const int p = operation[s];
                
                while (!stk.empty()) {
                    const char& back = stk.back();
                    
                    if (operation.count(back)) {
                        const int cp = operation[back];
                        if (p <= cp) {
                            answer.push_back(back);
                            stk.pop_back();
                        }
                        else break;
                    } else if (back == '(') break;
                }
                
                stk.push_back(s);
            } else if (s == '(') {
                stk.push_back(s);
            } else if (s == ')') {
                while (!stk.empty()) {
                    const char& back = stk.back();
                    
                    if (back == '(') {
                        stk.pop_back();
                        break;
                    } else {
                        answer.push_back(back);
                        stk.pop_back();
                    }
                }
            } else {
                answer.push_back(s);
            }
        }
        
        while (!stk.empty()) {
            answer.push_back(stk.back());
            stk.pop_back();
        }
        return answer;
    }
};