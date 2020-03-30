#include <iostream>
#include <vector>
using namespace std;
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(vector<int>arr, int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)

        for (j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
}


void printArray(vector<int>arr, int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void selectionSort(vector<int>arr, int n)
{
    int i, j, min_idx;

    for (i = 0; i < n-1; i++)
    {

        min_idx = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        swap(&arr[min_idx], &arr[i]);
    }
}

void insertionSort(vector<int>arr, int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int partition (vector<int>arr, int bajo, int alto)
{
    int pivot = arr[alto];
    int i = (bajo - 1);

    for (int j = bajo; j <= alto - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[alto]);
    return (i + 1);
}


void merge(vector<int>arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;


    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>arr, int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;

        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

void quickSort(vector<int>arr, int bajo, int alto)
{
    if (bajo < alto)
    {
        int pi = partition(arr, bajo, alto);

        quickSort(arr, bajo, pi - 1);
        quickSort(arr, pi + 1, alto);
    }
}

int shellSort(vector<int>arr, int n)
{

    for (int gap = n/2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            int temp = arr[i];

            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];

            arr[j] = temp;
        }
    }
    return 0;
}
void heapify(vector<int>arr, int n, int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;


    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>arr, int n)
{

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i=n-1; i>=0; i--)
    {
        swap(arr[0], arr[i]);

        heapify(arr, i, 0);
    }
}
// Driver code
int main()
{
    vector<int>arr = {64, 34, 25, 12, 22, 11, 90,100,200,520809,251,252,253,5,38,67};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n);
    cout<<"Sorted array by bubble sort: \n";
    printArray(arr, n);
    vector<int> arr2 = {64, 34, 25, 12, 22, 11, 90, 100, 200, 520809, 251, 252, 253, 5, 38, 67};
    selectionSort(arr2, n);
    cout<<"Sorted array by Selection sort: \n";
    printArray(arr2, n);
    vector<int> arr3 = {64, 34, 25, 12, 22, 11, 90, 100, 200, 520809, 251, 252, 253, 5, 38, 67};
    insertionSort(arr3, n);
    cout<<"Sorted array by insertion sort: \n";
    printArray(arr3, n);
    vector<int> arr4 = {64, 34, 25, 12, 22, 11, 90, 100, 200, 520809, 251, 252, 253, 5, 38, 67};
    quickSort(arr4,0,n-1);
    cout<<"Sorted array by Quick sort: \n";
    printArray(arr4, n);
    vector<int> arr5 = {64, 34, 25, 12, 22, 11, 90, 100, 200, 520809, 251, 252, 253, 5, 38, 67};
    shellSort(arr5,n);
    cout<<"Sorted array by Shell sort: \n";
    printArray(arr5, n);
    vector<int> arr6 = {64, 34, 25, 12, 22, 11, 90, 100, 200, 520809, 251, 252, 253, 5, 38, 67};
    int arr_size = sizeof(arr6)/sizeof(arr[60]);
    mergeSort(arr6,0,arr_size-1);
    cout<<"Sorted array by merge sort: \n";
    printArray(arr6, n);
    vector<int> arr7 = {64, 34, 25, 12, 22, 11, 90, 100, 200, 520809, 251, 252, 253, 5, 38, 67};
    int n2 = sizeof(arr)/sizeof(arr[0]);
    heapSort(arr7, n2);
    cout << "Sorted array by Heap sort \n";
    printArray(arr7, n2);




    return 0;
}
