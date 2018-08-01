#include "mem.h"
#include "misc.h"

#include <iostream>
#include <cstddef>

Mem::Mem(){
  data = NULL;
  size = 0;
}

Mem::Mem(int _size){
  data = new char[_size];
  size = _size;
}

Mem::Mem(void* _data, int _size){
  data = (char*)_data;
  size = _size;
}

ErrorCode Mem::read(int index, void* _data, int _size) const{
  if(index < 0 || index + _size >= size){
    return ErrorCode::OUT_OF_BOUNDS;
  }

  char* cdata = (char*)_data;
  for(int i=0,j=index;i<_size;i++,j++)
    cdata[i] = data[j];

  return ErrorCode::SUCCESS;
}

void* Mem::unsafe_read(int index){
  if(index < 0 || index >= size){
    return NULL;
  }

  return &(data[index]);
}

ErrorCode Mem::write(int index, void* _data, int _size){
  if(index < 0 || index + _size >= size){
    return ErrorCode::OUT_OF_BOUNDS;
  }

  char* cdata = (char*)_data;
  for(int i=0,j=index;i<_size;i++,j++)
    data[j] = cdata[i];

  return ErrorCode::SUCCESS;
}

void Mem::print(){
  for(int i=0;i<size;i++){
    std::pair<char, char> r = get_hexa(data[i]);
    std::cout << r.first << r.second << " ";
  }
}
