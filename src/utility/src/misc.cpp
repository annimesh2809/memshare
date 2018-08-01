#include "misc.h"

#include <iostream>

std::pair<char,char> get_hexa(char c){
  std::pair<char,char> r;
  int a = c/16, b = c%16;
  r.first = (b < 10) ? (b + '0') : (b - 10 + 'A');
  r.second = (a < 10) ? (a + '0') : (a - 10 + 'A');
  return r;
}

void print_interval_list(std::list<Interval>& intervals){
  if(intervals.empty()) return;
  auto it = intervals.begin();
  std::cout << "(" << it->l << "," << it->r << ")";
  it ++;
  for(; it != intervals.end(); it++){
    std::cout << " -> " << "(" << it->l << "," << it->r << ")";
  }
  std::cout << std::endl;
}
