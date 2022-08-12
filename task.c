#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

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
    container->day = day;
    container->month = month;
    container->year = year;
    return container;
}


Date* get_current_local_date() {
    time_t periodic_time = time(NULL);
    struct tm* formatted_time = localtime(&periodic_time);

    Date *local_date = initialize_date(
        formatted_time->tm_mday,
        // the time structure stores months from the range 0-11
        1 + formatted_time->tm_mon,
        // the time structure stores years since 1900!
        1900 + formatted_time->tm_year 
    );
    return local_date;
}


char* get_printable_date(const Date *date)    {
    char *date_str = (char*)malloc(sizeof(char)*STD_STRING_SIZE);
    sprintf(date_str, "%4d-%02d-%02d", date->year, date->month, date->day);
    return date_str;
}

/* ---------- */

/* Structure and Interface(s) to handle task(s) */

struct task {
    char *task_text;
    int priority;
};
typedef struct task Task;


Task* initialize_task(const char *text, int priority) {
    Task *container = (Task*)malloc(sizeof(Task));
    container->task_text = (char*)malloc(sizeof(char)*STD_STRING_SIZE);
    strcpy(container->task_text, text);
    container->priority = priority;
    return container;
} 

short write_tasks_to_file(const Task **tasks, int num_tasks, const char *filepath, short append_tasks) {
    // open file, handle errors
    char *write_mode = (append_tasks ? "ab" : "wb");
    FILE *f_out = fopen(filepath, write_mode);
    if(f_out==NULL){
        return -1;
    }
    // write to file, handle errors
    // int write_size = 0;
    int write_size = fwrite(*tasks, sizeof(Task), num_tasks, f_out);
    if(write_size!=(num_tasks*sizeof(Task))){
        return -1;
    }
    // close file
    fclose(f_out);
    return 0;
}

short read_tasks_from_file(const Task **tasks, int num_tasks, const char *filepath) {
    // open file, handle errors
    FILE *f_out = fopen(filepath, "rb");
    if(f_out==NULL){
        return -1;
    }
    // write to file, handle errors
    // int write_size = 0;
    int write_size = fwrite(*tasks, sizeof(Task), num_tasks, f_out);
    if(write_size!=(num_tasks*sizeof(Task))){
        return -1;
    }
    // close file
    fclose(f_out);
    return 0;
}


struct completed_task  {
    Task task;
    Date date_of_completion;
};
typedef struct completed_task CompletedTask;


int main(int argc, char* argv[])
{
    printf("Hello, World!");
    printf("\nToday is: %s\n", get_printable_date(get_current_local_date()));

    Task *test_task = initialize_task("Water the plants", 2);
    if(!write_tasks_to_file(&test_task, 1, "testfile.dat", 0)){
        printf("Couldn't write tasks to file");
    };

    return 0;
}
