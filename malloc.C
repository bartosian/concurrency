char *malloc (int n) {
    char *p;

    heaplock.acquire();
    // Code for a single threaded malloc()
    // p = allocate block of memory of size n

    heaplock.release();
    return p;
}

void free (char *p) {
    heaplock.acquire();
    // code for single threaded free()
    heaplock.release();
}    