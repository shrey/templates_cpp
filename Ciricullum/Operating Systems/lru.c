#include <stdio.h>

int findLRU(int time[], int n) {
  int i, minimum = time[0], pos = 0;
  for (i = 1; i < n; ++i) {
    if (time[i] < minimum) {
      minimum = time[i];
      pos = i;
    }
  }
  return pos;
}
int main() {
    int nf, np, frames[5], pages[30], counter = 0, time[5], flag1,
      flag2, i, j,
      pos, faults = 0;
    printf("Enter number of Pages: ");
    scanf("%d", & np);
    printf("Enter Reference String: ");
    for (i = 0; i < np; ++i) scanf("%d", & pages[i]);
    printf("Enter number of Frames: \n");
    scanf("%d", & nf);
    for (i = 0; i < nf; ++i) frames[i] = -1;
    printf("Ref. String Frames ");
      for (i = 0; i < np; ++i) {
        flag1 = flag2 = 0;
        for (j = 0; j < nf; ++j) {
          if (frames[j] == pages[i]) {
            counter++;
            time[j] = counter;
            flag1 = flag2 = 1;
            printf("%d", pages[i]);
            break;
          }
        }
        if (flag1 == 0) {
          for (j = 0; j < nf; ++j) {
            if (frames[j] == -1) {
              counter++;
              faults++;
              frames[j] = pages[i];
              time[j] = counter;
              flag2 = 1;
              printf("%d\t", pages[i]);
              for (j = 0; j < nf; ++j) printf("%d\t", frames[j]);
              break;
            }
          }
        }
        if (flag2 == 0) {
          pos = findLRU(time, nf);
          counter++;
          faults++;
          frames[pos] = pages[i];
          time[pos] = counter;
          printf("%d\t", pages[i]);
          for (j = 0; j < nf; ++j) printf("%d\t", frames[j]);
        }
        printf("\n");
      }
      printf("\nTotal Page Faults = %d", faults);
    }