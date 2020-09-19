#include <list>

class LRUCache {
public:
    /*
    * @param capacity: An integer
    */
    LRUCache(int capacity) {
        this->k = capacity;
    }

    /*
     * @param key: An integer
     * @return: An integer
     */
    int get(int key) {
        int ans = -1;
        if (hashmap.count(key)) {
            ans = hashmap[key];
            
            auto it = bindptr[key];
            ls.erase(it);
            ls.push_front(key);
            bindptr[key] = ls.begin();
        }
        
        return ans;
    }

    /*
     * @param key: An integer
     * @param value: An integer
     * @return: nothing
     */
    void set(int key, int value) {
        // write your code here
        if (hashmap.count(key)) {
            hashmap[key] = value;
            auto it = bindptr[key];
            ls.erase(it);
            ls.push_front(key);
            bindptr[key] = ls.begin();
        } else {
            if (ls.size() == k) {
                hashmap[key] = value;
                
                const int oldkey = *ls.rbegin();
                auto it = bindptr[oldkey];
                ls.erase(it);
                ls.push_front(key);
                bindptr[key] = ls.begin();
                hashmap.erase(oldkey);
            } else {
                hashmap[key] = value;
                ls.push_front(key);
                bindptr[key] = ls.begin();
            }
        }
        
    }
private:
    list<int> ls;
    int k;
    unordered_map<int, int> hashmap;
    unordered_map<int, std::list<int>::iterator> bindptr;
};
