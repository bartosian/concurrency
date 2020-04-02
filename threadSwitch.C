void thread_switch(oldThreadTCB, newThreadTCB) {
    pushad;
    oldThreadTCB->sp = %esp;
    %esp = newThreadTCB->sp;
    popad;
    return;
}

void thread_yield() {
    TCB *chosenTCB, *finishedTCB;

    disableInterrupts();

    chosenTCB = readyList.getNextThread();
    if (chosenTCB == NULL) {

    } else {
        runningThread->state = ready;
        readyList.add(runningThread);
        thread_switch(runningThread, chosenTCB);
        runningThread->state = running;
    }

    while ((finishedTCB = finishedList->getNextThread()) != NULL) {
        delete finishedTCB->stack;
        delete finishedTCB;
    }

    enableInterrupts();
}

