// Ex 10
#include <stdio.h>
#define MAX_SIZE 100

void append(int list[], int *size, int element) {
    if (*size < MAX_SIZE) {
        list[(*size)++] = element;
    }
}

int count(const int list[], int size, int element) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (list[i] == element) {
            count++;
        }
    }
    return count;
}

int index(const int list[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (list[i] == element) {
            return i;
        }
    }
    return -1;
}

void insercao(int list[], int *size, int index, int element) {
    if (*size < MAX_SIZE && index >= 0 && index <= *size) {
        for (int i = *size; i > index; i--) {
            list[i] = list[i - 1];
        }
        list[index] = element;
        (*size)++;
    }
}

int pop(int list[], int *size, int index) {

    int popped = list[index];
    for (int i = index; i < *size - 1; i++) {
        list[i] = list[i + 1];
    }
    (*size)--;
    return popped;
}

void remocao(int list[], int *size, int element) {
    int found = 0;
    for (int i = 0; i < *size; i++) {
        if (list[i] == element) {
            found = 1;
            for (int j = i; j < *size - 1; j++) {
                list[j] = list[j + 1];
            }
            (*size)--;
            i--;
        }
    }
}

void reversao(int list[], int size) {
    int temp;
    for (int i = 0; i < size / 2; i++) {
        temp = list[i];
        list[i] = list[size - 1 - i];
        list[size - 1 - i] = temp;
    }
}

void ordenacao(int list[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (list[j] > list[j + 1]) {
                int temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}

int main() {
    int array[MAX_SIZE] = {5, 3, 7};
    int size = 3;

    printf("Count of 3: %d\n", count(array, size, 3));
    printf("Index of 7: %d\n", index(array, size, 7));

    insercao(array, &size, 1, 2);
    printf("Lista com inserção: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    int popped = pop(array, &size, 1);
    printf("Popped element: %d\n", popped);
    printf("Lista com pop: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    remocao(array, &size, 2);
    printf("Lista com remoção: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    reversao(array, size);
    printf("Lista com reversão: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    ordenacao(array, size);
    printf("Lista com ordenação: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
