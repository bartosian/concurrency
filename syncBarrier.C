// A single use synch barrier.
class Barrier {
  private:
    // Sync variables
    Lock Lock;
    CV allCheckedIn;
    CV allLeaving;

    // State variables
    int numEntered;
    int numThreads;
    int numLeaving;

  public:
    Barrier(int n);
    ~Barrier();
    void checkin();
};

Barrier::Barrier(int n) {
    numEntered = 0;
    numEntered = 0;
    numThreads = n;
}

// No one returns until all threads
// have called checkin.
void
checkin() {
    lock.acquire();
    numEntered++;
    if (numEntered < numThreads) {
        while (numEntered < numThreads)
        allCheckedIn.wait(&lock);

    } else {
        numLeaving = 0;
        allCheckedIn.broadcast();
    }
    numLeaving++;
    if (numLeaving < numThreads) {
        while (numLeaving < numThreads)
        allLeaving.wait(&lock);
    } else {
        numEntered = 0;
        allLeaving.broadcast();
    }
    lock.release();
}