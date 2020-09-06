class Solution {
public:
    int lowbit(int x) {
        return x & (-x);
    }
    int cnt(int x) {
        int answer = 0;
        while (x) {
            answer++;
            x -= lowbit(x);
        }
        return answer;
    }
    vector<int> sortByBits(vector<int>& arr) {
        const int N = arr.size();
        vector<pair<int, int>> bit;
        for (int i : arr) {
            bit.emplace_back(i, cnt(i));
        }
        
        sort(bit.begin(), bit.end(), [&](const auto& $1, const auto& $2)->bool {
            if ($1.second == $2.second) return $1.first < $2.first;
            return $1.second < $2.second;
        });
        for (int i = 0; i < N; i++) arr[i] = bit[i].first;
        return arr;
    }
};
