class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        const int N = arr.size();

        int ptr = 0;
        for (int i = 0; i < N; i++) {
            if (arr[i] != 0) {
                arr[ptr] = arr[i];
                ptr++;
            }
        }

        for (int i = ptr; i < N; i++) arr[i] = 0;
    }
};
