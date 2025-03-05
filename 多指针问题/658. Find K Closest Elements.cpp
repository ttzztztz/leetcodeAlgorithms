class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        const int n = arr.size();
    
        deque<int> ans;
        auto it = upper_bound(arr.begin(), arr.end(), x);
        int r = it - arr.begin();
        int l = r - 1;

        for (int i = 0; i < k; i++) {
            if (r >= n || (l >= 0 && r < n && abs(arr[l] - x) <= abs(arr[r] - x))) {
                ans.push_front(arr[l]);
                l--;
            } else if (l < 0 || (l >= 0 && r < n && abs(arr[l] - x) > abs(arr[r] - x))) {
                ans.push_back(arr[r]);
                r++;
            }
        }
        return vector<int>(ans.begin(), ans.end());
    }
};