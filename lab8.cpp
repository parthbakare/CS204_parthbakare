#include <bits/stdc++.h>
using namespace std;

void swap(long long int *a, long long int *b)
{
    long long int temp = *a;
    *a = *b;
    *b = temp;
}

long long int partition(long long int arr[], long long int l, long long int r, long long int x)
{
    long long int i;
    for (i = l; i < r; i++)
        if (arr[i] == x)
            break;

    swap(&arr[i], &arr[r]);
    i = l;
    
    for (long long int j = l; j <= r - 1; j++)
    {
        if (arr[j] <= x)
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    
    swap(&arr[i], &arr[r]);
    return i;
}

long long int findMedian(long long int arr[], long long int n)
{
    sort(arr, arr + n);
    return arr[n / 2];
}

long long int ksmall(long long int arr[], long long int l, long long int r, long long int k)
{
    if (k > 0 && k <= r - l + 1)
    {
        long long int n = r - l + 1;
        long long int i, median[(n + 4) / 5];
        for (i = 0; i < n / 5; i++)
            median[i] = findMedian(arr + l + i * 5, 5);
        if (i * 5 < n)
        {
            median[i] = findMedian(arr + l + i * 5, n % 5);
            i++;
        }
        long long int medOfMed = (i == 1) ? median[i - 1] : ksmall(median, 0, i - 1, i / 2);
        long long int pos = partition(arr, l, r, medOfMed);
        if (pos - l == k - 1)
            return arr[pos];
        if (pos - l > k - 1)
            return ksmall(arr, l, pos - 1, k);

        return ksmall(arr, pos + 1, r, k - pos + l - 1);
    }
    return INT_MAX;
}


int main()
{
    long long int n, t;
    cin >> t;
    for(int j=0; j<t; j++)
    {
        cin >> n;
        long long int a[n];
        long long int x, y;
        
        for(int i=0; i<n; i++)
        {
            cin >> x >> y;
            a[i] = x * x + y * y;
        }
        
        long long int ans;
        long long int f = (n + 1) / 2;
        
        if (n <= 140)
        {
            sort(a, a + n);
            ans = a[f - 1];
        }
        
        else
            ans = ksmall(a, 0, n - 1, f);
        
        cout << sqrt(ans);
    }
    return 0;
}