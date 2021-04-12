#include <stdio.h>
#include <stdbool.h>

int main() {
    int currall[5][5];
    int max_need[5][5];
    int avl[5];
    int alloc[5] = {0, 0, 0, 0, 0};
    int max_res[5];
    int running[5];

    int i, j, exec, r, p;
    int count = 0;
    bool safe = false;

    printf("\nEnter the number of resources: ");
    scanf("%d", &r);

    printf("\nEnter the number of processes: ");
    scanf("%d", &p);

    for (i = 0; i < p; i++) {
        running[i] = 1;
        count++;
    }

    printf("\nEnter resource Vector: ");
    for (i = 0; i < r; i++)
        scanf("%d", &max_res[i]);

    printf("\nEnter Allocated Resource Table: ");
    for (i = 0; i < p; i++) {
        for (j = 0; j < r; j++)
            scanf("%d", &currall[i][j]);
    }

    printf("\nEnter Maximum resource table: ");
    for (i = 0; i < p; i++) {
        for (j = 0; j < r; j++)
            scanf("%d", &max_need[i][j]);
    }

    printf("\nThe resource Vector is: ");
    for (i = 0; i < r; i++)
        printf("%d ", max_res[i]);

    printf("\nThe Allocated Resource Table:\n");
    for (i = 0; i < p; i++) {
        for (j = 0; j < r; j++)
            printf("\t%d", currall[i][j]);
        printf("\n");
    }

    printf("\nThe Maximum resource Table:\n");
    for (i = 0; i < p; i++) {
        for (j = 0; j < r; j++)
            printf("\t%d", max_need[i][j]);
        printf("\n");
    }

    for (i = 0; i < p; i++)
        for (j = 0; j < r; j++)
            alloc[j] += currall[i][j];

    printf("\nAllocated resources: ");
    for (i = 0; i < r; i++)
        printf("%d ", alloc[i]);

    for (i = 0; i < r; i++)
        avl[i] = max_res[i] - alloc[i];

    printf("\nAvailable resources: ");
    for (i = 0; i < r; i++)
        printf("%d ", avl[i]);
    printf("\n");

    while (count != 0) {
        safe = false;
        for (i = 0; i < p; i++) {
            if (running[i]) {
                exec = 1;
                for (j = 0; j < r; j++) {
                    if (max_need[i][j] - currall[i][j] > avl[j]) {
                        exec = 0;
                        break;
                    }
                }

                if (exec) {
                    printf("\nProcess %d is executing.\n", i + 1);
                    running[i] = 0;
                    count--;
                    safe = true;
                    for (j = 0; j < r; j++)
                        avl[j] += currall[i][j];
                    break;
                }
            }
        }

        if (!safe) {
            printf("The processes are in unsafe state.\n");
            break;
        }

        if (safe)
            printf("The process is in safe state.\n");

        printf("Available vector: ");
        for (i = 0; i < r; i++)
            printf("%d ", avl[i]);
    }
    printf("\n");
    return 0;
}

/*
4 5
8 5 9 7
2 0 1 1 0
1 2 1 4 0
0 3 0 2 1
0 1 0 3 0
3 2 1 4 0
2 5 2 5 1
0 5 1 5 3
0 3 0 3 3
*/