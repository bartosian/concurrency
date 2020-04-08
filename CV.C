SharedObject::someMethodThatWaits() {
    lock.acquire();

    while (!testOnSharedState()) {
        cv.wait(&lock);
    }

    assert(testOnSharedState());

    lock.release();
}

SharedObject::someMethodThatSignals() {
    lock.acquire();
    cv.signal();

    lock.release();
}