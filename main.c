#include <stdio.h>

#define MAX_TASKS 100

// Structure to represent a Task
struct Task {
    int id;
    char title[100];
    char description[200];
    char deadline[20];
    char status[30];
};

// Array to store the tasks and the number of tasks
struct Task tasks[MAX_TASKS];
int numTasks = 0;

// Function to add a new task
void addTask() {
    // Check if the maximum task limit has been reached
    if (numTasks >= MAX_TASKS) {
        printf("Task limit reached!\n");
        return;
    }

    // Create a new task and read its attributes from the user
    struct Task newTask;
    printf("Enter task title: ");
    scanf("%s", newTask.title);
    printf("Enter task description: ");
    scanf("%s", newTask.description);
    printf("Enter task deadline: ");
    scanf("%s", newTask.deadline);
    printf("Enter task status: ");
    scanf("%s", newTask.status);

    // Assign a unique ID to the new task and add it to the tasks array
    newTask.id = numTasks + 1;
    tasks[numTasks] = newTask;
    numTasks++;

    printf("Task added successfully!\n");
}

// Function to display all the tasks
void displayTasks() {
    printf("Task List:\n");
    printf("ID  Title                 Description           Deadline      Status\n");
    printf("--------------------------------------------------------------\n");

    // Iterate over all the tasks and print their attributes
    for (int i = 0; i < numTasks; i++) {
        struct Task task = tasks[i];
        printf("%-3d %-20s %-20s %-12s %-15s\n", task.id, task.title, task.description, task.deadline, task.status);
    }
}

// Function to modify a task
void modifyTask() {
    int taskId;
    printf("Enter the ID of the task to modify: ");
    scanf("%d", &taskId);

    // Search for the task with the given ID and modify its attributes if found
    for (int i = 0; i < numTasks; i++) {
        if (tasks[i].id == taskId) {
            printf("Task found! Enter new description, status, and deadline:\n");
            scanf("%s", tasks[i].description);
            scanf("%s", tasks[i].status);
            scanf("%s", tasks[i].deadline);
            printf("Task modified successfully!\n");
            return;
        }
    }

    printf("Task with ID %d not found!\n", taskId);
}

// Function to delete a task
void deleteTask() {
    int taskId;
    printf("Enter the ID of the task to delete: ");
    scanf("%d", &taskId);

    // Search for the task with the given ID and delete it from the tasks array if found
    for (int i = 0; i < numTasks; i++) {
        if (tasks[i].id == taskId) {
            // Shift all the tasks after the deleted task to the left by one position
            for (int j = i; j < numTasks - 1; j++) {
                tasks[j] = tasks[j + 1];
            }
            numTasks--;
            printf("Task deleted successfully!\n");
            return;
        }
    }

    printf("Task with ID %d not found!\n", taskId);
}

// Function to search for a task by ID
void searchById() {
    int taskId;
    printf("Enter the ID of the task to search: ");
    scanf("%d", &taskId);

    // Search for the task with the given ID and print its attributes if found
    for (int i = 0; i < numTasks; i++) {
        if (tasks[i].id == taskId) {
            printf("Task found!\n");
            printf("Title: %s\n", tasks[i].title);
            printf("Description: %s\n", tasks[i].description);
            printf("Deadline: %s\n", tasks[i].deadline);
            printf("Status: %s\n", tasks[i].status);
            return;
        }
    }

    printf("Task with ID %d not found!\n", taskId);
}

// Function to search for tasks by title
void searchByTitle() {
    char title[100];
    printf("Enter the title of the task to search: ");
    scanf("%s", title);

    int found = 0;
    // Search for tasks with the given title and print their attributes if found
    for (int i = 0; i < numTasks; i++) {
        if (strcmp(tasks[i].title, title) == 0) {
            printf("Task found!\n");
            printf("ID: %d\n", tasks[i].id);
            printf("Description: %s\n", tasks[i].description);
            printf("Deadline: %s\n", tasks[i].deadline);
            printf("Status: %s\n", tasks[i].status);
            found = 1;
        }
    }

    if (!found) {
        printf("Task with title '%s' not found!\n", title);
    }
}

// Function to display statistics about the tasks
void displayStatistics() {
    printf("Number of tasks: %d\n", numTasks);

    int completeCount = 0;
    int incompleteCount = 0;

    // Count the number of complete and incomplete tasks
    for (int i = 0; i < numTasks; i++) {
        if (strcmp(tasks[i].status, "finalisée") == 0) {
            completeCount++;
        } else {
            incompleteCount++;
        }
    }

    printf("Number of complete tasks: %d\n", completeCount);
    printf("Number of incomplete tasks: %d\n", incompleteCount);

    printf("Days remaining for each task:\n");
    // Print the ID and remaining days for each task
    for (int i = 0; i < numTasks; i++) {
        printf("Task ID: %d, Days Remaining: %d\n", tasks[i].id, calculateDaysRemaining(tasks[i].deadline));
    }
}

// Function to calculate the number of days remaining until the deadline
int calculateDaysRemaining(char deadline[20]) {
    // Calculate and return the number of days remaining until the deadline
    // Date calculation logic goes here
    return 0;
}

// Main function to run the program
int main() {
    int choice;

    // Display the menu and process user's choice until they choose to exit
    do {
        printf("\nToDo List Management\n");
        printf("1. Add a new task\n");
        printf("2. Display all tasks\n");
        printf("3. Modify a task\n");
        printf("4. Delete a task\n");
        printf("5. Search tasks by ID\n");
        printf("6. Search tasks by title\n");
        printf("7. Display statistics\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Process the user's choice by calling the appropriate functions
        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                displayTasks();
                break;
            case 3:
                modifyTask();
                break;
            case 4:
                deleteTask();
                break;
            case 5:
                searchById();
                break;
            case 6:
                searchByTitle();
                break;
            case 7:
                displayStatistics();
                break;
            case 8:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 8);

    return 0;
}
