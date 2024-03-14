#pragma once

#include "Task.h"
#include "settings.h"

class TaskManager {
private:
	std::vector<Task*>* listTask;
public:
	TaskManager();
	TaskManager(const std::string& data);

	void readFile(const std::string& nameFile);
	void setlistTask(std::vector<Task*>* listTask);
};

