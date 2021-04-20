class Solution {
public:
    /**
     * @param intervals: the intervals
     * @param rooms: the sum of rooms
     * @param ask: the ask
     * @return: true or false of each meeting
     */
    vector<bool> meetingRoomIII(vector<vector<int>> &intervals, int rooms, vector<vector<int>> &ask) {
        for (auto& p : intervals) p[1]--;
        for (auto& p : ask) p[1]--;
        
        build(1, 1, 50000);
        for (auto& p : intervals) {
            update(1, p[0], p[1], 1);
        }
        vector<bool> answer(ask.size());
        for (int i = 0; i < ask.size(); i++) {
            int tmp = query(1, ask[i][0], ask[i][1]);
            answer[i] = tmp + 1 <= rooms;
        }
        return answer;
    }
private:
    class SegmentTreeNode {
    public:
        int left, right;
        int max, lazyTag;
    
        SegmentTreeNode(): left(0), right(0), max(0), lazyTag(0) {};
    };
    SegmentTreeNode treeNode[50050 * 4];
    int L(int u) {
        return (u << 1);
    }
    int R(int u) {
        return (u << 1) + 1;
    }
    void build(int u, int left, int right) {
        treeNode[u].left = left;
        treeNode[u].right = right;

        if (left == right) {
            treeNode[u].max = 0;
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
        
        treeNode[L(u)].max += treeNode[u].lazyTag;
        treeNode[R(u)].max += treeNode[u].lazyTag;
        
        treeNode[L(u)].lazyTag += treeNode[u].lazyTag;
        treeNode[R(u)].lazyTag += treeNode[u].lazyTag;

        treeNode[u].lazyTag = 0;
    }
    void pushUp(int u) {
        treeNode[u].max = std::max(treeNode[L(u)].max, treeNode[R(u)].max);
    }
    void update(int u, int left, int right, int val) {
        if (left <= treeNode[u].left && treeNode[u].right <= right) {
            treeNode[u].lazyTag += val;
            treeNode[u].max += val;
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
    int query(int u, int left, int right) {
        if (left <= treeNode[u].left && treeNode[u].right <= right) {
            return treeNode[u].max;
        }

        int answer = 0;
        pushDown(u);
        int middle = (treeNode[u].left + treeNode[u].right) >> 1;
        if (left <= middle) {
            answer = std::max(answer, query(L(u), left, right));
        }
        if (middle < right) {
            answer = std::max(answer, query(R(u), left, right));
        }
        return answer;
    }
};
