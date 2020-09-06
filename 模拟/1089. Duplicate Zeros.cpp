class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        vector<int> f = arr;
        const int N = arr.size();
        
        int ptr = 0;
        for (int i = 0; i < N; i++) {
            if (f[ptr] == 0) {
                arr[i] = 0;
                i++;
                if (i < N) arr[i] = 0;
                ptr++;
            } else {
                arr[i] = f[ptr++];
            }
        }
    }
};