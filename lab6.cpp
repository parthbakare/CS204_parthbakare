#include <bits/stdc++.h>
using namespace std;

struct querry {
    long long int num;
    long long int id;
    long long int value;
};

int main()
{
    long long int n, m;
    cin >> n >> m;

    struct querry q[m];
    long long int userid[m];
    long long int recharge[m];

    for(int i=0; i<m; i++)
        recharge[i] = 0;
  
    for(int i=0; i<m; i++)
    {
        cin >> q[i].num;
        if (q[i].num == 1)
        {
            cin >> q[i].id >> q[i].value;
            userid[i] = q[i].id;
        }
    }

    long long int k = 0; 
    long long int maximum;
    sort(userid, userid + m);
    
    for(int i=0; i<m; i++)
    {   
        long long int temp;

        if (q[i].num == 1)
        {
            temp = lower_bound(userid, userid + m, q[i].id) - userid;
            recharge[temp] += q[i].value;

            if (k == 0)
            {
                k = 1;
                maximum = temp;
            }

            else if (recharge[temp] > recharge[maximum])
                maximum = temp;
        }

        else
        {
            if (k == 0)
                cout << "No data available." << endl;
        
            else
                cout << userid[maximum] << endl;
        }
    }

    return 0;
}