Through this step we want to see how you implement a command-line (CLI) program that lets you manage your tasks.

The specification for this problem is written down as tests. Since we haven’t actually implemented anything, the tests are currently failing. You have to solve the problem by implementing the application and getting all the tests to pass.

Here's how it should work when you're done:

## Specification

1. The app can be run in the console with `./task`.

2. The app should read from and write to a task.dat binary file. Each task occupies a single line in this file. Each task should have an associated priority, an integer.

> Priority denotes how important a task is, if it is a high priority task, it should be completed earlier. Priority is denoted using an integer, the lower the number, the higher the priority.

   Here is an example of a list of 2 tasks.

   ```
   1 Buy milk
   2 Complete the project
   ```

3. A completed task is written to a completed.dat binary file. Each task should enapsulate all fields of the original task, and include an additional `date_of_completion` field that records _when_ the task is marked as done.

4. Priority can be any integer _greater than_ or _equal to_ 0. 0 being the highest priority

5. If two task have the same priority, the task that was added first should be displayed first.

   The application must open the files task.dat and completed.dat from where the app is run, and not where the app is located. 

6. The files should always be sorted in order of the priority, ie, the task with the highest priority should be first item in the file.

   ```
   $ cd /path/to/plans

   $ /path/to/apps/task ls
   ```

   The application should look for the task files in `/path/to/plans`, since that is the user’s current directory.
   
> Please note that the programming task can and preferably, should be completed without the use of any additional packages.


## Usage

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



## Getting started

1. You should have a C compiler available for building the code.

2. You are expected to write the code in `task.c` file.

3. You should be able to build the app by running `make app`.

4. Once you are done with the changes you should be able to execute the task app by running the following command from the terminal.

   **On Windows:**

   ```
   .\task.bat
   ```

   **On \*nix:**

   ```
   ./task.sh
   ```
## [Optional] Run Automated Tests

>If you are able to set up npm by following the steps below, great! You can validate that your app works as expected.

>Otherwise, we'll do this for you, when we are evaluating the project. In addition to the test cases mentioned here, we'll add on a few more during the evaluation.

### 1. Install Node.js

You need to have npm installed in your computer for this problem. It comes with Node.js and you can get it by installing Node from https://nodejs.org/en/

### 2. Install dependencies

Run `npm install` to install all dependencies.

### 3. Create Create symbolic link to the executable file

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

Run the following command in your shell:

```
$ ln -s task.sh task
```

### 4. Try running tests.

Now run `npm test` and you will see all the tests failing. As you fill in each functionality, you can re-run the tests to see them passing one by one.

## A Note about `/` for Windows Users

In the following sections, you'll see many commands prefixed with `./`, or paths containing the `/` (forward-slash) character.

If you're using the Windows _Command Prompt_, then you'll need to replace `/` with `\` (back-slash) for these commands and paths to work as expected.

On Windows _Powershell_, these substitutions are not required.

## Expected Issues

A few notes to help you avoid any hiccups while implementing the programming challenge:

1. If you are on Windows, you might have difficulty getting the tests to pass because of newline UTF encoding issues. If you get stuck, please [refer to the thread here](https://github.com/nseadlc-2020/package-todo-cli-task/issues/12).

2. In Windows machines, the `make` command might not exist and can prevent you from running the tests. This can be fixed [by using WSL, or installing MinGW, among other options](https://stackoverflow.com/questions/32127524/how-to-install-and-use-make-in-windows).
