#include "includes.h"

void bubble_sort(std::vector<int> &arr)
{
    bool IsSwapped;
    do
    {
        IsSwapped = false;
        for (size_t i = 0; i < arr.size() - 1; ++i)
        {
            if (arr[i] < arr[i + 1])
            {
                std::swap(arr[i], arr[i + 1]);
                IsSwapped = true;
            }
        }
    } while (IsSwapped);
}

void insertion_sort(std::vector<int> &arr)
{
    for (size_t i = 0; i < arr.size(); ++i)
    {
        const int key = arr[i];

        int j = i - 1;

        while (j >= 0 && arr[i] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

void QuickSort(std::vector<int>& arr, const int left, const int right) {

int i = left, j = right;
const int pivot = arr[(left + right) / 2];

while (i <= j) {
    while (arr[i] < pivot)
    i++;
    while (arr[j] > pivot)
        j--;
    if (i <= j) {
        std::swap(arr[i], arr[j]);
        i++;
        j--;
    }
}        
if (left < j)
    QuickSort(arr, left, j);

if (i < right)
    QuickSort(arr, i, right);
}

// merge sort

void merge(std::vector<int>& arr, const int left, const int mid, const int right) {

const int n1 = mid - left + 1;
const int n2 = right - mid;

std::vector<int> left_arr(n1), right_arr(n2);

for (int i = 0; i < n1; i++)
    left_arr[i] = arr[left + i];

for (int j = 0; j < n2; j++)
    right_arr[j] = arr[mid + 1 + j];

int i = 0, j = 0, k = left;

while (i < n1 && j < n2) {
    if (left_arr[i] <= right_arr[j])
        arr[k] = left_arr[i++];
    else
        arr[k] = right_arr[j++];
    k++;
}

while (i < n1)
    arr[k++] = left_arr[i++];

while (j < n2)
    arr[k++] = right_arr[j++];

}
void MergeSort(std::vector<int>& arr, const int left, const int right) {
if (left >= right)
return;
const int mid = left + (right - left) / 2;
MergeSort(arr, left, mid);
MergeSort(arr, mid + 1, right);
merge(arr, left, mid, right);
}

void shellSort(int list[], int listLength)
{
	for(int step = listLength/2; step > 0; step /= 2)
	{
		for (int i = step; i < listLength; i += 1)
        {       
			int j = i;
			while(j >= step && list[j - step] > list[i])
			{
				std::swap(list[j], list[j - step]);
				j-=step;
				std::cout<<"\ndid";
			}
        }
	}
}

// heap sort

void heapify(int list[], int listLength, int root)
{
	int largest = root;
	int l = 2*root + 1;
	int r = 2*root + 2;
	  
	if (l < listLength && list[l] > list[largest])
		largest = l;
	  
	if (r < listLength && list[r] > list[largest])
		largest = r;

	if (largest != root)
	{
		std::swap(list[root], list[largest]);
		heapify(list, listLength, largest);
	}
}
  
void heapSort(int list[], int listLength)
{
	for(int i = listLength / 2 - 1; i >= 0; i--)
		heapify(list, listLength, i);
	 
	for(int i = listLength - 1; i >= 0; i--)
	{
		std::swap(list[0], list[i]);
		heapify(list, i, 0);
	}
}