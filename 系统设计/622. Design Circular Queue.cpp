class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        this->k = k;
        data = vector<int>(k, 0);
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        const int nxt = (right + 1) % k;
        if (size + 1 > k) return false;
        else {
            data[right] = value;
            right = nxt;
            size++;
            return true;
        }
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        const int nxt = (left + 1) % k;
        if (size == 0) {
             return false;
        } else {
            left = nxt;
            size--;
            return true;
        }
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if (size == 0) return -1;
        return data[left];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if (size == 0) return -1;
        const int idx = (right - 1 + k) % k;
        return data[idx];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return size == 0;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return size == k;
    }
private:
    vector<int> data;
    int left = 0, right = 0;
    int size = 0, k = 0;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */