#include <stdio.h>

// Function to merge two sorted arrays
void merge(int n1, int n2, int a[], int b[]) {
    int i = 0, j = 0, k = 0;
    int s[n1 + n2]; // Array to store the merged result

    // Merge elements from both arrays
    while (i < n1 && j < n2) {
        if (a[i] <= b[j]) {
            s[k] = a[i];
            i++;
        } else {
            s[k] = b[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements from a[], if any
    while (i < n1) {
        s[k] = a[i];
        i++;
        k++;
    }

    // Copy remaining elements from b[], if any
    while (j < n2) {
        s[k] = b[j];
        j++;
        k++;
    }

    // Print the merged array
    printf("Merged array: ");
    for (i = 0; i < n1 + n2; i++) {
        printf("%d ", s[i]);
    }
    printf("\n");
}

int main() {
    int n1, n2;

    // Input for the first array
    printf("Enter the size of the first array: ");
    scanf("%d", &n1);
    int a[n1];
    printf("Enter the array elements in sorted order: ");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &a[i]);
    }

    // Input for the second array
    printf("Enter the size of the second array: ");
    scanf("%d", &n2);
    int b[n2];
    printf("Enter the array elements in sorted order: ");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &b[i]);
    }

    // Call the merge function
    merge(n1, n2, a, b);

    return 0;
}
