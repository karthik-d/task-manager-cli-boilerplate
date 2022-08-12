#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define STD_STRING_SIZE 30
#define STD_TASKS_COUNT 100


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
    int priority;
    char text[STD_STRING_SIZE];   
    // [Q]: Can you use a char* for text ?
};
typedef struct task Task;


// Declarations
Task* initialize_task(const char*, int);
short write_tasks_to_file(const Task**, int, const char*, short);
char* get_printable_task(Task*);
Task* _read_single_task_from_filestream(FILE*);
Task** read_all_tasks_from_file(const char*);


Task* initialize_task(const char *text, int priority) {
    Task *container = (Task*)malloc(sizeof(Task));
    strcpy(container->text, text);
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
    size_t write_size = fwrite(*tasks, sizeof(Task), num_tasks, f_out);
    if(write_size!=(num_tasks*sizeof(Task))){
        return -1;
    }
    // close file
    fclose(f_out);
    return 0;
}


Task* _read_single_task_from_filestream(FILE *f_in)    {
    Task t;
    size_t read_size = fread(&t, sizeof(Task), 1, f_in);
    if(read_size==0){
        return NULL;
    }
    return initialize_task(strdup(t.text), t.priority);
}


Task** read_all_tasks_from_file(const char *filepath) {
    Task **tasks = (Task**)malloc(sizeof(Task*)*STD_TASKS_COUNT);
    // open file, handle errors
    FILE *f_in = fopen(filepath, "rb");
    if(f_in==NULL){
        return NULL;
    }
    // read file, handle errors
    int num_tasks = 0;
    Task *t = _read_single_task_from_filestream(f_in);    
    while(t!=NULL){
        *(tasks + num_tasks) = t;
        num_tasks++;
        t = _read_single_task_from_filestream(f_in);
    }
    // close file
    fclose(f_in);
    return tasks;
}


char* get_printable_task(Task *task)  {
    char *task_str = (char*)malloc(sizeof(char)*STD_STRING_SIZE);
    sprintf(task_str, "[ ] %s \t | %d", task->text, task->priority);
    return task_str;
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
    Task **task_list = read_all_tasks_from_file("testfile.dat");
    printf(get_printable_task(*task_list));
    return 0;
}
