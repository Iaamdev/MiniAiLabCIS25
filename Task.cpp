#include "Task.h"
#include <iostream>

// --- Constructor ---
// Task(int task_id, const std::string& date, const std::string& desc)
Task::Task(int task_id, const std::string& date, const std::string& desc)
    : id(task_id), dueDate(date), description(desc), isComplete(false) {
    // isComplete is explicitly initialized to false as per the UML diagram.
}

// --- Destructor ---
// ~Task()
Task::~Task() {
    // Destructors in C++ handle cleanup. For this simple class, it might be empty.
    // std::cout << "Task " << id << " destroyed." << std::endl; // Optional log
}

// --- Methods ---

// markComplete(): void
// Sets the completion status to true.
void Task::markComplete() {
    isComplete = true;
}

// isTaskComplete(bool status): void
// Sets the completion status based on the input parameter.
void Task::isTaskComplete(bool status) {
    isComplete = status;
}

// getDueDate(): string
std::string Task::getDueDate() const {
    return dueDate;
}

// getDescription(): string
std::string Task::getDescription() const {
    return description;
}

// getStatus(): bool (Helper method for checking status)
bool Task::getStatus() const {
    return isComplete;
}

int Task::getId() const{
    return id;
}