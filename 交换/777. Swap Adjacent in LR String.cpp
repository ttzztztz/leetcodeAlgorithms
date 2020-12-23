class Solution {
public:
    bool canTransform(string start, string end) {
        if (start.size() != end.size()) return false;
        
        int l = 0, r = 0;
        for (int i = 0; i < start.size(); i++) {
            if (start[i] == 'L') l++;
            else if (start[i] == 'R') r++;
            
            if (end[i] == 'L') l--;
            else if (end[i] == 'R') r--;
        }
        if (l != 0 || r != 0) return false;
        
        for (int i = 0, j = 0; i < end.size(); i++) {
            if (end[i] == 'X') continue;
            while (j < start.size() && start[j] == 'X') j++;
            
            if (j >= start.size() || end[i] != start[j]) return false;
            if (end[i] == 'L') {
                if (j < i) return false;
            } else { // end[i] == 'R'
                if (j > i) return false;
            }
            j++;
        }
        
        return true;
    }
};
