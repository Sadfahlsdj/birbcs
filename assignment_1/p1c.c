#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define ARRAY_LENGTH 10000000

int *generate_array(int len);

void sort_array(int *arr, int len);

int check_sorted(int *arr, int len);

int main() {
    int *arr = generate_array(ARRAY_LENGTH);
    sort_array(arr, ARRAY_LENGTH);
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

void swap(int *a, int *b) {
    // helper function to swap 2 values
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i) {
    // running this function will correctly "heapify" a single element (at index i)
    // check element against what would be its 2 children
    int largest = i, left = 2 * i + 1, right = 2 * i + 2;

    // find largest
    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    // if root isn't largest, swap largest & root and run again
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void sift_down(int *arr, int i) {
    // swap first element (largest) and last one
    swap(&arr[0], &arr[i]);

    // heapify root element (swapped with first) since it's the only "wrong" one
    // i represents current len, decreases steadily since largest elements are swapped to the end
    heapify(arr, i, 0);
}

void sort_array(int *arr, int len) {
    for (int i = len / 2 - 1; i >= 0; i--)
        heapify(arr, len, i); // initial heapifying
        // all elements after len / 2 - 1 are leaf nodes so don't need heapifying
        // they will be swapped up by heapifying the non leaf nodes in the array

    for (int i = len - 1; i >= 0; i--) {
        // sift down each element, each iteration reduces size of the array
        sift_down(arr, i);
    }
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


