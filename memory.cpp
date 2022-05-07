/*
Author:         Alek DeMaio (ademaio@muhlenberg.edu)
Date:           May 6, 2022
Description:    This is the memory class for proj2.
*/




class Memory {
private:
  int current_process;
  bool being_used;

public:
  void set_current_process(int x) {
    current_process = x;
  }

  int get_current_process() {
    return current_process;
  }

  void set_being_used(bool x) {
    being_used = x;
  }

  bool get_being_used() {
    return being_used;
  }
};
