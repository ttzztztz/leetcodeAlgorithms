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
     * @param root: The root of segment tree.
     * @param start: start value.
     * @param end: end value.
     * @return: The maximum number in the interval [start, end]
     */
    int query(SegmentTreeNode * root, int start, int end) {
        if (start <= root->start && root->end <= end) {
            return root->max;
        }
        
        int answer = numeric_limits<int>::min();
        const int mid = (root->start + root->end) >> 1;
        if (start <= mid) answer = max(answer, query(root->left, start, end));
        if (mid < end) answer = max(answer, query(root->right, start, end));
        return answer;
    }
};
