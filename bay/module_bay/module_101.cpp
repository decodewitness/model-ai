// NOT USED YET

#include <string>

enum ModuleType { init1, init2, init3, init4, methods, functions, data_verification, enhance_metrics, process_data, assemble_module, check_modules, entropy, statistics, reset, halting, halt, reroute_power_cycle, halting, halt, router, control_sequence } moduleType; 

std::string init[4][32] = {"start", "starting", "starts","initiate"},
            artificial[2][32] = {"methods", "function"},
            intelligence[2][32] = {"functions"},
            learning[2][32] = {"data_verification"},
            calculation[2][32] = {"enhance_metrics"},
            files [2][32] = {"process_data"},
            construct[2][32] = {"assemble_module"},
            module_testing[2][32] = {"check_modules"},
            sensors[2][32] = {"entropy"},
            vitals[2][32] = {"statistics"},
            reset[2][32] = {"reset"},
            shutdown[2][32] = {"halt"},
            reroute[2][32] = {"reroute_power_cycle"},
            halt[2][32] = {"halting", "halt"},
            router[4][32] = {"0.0.0.0", "0.0.0.0", "0.0.0.0", "0.0.0.0"},
            control_sequence[16][16];   // memset later