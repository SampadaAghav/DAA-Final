#include <iostream> 
#include <vector> 
using namespace std; 
int partition(vector<int> &arr, int low, int high) 
{ 
 int pivot = arr[low]; 
 int left = low + 1; 
 int right = high; 
 while (true) 
 { 
 while (left <= right && arr[left] <= pivot) 
 { 
 left++; 
 } 
 while (left <= right && arr[right] > pivot) 
 { 
 right--; 
 } 
 if (left > right) 
 { 
 break; 
 } 
 swap(arr[left], arr[right]); 
 } 
 swap(arr[low], arr[right]); 
 return right; 
} 
void quickSort(vector<int> &arr, int low, int high) 
{ 
 if (low < high) 
 { 
 int pivotIndex = partition(arr, low, high); 
 quickSort(arr, low, pivotIndex - 1); 
 quickSort(arr, pivotIndex + 1, high); 
 } 
} 
int main() 
{ 
 int n; 
 cout << "Enter the number of elements: "; 
 cin >> n; 
 vector<int> arr(n); 
 cout << "Enter the elements: " << endl; 
 for (int i = 0; i < n; i++) 
 { 
 cin >> arr[i]; 
 } 
 cout << endl; 
 cout << "Original Array: "; 
 for (int num : arr) 
 { 
 cout << num << " "; 
 } 
 cout << endl; 
 quickSort(arr, 0, arr.size() - 1); 
 cout << "Sorted Array: "; 
 for (int num : arr) 
 { 
 cout << num << " "; 
 } 
 cout << endl; 
 return 0; 
} 