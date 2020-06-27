class Barrier {
    private:
        Lock lock;
        CV allCheckedIn;

        int numEntered;
        int numThreads;
    public:
        Barrier(int n);
        ~Barrier();
        void checkin();

};

Barrier::Barrier(int n) {
    numEntered = 0;
    numThreads = n;
}

void
checkin() {
    lock.acquire();

    if (numThreads < numThreads) {
        while (numThreads < numThreads) {
            allCheckedIn.wait(&lock);
        } else {
            allCheckedIn.broadcast();
        }    
    }

    lock.release();
}
