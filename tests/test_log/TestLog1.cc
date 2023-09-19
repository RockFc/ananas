
#include <iostream>
#include <string>

#include "util/ThreadPool.h"
#include "util/Logger.h"
#include "util/TimeUtil.h"
#include <sys/syscall.h>
#include <unistd.h>


int main(int ac, char* av[]) {
    
    ananas::LogManager::Instance().Start();
    // auto log = ananas::LogManager::Instance().CreateLog(logDEBUG, logConsole);
    // auto log = ananas::LogManager::Instance().CreateLog(logINFO, logConsole);
    auto log = ananas::LogManager::Instance().CreateLog(logALL, logConsole);
    std::cout << "getpid()" << getpid() << std::endl;
    std::cout << "this_thread::get_id=" << std::this_thread::get_id() << std::endl;
    //syscall(SYS_gettid);
    std::cout << "syscall(SYS_gettid)=" << syscall(SYS_gettid) << std::endl;


    DBG(log) << "Hello ananas, I am debug log!!!";
    INF(log) << "Hello ananas, I am info log!!!";
    WRN(log) << "Hello ananas, I am warning log!!!";
    ERR(log) << "Hello ananas, I am err log!!!";

   ananas::LogManager::Instance().Stop();
    return 0;
}

