#include "../lib/SRTNP.h"

static queue_object* SRTNP_queue;
//You can add more global variables here

process* SRTNP_tick (process* running_process){
/**
 * determine which is the current process to be processed. 
 * @param running_process the prevously running process
 * @result a pointer to the new running process (if something changed) or to the previously running process
 */ 
    return NULL;
}

int SRTNP_startup(){
/**
 * Do everything you have to at startup in this function. It is called once.
 * @result 0 if everything was fine. Any other number if there was an error.
 */
    return 1;
}

process* SRTNP_new_arrival(process* arriving_process, process* running_process){
/**
 * Handle new arrivals
 * @param arriving_process A pointer to a new arriving process
 * @param running_process A pointer to previously running process
 * @result A pointer to the new active (running) process (if that changed) or to the previously running process
 */ 
    return NULL;
}

void SRTNP_finish(){
/**
 * is called once after the all processes were handled. In case you want to cleanup something
 */
}




//BEISPIEL

int main()
{
    int A[100][4]; // Matrix for storing Process Id, Burst
                   // Time, Average Waiting Time & Average
                   // Turn Around Time.
    int i, j, n, total = 0, index, temp;
    float avg_wt, avg_tat;
    printf("Enter number of process: ");
    scanf("%d", &n);
    printf("Enter Burst Time:\n");
    // User Input Burst Time and alloting Process Id.
    for (i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d", &A[i][1]);
        A[i][0] = i + 1;
    }
    // Sorting process according to their Burst Time.
    for (i = 0; i < n; i++) {
        index = i;
        for (j = i + 1; j < n; j++)
            if (A[j][1] < A[index][1])
                index = j;
        temp = A[i][1];
        A[i][1] = A[index][1];
        A[index][1] = temp;
 
        temp = A[i][0];
        A[i][0] = A[index][0];
        A[index][0] = temp;
    }
    A[0][2] = 0;
    // Calculation of Waiting Times
    for (i = 1; i < n; i++) {
        A[i][2] = 0;
        for (j = 0; j < i; j++)
            A[i][2] += A[j][1];
        total += A[i][2];
    }
    avg_wt = (float)total / n;
    total = 0;
    printf("P     BT     WT     TAT\n");
    // Calculation of Turn Around Time and printing the
    // data.
    for (i = 0; i < n; i++) {
        A[i][3] = A[i][1] + A[i][2];
        total += A[i][3];
        printf("P%d     %d     %d      %d\n", A[i][0],
               A[i][1], A[i][2], A[i][3]);
    }
    avg_tat = (float)total / n;
    printf("Average Waiting Time= %f", avg_wt);
    printf("\nAverage Turnaround Time= %f", avg_tat);
}