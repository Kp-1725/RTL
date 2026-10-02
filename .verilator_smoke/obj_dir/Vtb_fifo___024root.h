// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_fifo.h for the primary calling header

#ifndef VERILATED_VTB_FIFO___024ROOT_H_
#define VERILATED_VTB_FIFO___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_cov.h"
#include "verilated_timing.h"


class Vtb_fifo__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_fifo___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ tb_fifo__DOT__clk;
    CData/*0:0*/ tb_fifo__DOT__rst;
    CData/*0:0*/ tb_fifo__DOT__wr_en;
    CData/*0:0*/ tb_fifo__DOT__rd_en;
    CData/*7:0*/ tb_fifo__DOT__data_in;
    CData/*7:0*/ tb_fifo__DOT__data_out;
    CData/*0:0*/ tb_fifo__DOT____Vtogcov__clk;
    CData/*0:0*/ tb_fifo__DOT____Vtogcov__rst;
    CData/*0:0*/ tb_fifo__DOT____Vtogcov__wr_en;
    CData/*0:0*/ tb_fifo__DOT____Vtogcov__rd_en;
    CData/*7:0*/ tb_fifo__DOT____Vtogcov__data_in;
    CData/*7:0*/ tb_fifo__DOT____Vtogcov__data_out;
    CData/*0:0*/ tb_fifo__DOT____Vtogcov__full;
    CData/*0:0*/ tb_fifo__DOT____Vtogcov__empty;
    CData/*1:0*/ tb_fifo__DOT__dut__DOT__read_pointer;
    CData/*1:0*/ tb_fifo__DOT__dut__DOT__write_pointer;
    CData/*2:0*/ tb_fifo__DOT__dut__DOT__count;
    CData/*0:0*/ tb_fifo__DOT__dut__DOT__write_accept;
    CData/*0:0*/ tb_fifo__DOT__dut__DOT__read_accept;
    CData/*1:0*/ tb_fifo__DOT__dut__DOT____Vtogcov__read_pointer;
    CData/*1:0*/ tb_fifo__DOT__dut__DOT____Vtogcov__write_pointer;
    CData/*2:0*/ tb_fifo__DOT__dut__DOT____Vtogcov__count;
    CData/*0:0*/ tb_fifo__DOT__dut__DOT____Vtogcov__write_accept;
    CData/*0:0*/ tb_fifo__DOT__dut__DOT____Vtogcov__read_accept;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb_fifo__DOT__clk__0;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ tb_fifo__DOT__checks;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*7:0*/, 4> tb_fifo__DOT__dut__DOT__memory;
    VlUnpacked<CData/*7:0*/, 4> tb_fifo__DOT__dut__DOT____Vtogcov__memory;
    VlUnpacked<CData/*0:0*/, 4> __Vm_traceActivity;
    VlQueue<CData/*7:0*/> tb_fifo__DOT__expected_queue;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_h7211e072__0;
    VlTriggerScheduler __VtrigSched_h7211e033__0;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<3> __VactTriggered;
    VlTriggerVec<3> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtb_fifo__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtb_fifo___024root(Vtb_fifo__Syms* symsp, const char* v__name);
    ~Vtb_fifo___024root();
    VL_UNCOPYABLE(Vtb_fifo___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
    void __vlCoverInsert(uint32_t* countp, bool enable, const char* filenamep, int lineno, int column,
        const char* hierp, const char* pagep, const char* commentp, const char* linescovp);
};


#endif  // guard
