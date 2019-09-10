#include <iostream>
#include <cstring>
#include <memory>
#include <unistd.h>
#include <signal.h>
#include <memory>

#include "BMService.h"


std::shared_ptr<badminton::BMService> pService = nullptr;
bool bQuit = false;

void sigint_handler(int sig)
{
    if (pService != nullptr && pService.get() != nullptr)
    {
        pService->stop();
    }
    bQuit = true;
}

int main(int argc, char *argv[])
{
    //通过按ctrl+c结束程序
    signal(SIGINT, sigint_handler);

    pService = std::make_shared<badminton::BMService>();
    
    pService->start();

    while(!bQuit) {
        sleep(1);
    }
    
    pService.reset();

    return 0;
}
