#include<bits/stdc++.h>
using namespace std;

struct edge
{
	int a;
	int b;
};

bool com(edge x, edge y)
{
	if(x.a != y.a)
		return (x.a < y.a);

	return (x.b < y.b);
}

int main()
{
	int m, n;
	cin >> m >> n;
	edge E[n];
	int k = 0;
	int color[m];

	fill(color, color+m, -1);

	for(int i=0; i<n; i++)
	{
		cin >> E[i].a >> E[i].b;

		if(E[i].a > E[i].b)
		{
			int t = E[i].a;
			E[i].a = E[i].b;
			E[i].b = t;
		}
	}

	sort(E, E+n, com);

	for(int i=0; i<n; i++)
	{
		if(k == 0)
		{
			color[E[i].a] = 0;
			color[E[i].b] = 1;
			
			if(E[i].a != E[i+1].a)
				k = 1;	
		}

		else
		{
			if(color[E[i].a] == 0 && color[E[i].b] == 0 || color[E[i].a] == 1 && color[E[i].b] == 1)
			{
				cout << "NO\n";
				return 0;
			}

			else if(color[E[i].a] != -1)
				color[E[i].b] = 1 - color[E[i].a];

			else if(color[E[i].b] != -1)
				color[E[i].a] = 1 - color[E[i].b];
		}
	}

	cout << "YES\n";
	return 0;
}