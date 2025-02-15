#include <iostream>
#include <vector>
using std::swap;

void dutchNationalFlag(std::vector<int>& arr) {
    int low = 0, mid = 0, high = arr.size() - 1;
    while (mid <= high) {
        // switch (arr[mid]) {
        //     case 0:
        //         std::swap(arr[low++], arr[mid++]);
        //         break;
        //     case 1:
        //         mid++;
        //         break;
        //     case 2:
        //         std::swap(arr[mid], arr[high--]);
        //         break;
        // }

        if(arr[mid] == 0){
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid] == 1){
            mid++;
        }
        else{
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main() {
    std::vector<int> arr = {2, 0, 2, 1, 1, 0};
    dutchNationalFlag(arr);
    for (int num : arr) {
        std::cout << num << " ";
    }
    return 0;
}