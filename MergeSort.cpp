#include <bits/stdc++.h>
using namespace std;

void mergedSortedArrays(vector<int> &a, int m, vector<int> &b, int n)
{
    int i = m - 1, j = n - 1, k = m + n - 1;
    while (i >= 0 && j >= 0)
    {
        if (a[i] > b[j])
        {
            a[k] = a[i];
            i--;
        }
        else
        {
            a[k] = b[j];
            j--;
        }
        k--;
    }
    // Checking if any other elements are left in b
    while (j >= 0)
    {
        a[k] = b[j];
        j--;
        k--;
    }
}
int main()
{
    vector<int> a = {11, 14, 19, 22, 26};
    vector<int> b = {1, 4, 6, 9};

    mergedSortedArrays(a, a.size(), b, b.size());
    for (auto i : a)
    {
        cout << i << " " << endl;
    }
    return 0;
}