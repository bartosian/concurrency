class SpinLock {
    private:
        int value = 0;
    public:
        void acquire() {
            while (test_and_set(&value));
        }

        void release() {
            value = 0;
            memory_barrier();
        }    
}

class Lock {
    private:
        int value = FREE;
        SpinLock spinLock;
        Queue waiting;
    public:
        void acquire();
        void release();    
}

Lock::acquire() {
    spinLock.acquire();
    if (value != FREE) {
        waiting.add(runningThread);
        scheduler.suspend(&spinLock);
    } else {
        value = BUSY;
        spinLock.release();
    }
}

void Lock::release() {
    TCB *next;

    
}