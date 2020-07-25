class Solution {
public:
    /**
     * @param offset: the number of items that the customer has viewed
     * @param n: the number of items that can be displayed on a page
     * @param len1: the length of L1
     * @param len2: the length of L2
     * @return: returns the intervals of goods displayed in L1 and L2
     */
    vector<int> ProductList(int offset, int n, int len1, int len2) {
        vector<int> answer = {0, 0, 0, 0};
        
        const int start = len1;
        answer[0] = min(len1, offset);
        answer[1] = min(len1, offset + n);
        answer[2] = max(0, min(len2, offset - len1));
        answer[3] = max(0, min(len2, offset + n - len1));
        
        return answer;
    }
};