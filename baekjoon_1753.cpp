#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

#define node 20009
#define INF 999999999

vector< pair < int, int > > a[node]; //간선 정보
int ans[node]; //최소 비용

int V, E;

void dijkstra(int start)
{
	ans[start] = 0;
    priority_queue< pair < int, int > > pq; //힙 구조
    pq.push(make_pair(0, start));
    
    // 가까운 순서대로 처리하므로 큐를 사용
    while (!pq.empty())
    {
        int distance = -pq.top().first;
        // 짧은 것이 먼저 오도록 음수화(-)
        int current = pq.top().second;
        pq.pop();
        // 최단 거리가 아닌 경우 스킵
        if (ans[current] < distance)
        {
            continue;
        }
        for (int i=0; i<a[current].size(); i++)
        {
            // 선택된 노드의 인접 노드
            int next = a[current][i].second;
            // 선택된 노드를 인접 노드로 거쳐서 가는 비용
            int nextDistance = distance + a[current][i].first;
            // 기존의 최소 비용보다 더 저렴하면 교체
            if (nextDistance < ans[next])
            {
                ans[next] = nextDistance;
                pq.push(make_pair(-nextDistance, next));
            }
        }
    }
}

int main()
{
	V = 0;
	E = 0;
	
	scanf("%d %d", &V, &E);
	for (int i=1; i<=V; i++)
	{
		ans[i] = INF;
	}

	int s = 0;
	scanf("%d", &s);

	int u = 0;
	int v = 0;
	int w = 0;

	for (int i=1; i<=E; i++)
	{
		scanf("%d %d %d", &u, &v, &w);
		a[u].push_back(make_pair(w, v));
	}

    dijkstra(s);

	for (int i=1; i<=V; i++)
	{
		if (ans[i] == INF)
		{
			printf("INF\n");
		}
		else
		{
			printf("%d\n", ans[i]);
		}
	}
}
