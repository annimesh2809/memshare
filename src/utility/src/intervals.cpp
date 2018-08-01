#include <intervals.h>
#include <misc.h>
#include <algorithm>
#include <iostream>

Interval::Interval(){
  l = r = 0;
}

Interval::Interval(int _l, int _r){
  l = _l;
  r = _r;
}


Intervals::Intervals(){
  intervals = std::list<Interval>();
}

int Intervals::insert(Interval interval){
  int st = interval.l, en = interval.r;
  for(auto it = intervals.begin(); it != intervals.end(); it++){
    if(it->r >= interval.l){
      st = std::min(st, it->l);
    }
    if(it->l <= interval.r){
      en = std::max(en, it->r);
    }
  }
  auto it = intervals.begin();
  for(; it != intervals.end(); it++){
    if(it->l >= st && it->r <= en){
      while(it != intervals.end() && it->l >= st && it->r <= en){
        it = intervals.erase(it);
      }
      break;
    }
  }
  intervals.insert(it, Interval(st,en));
  return 0;
}

void Intervals::clear(){
  intervals.clear();
}

std::list<Interval>& Intervals::get_intervals(){
  return intervals;
}

void Intervals::print(){
  print_interval_list(intervals);
}
