class Solution {
public:
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        unordered_map<string, string> parent;

        for (const vector<string>& region : regions) {
            for (int i = 1; i < region.size(); i++) {
                const string& r = region[i];
                parent[r] = region[0];
            }
        }

        vector<string> region1Parent, region2Parent;
        while (region1 != "") {
            region1Parent.push_back(region1);
            region1 = parent[region1];
        }
        while (region2 != "") {
            region2Parent.push_back(region2);
            region2 = parent[region2];
        }
        int ptr1 = region1Parent.size() - 1, ptr2 = region2Parent.size() - 1;

        while (ptr1 >= 0 && ptr2 >= 0 && region1Parent[ptr1] == region2Parent[ptr2]) {
            ptr1--,ptr2--;
        }
        return region1Parent[ptr1 + 1];
    }
};