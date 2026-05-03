#include "Task.h"
#include <random>
#include <sstream>
#include <iomanip>
 
Task::Task(const std::string& title)
    : id(generateId()),
      title(title),
      description(""),
      status(Status::Pending),
      createdAt(std::chrono::system_clock::now()) {
}
 
const std::string& Task::getTitle() const {
    return title;
}
 
const std::string& Task::getDescription() const {
    return description;
}
 
Task::Status Task::getStatus() const {
    return status;
}
 
std::string Task::getId() const {
    return id;
}
 
void Task::setDescription(const std::string& desc) {
    description = desc;
}
 
void Task::markDone() {
    status = Status::Done;
}
 
void Task::markPending() {
    status = Status::Pending;
}
 
std::string Task::generateId() {
    // Simple ID generation: timestamp + random
    auto now = std::chrono::system_clock::now();
    auto duration = now.time_since_epoch();
    auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
 
    // Add a small random component
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 9999);
    int random_part = dis(gen);
 
    std::stringstream ss;
    ss << millis << "-" << std::setfill('0') << std::setw(4) << random_part;
    return ss.str();
}
