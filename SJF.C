#include<stdio.h>
//Priority Based(PBS) Scheduling Discipline
struct process{
    //process id
    int pid;
    //execute/burst time
    int et;
    //service time
    int st;
    //wait time
    int wt;
};
int main(){
    int i, j, n;
    float tot = 0.0;
    printf("Enter number of processes: \n");
    scanf("%d", &n);
    struct process p[n], temp;//temp variable is for swapping/sorting
    //initialization
    for(i = 0; i < n; i++){
        p[i].et = 0;
        p[i].st = 0;
        p[i].wt = 0;
        //assuming sequential arrival
        p[i].pid = i;
    }
    printf("\n");
    printf("Enter execute/burst times respectively: \n");
    for(i = 0; i < n; i++){
        scanf("%d", &p[i].et);
    }
    printf("\n");
    for(i = 0; i < n - 1; i++){
        for(j = i + 1; j < n; j++){
            //sort processes by execute/burst time
            if(p[j].et < p[i].et){
                temp = p[j];
                p[j] = p[i];
                p[i] = temp;
            }
        }
    }
    //service time calculation on processes sorted by SJF
    for(i = 0; i < n - 1; i++){
        p[i + 1].st = p[i].st + p[i].et;
    }
    //sort by process id
    for(i = 0; i < n - 1; i++){
        for(j = i + 1; j < n; j++){
            if(p[j].pid < p[i].pid){
                temp = p[j];
                p[j] = p[i];
                p[i] = temp;
            }
        }
    }
    //wait time calculation: wt = st - at
    for(i = 0; i < n; i++){
        //at is same as pid it in sequential arrival
        p[i].wt = p[i].st - p[i].pid;
        if(p[i].wt < 0){
            //minimum wait time is zero
            p[i].wt = 0;
        }
        tot += p[i].wt;
    }
    tot /= n;//average wait time
    for(i = 0; i < n; i++){
        printf("Process: %d, Arrival Time: %d, Execute Time: %d, Service Time: %d, Wait Time: %d\n", i, i, p[i].et, p[i].st, p[i].wt);
    }
    printf("\nAverage wait time: %.2f\n", tot);
    return 0;
}
