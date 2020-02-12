#include <iostream>
#include <deque>
#include <vector>
using namespace std;

vector<long long> sum;

int main() {
    long long answer = -9999999999;
    int N, M;
    cin >> N >> M;

    sum = vector<long long>(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        long long temp;
        cin >> temp;
        sum[i] = sum[i - 1] + temp;
    }

    deque<int> queue;
    queue.push_back(0);
    for (int i = 1; i <= N; i++) {
        while (!queue.empty() && queue.front() < i - M) queue.pop_front();
        answer = max(answer, sum[i] - sum[queue.front()]);
        
        while (!queue.empty() && sum[queue.back()] > sum[i]) queue.pop_back();
        queue.push_back(i);
    }

    cout << answer << endl;
    return 0;
}
