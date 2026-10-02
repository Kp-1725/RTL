// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtb_fifo__pch.h"
#include "Vtb_fifo.h"
#include "Vtb_fifo___024root.h"

// FUNCTIONS
Vtb_fifo__Syms::~Vtb_fifo__Syms()
{
}

Vtb_fifo__Syms::Vtb_fifo__Syms(VerilatedContext* contextp, const char* namep, Vtb_fifo* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
        // Check resources
        Verilated::stackCheck(63);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    // Setup scopes
    __Vscope_tb_fifo.configure(this, name(), "tb_fifo", "tb_fifo", "<null>", -12, VerilatedScope::SCOPE_OTHER);
    __Vscope_tb_fifo__check_flags.configure(this, name(), "tb_fifo.check_flags", "check_flags", "<null>", -12, VerilatedScope::SCOPE_OTHER);
    __Vscope_tb_fifo__read_item.configure(this, name(), "tb_fifo.read_item", "read_item", "<null>", -12, VerilatedScope::SCOPE_OTHER);
    __Vscope_tb_fifo__simultaneous_item.configure(this, name(), "tb_fifo.simultaneous_item", "simultaneous_item", "<null>", -12, VerilatedScope::SCOPE_OTHER);
}
