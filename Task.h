#ifndef TASK_H
#define TASK_H

#include <string>

class Task {
private:
    int id;
    std::string dueDate;
    std::string description;
    bool isComplete = false;

public:
    Task(int task_id, const std::string& date, const std::string& desc);
    ~Task();

    void markComplete();

    void isTaskComplete(bool status);

    std::string getDueDate() const;
    std::string getDescription() const;

    bool getStatus() const;
    int getId() const;
    
};

#endif // TASK_H