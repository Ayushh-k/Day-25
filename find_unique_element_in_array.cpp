#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int unique_ele = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        unique_ele ^= arr[i];
    }
    if (unique_ele == INT_MIN)
    {
        cout << "Their was no unique element in the array." << endl;
    }
    else
    {
        cout << "Unique element in the given array is : " << unique_ele << endl;
    }

    delete[] arr;
}