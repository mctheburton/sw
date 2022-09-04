//[문제]
//N개의 도시가 있고, M개의 도로가 있다. 하나의 도로는 두 도시 사이를 연결하며, 임의의 두 도시를 연결하는 도로가 여러 개 있을 수 있다. 
//도시에는 1부터 N까지 번호가 순서대로 매겨져있고, 도로마다 지나가는데 걸리는 시간이 주어진다.
//도시의 도로 정보가 주어졌을 때, 1번 도시에서 N번 도시로 가는 최소 시간을 프로그램을 작성하시오.
//
//[입력]
//입력 파일에는 여러 테스트 케이스가 포함될 수 있다. 파일의 첫째 줄에 케이스의 개수 T가 주어지고, 이후 차례로 T개 테스트 케이스가 주어진다.
// (1 ≤ T ≤ 20) 각 케이스의 첫 줄에 도시의 수 N과 도로의 수 M이 공백으로 구분되어 주어진다. (1 ≤ N ≤ 100,000, 1 ≤ M ≤ 300,000)
//그리고 다음 M개의 줄에 각 도로에 대한 정보를 나타내는 세 정수가 공백으로 구분되어 주어진다. "a b c"라고 주어졌을 때 a번 도시와 b번 도시를 연결하는 도로가 존재하며, 
//그 도로를 지나는데 걸리는 시간이 c라는 것을 의미한다. (1 ≤ a, b ≤ N, 1 ≤ c ≤ 10,000, a ≠ b)
//
//[출력]
//각 테스트 케이스의 답을 순서대로 표준출력으로 출력하며, 각 케이스마다 줄의 시작에 “#x”를 출력하여야 한다. 이때 x는 케이스의 번호이다. 
//같은 줄에, 1번 도시에서 N번 도시로 가는 최소 시간을 출력한다. 만약 1번 도시에서 N번 도시로 갈 수 없다면 -1을 출력한다.
//
//[입출력 예]
//(입력)
//2     ← 2 test cases in total
//3 3   ← 1st case
//1 2 3
//2 3 1
//1 3 2
//6 9   ← 2nd case
//1 2 2
//1 3 4
//2 3 1
//2 5 2
//2 4 4
//3 5 3
//4 5 3
//4 6 2
//5 6 2
//
//(출력)
//#1 2
//#2 6

#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

#define max_node 100000
#define INF 999999999

int T, N, M;
vector< pair < int, int > > node[max_node]; //간선 정보
int ans[max_node]; //최소 비용
int t_ans[20];

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
        for (int i=0; i<node[current].size(); i++)
        {
            // 선택된 노드의 인접 노드
            int next = node[current][i].second;
            // 선택된 노드를 인접 노드로 거쳐서 가는 비용
            int nextDistance = distance + node[current][i].first;
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
	T = 0;	
	
	scanf("%d", &T);
	
	for (int i=1; i<=T; i++)
	{
		t_ans[i] = 0;
		N = 0;
		M = 0;
		scanf("%d %d", &N, &M);

		for (int k=1; k<=N; k++)
		{
			ans[k] = INF;
			node[k].push_back(make_pair(0, 0));
		}
			
		for (int j=1; j<=M; j++)
		{
			int a, b, c;
			a = 0;
			b = 0;
			c = 0;
			scanf("%d %d %d", &a, &b, &c);
			node[a].push_back(make_pair(c, b));
		}

    	dijkstra(1);
    	
    	if (ans[N] == INF)
		{	
			ans[N] = -1;
		}
		t_ans[i] = ans[N];
	}

	for (int i=1; i<=T; i++)
	{
		printf("#%d %d\n", i, t_ans[i]);
	}
	
}
