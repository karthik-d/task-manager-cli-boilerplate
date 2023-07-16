# C Programming Course - Guided Project: Task Manager CLI Application

Through this guided project, we want to see how you implement a command-line (CLI) program that lets you manage your tasks.

> A complete project description can be found in [description.md](./description.md). The specification for this problem is laid out below, and automated test-cases have been written down to test the application at each developmental stage. Since we haven’t actually implemented anything yet, the tests are currently failing. You have to solve the problem by implementing the application and getting to get all the tests to pass. 

The code for this capstone project has been partially implemented with the necessary APIs to facilitate its completion. The partial implementation will provide functional APIs to perform specific operations. For instance, to complete the `./task add` command’s implementation, the relevant `task_add()` function is defined with an empty function definition. The logic for this function body should be implemented. Furthermore, function APIs are also available to perform elementary operations such as reading and writing lines from text files. These APIs must be used to complete the implementation. 

## Course Material

This guided project is part of the **Short-term Hands-on Supplementary Course in C Programming**, conducted by the [Computer Science & Engineering Department](https://www.ssn.edu.in/college-of-engineering/computer-science-and-engineering-department-ssn-institutions/) at [Sri Sivasubramaniya Nadar College of Engineering](https://www.ssn.edu.in/) through a practicum-driven lesson plan during May-July 2022.

[Link to the Course Page](https://github.com/nive927/Short-term-Hands-on-Supplementary-Course-on-C-Programming).

[Link to the Project Page](https://github.com/karthik-d/C-Programming-Course_Project-Starter).

## Team

| Nivedhitha D | Karthik Desingu | Dr. B. Prabavathy | Dr. T. T. Mirnalinee |
| :----------: | :-------: | :---------------: | :-----------------: |
|![display-error](./assets/ND-profile-pic.PNG)|![display-error](./assets/KD-profile-pic.PNG)|![display-error](./assets/PB-profile-pic.PNG)|![display-error](./assets/TTM-profile-pic.PNG)|
|<a href="https://www.linkedin.com/in/nivedhitha-d-0bb67b1b0/"><img src="https://img.shields.io/badge/-Nivedhitha%20D-0077B5?style=flat&logo=Linkedin&logoColor=white"/></a> <a href="https://github.com/nive927"><img src="https://img.shields.io/badge/-nive927-B10036?style=flat&logo=GitHub&logoColor=white"/></a>|<a href="https://www.linkedin.com/in/karthik-desingu/"><img src="https://img.shields.io/badge/-Karthik%20Desingu-0077B5?style=flat&logo=Linkedin&logoColor=white"/></a> <a href="https://github.com/karthik-d"><img src="https://img.shields.io/badge/-karthik--d-B10036?style=flat&logo=GitHub&logoColor=white"/></a>|<a href="https://www.ssn.edu.in/staff-members/dr-b-prabavathy/"><img src="https://img.shields.io/badge/-Dr%20B%20Prabavathy-323EA8?style=flat&logo=#&logoColor=white"/></a>|<a href="https://www.ssn.edu.in/staff-members/dr-t-t-mirnalinee//"><img src="https://img.shields.io/badge/-Dr%20T%20T%20Mirnalinee-323EA8?style=flat&logo=#&logoColor=white"/></a>|
|B.E. CSE (2018-2022)|B.E. CSE (2019-2023)|Associate Professor, CSE|Professor & Head, CSE|

## Getting started


### Getting the Boilerplate Code

- Access the repository from the [project starter page](https://github.com/karthik-d/task-manager-cli-boilerplate).

- Follow the [instructions here](https://docs.github.com/en/get-started/quickstart/fork-a-repo) to [`fork`](https://github.com/karthik-d/task-manager-cli-boilerplate/fork) the repository to your local desktop.


### Getting the Code to your Local System

On a command line terminal,

- ```
   git clone <YOUR-REPOSITORY-URL>
   ```

   The git clone command copies your repository from GitHub to your local computer. Note that this is a git specific command.

- ```cd C-Programming-Course_Project-Starter```

   Move into your repository's local copy.

- Edit your code files here.

- When you think you have made a good amount of progress, **add** your files, and **commit** your code. 
   ```
   git add .
   git commit -m <SHORT-MSG-INDICATING-WHAT-PROGRESS-YOU'VE-MADE>
   ```

- When you are done for the day, **push** your code to GitHub.
   ```
   git push origin
   ```

### Running the code

1. You should have a C compiler available for building the code.

2. You are expected to write the code in `task.c` file.

3. You should be able to build the app by running `make task`.

4. Once you are done with the changes you should be able to execute the task app by running the following command from the terminal.


   **On Windows:**

   ```
   .\task.exe
   ```

   **On \*nix:**

   ```
   ./task
   ```

## Your Goals

### 1. Get the Boilerplate Running

- Follow the instructions in the **Getting Started** section to get the boilerplate code, and get it running on your local systems.


### 2. Understand the **Usage** and **Specifications** sections

- The **usage** section details the end-user interface. Understand how the CLI tool will be used by a user who gets your software.

- The **specification** section details how you should actually implement each functionality, what happens in the background. This is your logic.

### 3. Familiarize yourself with the source code in `task.c`

- Take a look at all the helper functions, interfaces, and structures in the source file. *Simply try to understand what each function does: its input and output.* 

> Start from the `main()` function, and trace your way through the function calls.

### 4. Start Implementing one Use-Case at a time

- Start with the first use-case in the **usage** section.

- Find the relevant portion of the code (start looking from `main()`!) and write your code to make appropriate function calls and/or operations to implement it.

- **Compile and Run** frequently, to ensure that you are headed in the right direction.

- Got one case running? Great! - Let us know.

(**implement-execute-test** and repeat for the rest of the use-cases).

### **[Bonus]** 5. Add a Task *Completion Date*

- Include an additional `date_of_completion` field that records _when_ the task is marked as done.

> The functions to get the current date and time, in the required character-array format, are already provided as helpers!

### **[Bonus]** 6. Run the Automated Tests

- Follow the instructions in the **Run Automated Tests** section to run automated tests, that wil evaluate multiple edge-cases of your application.

- Again, **implement-execute-test** and repeat for each use case.


## Todo CLI Usage

### 1. Help

Executing the command without any arguments, or with a single argument help prints the CLI usage.

```
$ ./task help
Usage :-
$ ./task add 2 hello world    # Add a new item with priority 2 and text "hello world" to the list
$ ./task ls                   # Show incomplete priority list items sorted by priority in ascending order
$ ./task del INDEX            # Delete the incomplete item with the given index
$ ./task done INDEX           # Mark the incomplete item with the given index as complete
$ ./task help                 # Show usage
$ ./task report               # Statistics
```

### 2. List all pending items

Use the ls command to see all the items that are not yet complete, in ascending order of priority.

Every item should be printed on a new line. with the following format

```
[index] [task] [priority]
```

Example:

```
$ ./task ls
1. change light bulb [2]
2. water the plants [5]
```

index starts from 1, this is used to identify a particular task to complete or delete it.

### 3. Add a new item

Use the add command. The text of the task should be enclosed within double quotes (otherwise only the first word is considered as the item text, and the remaining words are treated as different arguments).

```
$ ./task add 5 "the thing i need to do"
Added task: "the thing i need to do" with priority 5
```

### 4. Delete an item

Use the del command to remove an item by its index.

```
$ ./task del 3
Deleted item with index 3
```

Attempting to delete a non-existent item should display an error message.

```
$ ./task del 5
Error: item with index 5 does not exist. Nothing deleted.
```

### 5. Mark a task as completed

Use the done command to mark an item as completed by its index.

```
$ ./task done 1
Marked item as done.
```

Attempting to mark a non-existed item as completed will display an error message.

```
$ ./task done 5
Error: no incomplete item with index 5 exists.
```

### 6. Generate a report

Show the number of complete and incomplete items in the list. and the complete and incomplete items grouped together.

```
$ ./task report
Pending : 2
1. this is a pending task [1]
2. this is a pending task with priority [4]

Completed : 3
1. completed task
2. another completed task
3. yet another completed task
```

## Todo CLI Specification

1. The app can be run in the console with `./task`.

2. The app should read from and write to a `task.txt` text file. Each task occupies a single line in this file. Each task should have an associated priority, an integer.

> Priority denotes how important a task is, if it is a high priority task, it should be completed earlier. Priority is denoted using an integer. The lower the number, the higher the priority.
   
Here is an example of a list of 2 tasks in the file.
   ```
   1 Buy milk
   2 Complete the project
   ```

3. A completed task is written to a `done.txt` text file. Each task should enapsulate all fields of the original task.

4. Priority can be any integer _greater than_ or _equal to_ 0. 0 being the highest priority

5. If two task have the same priority, the task that was added first should be displayed first.

   The application must open the files task.txt and done.txt from where the app is run, and not where the app is located. 

   ```
   $ cd /path/to/plans

   $ /path/to/apps/task ls
   ```

   The application should look for the task files in `/path/to/plans`, since that is the user’s current directory.

6. The files should always be sorted in order of the priority, i.e., the task with the highest priority should be first item in the file.
   
> Please note that the programming task can and preferably, should be completed without the use of any additional packages.



## [Optional] Run Automated Tests

>If you are able to set up npm by following the steps below, great! You can validate that your app works as expected.

>Otherwise, we'll do this for you, when we are evaluating the project. In addition to the test cases mentioned here, we'll add on a few more during the evaluation.

### 1. Install Node.js

You need to have `npm` installed in your computer for the following steps. It comes with Node.js and you can get it by installing Node from https://nodejs.org/en/

### 2. Install dependencies

Run `npm install` to install all dependencies.

### 3. Create a symbolic link to the executable file

#### On Windows

To create a symbolic link on Windows, you'll need to run either the Windows Command Prompt, or Windows Powershell **with administrator privileges**. To do so, right-click on the icon for Command Prompt, or Powershell, and choose the _"Run as Administrator"_ option.

**Command Prompt:**

```
> mklink task task.bat
```

**Powershell:**

```
> cmd /c mklink task task.bat
```

#### On \*nix:

Run the following command in your terminal:

```
$ ln -s task.sh task
```

### 4. Try running tests.

Now run `npm test` and you will see all the tests failing. As you fill in each functionality, you can re-run the tests to see them passing one by one.

## A Note about `/` for Windows Users

In the previous sections, you might witness many commands prefixed with `./`, or paths containing the `/` (forward-slash) character.

If you're using the Windows _Command Prompt_, then you'll need to replace `/` with `\` (back-slash) for these commands and paths to work as expected.

On Windows _Powershell_, these substitutions are not required.

## Expected Issues

A few notes to help you avoid any hiccups while implementing the programming challenge:

1. If you are on Windows, you might have difficulty getting the tests to pass because of newline UTF encoding issues. If you get stuck, please [refer to the thread here](https://github.com/nseadlc-2020/package-todo-cli-task/issues/12).

2. In Windows machines, the `make` command might not exist and can prevent you from running the tests. This can be fixed [by using WSL, or installing MinGW, among other options](https://stackoverflow.com/questions/32127524/how-to-install-and-use-make-in-windows).

3. For any conceptual clarifications, refer to the [course material](https://github.com/nive927/Short-term-Hands-on-Supplementary-Course-on-C-Programming#course-schedule), the [C/C++ documentation](https://en.cppreference.com/w/c/header), or just _Google_ them out!
