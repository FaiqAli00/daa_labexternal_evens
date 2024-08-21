#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

void quicksort(int a[], int low, int high)
{
    if (low < high)
    {
        int pivot = a[low], i = low + 1, j = high, temp;
        while (i <= j)
        {
            while (i <= high && a[i] <= pivot)
                i++;
            while (a[j] > pivot)
                j--;
            if (i < j)
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
        temp = a[low];
        a[low] = a[j];
        a[j] = temp;
        quicksort(a, low, j - 1);
        quicksort(a, j + 1, high);
    }
}

int main()
{
    int a[MAX], n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    srand(time(NULL)); // Initialize random number generator
    for (int i = 0; i < n; i++)
        a[i] = rand() % 100;
    printf("Before sorting:\n");
    for (int i = 0; i < n; i++)
        printf("%d\t", a[i]);
    clock_t start = clock();
    quicksort(a, 0, n - 1);
    printf("\nAfter sorting:\n");
    for (int i = 0; i < n; i++)
        printf("%d\t", a[i]);
    printf("\nTime taken: %.6f seconds\n", (double)(clock() - start) / CLOCKS_PER_SEC);
    return 0;
}
