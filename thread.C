void
thread_create(thread_t *thread, void(*func)(int), int arg) {
    // Allocate TCB and stack
    TCB *tcb = new TCB();
    thread->tcb = tcb;
    tcb->stack_size = INITIAL_STACK_SIZE;
    tcb->stack = new Stack(INITIAL_STACK_SIZE);

    tcb->sp = tcb->stack + INITIAL_STACK_SIZE;
    tcb->pc = stub;

    *(tcb->sp) = arg;
    tcb->sp--;
    *(tcb->sp) = func;
    tcb->sp--;

    thread_dummySwitchFrame(tcb);

    tcb->state = READY;
    readyList.add(tcb);

    void
    stub(void (*func)(int), int arg) {
        (*func)(arg);
        thread_exit(0);
    }
}