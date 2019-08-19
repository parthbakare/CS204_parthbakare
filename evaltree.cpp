#include<bits/stdc++.h>
using namespace std;

struct node {
	string data;
	node *left;
	node *right;
};

int strint (string s)
{
	int num = 0;
	for(int i=0; i<s.length(); i++)
		num += num*10 + (s[i] - '0');

	return num;
}

int solve (struct node *root)
{
	if(root == NULL)
	{
		cout << "EMPTY, CANNOT BE EVALUATED\n";
		return 0;
	}

	else if(root->left == NULL && root->right == NULL)
		return strint(root->data);

	else
	{
		int rval = solve(root->right);
		int lval = solve(root->left);

		if(root->data == "+")
		return lval + rval;

		else if(root->data == "-")
		return lval - rval;

		else if(root->data == "*")
		return lval * rval;

		else if(root->data == "/")
		return lval / rval;

		else if(root->data == "^")
		return pow(lval, rval);
	}
}

int prec(char c) 
{ 
    if(c == '^') 
    return 5;

    else if(c == '/') 
    return 4; 
    
    else if(c == '*') 
    return 4; 
    
    else if(c == '+') 
    return 1;

    else if(c == '-') 
    return 1; 
    
    else
    return -1; 
}

string inposteasy (string s)
{
	stack<char> a;
	string post = "\0";

	for(int i=0; i<s.length(); i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
			{
				post += s[i];
			}

		else if(s[i] == '(')
			a.push(s[i]);

		else if(s[i] == ')')
		{
			while(a.empty() == 0 && a.top() != '(')
			{
				post += a.top();
				a.pop();
			}

			if(a.top() == '(')
			{
				post += a.top();
				a.pop();
			}
		}

		else
		{
			while(a.empty() == 0 && prec(s[i]) <= prec(a.top())) 
            { 
                char c = a.top(); 
                a.pop(); 
                post += c; 
            } 
            a.push(s[i]); 
		}
	}

		while(a.empty() == 0) 
    { 
        char c = a.top(); 
        a.pop(); 
        post += c; 
    } 
	
	return post;
}

string inpost (string s)
{
	stack<char> a;
	string post = "\0";

	for(int i=0; i<s.length(); i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
			{
				while(s[i] >= '0' && s[i] <= '9')
				{
					post += s[i];
					i++;
				}

				post += " ";
				i--;
			}

		else if(s[i] == '(')
			a.push(s[i]);

		else if(s[i] == ')')
		{
			while(a.empty() == 0 && a.top() != '(')
			{
				post += a.top();
				a.pop();
			}

			if(a.top() == '(')
			{
				post += a.top();
				a.pop();
			}
		}

		else
		{
			while(a.empty() == 0 && prec(s[i]) <= prec(a.top())) 
            { 
                char c = a.top(); 
                a.pop(); 
                post += c; 
            } 
            a.push(s[i]); 
		}
	}

		while(a.empty() == 0) 
    { 
        char c = a.top(); 
        a.pop(); 
        post += c; 
    } 
	
	return post;
}

struct node *tree(string s) 
{ 
    stack<struct node*> a; 
    struct node *t, *t1, *t2; 
  
    
    for (int i=0; i<s.length(); i++) 
    { 
         
        if (s[i] >= '0' && s[i] <= '9') 
        { 
            t = new node;
            t->data = s[i];
            t->left = NULL;
            t->right = NULL; 
            a.push(t); 
        } 
        else  
        { 
            t = new node; 
  			t->data = s[i];
            t->left = NULL;
            t->right = NULL;
 
            t1 = a.top(); 
            a.pop();       
            t2 = a.top(); 
            a.pop(); 
  
            t->right = t1; 
            t->left = t2; 

            a.push(t); 
        } 
    } 
  
    t = a.top(); 
    a.pop(); 
  
    return t; 
} 

struct node *treehard(string s) 
{ 
    stack<struct node*> a; 
    struct node *t, *t1, *t2; 
  
    
    for (int i=0; i<s.length(); i++) 
    { 
         
        if (s[i] >= '0' && s[i] <= '9') 
        { 
            string temp= "\0";
            while(s[i] >= '0' && s[i] <= '9')
				{
					temp += s[i];
					i++;
				}

			i--;

			cout << "\nABC" << temp;
            t = new node;
            t->data = temp;
            t->left = NULL;
            t->right = NULL; 
            a.push(t); 
        } 
        
        else if(s[i] == ' ')
        	i++;

        else  
        { 
            t = new node; 
  			t->data = s[i];
            t->left = NULL;
            t->right = NULL;
 
            t1 = a.top(); 
            a.pop();       
            t2 = a.top(); 
            a.pop(); 
  
            t->right = t1; 
            t->left = t2; 

            a.push(t); 
        } 
    } 
  
    t = a.top(); 
    a.pop(); 
  
    return t; 
} 


int main() {
	
	int n;
	cin >> n;

	for(int i=0; i<n; i++)
	{

		string A;
		cin >> A;
	
		string B = inposteasy(A);
		struct node *root = tree(B);
		cout << solve(root) << "\n";
	}
	
}



