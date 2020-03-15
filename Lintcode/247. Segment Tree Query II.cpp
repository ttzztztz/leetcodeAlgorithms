/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end, count;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int count) {
 *         this->start = start;
 *         this->end = end;
 *         this->count = count;
 *         this->left = this->right = NULL;
 *     }
 * }
 */


class Solution {
public:
    /*
     * @param root: The root of segment tree.
     * @param start: start value.
     * @param end: end value.
     * @return: The count number in the interval [start, end]
     */
    int query(SegmentTreeNode * root, int start, int end) {
        if (root == nullptr) return 0;
        if (start <= root->start && root->end <= end) {
            return root->count;
        }
        
        int answer = 0;
        const int mid = (root->start + root->end) >> 1;
        if (start <= mid) answer += query(root->left, start, end);
        if (mid < end) answer += query(root->right, start, end);
        return answer;
    }
};
