#ifndef MEMSHARE_SHARED_MEM

#define MEMSHARE_SHARED_MEM

#include "mem.h"
#include "intervals.h"

class SharedMem : public Mem{

protected:
  Intervals changed_intervals;

public:

  SharedMem();
  SharedMem(int);
  SharedMem(void*, int);

  ErrorCode write(int, void*, int);
  std::list<Interval>& get_changes();
};

#endif
