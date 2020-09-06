class Solution {
public:
    /**
     * @param onHand: the expiry days of m units of creamer already in stock
     * @param supplier: the expiry days of n units of creamer available for order
     * @param demand: the maximum units of creamer employees will uses daily
     * @return: the maximum units of creamer the manager can order without waste
     */
    int stockLounge(vector<int> &onHand, vector<int> &supplier, int demand) {
        // write your code here
        sort(onHand.begin(), onHand.end());
        sort(supplier.begin(), supplier.end());
        
        const int maxDay = max(
            *onHand.rbegin(), *supplier.rbegin());
        vector<int> used(maxDay + 1, 0);
        int ptr1 = 0;
        for (int i = 0; i <= maxDay; i++) {
            int use = 0;
            while (ptr1 < onHand.size() && onHand[ptr1] >= i && use < demand) {
                ptr1++;
                use++;
            }
        }
        
        if (ptr1 != onHand.size()) return -1;
        int answer = 0, ptr2 = 0;
        ptr1 = 0;
        
        for (int i = 0; i <= maxDay; i++) {
            while (ptr1 < onHand.size() && onHand[ptr1] <= i && used[i] < demand) {
                ptr1++;
                used[i]++;
            }
            while (ptr2 < supplier.size() && supplier[ptr2] < i) ptr2++;
            while (ptr2 < supplier.size() && used[i] < demand) {
                ptr2++;
                used[i]++;
                answer++;
            }
        }
        
        return answer;
    }
};
