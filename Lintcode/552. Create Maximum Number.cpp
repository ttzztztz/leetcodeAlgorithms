class Solution {
public:
    /**
     * @param nums1: an integer array of length m with digits 0-9
     * @param nums2: an integer array of length n with digits 0-9
     * @param k: an integer and k <= m + n
     * @return: an integer array
     */
    vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k) {
        vector<int> answer(k, 0);
        const int N = nums1.size(), M = nums2.size();
        for (int i = 0; i <= k; i++) {
            const int p1 = i, p2 = k - i;
            if (p1 < 0 || p2 < 0 || p1 > N || p2 > M) continue;
            
            vector<int> $1 = split(nums1, p1);
            vector<int> $2 = split(nums2, p2);
            
            vector<int> temp = merge($1, $2);
            answer = max(answer, temp);
        }
        return answer;
    }
    
    vector<int> split(const vector<int>& arr, int k) {
        const int N = arr.size();
        int remain = N - k;
        if (remain <= 0) return arr;
        vector<int> answer;
        
        for (int i = 0; i < N; i++) {
            while (!answer.empty() && arr[i] > answer.back() && remain) {
                remain--;
                answer.pop_back();
            }
            
            answer.push_back(arr[i]);
        }
        while (remain) {
            answer.pop_back();
            remain--;
        }
        return answer;
    }
    
    vector<int> merge(const vector<int>& $1, const vector<int>& $2) {
        vector<int> answer;
        
        const int N = $1.size(), M = $2.size();
        int ptr1 = 0, ptr2 = 0;
        
        while (ptr1 < N || ptr2 < M) {
            if (lexicographical_compare($1.begin() + ptr1, $1.end(), $2.begin() + ptr2, $2.end())) {
                answer.push_back($2[ptr2++]);
            } else {
                answer.push_back($1[ptr1++]);
            }
        }
        
        return answer;
    }
};
