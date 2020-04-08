// Event-driven
Hashtable<Buffer*> *hash;

while(1) {
    connection = select() // to find a readable connection ID
    buffer = hash.remove(connection);
    got = read(connection, tmpBuf, TMP_SIZE);
    buffer->append(tmpBuf, got);
    buffer = hash.put(connection, buffer);
}

// Thread-per-client
Buffer *b;

while(1) {
    got = read(connection, tmpBuf, TMP_SIZE);
    buffer->append(tmpBuf, got); 
}