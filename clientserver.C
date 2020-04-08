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