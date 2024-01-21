# C Programming Course - Guided Project: Task Manager CLI Application

This is a guided poject, designed for a C programming course, that tests participants' abilty to implement a command-line (CLI) program that lets its users manage their tasks.

> A complete project description can be found in [description.md](./description.md). The specification for this problem is laid out below, and automated test-cases have been written down to test the application at each developmental stage. Since we haven’t actually implemented anything yet, the tests are currently failing. You have to solve the problem by implementing the application to get all the tests to pass. 

The code for this capstone project has been partially implemented; the boilerplates for atomic operations on tasks, such as add, delete, mark as done, are provided and need to be completed, and all the fundamental operations on files and structures you will need have been composed as function APIs for you to understand and use while concretizing the boilerplates. 

The function APIs allow you to perform specific operations that will constitute your atomic operations; for instance, to complete the `./task add` command (an atomic operation), the relevant `task_add()` function is defined as a (functionally) incomplete template. The logic for this function - read task, wrap task into structure, and write to file - should be implemented. In this case, you might find the function APIs useful to perform elementary operations such as writing lines to text files, composing a structure using the task specification, displaying a task, etc. 

## Course Material

This guided project is part of the **Short-term Hands-on Supplementary Course in C Programming**, conducted by the [Computer Science & Engineering Department](https://www.ssn.edu.in/college-of-engineering/computer-science-and-engineering-department-ssn-institutions/) at [Sri Sivasubramaniya Nadar College of Engineering](https://www.ssn.edu.in/) through a practicum-driven lesson plan during May-July 2022.

[Link to the Course Page](https://github.com/nive927/Short-term-Hands-on-Supplementary-Course-on-C-Programming).

[Link to the Project Page](https://github.com/karthik-d/C-Programming-Course_Project-Starter).

[Link to Project Completion Instructions](./INSTRUCTIONS.md).

## Team

| Nivedhitha D | Karthik Desingu | Dr. B. Prabavathy | Dr. T. T. Mirnalinee |
| :----------: | :-------: | :---------------: | :-----------------: |
|![display-error](./assets/ND-profile-pic.PNG)|![display-error](./assets/KD-profile-pic.PNG)|![display-error](./assets/PB-profile-pic.PNG)|![display-error](./assets/TTM-profile-pic.PNG)|
|<a href="https://www.linkedin.com/in/nivedhitha-d-0bb67b1b0/"><img src="https://img.shields.io/badge/-Nivedhitha%20D-0077B5?style=flat&logo=Linkedin&logoColor=white"/></a> <a href="https://github.com/nive927"><img src="https://img.shields.io/badge/-nive927-B10036?style=flat&logo=GitHub&logoColor=white"/></a>|<a href="https://www.linkedin.com/in/karthik-desingu/"><img src="https://img.shields.io/badge/-Karthik%20Desingu-0077B5?style=flat&logo=Linkedin&logoColor=white"/></a> <a href="https://github.com/karthik-d"><img src="https://img.shields.io/badge/-karthik--d-B10036?style=flat&logo=GitHub&logoColor=white"/></a>|<a href="https://www.ssn.edu.in/staff-members/dr-b-prabavathy/"><img src="https://img.shields.io/badge/-Dr%20B%20Prabavathy-323EA8?style=flat&logo=#&logoColor=white"/></a>|<a href="https://www.ssn.edu.in/staff-members/dr-t-t-mirnalinee//"><img src="https://img.shields.io/badge/-Dr%20T%20T%20Mirnalinee-323EA8?style=flat&logo=#&logoColor=white"/></a>|
|B.E. CSE (2018-2022)|B.E. CSE (2019-2023)|Associate Professor, CSE|Professor & Head, CSE|

## Getting started


### 1. Getting the Boilerplate Code to your GitHub account

- Access the repository from the [project starter page](https://github.com/karthik-d/task-manager-cli-boilerplate).

- Follow the [instructions here](https://docs.github.com/en/get-started/quickstart/fork-a-repo) to [`fork`](https://github.com/karthik-d/task-manager-cli-boilerplate/fork) the repository to your local desktop.


### 2. Getting the Boilerplate Code to your Local System

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

### 3. Running the code

1. You should have a C compiler available for building the code.

2. You are expected to code in the`task.c` file.

3. You should be able to build the app by running `make task`.

4. Once you are done with the changes, you should be able to execute the task app by running the following command from the terminal.


   **On Windows:**

   ```
   .\task.exe
   ```

   **On \*nix:**

   ```
   ./task
   ```

- [Follow these instructions](./INSTRUCTIONS.md) to complete the project.

## A Note about `/` for Windows Users

In the previous sections, you might witness many commands prefixed with `./`, or paths containing the `/` (forward-slash) character.

If you're using the Windows _Command Prompt_, then you'll need to replace `/` with `\` (back-slash) for these commands and paths to work as expected.

On Windows _Powershell_, these substitutions are **not** required.

## Expected Issues

A few notes to help you avoid any hiccups while implementing the programming challenge:

1. If you are on Windows, you might have difficulty getting the tests to pass because of newline UTF encoding issues. If you get stuck, please [refer to the thread here](https://github.com/nseadlc-2020/package-todo-cli-task/issues/12).

2. In Windows machines, the `make` command might not exist and can prevent you from running the tests. This can be fixed [by using WSL, or installing MinGW, among other options](https://stackoverflow.com/questions/32127524/how-to-install-and-use-make-in-windows).

3. For any conceptual clarifications, refer to the [course material](https://github.com/nive927/Short-term-Hands-on-Supplementary-Course-on-C-Programming#course-schedule), the [C/C++ documentation](https://en.cppreference.com/w/c/header), or just _Google_ them out!
