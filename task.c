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
    char *write_mode = (append_tasks ? "a" : "w");
    FILE *f_out = fopen(filepath, write_mode);
    if(f_out==NULL){
        return -1;
    }
    // write to file, handle errors
    char *task_line;

    for(int i=0; i<num_tasks; i++)  {
        task_line = get_printable_task(*(tasks+i));
        fprintf(f_out, task_line); 
        // printf("\nAdded task: %s", task_line);
    }
    // close file
    fclose(f_out);
    return 0;
}


Task* _read_single_task_from_filestream(FILE *f_in)    {
    Task t;
    // printf("--->%ld<---\n\n", ftell(f_in));
    // char *task_line = (char*)malloc(sizeof(char)*STD_STRING_SIZE);
    char priority_str[20];
    size_t read_size = fscanf(f_in, "[ ] %[^|\n]|%s\n", t.text, priority_str);
    if(read_size==-1){
        return NULL;
    }
    // Encapsulate task_line to a structure
    return initialize_task(strdup(t.text), strtol(priority_str, NULL, 10));
}


Task** read_all_tasks_from_file(const char *filepath, int *num_tasks) {
    Task **tasks = (Task**)malloc(sizeof(Task*)*STD_TASKS_COUNT);
    // open file, handle errors
    FILE *f_in = fopen(filepath, "r");
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
    sprintf(task_str, "[ ] %s \t | %d\n", task->text, task->priority);
    return task_str;
}

char* get_printable_complete_task(Task *task)  {
    char *task_str = (char*)malloc(sizeof(char)*STD_STRING_SIZE);
    sprintf(task_str, "[X] %s \t | %d\n", task->text, task->priority);
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
    Task *new_task = initialize_task(task_text, task_priority);

    // append the new task on a new line to the `task.txt` using - write_tasks_to_file()
    // handle errors if it couldn't be written

    printf("\n\nAdded task:\n");
    // display the task using - get_printable_task()

    return;
}

int compare_Task(const void *a, const void *b)
{
    Task *task_a = *(Task**)a;
    Task *task_b = *(Task**)b;

    return task_a->priority - task_b->priority;
}

void task_ls()
{
    int num_tasks;

    // Use read_all_tasks_from_file() to read the list of tasks from the file

    Task **task_list = read_all_tasks_from_file("task.txt", &num_tasks);
    if(task_list==NULL)
    {
        printf("\n\nNo tasks to do.");
        return;
    }
    
    // use qsort() function to sort the tasks in the list

    printf("\n\nList of incomplete tasks:\n");
    
    // display all contents by iterating using get_printable_task() 
    for(int i=0; i<num_tasks; i++)
    {   
        printf("%d.\t", i+1);
        // place the print statement year
    }
    return;
}

void task_del(int task_index)
{
    int num_tasks;
    // read all tasks using read_all_tasks_from_file()
    Task **task_list = NULL;
    if(task_list==NULL)
    {
        printf("\n\nNo tasks to do.");
        return;
    }
    
    // use qsort() function to sort the tasks in the list

    for (int i = task_index - 1; i < (num_tasks-1); i++)  
    {  
        task_list[i] = task_list[i+1]; // assign arr[i+1] to arr[i]
    } 


    // Display all tasks after deletion, by iterating
    // NOTE: 1 less task


    // write_tasks_to_file() to write entire task_list. 
    return;
}

void task_done(int task_index)
{
    int num_tasks;

    // - read all tasks using read_all_tasks_from_file()
    // - sort the lists
    // - display status of the tasks after marking complete

    Task **task_list = NULL;

    if(task_list==NULL)
    {
        printf("\n\nNo tasks to do.");
        return;
    }

    // CODE-HERE

    Task* completed_task = task_list[task_index-1];

    printf("\n\nAfter complete:\n");
    // CODE-HERE

    for (int i = task_index - 1; i < (num_tasks-1); i++)  
    {  
        task_list[i] = task_list[i+1]; // assign arr[i+1] to arr[i]
        // printf("%s %s", (task_list[i])->text, (task_list[i])->text);
    }

    // write 'completed' task to done.txt (append)
    // write entire task list to task.txt (overwrite)

    return;
}

void task_report()
{
    int num_tasks;

    // read all tasks in task.txt using read_all_tasks_from_file() into task_list
    Task **task_list = NULL;

    if(task_list==NULL)
    {
        printf("\n\nNo tasks to do.");
        return;
    }
    
    // sort the task list

    printf("\n\nPending: %d\n", num_tasks);
    for(int i=0; i<num_tasks; i++)
    {   
        printf("%d.\t", i+1);
        printf(get_printable_task(*(task_list+i)));
    }

    int num_tasks_completed = 0;
     // read all tasks in done.txt using read_all_tasks_from_file() into task_list
    Task **task_list_completed = NULL;
    if(task_list_completed==NULL)
    {
        printf("\n\nNo tasks done.");
        return;
    }

    printf("\n\nCompleted: %d\n", num_tasks_completed);
    // display all tasks from the completed list -- iterate, and use get_printable_complete_task

    return;
}

void task_menu(int argc, char* argv[])
{
    char todo_text[STD_STRING_SIZE] = "";

    // check_arguments(argc, argv);
    // printf("-->%s", argv[1]);

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

    else if(strcmp(argv[1], "add") == 0)
    {
        if(argc >= 4)
        {
            for(int i=2; i<(argc-1); i++)
            {
                strcat(todo_text, argv[i]);
                if(i != argc - 1)
                    strcat(todo_text, " ");
            }

            task_add(strtol(argv[argc-1], NULL, 10), todo_text);
        }
        else
        {
            printf("\n\nERROR: Missing tasks string. Nothing added.");
        }
    }

    else if(strcmp(argv[1], "ls") == 0)
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

    else if(strcmp(argv[1], "del") == 0)
    {
        if(argc == 3)
        {
            int task_index = strtol(argv[argc-1], NULL, 10); // return -1 if index not found and handle error
            task_del(task_index); 
        }
        else
        {
            printf("\n\nERROR: Missing NUMBER for deleting tasks.");
        }
    }

    else if(strcmp(argv[1], "done") == 0)
    {
        if(argc == 3)
        {
            int task_index = strtol(argv[argc-1], NULL, 10); // return -1 if index not found and handle error
            task_done(task_index); 
        }
        else
        {
            printf("\n\nERROR: Missing NUMBER for marking tasks as done.");
        }
    }

    else if(strcmp(argv[1], "report") == 0)
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
}

int main(int argc, char* argv[])
{    
    printf("\n");
    printf("------------------------------------");
    printf("\n\tTODO CLI Application\n");
    printf("------------------------------------");

    // Menu
    task_menu(argc, argv);
    printf("\n\n");
    return 0;
}
