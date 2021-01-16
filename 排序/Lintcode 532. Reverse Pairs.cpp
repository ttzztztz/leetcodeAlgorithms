class Solution {
public:
    /**
     * @param A: an array
     * @return: total of reverse pairs
     */
    long long reversePairs(vector<int> &arr) {
        // write your code here
        if (arr.empty()) return 0;
        sort(arr, 0, arr.size() - 1);
        
        return ans;
    }
private:
    long long ans = 0;
    void sort(vector<int> &arr, int l, int r) {
        if (l >= r) return;
        const int mid = (l + r) / 2;
        
        sort(arr, l, mid);
        sort(arr, mid + 1, r);
        
        merge(arr, l, mid, mid + 1, r);
    }
    
    void merge(vector<int>& arr, int l1, int r1, int l2, int r2) {
        const int len1 = r1 - l1 + 1, len2 = r2 - l2 + 1;
        vector<int> tmp(len1 + len2, 0);
        
        int ptr1 = 0, ptr2 = 0;
        while (ptr1 < len1 && ptr2 < len2) {
            if (arr[l1 + ptr1] <= arr[l2 + ptr2]) {
                tmp[ptr1 + ptr2] = arr[l1 + ptr1];
                ptr1++;
            } else {
                tmp[ptr1 + ptr2] = arr[l2 + ptr2];
                ptr2++;
                
                ans += len1 - ptr1;
            }
        }
        
        while (ptr1 < len1) {
            tmp[ptr1 + ptr2] = arr[l1 + ptr1];
            ptr1++;
        }
        
        while (ptr2 < len2) {
            tmp[ptr1 + ptr2] = arr[l2 + ptr2];
            ptr2++;
        }
        
        for (int i = l1; i <= r2; i++) {
            arr[i] = tmp[i - l1];
        }
    }
};
