Client:
    char request[RequestSize];
    char reply[ReplySize];

    // ..compute..
    // Put the request into the buffer.
    // Send the buffer to the server.
    write(output, request, RequestSize);

    // Wait for response
    read(input, reply, ReplySize);
Server:
    char request[RequestSize];
    char reply[ReplySize];

    while (1) {
        read(input, request, RequestSize);

        // Do operation.

        write(output, reply, ReplySize);
    } 

// Server for multiclients

Server:
    char request[RequestSize];
    char reply[ReplySize];
    FileDescriptor clientInput[NumClients];
    FileDescriptor clientOuput[NumClients];

    while (fd = select(clientInput, NumClients) {
        read(clientInput[id], request, RequestSize);

        // Do operation.
       write(clientOutput[fd], reply, ReplySize);
    }