#include <stdio.h>

#define MAX_PARTITIONS 6
#define MAX_PROCESSES 5

void worstFit(int partitions[], int m, int processes[], int n) {
    int allocation[MAX_PROCESSES];
  
    for (int i = 0; i < n; i++) {
        int worstIdx = -1;
        for (int j = 0; j < m; j++) {
            if (partitions[j] >= processes[i]) {
                if (worstIdx == -1 || partitions[j] > partitions[worstIdx]) {
                    worstIdx = j;
                }
            }
        }

        if (worstIdx != -1) {
            allocation[i] = worstIdx;
            partitions[worstIdx] -= processes[i];
        } else {
            allocation[i] = -1; // Unable to allocate
        }
    }

    printf("\nProcess No.\tProcess Size\tPartition Index\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d KB\t\t", i + 1, processes[i]);
        if (allocation[i] != -1) {
            printf("%d\n", allocation[i] + 1);
        } else {
            printf("Not Allocated\n");
        }
    }
}

int main() {
    int partitions[MAX_PARTITIONS] = {300, 600, 350, 200, 750, 125};
    int processes[MAX_PROCESSES] = {115, 500, 358, 200, 375};

    printf("Memory Partitions: ");
    for (int i = 0; i < MAX_PARTITIONS; i++) {
        printf("%d KB ", partitions[i]);
    }
    printf("\n\n");

    printf("Processes: ");
    for (int i = 0; i < MAX_PROCESSES; i++) {
        printf("%d KB ", processes[i]);
    }
    printf("\n");

    worstFit(partitions, MAX_PARTITIONS, processes, MAX_PROCESSES);

    return 0;
}

