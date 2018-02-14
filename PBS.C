#include<stdio.h>
//Priority Based(PBS) Scheduling Discipline
struct process{
    //priority
    int pr;
    //arrival time
    int at;
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
        p[i].pid = i;
        p[i].at = 0;
        p[i].pr = 0;
        p[i].et = 0;
        p[i].st = 0;
        p[i].wt = 0;
    }
    printf("\n");
    printf("Enter execute times and priority respectively: \n");
    for(i = 0; i < n; i++){
        scanf("%d %d", &p[i].et, &p[i].pr);
    }
    printf("\n");
    for(i = 0; i < n - 1; i++){
        for(j = i + 1; j < n; j++){
            //sort processes by priority
            if(p[j].pr > p[i].pr){
                temp = p[j];
                p[j] = p[i];
                p[i] = temp;
            }
            //if same priority, sort by process id
            else if(p[j].pr == p[i].pr && p[j].pid < p[i].pid){
                temp = p[j];
                p[j] = p[i];
                p[i] = temp;
            }
        }
    }
    //wait time calculation: wt = st - at
    for(i = 0; i < n - 1; i++){
        p[i].at = i;//store the arrival time according to priority
        p[i + 1].st = p[i].st + p[i].et;
        p[i + 1].wt = p[i + 1].st - i - 1;
        tot += p[i + 1].wt;
    }
    p[n - 1].at = n - 1;
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
    tot /= n;//average wait time
    for(i = 0; i < n; i++){
        printf("Process: %d, Arrival Time: %d, priority: %d, Execute Time: %d, Service Time: %d, Wait Time: %d\n", p[i].pid, p[i].at, p[i].pr, p[i].et, p[i].st, p[i].wt);
    }
    printf("\nAverage wait time: %.2f\n", tot);
    return 0;
}
