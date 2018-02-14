#include<stdio.h>
//Round Robin(RRS) Scheduling Discipline
struct process{
    //arrival time
    int at;
    //execute/burst time
    int et;
    //service time
    int st;
    //wait time
    int wt;
};
int main(){
    int totd = 0, i, j, q, n;
    float tot = 0.0;
    printf("Enter quantum: \n");
    scanf("%d", &q);
    printf("\n");
    printf("Enter number of processes: \n");
    scanf("%d", &n);
    struct process p[n];
    //initialization
    for(i = 0; i < n; i++){
        p[i].et = 0;
        p[i].st = 0;
        p[i].wt = 0;
        //assuming arrival is at once, can also be taken as sequential
        p[i].at = 0;
    }
    printf("\n");
    printf("Enter execute times respectively: \n");
    for(i = 0; i < n; i++){
        scanf("%d", &p[i].et);
        totd += p[i].et;
    }
    printf("\n");
    for(i = 1; i <= totd; i += q){

    }
    //wait time calculation: wt = st - at
    for(i = 0; i < n - 1; i++){
        p[i].at = i;//store the arrival time according to priority
        p[i + 1].st = p[i].st + p[i].et;
        p[i + 1].wt = p[i + 1].st - i - 1;
        tot += p[i + 1].wt;
    }
    p[n - 1].at = n - 1;

    tot /= n;//average wait time
    for(i = 0; i < n; i++){
        //printf("Process: %d, Arrival Time: %d, priority: %d, Execute Time: %d, Service Time: %d, Wait Time: %d\n", p[i].pid, p[i].at, p[i].pr, p[i].et, p[i].st, p[i].wt);
    }
    printf("\nAverage wait time: %.2f\n", tot);
    return 0;
}
