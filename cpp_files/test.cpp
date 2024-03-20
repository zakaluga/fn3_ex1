#include"includes.h"

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

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> a[i];
    }
    insertion_sort(a);
    for (int i = 0; i < n; ++i)
    {
        std::cout << a[i] << ' ';
    }
}