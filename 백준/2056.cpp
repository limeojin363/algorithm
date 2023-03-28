#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

void input();
int dp(int x);

int n;
int t[10001];
vector<int> preceded[10001];
int cache[10001];

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    memset(cache, -1, sizeof(cache));

    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(dp(i), ans); // 작업들 중 가장 오래 걸리는 작업의 수행시간이 정답

    cout << ans;
}

void input()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int c;
        cin >> t[i] >> c;

        for (int j = 0; j < c; j++)
        {
            int temp;
            cin >> temp;
            preceded[i].push_back(temp);
        }
    }
}

// x번 작업이 수행되기까지 걸리는 시간을 반환하는 함수
int dp(int x)
{
    // 메모이제이션
    int &ret = cache[x];
    if (ret != -1)
        return ret;

    int prevRequiredTime = 0; // 그래프 상에서, 이전 작업들이 전부 수행되기 위한 시간

    // 이전 작업들(preceded[x])을 살펴보며, 가장 오래 걸리는 작업으로 갱신
    for (int i = 0; i < preceded[x].size(); i++)
        prevRequiredTime = max(prevRequiredTime, dp(preceded[x][i]));

    // 반환값: 이전 작업들 중 가장 오래 걸리는 시간 + 해당 작업 수행 시간
    return (ret = prevRequiredTime + t[x]);
}