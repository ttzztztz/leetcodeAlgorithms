class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        memset(f, 0xff, sizeof f);
        this->target = target;
        
        for (int i = 0; i < arr.size(); i++) {
            prefix.push_back(prefix[i] + arr[i]);
        }
        
        const int answer = dfs(arr, 0, 0);
        if (answer >= MAX) return -1;
        else return answer;
    }
private:
    int f[100005][2];
    vector<int> prefix = {0};
    const int MAX = 999999;
    int target;
    
    int dfs(const vector<int>& arr, int i, int cnt) {
        if (cnt == 2) return 0;
        if (i == arr.size()) return MAX;
        int& val = f[i][cnt];
        if (val != -1) return val;
        
        int answer = MAX;
        answer = min(answer, dfs(arr, i + 1, cnt));
        auto it = lower_bound(prefix.begin(), prefix.end(), prefix[i] + target);
        if (it != prefix.end() && *it == prefix[i] + target) {
            const int d = it - prefix.begin();
            answer = min(answer, d - i + dfs(arr, d, cnt + 1));
        }
        
        return val = answer;
    }
};
