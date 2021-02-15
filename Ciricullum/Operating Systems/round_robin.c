#include<stdio.h>

int main() {
    int i, j, n, tme, remain, flag = 0, tq;
    int wt = 0, tat = 0, at[10], bt[10], rt[10];
    printf("Enter Total Process:\t ");
    scanf("%d", & n);
    remain = n;
    for (i = 0; i < n; i++) {
        printf("Arrival time for process %d: ", i + 1);
        scanf("%d", & at[i]);
        printf("Burst time for process %d: ", i + 1);
        scanf("%d", & bt[i]);
        rt[i] = bt[i];
    }
    printf("Enter Time Quantum:\t");
    scanf("%d", & tq);
    printf("\n\nProcess\tTurnaround Time\tWaiting Time\n\n");
    for (tme = 0, i = 0; remain != 0;) {
        if (rt[i] <= tq && rt[i] > 0) {
            tme += rt[i];
            rt[i] = 0;
            flag = 1;
        } else if (rt[i] > 0) {
            rt[i] -= tq;
            tme += tq;
        }
        if (rt[i] == 0 && flag == 1) {
            remain--;
            printf("%d\t%d\t%d\n", i + 1, tme - at[i], tme - at[i] - bt[i]);
            wt += tme - at[i] - bt[i];
            tat += tme - at[i];
            flag = 0;
        }
        if (i == n - 1)
            i = 0;
        else if (at[i + 1] <= tme)
            i++;
        else
            i = 0;
    }
    printf("\nAverage Waiting Time= %f\n", wt * 1.0 / n);
    printf("Avg Turnaround Time = %f\n", tat * 1.0 / n);
    return 0;
}