class SnapshotArray {
public:
    SnapshotArray(int length) {
        
    }
    
    void set(int index, int val) {
        if (!data[index].empty() && data[index].rbegin()->first == cur) {
            data[index].rbegin()->second = val;
            return;
        }
        data[index].emplace_back(cur, val);
    }
    
    int snap() {
        return cur++;
    }
    
    int get(int index, int snap_id) {
        auto it = lower_bound(data[index].begin(), data[index].end(), make_pair(snap_id, -1));
        if (it != data[index].end() && it->first == snap_id) return it->second;
        if (it == data[index].begin()) return 0;
        it--;
        return it->second;
    }
private:
    unordered_map<int, vector<pair<int, int>>> data;
    int cur = 0;
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */