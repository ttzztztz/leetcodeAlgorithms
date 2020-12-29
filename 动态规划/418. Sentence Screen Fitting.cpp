class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int ptr = 0, ans = 0;
        const int n = sentence.size();
        
        unordered_map<int, pair<int, int>> memo;
        for (int i = 0; i < rows; i++) {
            const int key = ptr;
            if (memo.count(key)) {
                auto [delta_ans, end_ptr] = memo[key];
                ans += delta_ans;
                ptr = end_ptr;
            } else {
                int delta_ans = 0, j = 0;
                while (j + sentence[ptr].size() <= cols) {
                    j += sentence[ptr].size() + 1;
                    ptr = (ptr + 1) % n;
                    if (ptr == 0) ans++, delta_ans++;
                }
                memo[key] = { delta_ans, ptr };
            }
        }
        return ans;
    }
};
