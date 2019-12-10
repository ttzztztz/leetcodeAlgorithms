/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string answer;

        deque<TreeNode*> queue;
        queue.push_back(root);
        while (!queue.empty()) {
            TreeNode* node = queue.front();
            queue.pop_front();

            if (node == nullptr) {
                answer += "N ";
            } else {
                answer += to_string(node->val);
                answer += " ";

                queue.push_back(node->left), queue.push_back(node->right);
            }
        }

        return answer;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss;
        ss << data;
        string buffer;

        TreeNode *answer;
        deque<TreeNode **> queue;
        queue.push_back(&answer);

        while (ss >> buffer) {
            TreeNode **current = queue.front();
            queue.pop_front();

            if (buffer == "N") {
                *current = nullptr;
            } else {
                TreeNode* node = new TreeNode(stoi(buffer));
                *current = node;

                queue.push_back(&(node->left));
                queue.push_back(&(node->right));
            }
        }
        return answer;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));