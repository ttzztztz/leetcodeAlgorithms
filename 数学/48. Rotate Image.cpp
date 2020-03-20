class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        const int N = matrix.size();
        
        int left = 0, right = N - 1;
        while (left < right) {
            for (int i = 0; i < right - left; i++) {
                const int a = matrix[left][left + i];
                const int b = matrix[left + i][right];
                const int c = matrix[right][right - i];
                const int d = matrix[right - i][left];
                
                matrix[left][left + i] = d;
                matrix[left + i][right] = a;
                matrix[right][right - i] = b;
                matrix[right - i][left] = c;
            }
            left++, right--;
        }
        
    }
};
