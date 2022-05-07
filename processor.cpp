/*
Author:         Alek DeMaio (ademaio@muhlenberg.edu)
Date:           May 6, 2022
Description:    This is the processor class for proj2.
*/

#include "process.cpp"


class Processor {
private:
  int speed;
  int memory_capacity;
  bool being_used;
  int process_id;
  int service_time;
  int arrival_time;
  int wait_time;
  int memory_requirement;
  int total_time;
  Process process;



public:
  void set_process(Process x) {
    process = x;
  }

  Process get_process() {
    return process;
  }

  void set_id(int x) {
    process_id = x;
  }

  int get_id() {
    return process_id;
  }

  void set_being_used(bool x) {
    being_used = x;
  }

  bool get_being_used() {
    return being_used;
  }

  void set_memory_capacity(int x) {
    memory_capacity = x;
  }

  int get_memory_capacity() {
    return memory_capacity;
  }

  void set_speed(int x) {
    speed = x;
  }

  int get_speed() {
    return speed;
  }

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
