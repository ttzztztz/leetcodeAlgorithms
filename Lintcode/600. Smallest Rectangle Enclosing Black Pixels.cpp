class Solution {
public:
    /**
     * @param image: a binary matrix with '0' and '1'
     * @param x: the location of one of the black pixels
     * @param y: the location of one of the black pixels
     * @return: an integer
     */
    int N, M;
    int minArea(vector<vector<char>> &image, int x, int y) {
        N = image.size(), M = image[0].size();
        
        int left = binary_search_left(image, 0, y);
        int right = binary_search_right(image, y, M - 1);
        int top = binary_search_top(image, 0, x);
        int bottom = binary_search_bottom(image, x, N - 1);
        
        return (right - left + 1) * (bottom - top + 1);
    }
private:
    int binary_search_left(const vector<vector<char>> &image, int left, int right) {
        while (left <= right) {
            const int mid = (left + right) >> 1;
            
            bool haveOne = false;
            for (int i = 0; i < N; i++) {
                if (image[i][mid] == '1') {
                    haveOne = true;
                    break;
                }
            }
            
            if (haveOne) right = mid - 1;
            else left = mid + 1;
        }
        return left;
    }
    
    int binary_search_right(const vector<vector<char>> &image, int left, int right) {
        while (left <= right) {
            const int mid = (left + right) >> 1;
            
            bool haveOne = false;
            for (int i = 0; i < N; i++) {
                if (image[i][mid] == '1') {
                    haveOne = true;
                    break;
                }
            }
            
            if (haveOne) left = mid + 1;
            else right = mid - 1;
        }
        return left - 1;
    }
    
    int binary_search_top(const vector<vector<char>> &image, int left, int right) {
        while (left <= right) {
            const int mid = (left + right) >> 1;
            
            bool haveOne = false;
            for (int i = 0; i < M; i++) {
                if (image[mid][i] == '1') {
                    haveOne = true;
                    break;
                }
            }
            
            if (haveOne) right = mid - 1;
            else left = mid + 1;
        }
        return left;
    }
    
    int binary_search_bottom(const vector<vector<char>> &image, int left, int right) {
        while (left <= right) {
            const int mid = (left + right) >> 1;
            
            bool haveOne = false;
            for (int i = 0; i < M; i++) {
                if (image[mid][i] == '1') {
                    haveOne = true;
                    break;
                }
            }
            
            if (haveOne) left = mid + 1;
            else right = mid - 1;
        }
        return left - 1;
    }
};
