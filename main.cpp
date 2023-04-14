#include <iostream>
#include <vector>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>
#include <cstdlib>
#include <math.h>
#include "funcs.h"

int main(){
    std::vector<int> runTime;
    for(int i = 0; i < 15; i++){
        runTime.push_back(rand() % 50 + 1);
    }
    for(int j = 0; j < runTime.size(); j++){
        std::cout << runTime.at(j) << ", ";
    }
    //qsort(runTime);
    std::vector<int> runTest = qsort2(runTime, 0, 14);
    
    return 0;
}