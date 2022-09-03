#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

#define node 20009
#define INF 999999999

vector< pair < int, int > > a[node]; //���� ����
int ans[node]; //�ּ� ���

int V, E;

void dijkstra(int start)
{
	ans[start] = 0;
    priority_queue< pair < int, int > > pq; //�� ����
    pq.push(make_pair(0, start));
    
    // ����� ������� ó���ϹǷ� ť�� ���
    while (!pq.empty())
    {
        int distance = -pq.top().first;
        // ª�� ���� ���� ������ ����ȭ(-)
        int current = pq.top().second;
        pq.pop();
        // �ִ� �Ÿ��� �ƴ� ��� ��ŵ
        if (ans[current] < distance)
        {
            continue;
        }
        for (int i=0; i<a[current].size(); i++)
        {
            // ���õ� ����� ���� ���
            int next = a[current][i].second;
            // ���õ� ��带 ���� ���� ���ļ� ���� ���
            int nextDistance = distance + a[current][i].first;
            // ������ �ּ� ��뺸�� �� �����ϸ� ��ü
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
