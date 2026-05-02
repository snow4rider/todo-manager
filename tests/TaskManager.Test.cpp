#include <gtest/gtest.h>
#include "TaskManager.h"
 
// Test fixture - set up fresh TaskManager before each test
class TaskManagerTest : public ::testing::Test {
protected:
    TaskManager manager;
 
    // SetUp is called before each test
    void SetUp() override {
        manager.clear();
    }
 
    // TearDown is called after each test
    void TearDown() override {
        manager.clear();
    }
};
 
// Basic task creation
TEST_F(TaskManagerTest, AddTask) {
    manager.addTask("Buy groceries");
    EXPECT_EQ(manager.getTasks().size(), 1);
    EXPECT_EQ(manager.getTasks()[0]->getTitle(), "Buy groceries");
}
 
// Multiple tasks
TEST_F(TaskManagerTest, AddMultipleTasks) {
    manager.addTask("Task 1");
    manager.addTask("Task 2");
    manager.addTask("Task 3");
 
    EXPECT_EQ(manager.getTasks().size(), 3);
}
 
// Get task by ID
TEST_F(TaskManagerTest, GetTaskById) {
    manager.addTask("Important task");
    auto task = manager.getTasks()[0];
    auto id = task->getId();
 
    auto retrieved = manager.getTaskById(id);
    EXPECT_NE(retrieved, nullptr);
    EXPECT_EQ(retrieved->getTitle(), "Important task");
}
 
// Remove task
TEST_F(TaskManagerTest, RemoveTask) {
    manager.addTask("Task to remove");
    auto id = manager.getTasks()[0]->getId();
 
    bool removed = manager.removeTask(id);
    EXPECT_TRUE(removed);
    EXPECT_EQ(manager.getTasks().size(), 0);
}
 
// Remove non-existent task returns false
TEST_F(TaskManagerTest, RemoveNonExistentTask) {
    bool removed = manager.removeTask("fake-id");
    EXPECT_FALSE(removed);
}
 
// Mark task done
TEST_F(TaskManagerTest, MarkTaskDone) {
    manager.addTask("Complete me");
    auto task = manager.getTasks()[0];
    auto id = task->getId();
 
    bool marked = manager.markTaskDone(id);
    EXPECT_TRUE(marked);
    EXPECT_EQ(task->getStatus(), Task::Status::Done);
}
 
// Count pending tasks
TEST_F(TaskManagerTest, CountPendingTasks) {
    manager.addTask("Task 1");
    manager.addTask("Task 2");
    manager.addTask("Task 3");
 
    manager.markTaskDone(manager.getTasks()[0]->getId());
    manager.markTaskDone(manager.getTasks()[1]->getId());
 
    EXPECT_EQ(manager.getPendingCount(), 1);
    EXPECT_EQ(manager.getDoneCount(), 2);
}
 
// Task description
TEST_F(TaskManagerTest, SetTaskDescription) {
    manager.addTask("Titled task");
    auto task = manager.getTasks()[0];
 
    task->setDescription("This is a detailed description");
    EXPECT_EQ(task->getDescription(), "This is a detailed description");
}
 
// Mark task pending (toggle)
TEST_F(TaskManagerTest, MarkTaskPending) {
    manager.addTask("Toggle task");
    auto id = manager.getTasks()[0]->getId();
 
    manager.markTaskDone(id);
    EXPECT_EQ(manager.getTaskById(id)->getStatus(), Task::Status::Done);
 
    manager.markTaskPending(id);
    EXPECT_EQ(manager.getTaskById(id)->getStatus(), Task::Status::Pending);
}
 
// Save to file
TEST_F(TaskManagerTest, SaveToFile) {
    manager.addTask("Task 1");
    manager.addTask("Task 2");
    manager.markTaskDone(manager.getTasks()[0]->getId());
 
    bool saved = manager.saveToFile("/tmp/tasks_test.json");
    EXPECT_TRUE(saved);
 
    // File should exist and be readable
    std::ifstream file("/tmp/tasks_test.json");
    EXPECT_TRUE(file.good());
    file.close();
}
