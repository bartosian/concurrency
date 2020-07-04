  
“ConditionQueue insertQueue;
 ConditionQueue removeQueue;
 int numRemoveCalled = 0; // # of times remove has been called
 int numInsertCalled = 0; // # of times insert has been called
 
 int
 FIFOBBQ::remove() {
     int item;
     int myPosition;
     CV *myCV, *nextWaiter;
 
     lock.acquire();
 
     myPosition = numRemoveCalled++;
     mycv = new CV;  // Create a new condition variable to wait on.
     removeQueue.append(myCV);
 
 // Even if I am woken up, wait until it is my turn.
     while (front < myPosition || front == nextEmpty) {
         mycv->Wait(&lock);
     }
 
     delete self;    // The condition variable is no longer needed.
     item = items[front % size];
     front++;
 
 // Wake up the next thread waiting in insert, if any.
     nextWaiter = insertQueue.removeFromFront();
     if (nextWaiter != NULL)
         nextWaiter->Signal(&lock);
     lock.release();
     return item;
 }”
