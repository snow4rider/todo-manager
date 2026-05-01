#pragma once

#include "Task.h"
#include <vector>
#include <memory>

class TaskManager {
    public:
        TaskManager();

        // Task operations
        void addTask(const std::string& title);
        bool removeTask(const std::string& id);
        bool markTaskDone(const std::string& id);
        bool markTaskPending(const std::string& id);

        // Getters
        const std::vector<std::shared_ptr<Task>>& getTask() const;
        std::shared_ptr<Task> getTaskById(const std::string& id) const;
        int getPendingCount() const;
        int getDoneCount() const;

        // File operations
        bool saveToFile(const std::string& filename) const;
        bool loadFromFile(const std::string& filename);

        // Clear all tasks
        void clear();

    private:
        std::vector<std::shared_ptr<Task>> tasks;
};