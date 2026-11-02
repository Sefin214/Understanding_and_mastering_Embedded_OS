
#include <stdio.h>

typedef enum {
    NEW,
    READY,
    RUNNING,
    TERMINATED
} ProcessState;

typedef struct {
    int process_id;
    ProcessState state;
} ProcessControlBlock;

// Function to transition states
void transition_state(ProcessControlBlock *pcb,
                      ProcessState next_state)
{
    printf("Process ID [%d]: Transitioning from state enum (%d) to (%d).\n",
           pcb->process_id, pcb->state, next_state);

    // Update PCB state using the passed pointer
    pcb->state = next_state;
}

int main(void)
{
    // Create a new process
    ProcessControlBlock pcb1 = {
        .process_id = 101,
        .state = NEW
    };

    // Move from NEW to READY
    transition_state(&pcb1, READY);

    // Move from READY to RUNNING
    transition_state(&pcb1, RUNNING);

    return 0;
}

