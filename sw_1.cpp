//[����]
//N���� ���ð� �ְ�, M���� ���ΰ� �ִ�. �ϳ��� ���δ� �� ���� ���̸� �����ϸ�, ������ �� ���ø� �����ϴ� ���ΰ� ���� �� ���� �� �ִ�. 
//���ÿ��� 1���� N���� ��ȣ�� ������� �Ű����ְ�, ���θ��� �������µ� �ɸ��� �ð��� �־�����.
//������ ���� ������ �־����� ��, 1�� ���ÿ��� N�� ���÷� ���� �ּ� �ð��� ���α׷��� �ۼ��Ͻÿ�.
//
//[�Է�]
//�Է� ���Ͽ��� ���� �׽�Ʈ ���̽��� ���Ե� �� �ִ�. ������ ù° �ٿ� ���̽��� ���� T�� �־�����, ���� ���ʷ� T�� �׽�Ʈ ���̽��� �־�����.
// (1 �� T �� 20) �� ���̽��� ù �ٿ� ������ �� N�� ������ �� M�� �������� ���еǾ� �־�����. (1 �� N �� 100,000, 1 �� M �� 300,000)
//�׸��� ���� M���� �ٿ� �� ���ο� ���� ������ ��Ÿ���� �� ������ �������� ���еǾ� �־�����. "a b c"��� �־����� �� a�� ���ÿ� b�� ���ø� �����ϴ� ���ΰ� �����ϸ�, 
//�� ���θ� �����µ� �ɸ��� �ð��� c��� ���� �ǹ��Ѵ�. (1 �� a, b �� N, 1 �� c �� 10,000, a �� b)
//
//[���]
//�� �׽�Ʈ ���̽��� ���� ������� ǥ��������� ����ϸ�, �� ���̽����� ���� ���ۿ� ��#x���� ����Ͽ��� �Ѵ�. �̶� x�� ���̽��� ��ȣ�̴�. 
//���� �ٿ�, 1�� ���ÿ��� N�� ���÷� ���� �ּ� �ð��� ����Ѵ�. ���� 1�� ���ÿ��� N�� ���÷� �� �� ���ٸ� -1�� ����Ѵ�.
//
//[����� ��]
//(�Է�)
//2     �� 2 test cases in total
//3 3   �� 1st case
//1 2 3
//2 3 1
//1 3 2
//6 9   �� 2nd case
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
//(���)
//#1 2
//#2 6

#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

#define max_node 100000
#define INF 999999999

int T, N, M;
vector< pair < int, int > > node[max_node]; //���� ����
int ans[max_node]; //�ּ� ���
int t_ans[20];

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
        for (int i=0; i<node[current].size(); i++)
        {
            // ���õ� ����� ���� ���
            int next = node[current][i].second;
            // ���õ� ��带 ���� ���� ���ļ� ���� ���
            int nextDistance = distance + node[current][i].first;
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
