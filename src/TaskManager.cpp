#include "TaskManager.h"
#include <fstream>
#include <sstream>
#include <algorithm>
 
TaskManager::TaskManager() : tasks() {
}
 
void TaskManager::addTask(const std::string& title) {
    tasks.push_back(std::make_shared<Task>(title));
}
 
bool TaskManager::removeTask(const std::string& id) {
    auto it = std::find_if(tasks.begin(), tasks.end(),
        [&id](const std::shared_ptr<Task>& task) { return task->getId() == id; });
 
    if (it != tasks.end()) {
        tasks.erase(it);
        return true;
    }
    return false;
}
 
bool TaskManager::markTaskDone(const std::string& id) {
    auto task = getTaskById(id);
    if (task) {
        task->markDone();
        return true;
    }
    return false;
}
 
bool TaskManager::markTaskPending(const std::string& id) {
    auto task = getTaskById(id);
    if (task) {
        task->markPending();
        return true;
    }
    return false;
}
 
const std::vector<std::shared_ptr<Task>>& TaskManager::getTasks() const {
    return tasks;
}
 
std::shared_ptr<Task> TaskManager::getTaskById(const std::string& id) const {
    auto it = std::find_if(tasks.begin(), tasks.end(),
        [&id](const std::shared_ptr<Task>& task) { return task->getId() == id; });
 
    if (it != tasks.end()) {
        return *it;
    }
    return nullptr;
}
 
int TaskManager::getPendingCount() const {
    return std::count_if(tasks.begin(), tasks.end(),
        [](const std::shared_ptr<Task>& task) {
            return task->getStatus() == Task::Status::Pending;
        });
}
 
int TaskManager::getDoneCount() const {
    return std::count_if(tasks.begin(), tasks.end(),
        [](const std::shared_ptr<Task>& task) {
            return task->getStatus() == Task::Status::Done;
        });
}
 
void TaskManager::clear() {
    tasks.clear();
}
 
bool TaskManager::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        return false;
    }
 
    file << "{\n  \"tasks\": [\n";
 
    for (size_t i = 0; i < tasks.size(); ++i) {
        const auto& task = tasks[i];
        file << "    {\n";
        file << "      \"id\": \"" << task->getId() << "\",\n";
        file << "      \"title\": \"" << task->getTitle() << "\",\n";
        file << "      \"status\": \""
             << (task->getStatus() == Task::Status::Done ? "Done" : "Pending") << "\"\n";
        file << "    }";
        if (i < tasks.size() - 1) file << ",";
        file << "\n";
    }
 
    file << "  ]\n}\n";
    file.close();
    return true;
}
 
bool TaskManager::loadFromFile(const std::string& filename) {
    // Phase 1: Simple implementation
    // Phase 2: Consider using a JSON library
    std::ifstream file(filename);
    if (!file.is_open()) {
        return false;
    }
 
    clear();
    // TODO: Implement JSON parsing
    // For now, this is a placeholder
 
    return true;
}
 
