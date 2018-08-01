#ifndef MEMSHARE_INTERVALS

#define MEMSHARE_INTERVALS

#include <list>

class Interval{
public:
  int l,r;

  Interval();
  Interval(int, int);
};

class Intervals{
  std::list<Interval> intervals;

public:
  Intervals();
  int insert(Interval interval);
  void clear();
  std::list<Interval>& get_intervals();
  void print();
};

#endif
