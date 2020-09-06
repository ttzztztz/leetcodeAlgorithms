// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf destination buffer
     * @param n maximum number of characters to read
     * @return the number of characters read
     */
    int read(char *buf, int n) {
        int result = 0;
        for (int i = 0; i < n; i++) {
            int tmp = _read(buf);
            if (tmp == 0) break;
            else {
                result++;
                buf++;
            }
        }
        return result;
    }
private:
    char tmp[4];
    int _read(char* buf) {
        static int tmp_ptr = 0, tmp_size = 0;
        if (tmp_ptr == tmp_size) {
            tmp_ptr = 0;
            tmp_size = read4(tmp);
        }
        
        if (tmp_ptr == tmp_size) return 0;
        
        *buf = *(tmp + tmp_ptr);
        tmp_ptr++;
        return 1;
    }
};
