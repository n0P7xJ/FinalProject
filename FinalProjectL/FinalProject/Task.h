#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include "settings.h"

class Task {
    std::wstring wTask;  //  create variable task
    time_t tTime;    //  variable for save task time
public:
    //seters
    void setTask(const std::wstring& wTask);
    void setTime(const time_t& tTime);

    //geters
    std::wstring getTask() const;
    time_t getTime() const;

    //designer for create txt file
    Task();
    Task(const std::wstring& wTask, const time_t& tTime);
    Task(const std::string& pathFile, const std::wstring& wTask = defaultWstring, const time_t& tTime = NULL);

    //method for load task in file
    bool creatTaskInFile(const std::string& pathFile, const std::wstring& wTask, const time_t& tTask);

    //method for load from file into variable
    bool loadFile(const std::string& pathFile, const int& position = 0);

    //method for create file
    bool createFile(const std::string& nameFile, const std::wstring& wTask, const time_t& tTime);
};