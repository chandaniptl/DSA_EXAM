#include <iostream>
#include <vector>
using namespace std;

int BinarySearch(vector<int> &arr, int target)
{
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1;
}

int main()
{
    cout<<"Size of array: ";
    int num;
    cin>>num;
    vector<int> arr(num);
    cout<<"Elements of array: ";
    for(int i=0; i<num; i++)
    {
        cin>>arr[i];
    }
    cout<<"Element to be searched: ";
    int target;
    cin>>target;
    int result = BinarySearch(arr, target);
    cout<<"Found at index: "<<result<<endl;

    return 0;
}