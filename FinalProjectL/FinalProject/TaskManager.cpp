#include "TaskManager.h"

TaskManager::TaskManager() {}

TaskManager::TaskManager(const std::string& data){
	readFile(data);
}

void TaskManager::readFile(const std::string& nameFile){
	std::wifstream file(nameFile);

	if (!file.is_open()) {
		std::cerr << "ERROR opening file for write\n";
	}
	else {
		std::wstring output;
		while (std::getline(file, output)) {
			size_t pos = output.find(L'|');
			listTask->push_back(new Task(output.substr(0, pos), std::stoll(output.substr(pos + 1))));
		}
		file.close();
	}
}

void TaskManager::setlistTask(std::vector<Task*>* listTask){
	this->listTask = listTask;
}
