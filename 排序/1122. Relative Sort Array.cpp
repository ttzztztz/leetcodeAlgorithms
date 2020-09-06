class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> ord;
        int inc = 0;
        for (int i : arr2) ord[i] = ++inc;
        
        inc++;
        for (int i : arr1) if (!ord.count(i)) ord[i] = inc;
        
        sort(arr1.begin(), arr1.end(), [&](const int $1, const int $2) -> bool {
            if (ord[$1] == ord[$2]) {
                return $1 < $2;
            } else {
                return ord[$1] < ord[$2];
            }
        });
        
        return arr1;
    }
};