#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define ARRAY_LENGTH 100000

int *generate_array(int len);

void sort_array(int *arr, int len);

int check_sorted(int *arr, int len);

int main() {
    int *arr = generate_array(ARRAY_LENGTH);
    sort_array(arr, ARRAY_LENGTH);
//    for(int i = 0; i < ARRAY_LENGTH; i++){
//        printf("%d ", arr[i]);
//    }
    printf("array is %ssorted\n", check_sorted(arr, ARRAY_LENGTH) ? "" : "not ");
    free(arr);
}

int *generate_array(int len) {
    srand(time(NULL));
    int* arr = calloc(len, sizeof(int));
    for (int i = 0; i < len; i++) {
        arr[i] = rand();
    }
    return arr;
}

int comp(const void *a, const void *b) {
    // helper function for qsort to define increasing order
    return (*(int *)a - *(int *)b);
}

void sort_array(int *arr, int len) {
    qsort(arr, len, sizeof(arr[0]), comp);
}

// integers are truthy - nonzero values are evaluated as true, zero as false.
int check_sorted(int *arr, int len) {
    int i, last_checked = -1;
    int tmp;
    for (i = 0; i < len; ++i) {
        tmp = *(arr + i);
        if (last_checked > tmp) {
            return 0;
        }
        last_checked = tmp;
    }
    return 1;
}
