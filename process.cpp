/*
Author:         Alek DeMaio (ademaio@muhlenberg.edu)
Date:           May 6, 2022
Description:    This is the process class for proj2.
*/


class Process {
private:
  int service_time;
  int arrival_time;
  int id_number;
  int wait_time;
  int memory_requirement;
  int total_time;

public:
  void set_service_time (int x) {
    service_time = x;
  }
  int get_service_time() {
    return service_time;
  }

  void set_arrival_time (int x) {
    arrival_time = x;
  }
  int get_arrival_time() {
    return arrival_time;
  }

  void set_id (int x) {
    id_number = x;
  }
  int get_id() {
    return id_number;
  }

  void set_wait_time (int x) {
    wait_time = x;
  }
  int get_wait_time() {
    return wait_time;
  }

  void set_memory_requirement (int x) {
    memory_requirement = x;
  }
  int get_memory_requirement() {
    return memory_requirement;
  }

  void set_total_time (int x) {
    total_time = x;
  }
  int get_total_time() {
    return total_time;
  }
};
