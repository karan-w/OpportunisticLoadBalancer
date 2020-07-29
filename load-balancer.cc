#include <bits/stdc++.h>

#include "load-balancer.h"

using namespace std;

OpportunisticLoadBalancer::OpportunisticLoadBalancer(string input_filename){
    this->input_filename = input_filename;
    this->output_filename = input_filename.substr(0, input_filename.size() - 4) + "_output.txt";

    ifstream input_file(this->input_filename);
    if(input_file.is_open()){
        input_file >> this->tasks_count >> this->vm_count; 
        int rows = this->tasks_count * this->vm_count; 
        int current_vm = 0, current_task = 0;
        double value;
        this->ETC = new vector<double>[this->tasks_count];
        for(int i = 0; i < rows; i++){
            input_file >> value;
            this->ETC[current_task].push_back(value);
            current_vm = (current_vm + 1) % 16;
            if(current_vm == 0){ //done processing one row, move to next row (task)
                current_task++;
            }
        }
        for(int i = 0; i < this->vm_count; i++){ //initialize the vector of VMs
            VirtualMachine vm;
            this->virtual_machines.push_back(vm);
        }
        input_file.close();
    }else{
        cout << this->input_filename << " could not be found." << endl;
        exit(-1);
    }
}

OpportunisticLoadBalancer::~OpportunisticLoadBalancer(){
    delete []this->ETC;
}

void OpportunisticLoadBalancer::print_ETC_matrix(){
    for(int i = 0; i < this->tasks_count; i++){
        for(int j = 0; j < this->ETC[i].size(); j++){
            cout << this->ETC[i][j] << " ";
        }
        cout << endl;
    }
}

int OpportunisticLoadBalancer::findFreeVirtualMachine(){
    double min_cumulative_execution_time = numeric_limits<double>::max();
    int id = -1; 
    /*
    in case theres a tie, i.e, few VMs get free together, 
    the one with the greatest ID is chosen as the free one to break tie
    */
    int current_cumulative_execution_time = -1;
    for(int i = 0; i < this->vm_count; i++){ 
        current_cumulative_execution_time = virtual_machines[i].getCumulativeExecutionTime();
        if(current_cumulative_execution_time < min_cumulative_execution_time){
            min_cumulative_execution_time = current_cumulative_execution_time;
            id = i;
        }
    }
    return id;
}

void OpportunisticLoadBalancer::printVirtualMachinesStatus(ofstream &output){
    for(int i = 0; i < this->vm_count; i++){
        output << "ID: " << i + 1 << " | Cumulative Execution Time: " << std::setprecision (15) << this->virtual_machines[i].getCumulativeExecutionTime() << endl;
    }
}

void OpportunisticLoadBalancer::schedule(){
    ofstream output(this->output_filename);
    if (output.is_open())
    {
        output << "Initial cumulative execution times of all Virtual Machines" << endl;
        printVirtualMachinesStatus(output);

        /*
        since there is no CRT involved, initialize first 16 tasks in one go 
        */
        for(int i = 0; i < 16; i++){
            output << "Selecting Virtual Machine #" << i + 1 << " for scheduling task # " << i + 1 << endl;
            this->virtual_machines[i].addExecutionTime((double)this->ETC[i][i]);
            printVirtualMachinesStatus(output);
        }
        /*
        allot the remaining tasks by finding out whichever VM gets free at the earliest
        */
        int free_VM_id = -1;
        for(int i = 16; i < 512; i++){
            free_VM_id = findFreeVirtualMachine();
            output << "Selecting Virtual Machine #" << free_VM_id + 1 << " for scheduling task # " << i + 1 << endl;
            this->virtual_machines[free_VM_id].addExecutionTime((double)this->ETC[i][free_VM_id]);
            printVirtualMachinesStatus(output);
        }
        output.close();
    }else{
        cout << "Output file could not be created." << endl;
        exit(-2);
    }
}

string OpportunisticLoadBalancer::getOutputFilename() const{
    return this->output_filename;
}


