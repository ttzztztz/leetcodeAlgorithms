/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int calc1InRow(BinaryMatrix &binaryMatrix, int i) {
        int answer = 0;
        for (int j = 0; j < n; j++) answer += binaryMatrix.get(j, i);
        return answer;
    }
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dim = binaryMatrix.dimensions();
        n = dim[0], m = dim[1];
        
        int left = 0, right = m - 1;
        while (left < right) {
            const int mid = (left + right) >> 1;
            const int tmp = calc1InRow(binaryMatrix, mid);
            
            if (tmp >= 1) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        if (calc1InRow(binaryMatrix, left) >= 1) return left;
        else return -1;
    }
private:
    int n, m;
};
