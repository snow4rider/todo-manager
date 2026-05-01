#pragma once

#include <string>
#include <chrono>

class Task
{
public:
    enum class Status
    {
        Pending,
        Done
    };

    Task(const std::string &title);

    // Getters
    const std::string &getTitle() const;
    const std::string &getDescription() const;
    Status getStatus() const;
    std::string getId() const;

    // Setters
    void setDescription(const std::string &desc);
    void markDone();
    void markPending();

private:
    std::string id;
    std::string title;
    std::string description;
    Status status;
    std::chrono::system_clock::time_point createAt;

    // Helper to generate unique ID
    static std::string generateId();
};