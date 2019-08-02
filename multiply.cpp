#include<bits/stdc++.h>
using namespace std;


string add (string num1, string num2)
{

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
return sum;
}




int main() {

string num1, num2;
cin >> num1;
cin >> num2; 

int l1 = num1.length() - 1, l2 = num2.length() - 1;
string sum = "\0";


for(int i=l2; i>=0; i--)
{
	string temp = "\0";
	int rem = 0;

		for(int j=l1; j>=0; j--)
		{
			int mul = ( (num1[j] - 48) *  (num2[i] - 48) );
		

			temp[l1-j] = ((mul%10) + rem)%10 + 48;
			rem = mul/10 + (mul%10 + rem)/10;
		
			temp += temp[l1-j];
			
		}

		if(rem!='0')
			temp += rem+48;




		reverse(temp.begin(), temp.end());

        string zero = "\0";
		for(int k=1; k<=l2-i; k++)
			zero += '0';

    temp += zero;
    sum = add(sum, temp);
}

cout << sum << endl;

return 0;
}
