/*
    Source: https://github.com/ndb796/python-for-coding-test/blob/master/10/6.cpp
    Edited by limeojin363(https://github.com/limeojin363)
**/

#include <iostream>
#include <vector>
#include <queue>

void topologySort();
void input();

using namespace std;

int v, e;             // 노드개수 v, 간선개수 e
int indegree[100001]; // 진입차수: 0으로 초기화
vector<int> graph[100001];

void topologySort()
{
    vector<int> result;
    queue<int> q;

    // 진입차수가 0인 노드를 큐에 삽입
    for (int i = 1; i <= v; i++)
        if (indegree[i] == 0)
            q.push(i);

    // 큐가 빌 때까지 반복
    while (!q.empty())
    {
        // 큐에서 원소 꺼내기
        int now = q.front();
        q.pop();
        result.push_back(now);
        // 해당 원소와 연결된 노드들의 진입차수에서 1 빼기
        for (int i = 0; i < graph[now].size(); i++)
        {
            indegree[graph[now][i]] -= 1;
            // 새롭게 진입차수가 0이 되는 노드를 큐에 삽입
            if (indegree[graph[now][i]] == 0)
            {
                q.push(graph[now][i]);
            }
        }
    }

    // 위상 정렬을 수행한 결과 출력
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << ' ';
}

void input()
{
    cin >> v >> e;

    // 방향 그래프의 모든 간선 정보를 입력 받기
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b); // a -> b
        // b의 진입 차수 증가
        indegree[b] += 1;
    }
}

int main()
{
    input();
    topologySort();
}
