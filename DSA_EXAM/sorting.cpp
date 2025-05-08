#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>&arr, vector<int>::iterator left, vector<int>::iterator mid,  vector<int>::iterator right)
{
    vector<int> merge;
    auto it1 = left, it2 = mid;

    while (it1 != mid && it2 != right)
    {
        if (*it1 <= *it2)
        {
           merge.push_back(*it1++);
        }
        else{
            merge.push_back(*it2++);
        }
    }
    merge.insert(merge.end(),it1,mid);
    merge.insert(merge.end(),it2,right);

    move(merge.begin(), merge.end(), left);
}
    void mergesort(vector<int>&arr, vector<int>::iterator left, vector<int>::iterator right)
    {
        if (right - left <= 1)
        {
            return;
        }
        
        auto mid = left + (right - left) / 2;
        mergesort(arr,left,mid);
        mergesort(arr,mid,right);
        merge(arr, left, mid, right);
    }

    int partition(vector<int>& arr, int low, int high) {
        int pivot = arr[high], i = low - 1;
    
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot)
                swap(arr[++i], arr[j]);
        }
        swap(arr[i + 1], arr[high]);
        return i + 1;
    }
    
    void quickSort(vector<int>& arr, int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }
    
void printVector(const vector<int>&arr)
{
    for (int val : arr)
    cout<< val << " ";
    cout<<endl;
}


int main()
{

    int n, choice;
    cout <<"Enter Size of Array: ";
    cin>>n;

    vector<int> arr(n);
    cout<<"enter the element:"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Element [" << i << "]: ";
        cin >> arr[i];
    }
    cout<<endl;
    cout<<"*** Menu ***"<<endl;
    cout<<"1. Merge Sort"<<endl;
    cout<<"2. Quick Sort"<<endl;
    cout<<"enter choice:"<<endl;
    cin>>choice;

    cout<<endl;
    cout<<"Original Array:"<<endl;
    printVector(arr);

    cout<<endl;
    if (choice == 1)
    {
       mergesort(arr,arr.begin(), arr.end());
       cout<<"Merge Sort:"<<endl;
    }

    else if (choice == 2) {
        quickSort(arr, 0, arr.size() - 1);
        cout << "Quick Sort: "<<endl;
    }
    
    else {
        cout << "Invalid choice!\n";
        return 1;
    }

    printVector(arr);
    return 0;
}