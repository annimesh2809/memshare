#include <iostream>
#include <shared_mem.h>
#include <intervals.h>
#include <misc.h>

using namespace std;

int main(int argc, char const *argv[]) {
  // Mem m(256);
  // m.print();
  // int x = 65;
  // m.write(0, &x, 4);
  // cout << "\n";
  // m.print();

  // Intervals intervals;
  // intervals.insert(Interval(2,3));
  // intervals.print();
  // intervals.insert(Interval(5,6));
  // intervals.print();
  // intervals.insert(Interval(3,6));
  // intervals.print();
  // intervals.insert(Interval(2,4));
  // intervals.print();
  // intervals.insert(Interval(8,9));
  // intervals.print();
  // intervals.insert(Interval(9,11));
  // intervals.print();

  SharedMem m(256);
  m.print();
  int x = 65;
  m.write(0, &x, 4);
  cout << "\n";
  m.print();
  cout << "\n";
  list<Interval> intervals = m.get_changes();
  print_interval_list(intervals);
  cout << "\n";
  cout << "Test working :)" << endl;
  return 0;
}
