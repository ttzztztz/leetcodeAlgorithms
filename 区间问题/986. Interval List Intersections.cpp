class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ans;
        sort(firstList.begin(), firstList.end());
        sort(secondList.begin(), secondList.end());
        
        int ptr1 = 0, ptr2 = 0;
        const int len1 = firstList.size(), len2 = secondList.size();
        while (ptr1 < len1 && ptr2 < len2) {
            const int l1 = firstList[ptr1][0], r1 = firstList[ptr1][1];
            const int l2 = secondList[ptr2][0], r2 = secondList[ptr2][1];

            if (max(l1, l2) <= min(r1, r2)) {
                ans.push_back(vector<int>{ max(l1, l2), min(r1, r2) });
            }

            if (r1 <= r2) ptr1++;
            else ptr2++;
        }
        return ans;
    }
};