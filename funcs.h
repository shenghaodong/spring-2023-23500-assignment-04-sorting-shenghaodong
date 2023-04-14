#pragma once

void print_vector(std::vector<int> a);
int index_of(int item, int data[], int len);
int find_min_index(std::vector<int> a, int start_index, int stop_index);
std::vector<int> ssort(std::vector<int> a);
std::vector<int> merge(std::vector<int> left, std::vector<int> right);
std::vector<int> msort(std::vector<int> data);
std::vector<int> qsort(std::vector<int> list);
void print_help(char *command_name);
std::vector<int> qsort2(std::vector<int> &list, int low, int high);