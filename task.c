#include <stdio.h>
#include <time.h>

#define STD_STRING_SIZE 30

/* Structure and Interface to handle date */

struct date {
    int day;
    int month;
    int year;
};
typedef struct date Date;





/* ---------- */


struct task {
    char *task_text;
    int priority;
};
typedef struct task Task;


struct completed_task  {
    Task task;
    Date date_of_completion;
};
typedef struct completed_task CompletedTask;


int main(int argc, char* argv[])
{
    printf("Hello, World!");
    return 0;
}
