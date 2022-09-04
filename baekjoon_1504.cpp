#include <stdio.h>
#include <vector>
#include <queue>

#define n_max 801
#define INF 999999999

using namespace std;

vector < pair < int, int > > vec[n_max];
int ans_v1[n_max];
int ans_v2[n_max];
int ans_v3[n_max];
int ans_v4[n_max];
int V1, V2;

void dijkstra1 (int start)
{
	ans_v1[start] = 0;
	priority_queue < pair < int, int > > pq;
	pq.push(make_pair(0, start));
	
	while (!pq.empty())
	{
		int distance = -pq.top().first;
		int current = pq.top().second;
//		printf("distance : current [%d]:[%d]\n", distance, current);
		pq.pop();
				
//		if ( ans_v1[current] < distance )
//		{
//			continue;
//		}
		
		for (int i=0; i<vec[current].size(); i++)
		{
			int next = vec[current][i].second;
//			printf("next : [%d]\n", next);
			int next_distance = distance + vec[current][i].first;
//			printf("next_distance : [%d]\n", next_distance);
			
			if (ans_v1[next] > next_distance)
			{
				ans_v1[next] = next_distance;
				pq.push(make_pair(-next_distance, next));
			}
		}
//		printf("\n");
	}
}

void dijkstra2 (int start)
{
	ans_v2[start] = 0;
	priority_queue < pair < int, int > > pq;
	pq.push(make_pair(0, start));
	
	while (!pq.empty())
	{
		int distance = -pq.top().first;
		int current = pq.top().second;
//		printf("distance : current [%d]:[%d]\n", distance, current);
		pq.pop();
				
//		if ( ans_v2[current] < distance )
//		{
//			continue;
//		}
		
		for (int i=0; i<vec[current].size(); i++)
		{
			int next = vec[current][i].second;
//			printf("next : [%d]\n", next);
			int next_distance = distance + vec[current][i].first;
//			printf("next_distance : [%d]\n", next_distance);
			
			if (ans_v2[next] > next_distance)
			{
				ans_v2[next] = next_distance;
				pq.push(make_pair(-next_distance, next));
			}
		}
//		printf("\n");
	}
}

void dijkstra3 (int start)
{
	ans_v3[start] = 0;
	priority_queue < pair < int, int > > pq;
	pq.push(make_pair(0, start));
	
	while (!pq.empty())
	{
		int distance = -pq.top().first;
		int current = pq.top().second;
//		printf("distance : current [%d]:[%d]\n", distance, current);
		pq.pop();
				
//		if ( ans_v3[current] < distance )
//		{
//			continue;
//		}
		
		for (int i=0; i<vec[current].size(); i++)
		{
			int next = vec[current][i].second;
//			printf("next : [%d]\n", next);
			int next_distance = distance + vec[current][i].first;
//			printf("next_distance : [%d]\n", next_distance);
			
			if (ans_v3[next] > next_distance)
			{
				ans_v3[next] = next_distance;
				pq.push(make_pair(-next_distance, next));
			}
		}
//		printf("\n");
	}
}

void dijkstra4 (int start)
{
	ans_v4[start] = 0;
	priority_queue < pair < int, int > > pq;
	pq.push(make_pair(0, start));
	
	while (!pq.empty())
	{
		int distance = -pq.top().first;
		int current = pq.top().second;
//		printf("distance : current [%d]:[%d]\n", distance, current);
		pq.pop();
				
//		if ( ans_v4[current] < distance )
//		{
//			continue;
//		}
		
		for (int i=0; i<vec[current].size(); i++)
		{
			int next = vec[current][i].second;
//			printf("next : [%d]\n", next);
			int next_distance = distance + vec[current][i].first;
//			printf("next_distance : [%d]\n", next_distance);
			
			if (ans_v4[next] > next_distance)
			{
				ans_v4[next] = next_distance;
				pq.push(make_pair(-next_distance, next));
			}
		}
//		printf("\n");
	}
}

int main()
{
	int N, E;
	int fixed_dis;
	N = 0;
	E = 0;
	V1 = 0;
	V2 = 0;
	fixed_dis = 0;
	
	scanf("%d %d", &N, &E);
	
	for (int i=1; i<=N; i++)
	{
		ans_v1[i] = INF;
		ans_v2[i] = INF;
		ans_v3[i] = INF;
		ans_v4[i] = INF;
	}
	
	for (int i=1; i<=E; i++)
	{
		int a, b, c;
		a = 0;
		b = 0;
		c = 0;
		
		scanf("%d %d %d", &a, &b, &c);
		
		vec[a].push_back(make_pair(c, b));
		vec[b].push_back(make_pair(c, a));
	}
	
	scanf("%d %d", &V1, &V2);
//	printf("fixed_dis : [%d]\n", fixed_dis);
	
	dijkstra1(1);
	dijkstra2(V2);
	dijkstra3(1);
	dijkstra4(V1);
	fixed_dis = ans_v4[V2];
/*
	for (int i=1; i<=N; i++)
	{
		printf("[%d] ", ans_v1[i]);
	}
	printf("\n");
	for (int i=1; i<=N; i++)
	{
		printf("[%d] ", ans_v2[i]);
	}
	printf("\n");
	for (int i=1; i<=N; i++)
	{
		printf("[%d] ", ans_v3[i]);
	}
	printf("\n");
	for (int i=1; i<=N; i++)
	{
		printf("[%d] ", ans_v4[i]);
	}
	printf("\n");
*/	
	if (((ans_v1[V1] == INF) || (ans_v2[N] == INF)) || ((ans_v3[V2] == INF) || (ans_v4[N] == INF)))
	{
		printf("-1");
	}
	else
	{
		if ((ans_v1[V1] + ans_v2[N]) < (ans_v3[V2] + ans_v4[N]))
		{
			printf("%ld", ans_v1[V1] + ans_v2[N] + fixed_dis);
		}
		else
		{
			printf("%ld", ans_v3[V2] + ans_v4[N] + fixed_dis);
		}
	}
}
