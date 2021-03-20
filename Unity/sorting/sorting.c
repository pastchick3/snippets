#include <stddef.h>

void insertion_sort(size_t const len, int arr[len]) {
    for (size_t i = 1; i < len; ++i) {
        size_t j = i;
        while (j && (arr[j] < arr[j - 1])) {
            int temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
            --j;
        }
    }
}
