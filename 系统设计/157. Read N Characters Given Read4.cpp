/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    Solution() {
        memset(buffer_, 0, sizeof buffer_);
    }
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (!read_one(buf + i)) return cnt;
            cnt++;
        }
        return cnt;
    }
private:
    char buffer_[4];
    int ptr_ = 0;
    int len_ = 0;
    
    bool read_one(char* buf) {
        if (ptr_ == len_) {
            len_ = read4(buffer_);
            ptr_ = 0;
        }
        
        if (len_ == 0) {
            return false;
        } else {
            *buf = buffer_[ptr_];
            ptr_++;
            return true;
        }
    }
};
