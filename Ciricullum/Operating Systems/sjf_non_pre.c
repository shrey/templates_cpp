#include <stdio.h>

struct process {
    float id, at, bt, ct;
}
s[10], t;
int n; float time;

void comp(){ // to allocate the smallest at to first place
    int i, min;
    min = s[0].at;
    for (i = 0; i < n; i++)
        if (s[i].at < min) min = s[i].at;
    for (i = 0; i < n; i++)
        if (min == s[i].at) {
            t = s[0];
            s[0] = s[i];
            s[i] = t;
        }
}

void bubble_sort() {
    int i, d;
    for (i = 1; i < n; i++)
        for (d = 1; d < n - i; d++)
            if (s[d].bt > s[d + 1].bt) {
                t = s[d];
                s[d] = s[d + 1];
                s[d + 1] = t;
            }
}

int main() {
    int i, j; float wt = 0, tat = 0;
    printf("\nEnter No of Processes : ");
    scanf(" %d", & n);
    for (i = 0; i < n; i++) {
        printf("Arrival time %d : ", i+1);
        scanf("%f", &s[i].at);
        printf("Burst time %d : ", i+1);
        scanf("%f", &s[i].bt);
        s[i].id = i + 1;
    }
    comp();
    bubble_sort();
    time = s[0].at;
    printf("id\tat\tbt\tct\ttat\twt");
    for (i = 0; i < n; i++) {
        if (time < s[i].at) time = s[i].at;
        s[i].ct = time + s[i].bt;
        time = s[i].ct;
        tat += s[i].ct - s[i].at;
        wt += s[i].ct - s[i].at - s[i].bt;
        printf("\n%f \t%f \t%f \t%f \t%f \t%f ", s[i].id, s[i].at, s[i].bt, s[i].ct,
            s[i].ct - s[i].at, s[i].ct - s[i].at - s[i].bt);
    }
    printf("\nAverage Turn Around Time is %f ", tat / (float)n);
    printf("\nAverage Waiting time is %f ", wt / (float)n);
    return 0;
}