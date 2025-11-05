#include "List.h"
#include <limits> // Required for std::numeric_limits

// --- Constructor ---
List::List() : isRunning(false) {
    std::cout << "Task List initialized." << std::endl;
}

// --- Destructor ---
// IMPORTANT: Since 'tasks' stores raw pointers (Task*), we must iterate 
// and delete each dynamically allocated Task object to prevent a memory leak.
List::~List() {
    for (Task* task : tasks) {
        delete task; // Deletes the Task object pointed to
    }
    tasks.clear(); // Clears the vector itself
    std::cout << "Task List destroyed and all tasks deleted." << std::endl;
}

// --- Private Helper Method ---
void List::printTasks() const {
    if (tasks.empty()) {
        std::cout << "\n[ The task list is empty. ]" << std::endl;
        return;
    }

    std::cout << "\n===== TO-DO LIST =====" << std::endl;
    for (const Task* task : tasks) {
        // Assuming Task class has a getStatus() method
        std::string status = task->getStatus() ? "[DONE]" : "[  ]";
        std::cout << status << " ID: " << task->id 
                  << " | Due: " << task->getDueDate()
                  << " | Task: " << task->getDescription() << std::endl;
    }
    std::cout << "======================\n" << std::endl;
}

// --- Public Methods ---

// run() : void //while running, print vector of tasks
void List::run() {
    isRunning = true;
    std::cout << "\nStarting Task List application. Enter 'help' for commands." << std::endl;
    
    // The run loop
    while (isRunning) {
        printTasks(); // Prints the current list of tasks
        processInput(); // Prompts user for commands
    }
}

// processInput() : void //allow user to enter commands to do tasks
void List::processInput() {
    std::string command;
    std::cout << "Enter command (add/complete/run/quit/help): ";
    std::cin >> command;

    if (command == "quit") {
        isRunning = false;
    } else if (command == "add") {
        int id;
        std::string date, description;
        std::cout << "Enter ID: ";
        // Error handling for int input
        if (!(std::cin >> id)) {
            std::cout << "Invalid ID. Please enter an integer." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return;
        }

        std::cout << "Enter Due Date (e.g., YYYY-MM-DD): ";
        std::cin >> date;
        std::cout << "Enter Description (use underscores for spaces): ";
        std::cin >> description;
        
        addTask(id, date, description);
    } else if (command == "complete") {
        completeTask();
    } else if (command == "run") {
        std::cout << "The application is already running." << std::endl;
    } else if (command == "help") {
        std::cout << "--- Commands ---" << std::endl;
        std::cout << "add: Add a new task (ID, Date, Description)." << std::endl;
        std::cout << "complete: Mark a task as complete." << std::endl;
        std::cout << "quit: Stop the application." << std::endl;
        std::cout << "help: Show this message." << std::endl;
    } else {
        std::cout << "Unknown command. Try 'help'." << std::endl;
    }
    // Clear the input buffer after every command
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// addTask(int id, string date, string description) : void
void List::addTask(int id, const std::string& date, const std::string& description) {
    // Dynamically allocate a new Task object using the C++ constructor
    Task* newTask = new Task(id, date, description);
    tasks.push_back(newTask);
    std::cout << "Task with ID " << id << " added." << std::endl;
}

// completeTask() : void //set bool to true
void List::completeTask() {
    if (tasks.empty()) {
        std::cout << "No tasks to complete." << std::endl;
        return;
    }
    
    int id_to_complete;
    std::cout << "Enter the ID of the task to complete: ";
    if (!(std::cin >> id_to_complete)) {
        std::cout << "Invalid ID entered." << std::endl;
        std::cin.clear();
        return;
    }

    bool found = false;
    for (Task* task : tasks) {
        // Assuming the Task class has a private attribute 'id' that can be accessed 
        // by the List class for simplicity, or we would need a 'getId()' getter 
        // in the Task class. Let's assume a public-like ID for this example.
        if (task->id == id_to_complete) {
            task->markComplete(); // Assuming Task class has markComplete()
            std::cout << "Task ID " << id_to_complete << " marked as COMPLETE." << std::endl;
            found = true;
            break;
        }
    }

    if (!found) {
        std::cout << "Task with ID " << id_to_complete << " not found." << std::endl;
    }
}