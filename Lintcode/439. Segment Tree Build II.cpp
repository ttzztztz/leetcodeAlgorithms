/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end, max;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int max) {
 *         this->start = start;
 *         this->end = end;
 *         this->max = max;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param A: a list of integer
     * @return: The root of Segment Tree
     */
    SegmentTreeNode * build(vector<int> &A) {
        const int N = A.size();
        return dfs(A, 0, N - 1);
    }
private:
    SegmentTreeNode * dfs(const vector<int> &A, int left, int right) {
        const int N = A.size();
        if (left > right) return nullptr;
        
        const int mid = (left + right) >> 1;
        SegmentTreeNode* cur = new SegmentTreeNode(left, right);
        if (left == right) {
            cur->max = A[left];
            return cur;
        }
        
        cur->left = dfs(A, left, mid);
        cur->right = dfs(A, mid + 1, right);
        cur->max = max(cur->right->max, cur->left->max);
        
        return cur;
    }
};
