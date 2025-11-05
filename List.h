#ifndef LIST_H
#define LIST_H

#include <vector>
#include <string>
#include <iostream>
// Include the Task class header since we are managing Task objects
#include "Task.h" 

class List {
private:
    // Stores pointers to Task objects
    std::vector<Task*> tasks; 
    bool isRunning = false; // Initialized to false

public:
    // Constructor and Destructor
    List();
    ~List();

    // Methods (Public: indicated by '+')

    // processInput() : void //allow user to enter commands to do tasks
    void processInput();

    // Creates a new Task and adds its pointer to the 'tasks' vector.
    void addTask(int id, const std::string& date, const std::string& description);

    // prompts the user for a task ID to complete.
    void completeTask();

    // run() : void //while running, print vector of tasks
    void run();

    void printTasks() const;
};

#endif // LIST_H