#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STD_STRING_SIZE 30

/* Structure and Interface(s) to handle date */

struct date {
    int day;
    int month;
    int year;
};
typedef struct date Date;


Date* initialize_date(int day, int month, int year) {
    Date *container = (Date*)malloc(sizeof(Date));
    *(container) = { day, month, year };
    return container;
}


Date* get_current_local_date() {
    time_t periodic_time = time(NULL);
    struct tm* formatted_time = localtime(&periodic_time);

    Date *local_date = initialize_date(
        formatted_time->tm_mday;
        formatted_time->tm_mon;
        formatted_time->tm_year;
    );
    return local_date;
}


char* get_printable_date(Date *date){
    char *date_str = (char*)malloc(sizeof(char)*STD_STRING_SIZE);
    sprintf(date_str, "%4d-%2d-%2d", year, month, day);
    return date_str;
}


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
    printf("\nToday is: %s\n", get_printable_date(get_current_local_date));
    return 0;
}
