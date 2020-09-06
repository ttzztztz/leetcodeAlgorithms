/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minCameraCover(TreeNode* root) {
        tuple<int, int, int> answer = dp(root);
        return min(get<1>(answer), get<2>(answer));
    }
    tuple<int, int, int> dp(TreeNode* root) {
        if (root == nullptr) {
            return make_tuple(0, 0, 999999);
        }
        tuple<int, int, int> left = dp(root->left), right = dp(root->right);

        int state0 = get<1>(left) + get<1>(right);
        int state1 = min(get<2>(left) + min(get<1>(right), get<2>(right)), get<2>(right) + min(get<1>(left), get<2>(left)));
        int state2 = 1 + min(get<0>(left), min(get<1>(left), get<2>(left))) + min(get<0>(right), min(get<1>(right), get<2>(right)));

        return make_tuple(state0, state1, state2);
    }
};