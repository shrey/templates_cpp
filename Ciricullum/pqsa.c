#include <stdio.h>
struct process {
    int id, pr;
    float at, bt, ct;
}   a[10], t;
float n, time;
void comp() {
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

void bubble_sort() {
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
    float wt = 0, tat = 0;
    printf("\nEnter No of Processes : ");
    scanf(" %f", & n);
    for (i = 0; i < n; i++) {
        printf("Priority of %d : ", i + 1);
        scanf("%d",&a[i].pr);
        printf("Arrival time of %d : ", i + 1);
        scanf("%f",&a[i].at);
        printf("Burst time %d : ", i + 1);
        scanf("%f",&a[i].bt);
        a[i].id = i + 1;
        // scanf("%d%f%f", & a[i].pr, & a[i].at, & a[i].bt);
    }
    comp();
    bubble_sort();
    time = a[0].at;
    printf("PID\tPriority AT\tBT\tCT\tTAT\tWT");
    for (i = 0; i < n; i++) {
        if (time < a[i].at) time = a[i].at;
        a[i].ct = time + a[i].bt;
        time = a[i].ct;
        tat += a[i].ct - a[i].at;
        wt += a[i].ct - a[i].at - a[i].bt;
        printf("\n%d \t%d \t%f \t%f \t%f \t%f \t%f ", a[i].id, a[i].pr, a[i].at, a[i].bt, a[i].ct, a[i].ct - a[i].at, a[i].ct - a[i].at - a[i].bt);
    }
    printf("\nAverage Turn Around Time = %f ", tat / n);
    printf("\nAverage Waiting Time = %f ", wt / n);
}