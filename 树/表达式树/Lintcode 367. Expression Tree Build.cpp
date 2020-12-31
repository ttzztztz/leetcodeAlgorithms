/**
 * Definition of ExpressionTreeNode:
 * class ExpressionTreeNode {
 * public:
 *     string symbol;
 *     ExpressionTreeNode *left, *right;
 *     ExpressionTreeNode(string symbol) {
 *         this->symbol = symbol;
 *         this->left = this->right = NULL;
 *     }
 * }
 */


class Solution {
public:
    /*
     * @param expression: A string array
     * @return: The root of expression tree
     */
    ExpressionTreeNode * build(vector<string> &expression) {
        vector<string> expr = convert(expression);
        ptr = expr.size() - 1;
        if (expr.empty()) return nullptr;
        return buildTree(expr);
    }
    
private:
    unordered_map<string, int> operation = {
        {"+", 1},
        {"-", 1},
        {"*", 2},
        {"/", 2}
    };

    ExpressionTreeNode* buildTree(const vector<string> &expression) {
        const string& str = expression[ptr--];
        ExpressionTreeNode* node = new ExpressionTreeNode(str);
        
        if (operation.count(str)) {
            node->right = buildTree(expression);
            node->left = buildTree(expression);
        }
        
        return node;
    }
    int ptr = 0;
    vector<string> convert(const vector<string>& input) {
        vector<string> answer;
        
        vector<string> stk;
        for (const string& s : input) {
            if (operation.count(s)) {
                const int p = operation[s];
                
                while (!stk.empty()) {
                    const string& back = stk.back();
                    
                    if (operation.count(back)) {
                        const int cp = operation[back];
                        if (p <= cp) {
                            answer.push_back(back);
                            stk.pop_back();
                        }
                        else break;
                    } else if (back == "(") break;
                }
                
                stk.push_back(s);
            } else if (s == "(") {
                stk.push_back(s);
            } else if (s == ")") {
                while (!stk.empty()) {
                    const string& back = stk.back();
                    
                    if (back == "(") {
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
