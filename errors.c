void null_file(char *str)
{
    fprintf(stderr, "Error: Can't open file %s\n", str);
    exit(EXIT_FAILURE);
}

void count_error(void)
{
    fprintf(stderr, "USAGE: monty file\n");
    exit(EXIT_FAILURE);
}

void null_command(char *command, int count)
{
    fprintf(stderr, "L %d: unknown instruction %s\n", count, command);
    exit(EXIT_FAILURE);
}