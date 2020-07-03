  
main() {
    char *prog = NULL;
    char **args = NULL;

    while (readAndParseCmdLIne(&prog, &args)) {
        int child_pid = fork();

        if (child_pid == 0) {
            exec(prog, args);
        
         } esle {
             wait(child_pid);
             return 0;
         }
    }
}
