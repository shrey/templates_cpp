#include <stdio.h>

int main() {
    int at[10], bt[10], temp[10];
    int i, smallest, cnt = 0, tme, limit;
    double wt = 0, tat = 0, end;
    float avg_wt, avg_tat;
    printf("\nTotal Number of Processes? \t");
    scanf("%d", & limit);
    printf("\nDetails of %d Processes ? \n", limit);
    for (i = 0; i < limit; i++) {
        printf("\nArrival Time? \t");
        scanf("%d", & at[i]);
        printf("Burst Time? \t");
        scanf("%d", & bt[i]);
        temp[i] = bt[i];
    }
    bt[9] = 9999;
    for (tme = 0; cnt != limit; tme++) {
        smallest = 9;
        for (i = 0; i < limit; i++) {
            if (at[i] <= tme && bt[i] < bt[smallest] && bt[i] > 0) {
                smallest = i;
            }
        }
        bt[smallest]--;
        if (bt[smallest] == 0) {
            cnt++;
            end = tme + 1;
            wt = wt + end - at[smallest] - temp[smallest];
            tat = tat + end - at[smallest];
        }
    }
    avg_wt = wt / limit;
    avg_tat = tat / limit;
    printf("\n\nAverage Waiting Time is \t%lf\n", avg_wt);
    printf("Average Turnaround Time is \t%lf\n", avg_tat);
    return 0;
}