#include "Vtop.h"
#include "verilated.h"
#include "verilated_fst_c.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(int argc, char** argv){
      VerilatedContext* contextp = new VerilatedContext;
      contextp->commandArgs(argc, argv);
      Vtop* top = new Vtop{contextp};

      //add .fst file
      Verilated::traceEverOn(true);
      VerilatedFstC* tfp = new VerilatedFstC;
      top->trace(tfp, 99);
      tfp->open("/home/ghost/test_our/verilator_study_project/sim_top.fst");

      //loop time
      int sim_time = 100;

      while (contextp->time() < sim_time && !contextp->gotFinish()){
        //timpstep++
        contextp->timeInc(1);

        top->eval();
        
        //add result to .fst
        tfp->dump(contextp->time());

      }
      tfp->close();
      delete top;
      delete contextp;
      return 0;    
}