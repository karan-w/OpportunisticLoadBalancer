#ifndef OPPORTUNISTICLOADBALANCER_H
#define OPPORTUNISTICLOADBALANCER_H

#include <bits/stdc++.h>
#include "virtual-machine.h"

using namespace std;

class OpportunisticLoadBalancer{
    private:
        vector<VirtualMachine> virtual_machines;
        vector<double> * ETC;
        int tasks_count;
        int vm_count; 
        string input_filename;
        string output_filename;
    public:
        OpportunisticLoadBalancer(string input_filename);
        virtual ~OpportunisticLoadBalancer();
        void print_ETC_matrix();
        void schedule();
        int findFreeVirtualMachine(); //returns the ID/index of the vector of the virtual machine that is free
        void printVirtualMachinesStatus(ofstream &output);
        string getOutputFilename() const;

};

#endif /* OPPORTUNISTICLOADBALANCER_H */



