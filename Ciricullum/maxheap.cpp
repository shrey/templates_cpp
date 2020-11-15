#include <stdio.h>
int size = 0;
void swap(int *a, int *b) {
  int temp = *b;
  *b = *a;
  *a = temp;
}


void heapify(int array[], int size, int i) {
  if (size == 1) {
    printf("Single element in the heap");
  } else {

    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && array[l] > array[largest])
      largest = l;
    if (r < size && array[r] > array[largest])
      largest = r;


    if (largest != i) {
      swap(&array[i], &array[largest]);
      heapify(array, size, largest);
    }
  }
}

void insertQ(int array[], int newNum) {
  if (size == 0) {
    array[0] = newNum;
    size += 1;
  } else {
    array[size] = newNum;
    size += 1;
    for (int i = size / 2 - 1; i >= 0; i--) {
      heapify(array, size, i);
    }
  }
}

void deleteQ(int array[]) {
 /* int i;
  for (i = 0; i < size; i++) {
    if (num == array[i])
      break;
  }*/

  swap(&array[0], &array[size - 1]);
  size -= 1;
  for (int i = size / 2 - 1; i >= 0; i--) {
    heapify(array, size, i);
  }
}


void displayHeap(int array[], int size) {
  for (int i = 0; i < size; ++i)
    printf("%d ", array[i]);
  printf("\n");
}

int main() {
  int array[10];
    int choice;
    while(1){
        printf("------Priority Queue Menu--------\n");
        printf("1.Insert \t2.Delete\t3.Display\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:;
                int k;
                printf("Enter the no. you want to insert: ");
                scanf("%d",&k);
                insertQ(array,k);
                break;
            case 2:
                /*int key;
                printf("Enter the no. you want to delete: ");
                scanf("%d",&key);*/
                deleteQ(array);
                break;
            case 3:
                printf("Max-Heap array: ");
                displayHeap(array, size);

                break;
            default: printf(" Invalid Choice ");
                            break;

        }

    }


}