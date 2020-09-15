class Solution {
public:
    class SegmentTreeNode {
    public:
        int left, right;
        long long sum, lazyTag;
    
        SegmentTreeNode() : left(0), right(0), sum(0), lazyTag(0) {};
    };
    /**
     * @param positions: a list of (left, side_length)
     * @return: return a list of integer
     */
    vector<int> fallingSquares(vector<vector<int>> &positions) {
        memset(treeNode, 0, sizeof treeNode);
        const int n = positions.size();
        vector<int> answer(n, 0);
        vector<int> all;
        for (int i = 0; i < n; i++) {
            all.push_back(positions[i][0]);
            all.push_back(positions[i][0] + positions[i][1]);
        }
        sort(all.begin(), all.end());
        auto endIt = unique(all.begin(), all.end());
        
        build(1, 0, 2 * n + 5);
        for (int i = 0; i < n; i++) {
            const int l = lower_bound(all.begin(), endIt, positions[i][0]) - all.begin();
            const int r = lower_bound(all.begin(), endIt, positions[i][0] + positions[i][1]) - all.begin();
            
            const int k = query(1, l, r);
            update(1, l, r, k + positions[i][1]);
            answer[i] = treeNode[1].sum;
        }
        
        return answer;
    }
private:
    SegmentTreeNode treeNode[2005 * 4];
    
    int L(int u) {
        return (u << 1);
    }
    
    int R(int u) {
        return (u << 1) + 1;
    }
    
    void pushUp(int u) {
        treeNode[u].sum = max(treeNode[L(u)].sum, treeNode[R(u)].sum);
    }
    
    void build(int u, int left, int right) {
        treeNode[u].left = left;
        treeNode[u].right = right;
    
        if (left == right) {
            return;
        }
    
        int middle = (left + right) >> 1;
        build(L(u), left, middle);
        build(R(u), middle + 1, right);
        pushUp(u);
    }
    
    void pushDown(int u) {
        if (!treeNode[u].lazyTag) {
            return;
        }
    
        treeNode[L(u)].sum = max(treeNode[u].lazyTag, treeNode[L(u)].sum);
        treeNode[R(u)].sum = max(treeNode[u].lazyTag, treeNode[R(u)].sum);
    
        treeNode[L(u)].lazyTag = max(treeNode[u].lazyTag, treeNode[L(u)].lazyTag);
        treeNode[R(u)].lazyTag = max(treeNode[u].lazyTag, treeNode[R(u)].lazyTag);
    
        treeNode[u].lazyTag = 0;
    }
    
    void update(int u, int left, int right, long long val) {
        if (left <= treeNode[u].left && treeNode[u].right <= right) {
            treeNode[u].sum = max(val, treeNode[u].sum);
            treeNode[u].lazyTag = max(val, treeNode[u].lazyTag);
            return;
        }
    
        pushDown(u);
        int middle = (treeNode[u].left + treeNode[u].right) >> 1;
        if (left <= middle) {
            update(L(u), left, right, val);
        }
        if (middle < right) {
            update(R(u), left, right, val);
        }
        pushUp(u);
    }
    
    long long query(int u, int left, int right) {
        if (left <= treeNode[u].left && treeNode[u].right <= right) {
            return treeNode[u].sum;
        }
    
        long long answer = 0;
        pushDown(u);
        int middle = (treeNode[u].left + treeNode[u].right) >> 1;
        if (left <= middle) {
            answer = max(answer, query(L(u), left, right));
        }
        if (middle < right) {
            answer = max(answer, query(R(u), left, right));
        }
        return answer;
    }
};