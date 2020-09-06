class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return overlap(rec1[0], rec1[2], rec2[0], rec2[2]) && overlap(rec1[1], rec1[3], rec2[1], rec2[3]);
    }
private:
    bool overlap(int l1, int r1, int l2, int r2) {
        return max(l1, l2) < min(r1, r2);
    }
};