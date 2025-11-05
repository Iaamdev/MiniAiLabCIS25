#include "List.h"
#include <iostream>
#include <cstdlib> // Required for system("cls") or system("clear")

// Note: To compile and run this, you will need all three files:
// 1. Task.h
// 2. Task.cpp
// 3. List.h
// 4. List.cpp
// 5. main.cpp

void clearScreen() {
    #ifdef _WIN32
        system("cls"); // Command for Windows
    #else
        system("clear"); // Command for Unix/Linux/macOS
    #endif
}

int main() {
    clearScreen(); // Clear the console for a clean start
    
    std::cout << "========================================" << std::endl;
    std::cout << "       C++ Task List Application        " << std::endl;
    std::cout << "========================================" << std::endl;

    // Create an instance of the List class
    List todoList;

    // 1. Seed the list with a couple of tasks for demonstration
    // Note: The List::addTask method dynamically allocates Task objects.
    todoList.addTask(1, "2025-11-05", "Implement_UML_diagrams");
    todoList.addTask(2, "2025-11-07", "Test_List_functionality");

    // 2. Run the main application loop
    // This calls the run() method defined in List.cpp, 
    // which then calls processInput() repeatedly until the user quits.
    todoList.run(); 

    // 3. Program exit
    std::cout << "\nApplication closing. Good-bye!" << std::endl;

    // When 'todoList' goes out of scope here, its destructor (~List())
    // will automatically run, deleting all the dynamically allocated Task objects.
    
    return 0;
}