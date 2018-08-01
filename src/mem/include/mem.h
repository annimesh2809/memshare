#ifndef MEMSHARE_MEM

#define MEMSHARE_MEM

#include "error.h"

class Mem{
  
protected:
  char* data;
  unsigned int size;

public:
  Mem();
  Mem(int);
  Mem(void*, int);

  ErrorCode read(int, void*, int) const;
  void* unsafe_read(int);
  ErrorCode write(int, void*, int);

  void print();
};

#endif
