#include<iostream>
#include<math.h>
using namespace std;

struct point {
    int x;
    int y;
    point *node;
};

point *first = NULL;
point *last = NULL;

float distance(int X, int Y)
{
    float d = sqrt(X*X + Y*Y);
    return d;
}

void AddFirst(int X, int Y)
{
    point *newnode = new point;
    newnode->x = X;
    newnode->y = Y;
    newnode->node = first;
    first = newnode;
    
}

string Search(int X, int Y)
{
    string k = "false";
    struct point *temp = first;
    
    while(temp!=NULL)
    {
        if(temp->x == X && temp->y == Y)
        {
            k = "true";
            return k;
        }
        temp = temp->node;
    }
    
    return k;
}

void DelFirst()
{
    if(first == NULL)
    {
        cout << "-1\n";
    }
    
    else
    {
        point *temp = first;
        first = first->node;
        temp->node = NULL;
        delete temp;
    }
}

void Del(int X, int Y)
{
    if(Search(X, Y) == "false")
        cout << "-1\n";
    
    else
    {
        if(first->x == X && first->y == Y)
        {
            DelFirst();
        }
        
        else
        {
            
            point *temp1 = first;
            point *temp2 = NULL;
            
            while((temp1->x != X || temp1->y != Y) && temp1->node != NULL)
            {
                temp2 = temp1;
                temp1 = temp1->node;
            }
            
            temp2->node = temp1->node;
            temp1->node = NULL;
            delete temp1;
        }
    }
}

void Search(float d)
{
    point *temp = first;
    int count = 0;
    
    while(temp!=NULL)
    {
        if(distance(temp->x, temp->y) <= d)
        {
            count++;
        }
        temp = temp->node;
    }
    
    cout << count << endl;
}


void Length()
{
    int count = 0;
    struct point *temp = first;
    
    while(temp!=NULL)
    {
        count++;
        temp = temp->node;
    }
    
    delete temp;
    cout << count;
}

int main() {
    int n;
    cin >> n;
    int f;
    
    for(int i=1; i<=n; i++)
    {
        cin >> f;
        
        if(f==1)
        {
            int X, Y;
            cin >> X >> Y;
            AddFirst(X, Y);
        }
        
        else if(f==2)
        {
            DelFirst();
        }
        
        else if(f==3)
        {
            int X, Y;
            cin >> X >> Y;
            Del(X, Y);
        }
        
        else if(f==4)
        {
            float d;
            cin >> d;
            Search(d);
        }
        
        else if(f==5)
        {
            int X, Y;
            cin >> X >> Y;
            cout << Search(X, Y) << endl;
        }
        
        else
        {
            Length();
        }
    }
    
    
    cout << endl;
    return 0;
}


