class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        const int n = arr.size();
        
        vector<int> pos1;
        for (int i = 0; i < n; i++) {
            if (arr[i] == 1) pos1.push_back(i);
        }
        
        if (pos1.size() % 3 != 0) return { -1, -1 };
        if (pos1.empty()) return { 0, 2 };
        const int m = pos1.size();
        
        int a_end = pos1[(m / 3) - 1], b_end = pos1[(m / 3 * 2) - 1];
        int b_start = pos1[m / 3], c_start = pos1[m / 3 * 2];
        int c_end = n - 1;
        
        const int tail_zeros = n - pos1.back() - 1;
        if (a_end + tail_zeros >= b_start) return { -1, -1 };
        if (b_end + tail_zeros >= c_start) return { -1, -1 };
        
        for (
            int delta = 0;
            
            a_end + tail_zeros - delta >= 0 
            && b_end + tail_zeros - delta > a_end 
            && c_end - delta > b_end;
            
            delta++
        ) {
            
            if (
                arr[a_end + tail_zeros - delta] == arr[b_end + tail_zeros - delta]
                && arr[b_end + tail_zeros - delta] == arr[c_end - delta]
            ) {
                continue;
            } else {
                return { -1, -1 };
            }
        }
        return { a_end + tail_zeros, b_end + tail_zeros + 1 };
    }
};