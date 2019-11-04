#include<bits/stdc++.h>
using namespace std;

struct edge {
	int x;
	int y;
	long long int w;
};

bool com(edge A, edge B)
{
	return (A.w > B.w);
}

int main(){
	int n, m;
	cin >> n >> m;
	long long int cost = 1;
	vector<edge> E;

	for(int i=0; i<m; i++)
	{
		edge temp;
		cin >> temp.x >> temp.y >> temp.w;
		E.push_back(temp);
	}

	int id[n];

	for(int i=0; i<n; i++)
		id[i] = i;

	sort(E.begin(), E.end(), com);

	for(edge temp : E)
	{
		if(id[temp.x] != id[temp.y])
		{
			cost *= temp.w;
			int old_id = id[temp.x], new_id = id[temp.y];

			for(int i=0; i<n; i++)
			{
				if(id[i] == old_id)
					id[i] = new_id;
			}
		}
	}

	long long int COST = floor(cost);
	COST = COST % 1000000007;
	cout << COST << endl;
	return 0;
}
