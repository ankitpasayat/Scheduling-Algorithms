#include<stdio.h>
//First Come First Serve(FCFS) Scheduling Discipline
struct process{
    //execute/burst time
    int et;
    //service time
    int st;
    //wait time
    int wt;
};
int main(){
    int i, n;
    float tot = 0.0;
    printf("Enter number of processes: \n");
    scanf("%d", &n);
    struct process p[n];
    //initialization
    for(i = 0; i < n; i++){
        p[i].et = 0;
        p[i].st = 0;
        p[i].wt = 0;
    }
    printf("\n");
    printf("Enter execute times respectively: \n");
    for(i = 0; i < n; i++){
        scanf("%d", &p[i].et);
    }
    printf("\n");
    //wait time calculation: wt = st - at
    for(i = 0; i < n - 1; i++){
        p[i + 1].st = p[i].st + p[i].et;
        p[i + 1].wt = p[i + 1].st - i - 1;
        tot += p[i + 1].wt;
    }
    tot /= n;//average wait time
    for(i = 0; i < n; i++){
        printf("Process: %d, Arrival Time: %d, Execute Time: %d, Service Time: %d, Wait Time: %d\n", i, i, p[i].et, p[i].st, p[i].wt);
    }
    printf("\nAverage wait time: %.2f\n", tot);
    return 0;
}
