#include <iostream>
#include <queue>
#include <functional> // greater, less

using namespace std;

int main()
{
    priority_queue<int> pq1;                            // 기본값: 내림차순
    priority_queue<int, vector<int>, greater<int>> pq2; // 오름차순

    pq2.push(1);
    pq2.push(3);
    pq2.push(190);
    pq2.push(7);
    pq2.push(-1);

    cout << pq2.top();
    pq2.pop();
}
