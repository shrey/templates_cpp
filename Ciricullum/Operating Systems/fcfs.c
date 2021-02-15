#include <stdio.h>

struct process {
    float id, at, bt, ct;
}
s[10];
float n, time;
void swap(float * a, float * b) {
    int t;
    t = * a;
    * a = * b;
    * b = t;
}

int main() {
    float wt = 0, tat = 0;
    printf("\nEnter number of Processes : ");
    scanf(" %f", & n);
    for (int i = 0; i < n; i++) {
        printf("Enter the burst time :");
        s[i].id = i + 1;
        scanf("%f", & s[i].bt);
        printf("Enter the arrival time : ");
        scanf("%f", &s[i].at);
    }
    time = s[0].at;
    printf("PID\t\tAT\t\tBT\t\tCT\t\tTAT\t\tWT");
    for (int i = 0; i < n; i++) {
        if (time < s[i].at) time = s[i].at;
        s[i].ct = time + s[i].bt;
        time = s[i].ct;
        tat += s[i].ct - s[i].at;
        wt += s[i].ct - s[i].at - s[i].bt;
        printf("\n%f \t\t%f \t\t%f \t\t%f \t\t%f \t\t%f ", s[i].id, s[i].at,
            s[i].bt, s[i].ct,
            s[i].ct - s[i].at, s[i].ct - s[i].at - s[i].bt);
    }
    printf("\nAverage Turn Around Time is %f ", tat / n);
    printf("\nAverage Waiting Time is %f \n", wt / n);
    return  0;
}