#include<iostream>
#include<deque>
#include<mutex>
#include<condition_variable>
using namespace std;

template <typename T>
class BoundedBlockingQueue {
private:
    deque<T> q;

    mutex mu;
    condition_variable cv_push;
    condition_variable cv_pop;

    size_t capacity;
public:
    BoundedBlockingQueue(size_t capacity) : capacity(capacity) {
    }

    size_t size() {
        lock_guard<mutex> g(mu);
        return q.size();
    }

    T deque() {
        unique_lock<mutex> lk(mu);
        cv_pop.wait(lk, [&]() -> bool {
            return !q.empty();
        });

        T res = q.front();
        q.pop_front();

        lk.unlock();
        cv_push.notify_one();

        return res;
    }

    void enqueue(T element) {
        unique_lock<mutex> lk(mu);
        cv_push.wait(lk, [&]() -> bool {
            return q.size() < capacity;
        });

        q.push_back(element);

        lk.unlock();
        cv_pop.notify_one();
    }
};

int main() {
    BoundedBlockingQueue<int> q(1);
    return 0;
}
