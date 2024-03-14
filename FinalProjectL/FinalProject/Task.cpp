#include "Task.h"

//seters
void Task::setTask(const std::wstring& wTask)
{
    this->wTask = wTask;
}

void Task::setTime(const time_t& tTime)
{
    this->tTime = tTime;
}

//geters
std::wstring Task::getTask() const
{
    return wTask;
}

time_t Task::getTime() const
{
    return tTime;
}

Task::Task() : wTask(defaultWstring), tTime(0) {}

Task::Task(const std::wstring& wTask, const time_t& tTime) : wTask(wTask),tTime(tTime){}

//designer for create txt file
Task::Task(const std::string& pathFile, const std::wstring& wTask, const time_t& tTime) {
    if (wTask == defaultWstring || tTime == 0) {
        loadFile(pathFile);
    }
    else {
        createFile(pathFile, wTask, tTime);
    }
}

//method for load file
bool Task::creatTaskInFile(const std::string& pathFile, const std::wstring& wTask, const time_t& cTime)
{
    std::wofstream file(pathFile);
    if (!file.is_open()) {
        return false;
    }
    else {
        std::wstring taskTime = std::to_wstring(cTime);
        file << wTask << '|' << taskTime;
        file.close();
        return true;
    }
}

//method for load from file into variable
bool Task::loadFile(const std::string& pathFile, const int& position) {
    std::wifstream outputFile(pathFile);

    if (!outputFile.is_open()) {
        std::cerr << "ERROR opening file for write\n";
        return false;
    }
    else {
        outputFile.seekg(position);
        std::wstring outputLine;
        std::getline(outputFile, outputLine);
        std::wcout << outputLine + L'\n';
        outputFile.close();
        return true;
    }
}

//method for create file
bool Task::createFile(const std::string& fileName, const std::wstring& wTask, const time_t& cTime) {
    std::wofstream outputFile(fileName, std::ios::out | std::ios::app);

    if (!outputFile.is_open()) {
        std::cerr << "ERROR opening file for write\n";
    }
    else {
        std::wstring taskTime = std::to_wstring(cTime);
        outputFile << wTask << '|' << taskTime;
        outputFile.close();
        return true;
    }
    return false;
}