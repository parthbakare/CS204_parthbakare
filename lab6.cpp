#include<bits/stdc++.h>
using namespace std;

int main() {
	
	vector<long long int> A;
	vector<long long int> B;	
	long long int maxi;

	long long int m;
	cin >> m;

	long long int n;
	cin >> n;

	int t;
	for(int i=1; i<=n; i++)
	{
		cin >> t;

		if(t==1)
		{
			long long int x, y;
			cin >> x >> y;

			if(A.empty())
		  	{
		  		A.push_back(x);
		  		B.push_back(y);
		  		maxi = 0;
		  	}
			
			else 
			{
				int p = -1;
  	
	  			for(long long int i=0; i<A.size(); i++)
	  			{
	  				if(A[i]==x)
	  				p = i;
	  			}

	  			if(p == -1)
			  	{	
			  		A.push_back(x);
			  		B.push_back(y);
			  		if(y >= B[maxi])
			  			maxi = B.size() - 1;
			  	}

			  	else
			  	{
			  		B[p]+=y;
			  		if(B[p] >= B[maxi])
			  			maxi = p;
			  	}
		  	}
		}

		else if(t==2)
		{
			if(A.empty())
			{
				cout << "No data available.\n";
			}

			else
			{
				cout << A[maxi] << endl;
			}
		}	
	}

	return 0;
}