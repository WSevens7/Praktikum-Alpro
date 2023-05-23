#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Menghasilkan_Array_Acak (int Array[], int Size, int min_value, int max_value) {
    int i;
    for (i = 0; i < Size; i++) {
        Array[i] = min_value + rand()%(max_value - min_value + 1);
    }
}

void Bubble_Sort(int Array[], int Size) {
    int i, j;
    for (i = 0; i < Size - 1; i++) {
        for (j = 0; j < Size - i - 1; j++) {
            if (Array[j] > Array[j + 1]) {
                int temp = Array[j];
                Array[j] = Array[j + 1];
                Array[j + 1] = temp;
            }
        }
    }
}

void Counting_Sort(int Array[], int Size, int max_value) {
    int Counting_Array[max_value + 1];
    int i, j;

    for (i = 0; i <= max_value; i++) {
        Counting_Array[i] = 0;
    }

    for (i = 0; i < Size; i++) {
        Counting_Array[Array[i]]++;
    }

    int index = 0;
    for (i = 0; i <= max_value; i++) {
        for (j = 0; j < Counting_Array[i]; j++) {
            Array[index++] = i;
        }
    }
}

void Insertion_Sort(int Array[], int Size) {
    int i, j, key;
    for (i = 1; i < Size; i++) {
        key = Array[i];
        j = i - 1;

        while (j >= 0 && Array[j] > key) {
            Array[j + 1] = Array[j];
            j = j - 1;
        }

        Array[j + 1] = key;
    }
}

void Selection_Sort(int Array[], int Size) {
    int i, j, min_idx;
    for (i = 0; i < Size - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < Size; j++) {
            if (Array[j] < Array[min_idx]) {
                min_idx = j;
            }
        }
        int temp = Array[min_idx];
        Array[min_idx] = Array[i];
        Array[i] = temp;
    }
}

void print_Array(int Array[], int Size) {
    int i;
    for (i = 0; i < Size; i++) {
        printf("%d ", Array[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    int Size, min_value, max_value;
    printf("Masukkan panjang Array: ");
    scanf("%d", &Size);

    int Array[Size];

    printf("Masukkan Arraynya: ");
    for (int i = 0; i < Size; i++) {
        scanf("%d", &Array[i]);
    }

    printf("\nArray yang belum terurut: ");
    print_Array(Array, Size);

    char sort_type;
    printf("Pilihan Sorting: \n");
    printf("A. Bubble Sort\n");
    printf("B. Counting Sort\n");
    printf("C. Insertion Sort\n");
    printf("D. Selection Sort\n");
    printf("Pilih sort yang digunakan: ");
    scanf(" %c", &sort_type);
    printf("\n");

    switch (sort_type) {

        case 'A':
            printf("Sorting yang digunakan adalah Bubble Sort\n");
            Bubble_Sort(Array, Size);
            break;

        case 'B':
            printf("Sorting yang digunakan adalah Counting Sort\n");
            Counting_Sort(Array, Size, 100);
            break;

        case 'C':
            printf("Sorting yang digunakan adalah Insertion Sort\n");
            Insertion_Sort(Array, Size);
            break;

        case 'D':
            printf("Sorting yang digunakan adalah Selection Sort\n");
            Selection_Sort(Array, Size);
            break;
        default:
            printf("Pilihan sorting tidak valid\n");
            return 1;
    }
    printf("\nArray yang sudah terurut: ");
    print_Array(Array, Size);
    return 0;
}