class NumberContainers {
public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if (val_map.count(index)) {
            const int old_number = val_map[index];
            index_map[old_number].erase(index);
            if (index_map[old_number].empty()) index_map.erase(old_number);
        }

        val_map[index] = number;
        index_map[number].insert(index);
    }
    
    int find(int number) {
        if (!index_map.count(number)) return -1;
        return *index_map[number].begin();
    }
private:
    unordered_map<int, int> val_map;
    unordered_map<int, set<int>> index_map;
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */