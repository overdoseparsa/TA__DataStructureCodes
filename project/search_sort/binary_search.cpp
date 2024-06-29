#include <iostream>
using namespace std;

class SortSearch {
public:
    
    void bubbleSort(int arr[], int n) {
        for (int i = 0; i < n-1; i++)    
            for (int j = 0; j < n-i-1; j++)
                if (arr[j] > arr[j+1])
                    swap(arr[j], arr[j+1]);
    }

    
    void selectionSort(int arr[], int n) {
        int i, j, min_idx;
        for (i = 0; i < n-1; i++) {
            min_idx = i;
            for (j = i+1; j < n; j++)
                if (arr[j] < arr[min_idx])
                    min_idx = j;
            swap(arr[min_idx], arr[i]);
        }
    }

    
    void insertionSort(int arr[], int n) {
        int i, key, j;
        for (i = 1; i < n; i++) {
            key = arr[i];
            j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
    }


    int binarySearch(int arr[], int left, int right, int x) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == x)
                return mid;
            if (arr[mid] < x)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }

    
    int linearSearch(int arr[], int n, int x) {
        for (int i = 0; i < n; i++)
            if (arr[i] == x)
                return i;
        return -1;
    }
};

int main() {
    SortSearch sortSearch;

    
    int arr[] = {5, 2, 8, 1, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    
    cout << "bb Sort: ";
    sortSearch.bubbleSort(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    
    int selectionArr[] = {5, 2, 8, 1, 9};
    cout << "select Sort: ";
    sortSearch.selectionSort(selectionArr, n);
    for (int i = 0; i < n; i++)
        cout << selectionArr[i] << " ";
    cout << endl;

    
    int insertionArr[] = {5, 2, 8, 1, 9};
    cout << "insert Sort: ";
    sortSearch.insertionSort(insertionArr, n);
    for (int i = 0; i < n; i++)
        cout << insertionArr[i] << " ";
    cout << endl;

    
    int binaryArr[] = {1, 2, 5, 8, 9};
    int target = 5;
    int index = sortSearch.binarySearch(binaryArr, 0, n - 1, target);
    cout << "Binary Search treee: Elemeaent " << target << " foaadund at d " << index << endl;

    // Linear Search
    int linearArr[] = {5, 2, 8, 1, 9};
    target = 8;
    index = sortSearch.linearSearch(linearArr, n, target);
    cout << "Linear Searsch: Elemeddnt " << target << " found at insdex " << index << endl;

    return 0;
}
