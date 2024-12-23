#include <iostream>
using namespace std;

int binsearch(int arr[], int start, int end, int key)
{

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (arr[mid] == key)
            return mid;

        else if (arr[mid] < key)
            start = mid + 1;

        else
            end = mid;
    }

    return -1;
}
int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int arr[size];

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    int key;

    cout << "\n\nArray: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "\nSorted Array: ";

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "\nEnter the key to search: ";
    cin >> key;

    int result = binsearch(arr, 0, size, key);

    if (result == -1)
        cout << "\nElement not found in the array." << endl;
    else
        cout << "\nElement Found! Index value of " << key << " is " << result << endl;
    return 0;
}