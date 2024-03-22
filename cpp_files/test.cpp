#include<iostream>
#include<set>


// void insertion_sort(std::vector<int> &arr)
// {
//     for (size_t i = 0; i < arr.size(); ++i)
//     {
//         const int key = arr[i];

//         int j = i - 1;

//         while (j >= 0 && arr[i] > key)
//         {
//             arr[j + 1] = arr[j];
//             j--;
//         }

//         arr[j + 1] = key;
//     }
// }

int main()
{
    std::set<int> s; 
    s.insert(1); 
    s.insert(2); 
    s.insert(3); 
    s.insert(4);
    for (auto it = s.begin(); it!= s.end(); ++it){
        std::cout << *it << " ";
    }
}