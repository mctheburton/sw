#include <stdio.h>
#include <vector>
#include <queue>
 
#define MAX 1009
 
using namespace std;

priority_queue < pair < int, int > > q_to;
priority_queue < pair < int, int > > q_from;

int main()
{
	q_to.push(make_pair(5, 2));
	q_to.push(make_pair(3, 1));
	q_to.push(make_pair(4, 1));
	q_to.push(make_pair(2, 2));

	q_from.push(make_pair(5*-1, 2));
	q_from.push(make_pair(3*-1, 1));
	q_from.push(make_pair(4*-1, 1));
	q_from.push(make_pair(2*-1, 2));
	
	for (int i=1; i<=4; i++)
	{
		int x, y;
		x = q_to.top().first;
		y = q_to.top().second;
		q_to.pop();
		printf("to i : %d, (%d, %d)\n", i, x, y);
	}

	for (int i=1; i<=4; i++)
	{
		int a, b;
		a = q_from.top().first*-1;
		b = q_from.top().second;
		q_from.pop();
		printf("from i : %d, (%d, %d)\n", i, a, b);
	}
}

