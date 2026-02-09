#include "../include/ant.h"
#include "../include/tape.h"
#include "../include/simulator.h"


int main(int argc, char* argv[]) {
  Simulator simulator{argv[1]};
  simulator.Simulation(); 
  return 0;
}