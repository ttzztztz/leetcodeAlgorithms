/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

 class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (int i = nestedList.size() - 1; i >= 0; i--) {
            data.push_back(nestedList[i]);
        }
    }
    
    int next() {
        if (!hasNext()) return -1;

        const int val = data.back().getInteger();
        data.pop_back();
        return val;
    }
    
    bool hasNext() {
        while (!data.empty() && !data.back().isInteger()) {
            NestedInteger item = data.back();
            data.pop_back();

            vector<NestedInteger> next = item.getList();
            for (int i = next.size() - 1; i >= 0; i--) {
                data.push_back(next[i]);
            }
        }

        return !data.empty();
    }
private:
    vector<NestedInteger> data;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */