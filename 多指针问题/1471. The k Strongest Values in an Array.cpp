class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        const int N = arr.size();
        sort(arr.begin(), arr.end());
        const int m = arr[(N - 1) / 2];
        
        vector<int> answer;
        int ptr1 = 0, ptr2 = N - 1;
        while (answer.size() < k) {
            if (abs(arr[ptr1] - m) > abs(arr[ptr2] - m)) {
                answer.push_back(arr[ptr1++]);
            } else {
                answer.push_back(arr[ptr2--]);
            }
        }
        return answer;
    }
};
