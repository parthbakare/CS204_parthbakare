#include <bits/stdc++.h>
using namespace std;

int main(){
string num1;
string num2;
cin >> num1;
cin >> num2;

int l1 = num1.length() - 1;
int l2 = num2.length() - 1;

if(l1 <= l2)
{ 
	for(int i=l2; i>=l2-l1; i--)
	num1[i] = num1[i-l2+l1];

	
	for(int j=l2-l1-1; j>=0; j--)
    num1[j] = '0';
	
    l1 = l2;
    num1[l1+1] = '\0';
}

else
{
	for(int i=l1; i>=l1-l2; i--)
	num2[i] = num2[i-l1+l2];

	for(int j=l1-l2-1; j>=0; j--)
    num2[j] = '0';

    l2 = l1;
    num2[l2+1] = '\0';
}


string sum = "\0";
int rem = 0;

for(int k=0; k<=l2; k++)
{
	sum[k] = num1[l2-k] - 48 + num2[l2-k] - 48 + rem + 48;

	if(sum[k]>=58)
	{sum[k] -= 10;
	 rem = 1;}

	 else
	 rem = 0;


	sum += sum[k];

}

if(rem==1)
{sum += rem + 48;
sum[l1+2] = '\0';}

else
sum[l1+1] = '\0';

reverse(sum.begin(),sum.end());
cout << sum << endl;


return 0;
}