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
    // [Q]: Can you use a char* for text int the structure ?
};
typedef struct task Task;


// Declarations
Task* initialize_task(const char*, int);
short write_tasks_to_file(Task**, int, const char*, short);
char* get_printable_task(Task*);
Task* _read_single_task_from_filestream(FILE*);
Task** read_all_tasks_from_file(const char*, int*);


Task* initialize_task(const char *text, int priority) {
    Task *container = (Task*)malloc(sizeof(Task));
    strcpy(container->text, text);
    container->priority = priority;
    return container;
} 

short write_tasks_to_file(Task **tasks, int num_tasks, const char *filepath, short append_tasks) {
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
    // printf("--->%ld<---\n\n", ftell(f_in));
    size_t read_size = fread(&t, sizeof(Task), 1, f_in);
    if(read_size==0){
        return NULL;
    }
    return initialize_task(strdup(t.text), t.priority);
}


Task** read_all_tasks_from_file(const char *filepath, int *num_tasks) {
    Task **tasks = (Task**)malloc(sizeof(Task*)*STD_TASKS_COUNT);
    // open file, handle errors
    FILE *f_in = fopen(filepath, "rb");
    if(f_in==NULL){
        return NULL;
    }
    // read file, handle errors
    *num_tasks = 0;
    Task *t = _read_single_task_from_filestream(f_in);    
    while(t!=NULL){
        *(tasks + *num_tasks) = t;
        (*num_tasks)++;
        t = _read_single_task_from_filestream(f_in);
    }
    // close file
    fclose(f_in);
    if(*num_tasks==0){
        return NULL;
    }
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

void check_arguments(int argc, char* argv[])
{
    char print_text[STD_STRING_SIZE] = "";
    printf("\n\nArguments");
    for(int i=1; i<argc; i++)
    {
        strcat(print_text, argv[i]);
    }
    printf("\n\nargc: %d, argv[1:]:%s\n\n", argc, print_text);
}

void task_help()
{
    printf("\n\nUsage :-\n$ ./task add 2 walk cat # Add a new item with priority 2 and text 'walk cat' to the list\n$ ./task ls # Show incomplete priority list items sorted by priority in ascending order\n$ ./task del INDEX # Delete the incomplete item with the given index\n$ ./task done INDEX # Mark the incomplete item with the given index as complete\n$ ./task help # Show usage\n$ ./task report # Statistics\n\n");
}

void task_add(int task_priority, char* task_text)
{
    return;
}

void task_ls()
{
    return;
}

void task_del(int task_index)
{
    return;
}

void task_done(int task_index)
{
    return;
}

void task_report()
{
    return;
}

int main(int argc, char* argv[])
{
    // Change to todo Manager Header
    printf("\n\nHello, World!");
    printf("\nToday is: %s\n\n\n", get_printable_date(get_current_local_date()));

    // Task *test_task = initialize_task("Water the plants", 2);
    // if(!write_tasks_to_file(&test_task, 1, "testfile.dat", 0)){
    //     printf("Couldn't write tasks to file");
    // };

    int num_tasks;
    Task **task_list = read_all_tasks_from_file("testfile.dat", &num_tasks);
    if(task_list==NULL) {
        printf("\nNo tasks to read");
    }
    else{
        printf(get_printable_task(*task_list));
    }
    printf("\n");

    // Menu

    char todo_text[STD_STRING_SIZE] = "";

    check_arguments(argc, argv);

    if(argc == 1)
    {
        task_help();
    }

    else if(strcmp(argv[1], "help") == 0)
    {
        if(argc == 2)
        {
            task_help();
        }
        else
        {
            printf("\n\nERROR: Too Many Arguments for help! Please use './task help' for Usage Information.");
        }
    }

    else if(strcmp(argv[1], "add "))
    {
        if(argc == 4)
        {
            for(int i=3; i<argc; i++)
            {
                strcat(todo_text, argv[i]);
            }
            task_add(strtol(argv[2], NULL, 10), todo_text);
        }
        else
        {
            printf("\n\nERROR: Missing tasks string. Nothing added.");
        }
    }

    else if(strcmp(argv[1], "ls "))
    {
        if(argc == 2)
        {
            task_ls();
        }
        else
        {
            printf("\n\nERROR: Too Many Arguments for ls! Please use './task help' for Usage Information.");
        }
    }

    else if(strcmp(argv[1], "del "))
    {
        if(argc == 3)
        {
            int task_index = -1;
            task_del(task_index); // return -1 if index not found and handle error
        }
        else
        {
            printf("\n\nERROR: Missing NUMBER for deleting tasks.");
        }
    }

    else if(strcmp(argv[1], "done "))
    {
        if(argc == 3)
        {
            int task_index = -1;
            task_done(task_index); // return -1 if index not found and handle error
        }
        else
        {
            printf("\n\nERROR: Missing NUMBER for marking tasks as done.");
        }
    }

    else if(strcmp(argv[1], "report "))
    {
        if(argc == 2)
        {
            task_report();
        }
        else
        {
            printf("\n\nERROR: Too Many Arguments for report! Please use './task help' for Usage Information.");
        }
    }

    printf("\n\n");
    return 0;
}
