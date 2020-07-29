#include <bits/stdc++.h>
#include "virtual-machine.h"

using namespace std;

VirtualMachine::VirtualMachine(){
    this->cumulative_execution_time = 0;
}


void VirtualMachine::addExecutionTime(double execution_time){
    this->cumulative_execution_time += execution_time;
}

double VirtualMachine::getCumulativeExecutionTime() const{
    return this->cumulative_execution_time;
}