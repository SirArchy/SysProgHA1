#include "../lib/HRRN.h"

static queue_object* HRRN_queue;
//You can add more global variables and structs here

process* HRRN_tick (process* running_process){
/**
 * determine which is the current process to be processed. 
 * @param running_process the prevously running process
 * @result a pointer to the new running process (if something changed) or to the previously running process
 */ 
    return NULL;
}

int HRRN_startup(){
/**
 * Do everything you have to at startup in this function. It is called once.
 * @result 0 if everything was fine. Any other number if there was an error.
 */
    return 1;
}

process* HRRN_new_arrival(process* arriving_process, process* running_process){
/**
 * Handle new arrivals
 * @param arriving_process A pointer to a new arriving process
 * @param running_process A pointer to previously running process
 * @result A pointer to the new active (running) process (if that changed) or to the previously running process
 */ 
    return NULL;
}

void HRRN_finish(){
/**
 * is called once after the all processes were handled. In case you want to cleanup something
 */
}




//BEISPIEL
struct process {
    char name;
    int at, bt, ct, wt, tt;
    int completed;
    float ntt;
} p[10];
 
int n;
 
// Sorting Processes by Arrival Time
void sortByArrival()
{
    struct process temp;
    int i, j;
 
    // Selection Sort applied
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
 
            // Check for lesser arrival time
            if (p[i].at > p[j].at) {
 
                // Swap earlier process to front
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}
 
void main()
{
    int i, j, t, sum_bt = 0;
    char c;
    float avgwt = 0, avgtt = 0;
    n = 5;
 
    // predefined arrival times
    int arriv[] = { 0, 2, 4, 6, 8 };
 
    // predefined burst times
    int burst[] = { 3, 6, 4, 5, 2 };
 
    // Initializing the structure variables
    for (i = 0, c = 'A'; i < n; i++, c++) {
        p[i].name = c;
        p[i].at = arriv[i];
        p[i].bt = burst[i];
 
        // Variable for Completion status
        // Pending = 0
        // Completed = 1
        p[i].completed = 0;
 
        // Variable for sum of all Burst Times
        sum_bt += p[i].bt;
    }
 
    // Sorting the structure by arrival times
    sortByArrival();
    printf("\nName\tArrival Time\tBurst Time\tWaiting Time");
    printf("\tTurnAround Time\t Normalized TT");
    for (t = p[0].at; t < sum_bt;) {
 
        // Set lower limit to response ratio
        float hrr = -9999;
 
        // Response Ratio Variable
        float temp;
 
        // Variable to store next process selected
        int loc;
        for (i = 0; i < n; i++) {
 
            // Checking if process has arrived and is Incomplete
            if (p[i].at <= t && p[i].completed != 1) {
 
                // Calculating Response Ratio
                temp = (p[i].bt + (t - p[i].at)) / p[i].bt;
 
                // Checking for Highest Response Ratio
                if (hrr < temp) {
 
                    // Storing Response Ratio
                    hrr = temp;
 
                    // Storing Location
                    loc = i;
                }
            }
        }
 
        // Updating time value
        t += p[loc].bt;
 
        // Calculation of waiting time
        p[loc].wt = t - p[loc].at - p[loc].bt;
 
        // Calculation of Turn Around Time
        p[loc].tt = t - p[loc].at;
 
        // Sum Turn Around Time for average
        avgtt += p[loc].tt;
 
        // Calculation of Normalized Turn Around Time
        p[loc].ntt = ((float)p[loc].tt / p[loc].bt);
 
        // Updating Completion Status
        p[loc].completed = 1;
 
        // Sum Waiting Time for average
        avgwt += p[loc].wt;
        printf("\n%c\t\t%d\t\t", p[loc].name, p[loc].at);
        printf("%d\t\t%d\t\t", p[loc].bt, p[loc].wt);
        printf("%d\t\t%f", p[loc].tt, p[loc].ntt);
    }
    printf("\nAverage waiting time:%f\n", avgwt / n);
    printf("Average Turn Around time:%f\n", avgtt / n);
}