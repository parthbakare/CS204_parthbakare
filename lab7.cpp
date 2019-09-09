#include<bits/stdc++.h>
using namespace std;

bool com(string x, string y)
{
    string a = x + y;
    string b = y + x;

    return (a > b);
}

int main() {
 
 	int t;
 	cin >> t;

 	for(int j=0; j<t; j++)
    {
        int n;
        cin >> n;
        vector<string> a;
        int maxlength = 0;
        
        for(int i=0; i<n; i++)
        {    
            string s;
            cin >> s;
            a.push_back(s);
        }

     	sort(a.begin(), a.end(), com);
        string num = "\0";

        for(int i=0; i<n; i++)
            num = num + a[i];

        cout << num << endl;
    }

    return 0;
}