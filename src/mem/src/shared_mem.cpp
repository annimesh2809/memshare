#include "shared_mem.h"

SharedMem::SharedMem() : Mem(){}

SharedMem::SharedMem(int _size) : Mem(_size){}

SharedMem::SharedMem(void* _data, int _size) : Mem(_data, _size){}

ErrorCode SharedMem::write(int index, void* _data, int _size){
  Mem::write(index, _data, _size);
  changed_intervals.insert(Interval(index, index+_size));
}

std::list<Interval>& SharedMem::get_changes(){
  return changed_intervals.get_intervals();
}
