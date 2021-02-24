#include <stdio.h>
struct process {
    int id, pr;
    int at, bt, ct;
}   a[10], t;
int n, time;
void start() {
    int i, min;
    min = a[0].at;
    for (i = 0; i < n; i++)
        if (a[i].at < min) min = a[i].at;
    for (i = 0; i < n; i++)
        if (min == a[i].at) {
            t = a[0];
            a[0] = a[i];
            a[i] = t;
        }
}

void sort() {
    int i, d;
    for (i = 0; i < n-1; i++)
        for (d = 0; d < n - i - 1; d++)
            if (a[d].at > a[d + 1].at) {
                t = a[d];
                a[d] = a[d + 1];
                a[d + 1] = t;
            }else if(a[d].at == a[d+1].at && a[d].pr < a[d+1].pr){
                t = a[d];
                a[d] = a[d+1];
                a[d+1] = t;
            }
}
int main() {
    int i, j;
    int wt = 0, tat = 0;
    printf("\nEnter No of Processes : ");
    scanf(" %d", & n);
    for (i = 0; i < n; i++) {
        printf("Priority, AT, BT of %d : ", i + 1);
        a[i].id = i + 1;
        scanf("%d%d%d",&a[i].pr, &a[i].at, &a[i].bt);

    }
    start();
    sort();
    time = a[0].at;
    printf("PID\tPriority AT\tBT\tCT\tTAT\tWT");
    for (i = 0; i < n; i++) {
        if (time < a[i].at) time = a[i].at;
        a[i].ct = time + a[i].bt;
        time = a[i].ct;
        tat += a[i].ct - a[i].at;
        wt += a[i].ct - a[i].at - a[i].bt;
        printf("\n%d \t%d \t%d \t%d \t%d \t%d \t%d ", a[i].id, a[i].pr, a[i].at, a[i].bt, a[i].ct, a[i].ct - a[i].at, a[i].ct - a[i].at - a[i].bt);
    }
    printf("\nAverage Turn Around Time = %f ", tat /(float) n);
    printf("\nAverage Waiting Time = %f ", wt /(float) n);
}