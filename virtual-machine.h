#ifndef VIRTUALMACHINE_H
#define VIRTUALMACHINE_H

#include <bits/stdc++.h>

using namespace std;

class VirtualMachine{
    private:
        double cumulative_execution_time;

    public: 
        VirtualMachine();
        void addExecutionTime(double execution_time);
        double getCumulativeExecutionTime() const;

};


#endif /* VIRTUALMACHINE_H */


