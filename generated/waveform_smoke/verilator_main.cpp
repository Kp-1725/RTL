#include "Vtb_fifo.h"
#include "verilated.h"
#include "verilated_cov.h"

int main(int argc, char** argv) {
    VerilatedContext context;
    context.commandArgs(argc, argv);
    Verilated::traceEverOn(true);
    Vtb_fifo top{&context};
    while (!context.gotFinish() && context.time() < 100000) {
        top.eval();
        context.timeInc(1);
    }
    top.final();
    VerilatedCov::write("/mnt/f/ieee workshop/agentic-rtl/generated/waveform_smoke/coverage.dat");
    return context.gotFinish() ? 0 : 1;
}
