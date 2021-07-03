class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        deque<int> ans;
        const int n = arr.size();
        
        auto it = lower_bound(arr.begin(), arr.end(), x);
        int r = it - arr.begin(), l = r - 1;
        while (l >= 0 && r < n && ans.size() < k) {
            if (
                abs(arr[l] - x) < abs(arr[r] - x) 
                || (abs(arr[l] - x) == abs(arr[r] - x) && l < r)
            ) {
                ans.push_front(arr[l]);
                l--;
            } else {
                ans.push_back(arr[r]);
                r++;
            }
        }
        
        while (l >= 0 && ans.size() < k) {
            ans.push_front(arr[l]);
            l--;
        }
        while (r < n && ans.size() < k) {
            ans.push_back(arr[r]);
            r++;
        }
        
        return vector<int>(ans.begin(), ans.end());
    }
};