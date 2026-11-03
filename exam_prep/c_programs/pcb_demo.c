
#include <stdio.h>

// 1. Define process states
typedef enum {
    NEW,
    READY,
    RUNNING,
    TERMINATED
} ProcessState;

// 2. Define Process Control Block
typedef struct {
    int process_id;
    ProcessState state;
} ProcessControlBlock;

// 3. Function to update process state
void transition_state(ProcessControlBlock *pcb, ProcessState next_state)
{
    printf("Process ID [%d]: Transitioning from state enum (%d) to (%d).\n",
           pcb->process_id, pcb->state, next_state);

    // Update the state
    pcb->state = next_state;
}

int main()
{
    // Create a process
    ProcessControlBlock pcb1 = { .process_id = 101, .state = NEW };

    // NEW to READY
    transition_state(&pcb1, READY);

    // READY to RUNNING
    transition_state(&pcb1, RUNNING);

    return 0;
}

