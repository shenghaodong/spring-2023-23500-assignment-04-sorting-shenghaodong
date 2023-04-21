#include <iostream>
#include <vector>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>
#include <cstdlib>
#include <math.h>
#include "funcs.h"
extern char *optarg;

// int main(){
//     std::vector<int> runTime;
//     for(int i = 0; i < 25; i++){
//         runTime.push_back(rand() % 20 + 1);
//     }
//     std::cout << "Original Array: ";
//     for(int j = 0; j < runTime.size(); j++){
//         std::cout << runTime.at(j) << " ";
//     }
//     //qsort(runTime);
//     std::cout << "\n\n";
//     sortOnce(runTime, 0, runTime.size());
//     std::cout << "\n";
//     std::cout << "Finished Array: ";
//     for(int x = 0; x < runTime.size(); x++){
//         std::cout << runTime.at(x) << " ";
//     }
//     std::cout << "\n";

//     return 0;
// }


int main(int argc, char *argv[])
{


  int size = 20;
  int max_val = 100;
  char algorithm = 's' ; // selection sort
  bool print = false;
  char c;

  while ( ( c = getopt(argc, argv, "phs:m:a:")) != -1){
    switch(c) {
    case 'h' :
      print_help(argv[0]);
      exit(0);
      break;
    case 'p' :
      print = true;
      break;
    case 's' :
      size = std::stoi(optarg);
      break;
    case 'm' :
      max_val = std::stoi(optarg);
      break;
    case 'a' :
      algorithm = optarg[0];
    }
  }
  
  
  srand(time(nullptr));
  std::vector<int> a(size);
  for (int i = 0; i < size; i++){
    a[i] = rand()%max_val;
  }


  if (print){
    print_vector(a);
  }

  std::vector<int> b;
  
  std::cout << "Starting the sort.\n";
  struct timeval tp;
  gettimeofday(&tp, NULL);
  long start_time = tp.tv_sec * 1000 + tp.tv_usec / 1000;
  
  if (algorithm=='s'){
    b = ssort(a);
  } else if (algorithm=='m'){
    b = msort(a);
  } else if (algorithm=='q'){
    b = qsort(a);
  } else if(algorithm == 'q2'){
    b = qsort2(a);
  }else if(algorithm == 'd'){
    b = std::sort(algorithm);
  }
  

  gettimeofday(&tp,NULL);
  long current_time = tp.tv_sec * 1000 + tp.tv_usec / 1000;
  long elapsed = current_time - start_time;
  
  if (print){
    print_vector(b);
  }

  std::cout << "\n----------------\nElapsed Time: ";
  std::cout << elapsed << "\n";
  return 0;
}
