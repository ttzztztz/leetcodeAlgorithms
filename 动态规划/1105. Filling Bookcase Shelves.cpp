class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        memset(f, 0xff, sizeof f);
        N = books.size();
        
        return dfs(books, shelf_width, 0);
    }
private:
    int f[1005];
    int N;
    int dfs(const vector<vector<int>>& books, const int w, int i) {
        if (i == N) return 0;
        if (f[i] != -1) return f[i];
        
        int answer = 999999;
        int max_height = 0, total_width = 0;
        for (int j = i; j < N; j++) {
            const int width = books[j][0], height = books[j][1];
            
            total_width += width;
            max_height = max(max_height, height);
            
            if (total_width > w) break;
            answer = min(answer, max_height + dfs(books, w, j + 1));
        }
        return f[i] = answer;
    }
};
