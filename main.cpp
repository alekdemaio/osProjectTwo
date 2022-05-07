/*
Author:         Alek DeMaio (ademaio@muhlenberg.edu)
Date:           May 6, 2022
Description:    This is the main file for proj2. It creates the processes,
                populates them. This program also has the my_alloc function
                for FIFO defined.
*/

#include "header.h"

int main(){

  //SCENARIO 2
  default_random_engine generator;
  normal_distribution<float> distribution(200,75);

  // seeding
  cout << "Seed value?:" << endl;
  int seed_value;
  cin >> seed_value;
  generator.seed(seed_value);
  srand(time(NULL));

  // create processes
  Process process[50];
  for(int i=0; i<50; ++i){
    process[i].set_service_time(0);
    process[i].set_memory_requirement(1);
    process[i].set_id(i);
  }

  // add values to processes
  for(int i=0; i<50; ++i){
    process[i].set_service_time(rand()%2000+201);
  }

  // add memory_requirement values using normal_distribution
  int memory_left = 9950;
  int add_value = 0;
  while(memory_left > 0){
    for(int i=0; i<50; ++i){
      add_value = (distribution(generator));

      if((memory_left-add_value) <= 0){
        process[i].set_memory_requirement(process[i].get_memory_requirement()+memory_left);
        memory_left = 0;
        break;
      }
      else{
        process[i].set_memory_requirement(process[i].get_memory_requirement()+add_value);
        memory_left-=add_value;
      }
    }
  }

  // print processes
  int total_memory;
  for(int i=0; i<50; ++i){
    cout << "Process " << i << " ";
    cout << process[i].get_service_time() << " ";
    cout << process[i].get_memory_requirement() << " ";
    cout << process[i].get_id() << endl;
    total_memory += process[i].get_memory_requirement();
  }
  cout << total_memory << endl;

  // create processors
  Processor processor[4];
  for(int i=0; i<4; ++i){
    processor[i].set_speed(150);
    processor[i].set_id(i+1);
  }

  // return processors
  for(int i=0; i<4; ++i){
    cout << processor[i].get_speed() << " ";
    cout << processor[i].get_id() << endl;
  }

  // create memory
  Memory memory[10000];
  for(int i=0; i<10000; ++i){
    memory[i].set_being_used(false);
  }

  //return memory
  for(int i=0; i<10000; ++i){
    cout << "Memory " << i+1 << " ";
    cout << memory[i].get_being_used() << endl;
  }



}

// my_alloc FIFO
// this function looks through a memory array and looks for the firsts hole
// if its finds a space, it looks to see if the space is big enought o fit a
// process and if it is, then memory is set to being used there.
void my_alloc(Memory mem[], Process process) {
  int cycle_start = 0;
  for(int i=0; i<(sizeof(mem)/sizeof(mem[0])); ++i){
    if(mem[i].get_being_used()==false){
      for(int i=0; i<process.get_memory_requirement(); ++i){
        if(mem[i].get_being_used()==false){
          continue;
        }
        else if(mem[i].get_being_used()==false && i+1==process.get_memory_requirement()){
          for(int j=i-process.get_memory_requirement(); i<i+process.get_memory_requirement(); ++i){
            mem[i].set_being_used(true);
          }
        }
        else{
          break;
        }
      }
    }
  }
}
