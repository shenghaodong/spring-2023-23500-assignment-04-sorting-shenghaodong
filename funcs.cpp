//Class Code
#include <iostream>
#include <vector>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>
#include <cstdlib>
#include <math.h>

// compile with -fconcepts and you
// can make the std::vector<int>
// into std::vector<auto>
void print_vector(std::vector<int> a){
  for(auto item:a){
    std::cout << item << ", ";
  }
  std::cout << "\n";
}


int index_of(int item, int data[], int len){
  for (int i = 0; i < len; i++){
    if (data[i] == item)
      return i;
  }

  return -1;
}

int find_min_index(std::vector<int> a, int low_index, int stop_index){
  int min_index = low_index;
  int i;
  for (i = low_index; i < stop_index; i++){
    if (a[i] < a[min_index]){
      min_index = i;
    }
  }
  return min_index;
}

std::vector<int> ssort(std::vector<int> a){
  int i,min_index,tmp;
  int len = a.size();

  for (i=0;i<len;i++){
    min_index = find_min_index(a,i,len);

    tmp = a[i];
    a[i] = a[min_index];
    a[min_index] = tmp;
  }
  return a;
}

/*
  left and right are already sorted low to high
  create a new std::vector named merged
  and fill it with all the elements of left and right.
  When done, merged should be in order low to high.
*/
std::vector<int> merge(std::vector<int> left, std::vector<int> right){
  std::vector<int> merged;
  int l=0,r=0; // indices into left and right;

  while (l < left.size() && r< right.size()){
    if (left[l] < right[r]){
      merged.push_back(left[l]);
      l++;
    } else {
      merged.push_back(right[r]);
      r++;
    }
  }

  while (l < left.size()){
    merged.push_back(left[l]);
    l++;
  }
  while (r < right.size()){
    merged.push_back(right[r]);
    r++;
  }
     
  return merged;
}

std::vector<int> msort(std::vector<int> data){

  std::vector<int> result;
  
  if (data.size() <= 1){
    return data;
  }
  
  std::vector<int> a,b;
  int i;
  int mid = data.size()/2;
  for (i=0;i<mid;i++){
    a.push_back(data[i]);
  }
  
  for (;i<data.size();i++){
    b.push_back(data[i]);
  }

  a = msort(a);
  b = msort(b);

  result= merge(a,b);
  
  return result;
}

std::vector<int> qsort(std::vector<int> list){
  int i,j;

  // base case
  if (list.size() <= 1){
    return list;
  }

  // select pivot value
  // for now we'll just pick list[0]
  int pivot = list[0];

  // make 2 new vectors
  std::vector<int> lower,higher;
  
  // copy all the values < pivot to lower
  // copy all the values >= pivot to higher;
  for (i=1;i<list.size();i++){
    if (list[i] < pivot){
      lower.push_back(list[i]);
    } else {
      higher.push_back(list[i]);
    }
  }

  // make our recursive calls
  lower = qsort(lower);
  higher = qsort(higher);

  // copy everything back
  for (i=0; i < lower.size(); i++){
    list[i] = lower[i];
  }
  list[i] = pivot;
  i++;
  for (j=0;j<higher.size(); j++){
    list[i] = higher[j];
    i++;
  }

  // return the sorted list
  return list;
}


void print_help(char *command_name){
  std::cout << command_name << " usage: ";
  std::cout << command_name << "[OPTIONS]\n";
  std::cout << "  -h : help\n";
  std::cout << "  -p : print\n";
  std::cout << "  -s SIZE : array size\n";
  std::cout << "  -m MAX_VAL : maximum element value\n";
  std::cout << "  -a [s|m|q] : selection, merge, or quick sort\n";
  
}


//Quick Sort 2 (Assignment)
void qsort2(std::vector<int> &list, int low, int high){
  //Make sure it works for the first step then move to qsort2

  //Base Case
  if(low >= high){
    return;
  }

  //Set Pivot, It's set as the first index for now (for testing)
  int pivot = list[high - 1];
  int pivotIndex = high - 1;

  //Set Pivot to Last Index so we can swap without worrying about it
  std::swap(list[pivotIndex], list[high - 1]);
  std::cout << "This is the pivot: " << pivot << std::endl;


  //Set to first and last index for our loop
  int i = low;
  int j = high - 2;

  //As long as low doesn't get higher than high then continue running
  while(i < j){
    while(list[i] < pivot && i < high){
      i++;
    }
    while(list[j] >= pivot && j >= 1){
      j--;
    }
    //Swap
    if(list[i] >= pivot && list[j] < pivot && i <= j){
      //std:: cout << "Swapped: " << "\nIndex I: " << i << "\nNum: " << list[i] << "\nIndex J: " << j << "\nNum: " << list[j] << std::endl;
      std::swap(list[i++], list[j--]);
    }
  }

  //Move Pivot back
  pivotIndex = i;
  if(list[i] > list[high - 1]){
  std::swap(list[i], list[high - 1]);
  }

  //Recurse
  qsort2(list, low, pivotIndex);
  qsort2(list, pivotIndex + 1, high);
}