#ifndef OPTIMISTICLOADBALANCER_H
#define OPTIMISTICLOADBALANCER_H

#include <bits/stdc++.h>
#include "virtual-machine.h"

using namespace std;

class OptimisticLoadBalancer{
    private:
        vector<VirtualMachine> virtual_machines;
        vector<double> * ETC;
        int tasks_count;
        int vm_count; 
        string input_filename;
        string output_filename;
    public:
        OptimisticLoadBalancer(string input_filename);
        virtual ~OptimisticLoadBalancer();
        void print_ETC_matrix();
        void schedule();
        int findFreeVirtualMachine(); //returns the ID/index of the vector of the virtual machine that is free
        void printVirtualMachinesStatus(ofstream &output);
        string getOutputFilename() const;

};


#endif /* OPTIMISTICLOADBALANCER_H */