#include <string>
#include <fstream>
#include <iostream>

const std::string LOG_FILE_NAME = "logs/log.txt";

void log(std::string logStr){
    std::ofstream log;
    log.open(LOG_FILE_NAME, std::ios_base::app);
    std::cout << "here" << std::endl;

    if (!log.is_open()){
       std::system("mkdir logs");
       log.open(LOG_FILE_NAME, std::ios_base::app);
    }
    log << logStr << std::endl;
    log.close();
}