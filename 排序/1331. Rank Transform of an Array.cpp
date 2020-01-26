class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        const int N = arr.size();
        vector<int> numbers;
        for (int i = 0; i < N; i++) {
            numbers.push_back(arr[i]);
        }
        sort(numbers.begin(), numbers.end());
        auto end = unique(numbers.begin(), numbers.end());
        vector<int> answer(N, 0);
        for (int i = 0; i < N; i++) {
            answer[i] = lower_bound(numbers.begin(), end, arr[i]) - numbers.begin() + 1;
        }
        
        return answer;
    }
};
