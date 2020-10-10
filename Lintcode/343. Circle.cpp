class Solution {
public:
    /**
     * @param circles: The value of 6 points on n rings
     * @return: Whether there are two same circles
     */
    bool samecircle(vector<vector<int>> &circles) {
        unordered_set<string> vis;
        for (vector<int> circle : circles) {
            sort(circle.begin(), circle.end());
            
            const string h = _hash(circle);
            if (vis.count(h)) return true;
            else vis.insert(h);
        }
        
        return false;
    }
private:
    string _hash(const vector<int>& circle) {
        string ans;
        for (int i : circle) ans += to_string(i) + ",";
        ans.pop_back();
        return ans;
    }
};
