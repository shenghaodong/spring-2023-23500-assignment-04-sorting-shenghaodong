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
        runTime.push_back(rand() % 9 + 1);
    }
    std::cout << "Original Array: ";
    for(int j = 0; j < runTime.size(); j++){
        std::cout << runTime.at(j) << " ";
    }
    //qsort(runTime);
    std::cout << "\n\n";
    qsort2(runTime, 0, 15);
    std::cout << "\n\n";
    std::cout << "Finished Array: ";
    for(int x = 0; x < runTime.size(); x++){
        std::cout << runTime.at(x) << " ";
    }

    return 0;
}