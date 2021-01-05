class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        if (image.empty()) return 0;
        
        n = image.size(), m = image[0].size();
        int l = bs1(image, 0, x, 0), r = bs1(image, x, n - 1, 1);
        int t = bs2(image, 0, y, 0), b = bs2(image, y, m - 1, 1);
        
        return (r - l + 1) * (b - t + 1);
    }
private:
    int n, m;
    int bs1(const vector<vector<char>>& image, int l, int r, int dir) {
        // 0 [0 0 0 0 1 1 1]
        // 1 [1 1 1 1 0 0 0]
        
        while (l <= r) {
            const int mid = l + (r - l) / 2;
            
            int cnt_1 = 0;
            for (int j = 0; j < m; j++) cnt_1 += (image[mid][j] == '1');
            
            if (dir == 0) { // l
                if (cnt_1) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else { // r
                if (cnt_1) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        
        
        if (dir == 0) {
            return l;
        } else {
            return r;
        }
    }
    
    int bs2(const vector<vector<char>>& image, int l, int r, int dir) {
        // 0 [0 0 0 0 1 1 1]
        // 1 [1 1 1 1 0 0 0]
        
        while (l <= r) {
            const int mid = l + (r - l) / 2;
            
            int cnt_1 = 0;
            for (int j = 0; j < n; j++) cnt_1 += (image[j][mid] == '1');
            
            if (dir == 0) { // l
                if (cnt_1) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else { // r
                if (cnt_1) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        
        
        if (dir == 0) {
            return l;
        } else {
            return r;
        }
    }
};
