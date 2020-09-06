class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        const int N = nums.size();
        
        int left = 0, right = N - 1;
        
        while (left <= right) {
            const int mid = (left + right) >> 1;
            cout << left << ", " << right << ", " << mid << ", " << nums[mid] << endl;
            
            if (mid >= 1 && nums[mid] == nums[mid - 1]) {
                const int len_left = mid - 2 - left + 1;
                if (len_left % 2 == 1) {
                    right = mid - 2;
                } else {
                    left = mid + 1;
                }
            } else if (mid + 1 < N && nums[mid] == nums[mid + 1]) {
                const int len_right = right - (mid + 2) + 1;
                if (len_right % 2 == 1) {
                    left = mid + 2;
                } else {
                    right = mid - 1;
                }
            } else {
                return nums[mid];
            }
        }
        
        return -1; // never reach this branch
    }
};
