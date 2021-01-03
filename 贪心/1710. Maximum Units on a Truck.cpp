class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](const auto& $1, const auto& $2) -> bool {
            return $1[1] > $2[1];
        });
        
        int ans = 0, ptr = 0;
        while (truckSize > 0 && ptr < boxTypes.size()) {
            const int num = boxTypes[ptr][0], unit = boxTypes[ptr][1];
            const int pick = min(num, truckSize);
            ans += pick * unit;
            truckSize -= pick;
            ptr++;
        }
        return ans;
    }
};
