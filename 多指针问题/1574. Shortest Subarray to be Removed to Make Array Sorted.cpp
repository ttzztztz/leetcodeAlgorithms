class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        const int n = arr.size();
        
        int l = 1, r = n - 2;
        while (l < n && arr[l] >= arr[l - 1]) l++;
        while (l <= r && arr[r + 1] >= arr[r]) r--;
        
        int answer = min(n - l, r + 1);
    
        for (int left = 0, right = r + 1; left < l; left++) {
            while (right < n && arr[left] > arr[right]) {
                right++;
            }
            
            answer = min(answer, max(0, right - left - 1));
        }
        
        return answer;
    }
};