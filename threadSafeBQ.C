// Thread-safe queue interface
const int MAX = 10;

class TSQueue {
    // Sync variale
    Lock lock;

    // State variables
    int items[MAX];
    int front;
    int nextEmpty;

    public:
        TSQueue();
        -TSQueue(){};
        bool tryInsert(int item);
        bool tryRemove(int *item);
};

TSQueue::TSQueue() {
    front = nextEmpty = 0;
}

bool
TSQueue::tryInsert(int item) {
    bool success = false;

    lock.acquire();
    if ((nextEmpty - front) < MAX) {
        items[nextEmpty % MAX] = item;
        nextEmpty++;
        success = true;
    }
    lock.release();
    return success;
}

bool
TSQueue::tryRemove(int *item) {
    bool success = false;

    lock.acquire();
    if (front < nextEmpty) {
        *item = items[front % MAX];
        front++;
        success = true;
    }

    lock.release();
    return success;
}