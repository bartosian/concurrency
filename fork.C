int child_pid = fork();

if (child_pid == 0) {
    printf("I am process #%d\n", getpid());
    return 0;
} else {
    printf("I am the patrent of process #%d\n", child_pid);
    return 0;
}