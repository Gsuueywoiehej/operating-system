#include <stdio.h>

#define MAX_PROCESSES 3

struct Process {
    int burstTime;
    int priority;
};

void calculateWaitingTime(struct Process processes[], int n, int waitingTime[]) {
    int i;
	int currentTime = 0;
    int remainingBurstTime[MAX_PROCESSES];
    int completed = 0;


    for (i = 0; i < n; i++) {
        remainingBurstTime[i] = processes[i].burstTime;
    }

    while (completed != n) {
        int highestPriority = -1;
        int selectedProcess = -1;

        
        for (i = 0; i < n; i++) {
            if (remainingBurstTime[i] > 0 && processes[i].priority > highestPriority) {
                highestPriority = processes[i].priority;
                selectedProcess = i;
            }
        }

        if (selectedProcess == -1) {
            currentTime++;
            continue;
        }

       
        waitingTime[selectedProcess] = currentTime;

        
        remainingBurstTime[selectedProcess]--;

        
        if (remainingBurstTime[selectedProcess] == 0) {
            completed++;
        }

        currentTime++;
    }
}

void calculateTurnaroundTime(struct Process processes[], int n, int waitingTime[], int turnaroundTime[]) {
    int i;
	for (i = 0; i < n; i++) {
        turnaroundTime[i] = processes[i].burstTime + waitingTime[i];
    }
}

void calculateAverageTimes(struct Process processes[], int n) {
    int waitingTime[MAX_PROCESSES] = {0};
    int turnaroundTime[MAX_PROCESSES] = {0};

    calculateWaitingTime(processes, n, waitingTime);
    calculateTurnaroundTime(processes, n, waitingTime, turnaroundTime);

    int totalWaitingTime = 0;
    int totalTurnaroundTime = 0;
    int i;

    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (i = 0; i < n; i++) {
        totalWaitingTime += waitingTime[i];
        totalTurnaroundTime += turnaroundTime[i];

        printf("%d\t%d\t\t%d\t\t%d\n", i + 1, processes[i].burstTime, waitingTime[i], turnaroundTime[i]);
    }

    double averageWaitingTime = (double) totalWaitingTime / n;
    double averageTurnaroundTime = (double) totalTurnaroundTime / n;

    printf("\nAverage Waiting Time: %.2f\n", averageWaitingTime);
    printf("Average Turnaround Time: %.2f\n", averageTurnaroundTime);
}

int main() {
    struct Process processes[MAX_PROCESSES] = {
        {30, 2},
        {5, 1},
        {12, 3},

    };

    int n = sizeof(processes) / sizeof(processes[0]);

    calculateAverageTimes(processes, n);

    return 0;
}
