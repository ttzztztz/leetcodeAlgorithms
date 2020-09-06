class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        this->A = A;
        
        dfs(0);
        if (ans == make_pair(-1, -1)) return "";
        else return realAnswer;
    }
private:
    vector<int> A;
    pair<int, int> ans = {-1, -1};
    string realAnswer;
    string cur;
    
    bool valid(int h, int m) {
        return h >= 0 && h <= 23 && m >= 0 && m <= 59;
    }
    
    void dfs(int state) {
        if (state == (1 << 4) - 1) {
            const int h = stoi(cur.substr(0, 2));
            const int m = stoi(cur.substr(2, 2));
            
            pair<int, int> tmp = {h, m};
            if (valid(h, m) && (ans == make_pair(-1, -1) || tmp > ans)) {
                ans = tmp;
                realAnswer = cur.substr(0, 2) + ":" + cur.substr(2, 2);
            }
            
            return;
        }
        
        for (int j = 0; j < 4; j++) {
            if (!(state & (1 << j))) {
                cur += '0' + A[j];
                dfs(state | (1 << j));
                cur.pop_back();
            }
        }
    }
};