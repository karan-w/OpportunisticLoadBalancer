#include <bits/stdc++.h>

#include "virtual-machine.cc"
#include "load-balancer.cc"

#define fastio cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);

using namespace std;

int main(int argc, char *argv[]){
    fastio
    if(argc > 1){
        cout << "-----------------------------------------------------------------------------------" << endl;
        for(int i = 1; i < argc; i++){
            string input_filename(argv[i]);
            cout << "Starting optimistic load balancer algorithm with input as " << input_filename << endl;
            OptimisticLoadBalancer olb(input_filename); 
            olb.schedule();
            cout << "Completed processing. Logs can be found in " << olb.getOutputFilename() << endl;
            cout << "-----------------------------------------------------------------------------------" << endl;
        }
    }else{
        cout << "Please provide space separated dataset filenames as command line arguments to the program." << endl;
    }
    return 0;
}




