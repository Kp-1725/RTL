// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_fifo.h for the primary calling header

#include "Vtb_fifo__pch.h"
#include "Vtb_fifo__Syms.h"
#include "Vtb_fifo___024root.h"

VL_INLINE_OPT VlCoroutine Vtb_fifo___024root___eval_initial__TOP__Vtiming__0(Vtb_fifo___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fifo___024root___eval_initial__TOP__Vtiming__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*7:0*/ __Vtask_tb_fifo__DOT__read_item__1__expected_value;
    __Vtask_tb_fifo__DOT__read_item__1__expected_value = 0;
    CData/*0:0*/ __Vtask_tb_fifo__DOT__read_item__1__had_read;
    __Vtask_tb_fifo__DOT__read_item__1__had_read = 0;
    CData/*7:0*/ __Vtask_tb_fifo__DOT__write_item__3__value;
    __Vtask_tb_fifo__DOT__write_item__3__value = 0;
    CData/*7:0*/ __Vtask_tb_fifo__DOT__read_item__5__expected_value;
    __Vtask_tb_fifo__DOT__read_item__5__expected_value = 0;
    CData/*0:0*/ __Vtask_tb_fifo__DOT__read_item__5__had_read;
    __Vtask_tb_fifo__DOT__read_item__5__had_read = 0;
    CData/*7:0*/ __Vtask_tb_fifo__DOT__write_item__7__value;
    __Vtask_tb_fifo__DOT__write_item__7__value = 0;
    CData/*7:0*/ __Vtask_tb_fifo__DOT__write_item__9__value;
    __Vtask_tb_fifo__DOT__write_item__9__value = 0;
    CData/*7:0*/ __Vtask_tb_fifo__DOT__write_item__11__value;
    __Vtask_tb_fifo__DOT__write_item__11__value = 0;
    CData/*7:0*/ __Vtask_tb_fifo__DOT__write_item__13__value;
    __Vtask_tb_fifo__DOT__write_item__13__value = 0;
    CData/*7:0*/ __Vtask_tb_fifo__DOT__write_item__15__value;
    __Vtask_tb_fifo__DOT__write_item__15__value = 0;
    CData/*7:0*/ __Vtask_tb_fifo__DOT__read_item__17__expected_value;
    __Vtask_tb_fifo__DOT__read_item__17__expected_value = 0;
    CData/*0:0*/ __Vtask_tb_fifo__DOT__read_item__17__had_read;
    __Vtask_tb_fifo__DOT__read_item__17__had_read = 0;
    CData/*7:0*/ __Vtask_tb_fifo__DOT__read_item__19__expected_value;
    __Vtask_tb_fifo__DOT__read_item__19__expected_value = 0;
    CData/*0:0*/ __Vtask_tb_fifo__DOT__read_item__19__had_read;
    __Vtask_tb_fifo__DOT__read_item__19__had_read = 0;
    CData/*7:0*/ __Vtask_tb_fifo__DOT__read_item__21__expected_value;
    __Vtask_tb_fifo__DOT__read_item__21__expected_value = 0;
    CData/*0:0*/ __Vtask_tb_fifo__DOT__read_item__21__had_read;
    __Vtask_tb_fifo__DOT__read_item__21__had_read = 0;
    CData/*7:0*/ __Vtask_tb_fifo__DOT__read_item__23__expected_value;
    __Vtask_tb_fifo__DOT__read_item__23__expected_value = 0;
    CData/*0:0*/ __Vtask_tb_fifo__DOT__read_item__23__had_read;
    __Vtask_tb_fifo__DOT__read_item__23__had_read = 0;
    CData/*7:0*/ __Vtask_tb_fifo__DOT__write_item__25__value;
    __Vtask_tb_fifo__DOT__write_item__25__value = 0;
    CData/*7:0*/ __Vtask_tb_fifo__DOT__write_item__27__value;
    __Vtask_tb_fifo__DOT__write_item__27__value = 0;
    CData/*7:0*/ __Vtask_tb_fifo__DOT__simultaneous_item__29__value;
    __Vtask_tb_fifo__DOT__simultaneous_item__29__value = 0;
    CData/*7:0*/ __Vtask_tb_fifo__DOT__simultaneous_item__29__expected_value;
    __Vtask_tb_fifo__DOT__simultaneous_item__29__expected_value = 0;
    CData/*0:0*/ __Vtask_tb_fifo__DOT__simultaneous_item__29__had_read;
    __Vtask_tb_fifo__DOT__simultaneous_item__29__had_read = 0;
    CData/*0:0*/ __Vtask_tb_fifo__DOT__simultaneous_item__29__had_write;
    __Vtask_tb_fifo__DOT__simultaneous_item__29__had_write = 0;
    CData/*7:0*/ __Vtask_tb_fifo__DOT__read_item__31__expected_value;
    __Vtask_tb_fifo__DOT__read_item__31__expected_value = 0;
    CData/*0:0*/ __Vtask_tb_fifo__DOT__read_item__31__had_read;
    __Vtask_tb_fifo__DOT__read_item__31__had_read = 0;
    CData/*7:0*/ __Vtask_tb_fifo__DOT__read_item__33__expected_value;
    __Vtask_tb_fifo__DOT__read_item__33__expected_value = 0;
    CData/*0:0*/ __Vtask_tb_fifo__DOT__read_item__33__had_read;
    __Vtask_tb_fifo__DOT__read_item__33__had_read = 0;
    CData/*7:0*/ __Vtask_tb_fifo__DOT__write_item__35__value;
    __Vtask_tb_fifo__DOT__write_item__35__value = 0;
    // Body
    vlSymsp->_vm_contextp__->dumpfile(std::string{"fifo.vcd"});
    vlSymsp->_traceDumpOpen();
    vlSelfRef.tb_fifo__DOT__clk = 0U;
    vlSelfRef.tb_fifo__DOT__rst = 1U;
    vlSelfRef.tb_fifo__DOT__wr_en = 0U;
    vlSelfRef.tb_fifo__DOT__rd_en = 0U;
    vlSelfRef.tb_fifo__DOT__data_in = 0U;
    vlSelfRef.tb_fifo__DOT__checks = 0U;
    co_await vlSelfRef.__VtrigSched_h7211e072__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_fifo.clk)", 
                                                         "designs/fifo/reference/tb_fifo.sv", 
                                                         119);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    ++(vlSymsp->__Vcoverage[39]);
    co_await vlSelfRef.__VtrigSched_h7211e072__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_fifo.clk)", 
                                                         "designs/fifo/reference/tb_fifo.sv", 
                                                         119);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    ++(vlSymsp->__Vcoverage[39]);
    co_await vlSelfRef.__VdlySched.delay(1ULL, nullptr, 
                                         "designs/fifo/reference/tb_fifo.sv", 
                                         120);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.tb_fifo__DOT__expected_queue.clear();
    if (VL_UNLIKELY(((0U == (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__count)) 
                     != (0U == vlSelfRef.tb_fifo__DOT__expected_queue.size())))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_fifo.sv:36: Assertion failed in %Ntb_fifo.check_flags: FAIL: empty mismatch at time %0t\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                     64,VL_TIME_UNITED_Q(1),-12);
        VL_STOP_MT("designs/fifo/reference/tb_fifo.sv", 36, "", false);
    } else {
        ++(vlSymsp->__Vcoverage[23]);
    }
    if (VL_UNLIKELY(((4U == (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__count)) 
                     != (4U == vlSelfRef.tb_fifo__DOT__expected_queue.size())))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_fifo.sv:39: Assertion failed in %Ntb_fifo.check_flags: FAIL: full mismatch at time %0t\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                     64,VL_TIME_UNITED_Q(1),-12);
        VL_STOP_MT("designs/fifo/reference/tb_fifo.sv", 39, "", false);
    } else {
        ++(vlSymsp->__Vcoverage[24]);
    }
    vlSelfRef.tb_fifo__DOT__checks = ((IData)(1U) + vlSelfRef.tb_fifo__DOT__checks);
    ++(vlSymsp->__Vcoverage[25]);
    vlSelfRef.tb_fifo__DOT__rst = 0U;
    co_await vlSelfRef.__VtrigSched_h7211e033__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_fifo.clk)", 
                                                         "designs/fifo/reference/tb_fifo.sv", 
                                                         64);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.tb_fifo__DOT__wr_en = 0U;
    vlSelfRef.tb_fifo__DOT__rd_en = 1U;
    __Vtask_tb_fifo__DOT__read_item__1__had_read = 
        VL_LTS_III(32, 0U, vlSelfRef.tb_fifo__DOT__expected_queue.size());
    if (__Vtask_tb_fifo__DOT__read_item__1__had_read) {
        __Vtask_tb_fifo__DOT__read_item__1__expected_value 
            = vlSelfRef.tb_fifo__DOT__expected_queue.pop_front();
        ++(vlSymsp->__Vcoverage[29]);
    } else {
        ++(vlSymsp->__Vcoverage[30]);
    }
    co_await vlSelfRef.__VtrigSched_h7211e072__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_fifo.clk)", 
                                                         "designs/fifo/reference/tb_fifo.sv", 
                                                         71);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(1ULL, nullptr, 
                                         "designs/fifo/reference/tb_fifo.sv", 
                                         72);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    if (VL_UNLIKELY(((IData)(__Vtask_tb_fifo__DOT__read_item__1__had_read) 
                     & ((IData)(__Vtask_tb_fifo__DOT__read_item__1__expected_value) 
                        != (IData)(vlSelfRef.tb_fifo__DOT__data_out))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_fifo.sv:74: Assertion failed in %Ntb_fifo.read_item: FAIL: read data mismatch: expected %0# got %0#\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                     8,(IData)(__Vtask_tb_fifo__DOT__read_item__1__expected_value),
                     8,vlSelfRef.tb_fifo__DOT__data_out);
        VL_STOP_MT("designs/fifo/reference/tb_fifo.sv", 74, "", false);
    } else {
        ++(vlSymsp->__Vcoverage[31]);
    }
    if (VL_UNLIKELY(((0U == (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__count)) 
                     != (0U == vlSelfRef.tb_fifo__DOT__expected_queue.size())))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_fifo.sv:36: Assertion failed in %Ntb_fifo.check_flags: FAIL: empty mismatch at time %0t\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                     64,VL_TIME_UNITED_Q(1),-12);
        VL_STOP_MT("designs/fifo/reference/tb_fifo.sv", 36, "", false);
    } else {
        ++(vlSymsp->__Vcoverage[23]);
    }
    if (VL_UNLIKELY(((4U == (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__count)) 
                     != (4U == vlSelfRef.tb_fifo__DOT__expected_queue.size())))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_fifo.sv:39: Assertion failed in %Ntb_fifo.check_flags: FAIL: full mismatch at time %0t\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                     64,VL_TIME_UNITED_Q(1),-12);
        VL_STOP_MT("designs/fifo/reference/tb_fifo.sv", 39, "", false);
    } else {
        ++(vlSymsp->__Vcoverage[24]);
    }
    vlSelfRef.tb_fifo__DOT__checks = ((IData)(1U) + vlSelfRef.tb_fifo__DOT__checks);
    ++(vlSymsp->__Vcoverage[25]);
    ++(vlSymsp->__Vcoverage[32]);
    __Vtask_tb_fifo__DOT__write_item__3__value = 0x11U;
    co_await vlSelfRef.__VtrigSched_h7211e033__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_fifo.clk)", 
                                                         "designs/fifo/reference/tb_fifo.sv", 
                                                         47);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.tb_fifo__DOT__wr_en = 1U;
    vlSelfRef.tb_fifo__DOT__rd_en = 0U;
    vlSelfRef.tb_fifo__DOT__data_in = __Vtask_tb_fifo__DOT__write_item__3__value;
    co_await vlSelfRef.__VtrigSched_h7211e072__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_fifo.clk)", 
                                                         "designs/fifo/reference/tb_fifo.sv", 
                                                         51);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(1ULL, nullptr, 
                                         "designs/fifo/reference/tb_fifo.sv", 
                                         52);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    if (VL_GTS_III(32, 4U, vlSelfRef.tb_fifo__DOT__expected_queue.size())) {
        vlSelfRef.tb_fifo__DOT__expected_queue.push_back(__Vtask_tb_fifo__DOT__write_item__3__value);
        ++(vlSymsp->__Vcoverage[26]);
    } else {
        ++(vlSymsp->__Vcoverage[27]);
    }
    if (VL_UNLIKELY(((0U == (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__count)) 
                     != (0U == vlSelfRef.tb_fifo__DOT__expected_queue.size())))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_fifo.sv:36: Assertion failed in %Ntb_fifo.check_flags: FAIL: empty mismatch at time %0t\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                     64,VL_TIME_UNITED_Q(1),-12);
        VL_STOP_MT("designs/fifo/reference/tb_fifo.sv", 36, "", false);
    } else {
        ++(vlSymsp->__Vcoverage[23]);
    }
    if (VL_UNLIKELY(((4U == (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__count)) 
                     != (4U == vlSelfRef.tb_fifo__DOT__expected_queue.size())))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_fifo.sv:39: Assertion failed in %Ntb_fifo.check_flags: FAIL: full mismatch at time %0t\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                     64,VL_TIME_UNITED_Q(1),-12);
        VL_STOP_MT("designs/fifo/reference/tb_fifo.sv", 39, "", false);
    } else {
        ++(vlSymsp->__Vcoverage[24]);
    }
    vlSelfRef.tb_fifo__DOT__checks = ((IData)(1U) + vlSelfRef.tb_fifo__DOT__checks);
    ++(vlSymsp->__Vcoverage[25]);
    ++(vlSymsp->__Vcoverage[28]);
    co_await vlSelfRef.__VtrigSched_h7211e033__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_fifo.clk)", 
                                                         "designs/fifo/reference/tb_fifo.sv", 
                                                         64);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.tb_fifo__DOT__wr_en = 0U;
    vlSelfRef.tb_fifo__DOT__rd_en = 1U;
    __Vtask_tb_fifo__DOT__read_item__5__had_read = 
        VL_LTS_III(32, 0U, vlSelfRef.tb_fifo__DOT__expected_queue.size());
    if (__Vtask_tb_fifo__DOT__read_item__5__had_read) {
        __Vtask_tb_fifo__DOT__read_item__5__expected_value 
            = vlSelfRef.tb_fifo__DOT__expected_queue.pop_front();
        ++(vlSymsp->__Vcoverage[29]);
    } else {
        ++(vlSymsp->__Vcoverage[30]);
    }
    co_await vlSelfRef.__VtrigSched_h7211e072__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_fifo.clk)", 
                                                         "designs/fifo/reference/tb_fifo.sv", 
                                                         71);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(1ULL, nullptr, 
                                         "designs/fifo/reference/tb_fifo.sv", 
                                         72);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    if (VL_UNLIKELY(((IData)(__Vtask_tb_fifo__DOT__read_item__5__had_read) 
                     & ((IData)(__Vtask_tb_fifo__DOT__read_item__5__expected_value) 
                        != (IData)(vlSelfRef.tb_fifo__DOT__data_out))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_fifo.sv:74: Assertion failed in %Ntb_fifo.read_item: FAIL: read data mismatch: expected %0# got %0#\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                     8,(IData)(__Vtask_tb_fifo__DOT__read_item__5__expected_value),
                     8,vlSelfRef.tb_fifo__DOT__data_out);
        VL_STOP_MT("designs/fifo/reference/tb_fifo.sv", 74, "", false);
    } else {
        ++(vlSymsp->__Vcoverage[31]);
    }
    if (VL_UNLIKELY(((0U == (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__count)) 
                     != (0U == vlSelfRef.tb_fifo__DOT__expected_queue.size())))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_fifo.sv:36: Assertion failed in %Ntb_fifo.check_flags: FAIL: empty mismatch at time %0t\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                     64,VL_TIME_UNITED_Q(1),-12);
        VL_STOP_MT("designs/fifo/reference/tb_fifo.sv", 36, "", false);
    } else {
        ++(vlSymsp->__Vcoverage[23]);
    }
    if (VL_UNLIKELY(((4U == (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__count)) 
                     != (4U == vlSelfRef.tb_fifo__DOT__expected_queue.size())))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_fifo.sv:39: Assertion failed in %Ntb_fifo.check_flags: FAIL: full mismatch at time %0t\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                     64,VL_TIME_UNITED_Q(1),-12);
        VL_STOP_MT("designs/fifo/reference/tb_fifo.sv", 39, "", false);
    } else {
        ++(vlSymsp->__Vcoverage[24]);
    }
    vlSelfRef.tb_fifo__DOT__checks = ((IData)(1U) + vlSelfRef.tb_fifo__DOT__checks);
    ++(vlSymsp->__Vcoverage[25]);
    ++(vlSymsp->__Vcoverage[32]);
    __Vtask_tb_fifo__DOT__write_item__7__value = 0x21U;
    co_await vlSelfRef.__VtrigSched_h7211e033__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_fifo.clk)", 
                                                         "designs/fifo/reference/tb_fifo.sv", 
                                                         47);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.tb_fifo__DOT__wr_en = 1U;
    vlSelfRef.tb_fifo__DOT__rd_en = 0U;
    vlSelfRef.tb_fifo__DOT__data_in = __Vtask_tb_fifo__DOT__write_item__7__value;
    co_await vlSelfRef.__VtrigSched_h7211e072__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_fifo.clk)", 
                                                         "designs/fifo/reference/tb_fifo.sv", 
                                                         51);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(1ULL, nullptr, 
                                         "designs/fifo/reference/tb_fifo.sv", 
                                         52);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    if (VL_GTS_III(32, 4U, vlSelfRef.tb_fifo__DOT__expected_queue.size())) {
        vlSelfRef.tb_fifo__DOT__expected_queue.push_back(__Vtask_tb_fifo__DOT__write_item__7__value);
        ++(vlSymsp->__Vcoverage[26]);
    } else {
        ++(vlSymsp->__Vcoverage[27]);
    }
    if (VL_UNLIKELY(((0U == (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__count)) 
                     != (0U == vlSelfRef.tb_fifo__DOT__expected_queue.size())))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_fifo.sv:36: Assertion failed in %Ntb_fifo.check_flags: FAIL: empty mismatch at time %0t\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                     64,VL_TIME_UNITED_Q(1),-12);
        VL_STOP_MT("designs/fifo/reference/tb_fifo.sv", 36, "", false);
    } else {
        ++(vlSymsp->__Vcoverage[23]);
    }
    if (VL_UNLIKELY(((4U == (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__count)) 
                     != (4U == vlSelfRef.tb_fifo__DOT__expected_queue.size())))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_fifo.sv:39: Assertion failed in %Ntb_fifo.check_flags: FAIL: full mismatch at time %0t\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                     64,VL_TIME_UNITED_Q(1),-12);
        VL_STOP_MT("designs/fifo/reference/tb_fifo.sv", 39, "", false);
    } else {
        ++(vlSymsp->__Vcoverage[24]);
    }
    vlSelfRef.tb_fifo__DOT__checks = ((IData)(1U) + vlSelfRef.tb_fifo__DOT__checks);
    ++(vlSymsp->__Vcoverage[25]);
    ++(vlSymsp->__Vcoverage[28]);
    __Vtask_tb_fifo__DOT__write_item__9__value = 0x22U;
    co_await vlSelfRef.__VtrigSched_h7211e033__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_fifo.clk)", 
                                                         "designs/fifo/reference/tb_fifo.sv", 
                                                         47);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.tb_fifo__DOT__wr_en = 1U;
    vlSelfRef.tb_fifo__DOT__rd_en = 0U;
    vlSelfRef.tb_fifo__DOT__data_in = __Vtask_tb_fifo__DOT__write_item__9__value;
    co_await vlSelfRef.__VtrigSched_h7211e072__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_fifo.clk)", 
                                                         "designs/fifo/reference/tb_fifo.sv", 
                                                         51);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(1ULL, nullptr, 
                                         "designs/fifo/reference/tb_fifo.sv", 
                                         52);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    if (VL_GTS_III(32, 4U, vlSelfRef.tb_fifo__DOT__expected_queue.size())) {
        vlSelfRef.tb_fifo__DOT__expected_queue.push_back(__Vtask_tb_fifo__DOT__write_item__9__value);
        ++(vlSymsp->__Vcoverage[26]);
    } else {
        ++(vlSymsp->__Vcoverage[27]);
    }
    if (VL_UNLIKELY(((0U == (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__count)) 
                     != (0U == vlSelfRef.tb_fifo__DOT__expected_queue.size())))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_fifo.sv:36: Assertion failed in %Ntb_fifo.check_flags: FAIL: empty mismatch at time %0t\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                     64,VL_TIME_UNITED_Q(1),-12);
        VL_STOP_MT("designs/fifo/reference/tb_fifo.sv", 36, "", false);
    } else {
        ++(vlSymsp->__Vcoverage[23]);
    }
    if (VL_UNLIKELY(((4U == (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__count)) 
                     != (4U == vlSelfRef.tb_fifo__DOT__expected_queue.size())))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_fifo.sv:39: Assertion failed in %Ntb_fifo.check_flags: FAIL: full mismatch at time %0t\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                     64,VL_TIME_UNITED_Q(1),-12);
        VL_STOP_MT("designs/fifo/reference/tb_fifo.sv", 39, "", false);
    } else {
        ++(vlSymsp->__Vcoverage[24]);
    }
    vlSelfRef.tb_fifo__DOT__checks = ((IData)(1U) + vlSelfRef.tb_fifo__DOT__checks);
    ++(vlSymsp->__Vcoverage[25]);
    ++(vlSymsp->__Vcoverage[28]);
    __Vtask_tb_fifo__DOT__write_item__11__value = 0x23U;
    co_await vlSelfRef.__VtrigSched_h7211e033__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_fifo.clk)", 
                                                         "designs/fifo/reference/tb_fifo.sv", 
                                                         47);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.tb_fifo__DOT__wr_en = 1U;
    vlSelfRef.tb_fifo__DOT__rd_en = 0U;
    vlSelfRef.tb_fifo__DOT__data_in = __Vtask_tb_fifo__DOT__write_item__11__value;
    co_await vlSelfRef.__VtrigSched_h7211e072__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_fifo.clk)", 
                                                         "designs/fifo/reference/tb_fifo.sv", 
                                                         51);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(1ULL, nullptr, 
                                         "designs/fifo/reference/tb_fifo.sv", 
                                         52);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    if (VL_GTS_III(32, 4U, vlSelfRef.tb_fifo__DOT__expected_queue.size())) {
        vlSelfRef.tb_fifo__DOT__expected_queue.push_back(__Vtask_tb_fifo__DOT__write_item__11__value);
        ++(vlSymsp->__Vcoverage[26]);
    } else {
        ++(vlSymsp->__Vcoverage[27]);
    }
    if (VL_UNLIKELY(((0U == (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__count)) 
                     != (0U == vlSelfRef.tb_fifo__DOT__expected_queue.size())))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_fifo.sv:36: Assertion failed in %Ntb_fifo.check_flags: FAIL: empty mismatch at time %0t\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                     64,VL_TIME_UNITED_Q(1),-12);
        VL_STOP_MT("designs/fifo/reference/tb_fifo.sv", 36, "", false);
    } else {
        ++(vlSymsp->__Vcoverage[23]);
    }
    if (VL_UNLIKELY(((4U == (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__count)) 
                     != (4U == vlSelfRef.tb_fifo__DOT__expected_queue.size())))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_fifo.sv:39: Assertion failed in %Ntb_fifo.check_flags: FAIL: full mismatch at time %0t\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                     64,VL_TIME_UNITED_Q(1),-12);
        VL_STOP_MT("designs/fifo/reference/tb_fifo.sv", 39, "", false);
    } else {
        ++(vlSymsp->__Vcoverage[24]);
    }
    vlSelfRef.tb_fifo__DOT__checks = ((IData)(1U) + vlSelfRef.tb_fifo__DOT__checks);
    ++(vlSymsp->__Vcoverage[25]);
    ++(vlSymsp->__Vcoverage[28]);
    __Vtask_tb_fifo__DOT__write_item__13__value = 0x24U;
    co_await vlSelfRef.__VtrigSched_h7211e033__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_fifo.clk)", 
                                                         "designs/fifo/reference/tb_fifo.sv", 
                                                         47);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.tb_fifo__DOT__wr_en = 1U;
    vlSelfRef.tb_fifo__DOT__rd_en = 0U;
    vlSelfRef.tb_fifo__DOT__data_in = __Vtask_tb_fifo__DOT__write_item__13__value;
    co_await vlSelfRef.__VtrigSched_h7211e072__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_fifo.clk)", 
                                                         "designs/fifo/reference/tb_fifo.sv", 
                                                         51);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(1ULL, nullptr, 
                                         "designs/fifo/reference/tb_fifo.sv", 
                                         52);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    if (VL_GTS_III(32, 4U, vlSelfRef.tb_fifo__DOT__expected_queue.size())) {
        vlSelfRef.tb_fifo__DOT__expected_queue.push_back(__Vtask_tb_fifo__DOT__write_item__13__value);
        ++(vlSymsp->__Vcoverage[26]);
    } else {
        ++(vlSymsp->__Vcoverage[27]);
    }
    if (VL_UNLIKELY(((0U == (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__count)) 
                     != (0U == vlSelfRef.tb_fifo__DOT__expected_queue.size())))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_fifo.sv:36: Assertion failed in %Ntb_fifo.check_flags: FAIL: empty mismatch at time %0t\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                     64,VL_TIME_UNITED_Q(1),-12);
        VL_STOP_MT("designs/fifo/reference/tb_fifo.sv", 36, "", false);
    } else {
        ++(vlSymsp->__Vcoverage[23]);
    }
    if (VL_UNLIKELY(((4U == (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__count)) 
                     != (4U == vlSelfRef.tb_fifo__DOT__expected_queue.size())))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_fifo.sv:39: Assertion failed in %Ntb_fifo.check_flags: FAIL: full mismatch at time %0t\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                     64,VL_TIME_UNITED_Q(1),-12);
        VL_STOP_MT("designs/fifo/reference/tb_fifo.sv", 39, "", false);
    } else {
        ++(vlSymsp->__Vcoverage[24]);
    }
    vlSelfRef.tb_fifo__DOT__checks = ((IData)(1U) + vlSelfRef.tb_fifo__DOT__checks);
    ++(vlSymsp->__Vcoverage[25]);
    ++(vlSymsp->__Vcoverage[28]);
    if (VL_LIKELY((4U == (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__count)))) {
        ++(vlSymsp->__Vcoverage[40]);
    } else {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_fifo.sv:138: Assertion failed in %Ntb_fifo: FAIL: FIFO did not become full\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("designs/fifo/reference/tb_fifo.sv", 138, "", false);
    }
    __Vtask_tb_fifo__DOT__write_item__15__value = 0xffU;
    co_await vlSelfRef.__VtrigSched_h7211e033__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_fifo.clk)", 
                                                         "designs/fifo/reference/tb_fifo.sv", 
                                                         47);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.tb_fifo__DOT__wr_en = 1U;
    vlSelfRef.tb_fifo__DOT__rd_en = 0U;
    vlSelfRef.tb_fifo__DOT__data_in = __Vtask_tb_fifo__DOT__write_item__15__value;
    co_await vlSelfRef.__VtrigSched_h7211e072__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_fifo.clk)", 
                                                         "designs/fifo/reference/tb_fifo.sv", 
                                                         51);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(1ULL, nullptr, 
                                         "designs/fifo/reference/tb_fifo.sv", 
                                         52);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    if (VL_GTS_III(32, 4U, vlSelfRef.tb_fifo__DOT__expected_queue.size())) {
        vlSelfRef.tb_fifo__DOT__expected_queue.push_back(__Vtask_tb_fifo__DOT__write_item__15__value);
        ++(vlSymsp->__Vcoverage[26]);
    } else {
        ++(vlSymsp->__Vcoverage[27]);
    }
    if (VL_UNLIKELY(((0U == (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__count)) 
                     != (0U == vlSelfRef.tb_fifo__DOT__expected_queue.size())))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_fifo.sv:36: Assertion failed in %Ntb_fifo.check_flags: FAIL: empty mismatch at time %0t\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                     64,VL_TIME_UNITED_Q(1),-12);
        VL_STOP_MT("designs/fifo/reference/tb_fifo.sv", 36, "", false);
    } else {
        ++(vlSymsp->__Vcoverage[23]);
    }
    if (VL_UNLIKELY(((4U == (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__count)) 
                     != (4U == vlSelfRef.tb_fifo__DOT__expected_queue.size())))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_fifo.sv:39: Assertion failed in %Ntb_fifo.check_flags: FAIL: full mismatch at time %0t\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                     64,VL_TIME_UNITED_Q(1),-12);
        VL_STOP_MT("designs/fifo/reference/tb_fifo.sv", 39, "", false);
    } else {
        ++(vlSymsp->__Vcoverage[24]);
    }
    vlSelfRef.tb_fifo__DOT__checks = ((IData)(1U) + vlSelfRef.tb_fifo__DOT__checks);
    ++(vlSymsp->__Vcoverage[25]);
    ++(vlSymsp->__Vcoverage[28]);
    co_await vlSelfRef.__VtrigSched_h7211e033__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_fifo.clk)", 
                                                         "designs/fifo/reference/tb_fifo.sv", 
                                                         64);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.tb_fifo__DOT__wr_en = 0U;
    vlSelfRef.tb_fifo__DOT__rd_en = 1U;
    __Vtask_tb_fifo__DOT__read_item__17__had_read = 
        VL_LTS_III(32, 0U, vlSelfRef.tb_fifo__DOT__expected_queue.size());
    if (__Vtask_tb_fifo__DOT__read_item__17__had_read) {
        __Vtask_tb_fifo__DOT__read_item__17__expected_value 
            = vlSelfRef.tb_fifo__DOT__expected_queue.pop_front();
        ++(vlSymsp->__Vcoverage[29]);
    } else {
        ++(vlSymsp->__Vcoverage[30]);
    }
    co_await vlSelfRef.__VtrigSched_h7211e072__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_fifo.clk)", 
                                                         "designs/fifo/reference/tb_fifo.sv", 
                                                         71);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(1ULL, nullptr, 
                                         "designs/fifo/reference/tb_fifo.sv", 
                                         72);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    if (VL_UNLIKELY(((IData)(__Vtask_tb_fifo__DOT__read_item__17__had_read) 
                     & ((IData)(__Vtask_tb_fifo__DOT__read_item__17__expected_value) 
                        != (IData)(vlSelfRef.tb_fifo__DOT__data_out))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_fifo.sv:74: Assertion failed in %Ntb_fifo.read_item: FAIL: read data mismatch: expected %0# got %0#\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                     8,(IData)(__Vtask_tb_fifo__DOT__read_item__17__expected_value),
                     8,vlSelfRef.tb_fifo__DOT__data_out);
        VL_STOP_MT("designs/fifo/reference/tb_fifo.sv", 74, "", false);
    } else {
        ++(vlSymsp->__Vcoverage[31]);
    }
    if (VL_UNLIKELY(((0U == (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__count)) 
                     != (0U == vlSelfRef.tb_fifo__DOT__expected_queue.size())))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_fifo.sv:36: Assertion failed in %Ntb_fifo.check_flags: FAIL: empty mismatch at time %0t\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                     64,VL_TIME_UNITED_Q(1),-12);
        VL_STOP_MT("designs/fifo/reference/tb_fifo.sv", 36, "", false);
    } else {
        ++(vlSymsp->__Vcoverage[23]);
    }
    if (VL_UNLIKELY(((4U == (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__count)) 
                     != (4U == vlSelfRef.tb_fifo__DOT__expected_queue.size())))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_fifo.sv:39: Assertion failed in %Ntb_fifo.check_flags: FAIL: full mismatch at time %0t\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                     64,VL_TIME_UNITED_Q(1),-12);
        VL_STOP_MT("designs/fifo/reference/tb_fifo.sv", 39, "", false);
    } else {
        ++(vlSymsp->__Vcoverage[24]);
    }
    vlSelfRef.tb_fifo__DOT__checks = ((IData)(1U) + vlSelfRef.tb_fifo__DOT__checks);
    ++(vlSymsp->__Vcoverage[25]);
    ++(vlSymsp->__Vcoverage[32]);
    co_await vlSelfRef.__VtrigSched_h7211e033__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_fifo.clk)", 
                                                         "designs/fifo/reference/tb_fifo.sv", 
                                                         64);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.tb_fifo__DOT__wr_en = 0U;
    vlSelfRef.tb_fifo__DOT__rd_en = 1U;
    __Vtask_tb_fifo__DOT__read_item__19__had_read = 
        VL_LTS_III(32, 0U, vlSelfRef.tb_fifo__DOT__expected_queue.size());
    if (__Vtask_tb_fifo__DOT__read_item__19__had_read) {
        __Vtask_tb_fifo__DOT__read_item__19__expected_value 
            = vlSelfRef.tb_fifo__DOT__expected_queue.pop_front();
        ++(vlSymsp->__Vcoverage[29]);
    } else {
        ++(vlSymsp->__Vcoverage[30]);
    }
    co_await vlSelfRef.__VtrigSched_h7211e072__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_fifo.clk)", 
                                                         "designs/fifo/reference/tb_fifo.sv", 
                                                         71);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(1ULL, nullptr, 
                                         "designs/fifo/reference/tb_fifo.sv", 
                                         72);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    if (VL_UNLIKELY(((IData)(__Vtask_tb_fifo__DOT__read_item__19__had_read) 
                     & ((IData)(__Vtask_tb_fifo__DOT__read_item__19__expected_value) 
                        != (IData)(vlSelfRef.tb_fifo__DOT__data_out))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_fifo.sv:74: Assertion failed in %Ntb_fifo.read_item: FAIL: read data mismatch: expected %0# got %0#\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                     8,(IData)(__Vtask_tb_fifo__DOT__read_item__19__expected_value),
                     8,vlSelfRef.tb_fifo__DOT__data_out);
        VL_STOP_MT("designs/fifo/reference/tb_fifo.sv", 74, "", false);
    } else {
        ++(vlSymsp->__Vcoverage[31]);
    }
    if (VL_UNLIKELY(((0U == (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__count)) 
                     != (0U == vlSelfRef.tb_fifo__DOT__expected_queue.size())))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_fifo.sv:36: Assertion failed in %Ntb_fifo.check_flags: FAIL: empty mismatch at time %0t\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                     64,VL_TIME_UNITED_Q(1),-12);
        VL_STOP_MT("designs/fifo/reference/tb_fifo.sv", 36, "", false);
    } else {
        ++(vlSymsp->__Vcoverage[23]);
    }
    if (VL_UNLIKELY(((4U == (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__count)) 
                     != (4U == vlSelfRef.tb_fifo__DOT__expected_queue.size())))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_fifo.sv:39: Assertion failed in %Ntb_fifo.check_flags: FAIL: full mismatch at time %0t\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                     64,VL_TIME_UNITED_Q(1),-12);
        VL_STOP_MT("designs/fifo/reference/tb_fifo.sv", 39, "", false);
    } else {
        ++(vlSymsp->__Vcoverage[24]);
    }
    vlSelfRef.tb_fifo__DOT__checks = ((IData)(1U) + vlSelfRef.tb_fifo__DOT__checks);
    ++(vlSymsp->__Vcoverage[25]);
    ++(vlSymsp->__Vcoverage[32]);
    co_await vlSelfRef.__VtrigSched_h7211e033__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_fifo.clk)", 
                                                         "designs/fifo/reference/tb_fifo.sv", 
                                                         64);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.tb_fifo__DOT__wr_en = 0U;
    vlSelfRef.tb_fifo__DOT__rd_en = 1U;
    __Vtask_tb_fifo__DOT__read_item__21__had_read = 
        VL_LTS_III(32, 0U, vlSelfRef.tb_fifo__DOT__expected_queue.size());
    if (__Vtask_tb_fifo__DOT__read_item__21__had_read) {
        __Vtask_tb_fifo__DOT__read_item__21__expected_value 
            = vlSelfRef.tb_fifo__DOT__expected_queue.pop_front();
        ++(vlSymsp->__Vcoverage[29]);
    } else {
        ++(vlSymsp->__Vcoverage[30]);
    }
    co_await vlSelfRef.__VtrigSched_h7211e072__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_fifo.clk)", 
                                                         "designs/fifo/reference/tb_fifo.sv", 
                                                         71);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(1ULL, nullptr, 
                                         "designs/fifo/reference/tb_fifo.sv", 
                                         72);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    if (VL_UNLIKELY(((IData)(__Vtask_tb_fifo__DOT__read_item__21__had_read) 
                     & ((IData)(__Vtask_tb_fifo__DOT__read_item__21__expected_value) 
                        != (IData)(vlSelfRef.tb_fifo__DOT__data_out))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_fifo.sv:74: Assertion failed in %Ntb_fifo.read_item: FAIL: read data mismatch: expected %0# got %0#\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                     8,(IData)(__Vtask_tb_fifo__DOT__read_item__21__expected_value),
                     8,vlSelfRef.tb_fifo__DOT__data_out);
        VL_STOP_MT("designs/fifo/reference/tb_fifo.sv", 74, "", false);
    } else {
        ++(vlSymsp->__Vcoverage[31]);
    }
    if (VL_UNLIKELY(((0U == (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__count)) 
                     != (0U == vlSelfRef.tb_fifo__DOT__expected_queue.size())))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_fifo.sv:36: Assertion failed in %Ntb_fifo.check_flags: FAIL: empty mismatch at time %0t\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                     64,VL_TIME_UNITED_Q(1),-12);
        VL_STOP_MT("designs/fifo/reference/tb_fifo.sv", 36, "", false);
    } else {
        ++(vlSymsp->__Vcoverage[23]);
    }
    if (VL_UNLIKELY(((4U == (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__count)) 
                     != (4U == vlSelfRef.tb_fifo__DOT__expected_queue.size())))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_fifo.sv:39: Assertion failed in %Ntb_fifo.check_flags: FAIL: full mismatch at time %0t\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                     64,VL_TIME_UNITED_Q(1),-12);
        VL_STOP_MT("designs/fifo/reference/tb_fifo.sv", 39, "", false);
    } else {
        ++(vlSymsp->__Vcoverage[24]);
    }
    vlSelfRef.tb_fifo__DOT__checks = ((IData)(1U) + vlSelfRef.tb_fifo__DOT__checks);
    ++(vlSymsp->__Vcoverage[25]);
    ++(vlSymsp->__Vcoverage[32]);
    co_await vlSelfRef.__VtrigSched_h7211e033__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_fifo.clk)", 
                                                         "designs/fifo/reference/tb_fifo.sv", 
                                                         64);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.tb_fifo__DOT__wr_en = 0U;
    vlSelfRef.tb_fifo__DOT__rd_en = 1U;
    __Vtask_tb_fifo__DOT__read_item__23__had_read = 
        VL_LTS_III(32, 0U, vlSelfRef.tb_fifo__DOT__expected_queue.size());
    if (__Vtask_tb_fifo__DOT__read_item__23__had_read) {
        __Vtask_tb_fifo__DOT__read_item__23__expected_value 
            = vlSelfRef.tb_fifo__DOT__expected_queue.pop_front();
        ++(vlSymsp->__Vcoverage[29]);
    } else {
        ++(vlSymsp->__Vcoverage[30]);
    }
    co_await vlSelfRef.__VtrigSched_h7211e072__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_fifo.clk)", 
                                                         "designs/fifo/reference/tb_fifo.sv", 
                                                         71);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(1ULL, nullptr, 
                                         "designs/fifo/reference/tb_fifo.sv", 
                                         72);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    if (VL_UNLIKELY(((IData)(__Vtask_tb_fifo__DOT__read_item__23__had_read) 
                     & ((IData)(__Vtask_tb_fifo__DOT__read_item__23__expected_value) 
                        != (IData)(vlSelfRef.tb_fifo__DOT__data_out))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_fifo.sv:74: Assertion failed in %Ntb_fifo.read_item: FAIL: read data mismatch: expected %0# got %0#\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                     8,(IData)(__Vtask_tb_fifo__DOT__read_item__23__expected_value),
                     8,vlSelfRef.tb_fifo__DOT__data_out);
        VL_STOP_MT("designs/fifo/reference/tb_fifo.sv", 74, "", false);
    } else {
        ++(vlSymsp->__Vcoverage[31]);
    }
    if (VL_UNLIKELY(((0U == (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__count)) 
                     != (0U == vlSelfRef.tb_fifo__DOT__expected_queue.size())))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_fifo.sv:36: Assertion failed in %Ntb_fifo.check_flags: FAIL: empty mismatch at time %0t\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                     64,VL_TIME_UNITED_Q(1),-12);
        VL_STOP_MT("designs/fifo/reference/tb_fifo.sv", 36, "", false);
    } else {
        ++(vlSymsp->__Vcoverage[23]);
    }
    if (VL_UNLIKELY(((4U == (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__count)) 
                     != (4U == vlSelfRef.tb_fifo__DOT__expected_queue.size())))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_fifo.sv:39: Assertion failed in %Ntb_fifo.check_flags: FAIL: full mismatch at time %0t\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                     64,VL_TIME_UNITED_Q(1),-12);
        VL_STOP_MT("designs/fifo/reference/tb_fifo.sv", 39, "", false);
    } else {
        ++(vlSymsp->__Vcoverage[24]);
    }
    vlSelfRef.tb_fifo__DOT__checks = ((IData)(1U) + vlSelfRef.tb_fifo__DOT__checks);
    ++(vlSymsp->__Vcoverage[25]);
    ++(vlSymsp->__Vcoverage[32]);
    if (VL_LIKELY((0U == (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__count)))) {
        ++(vlSymsp->__Vcoverage[41]);
    } else {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_fifo.sv:150: Assertion failed in %Ntb_fifo: FAIL: FIFO did not become empty\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("designs/fifo/reference/tb_fifo.sv", 150, "", false);
    }
    __Vtask_tb_fifo__DOT__write_item__25__value = 0xa1U;
    co_await vlSelfRef.__VtrigSched_h7211e033__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_fifo.clk)", 
                                                         "designs/fifo/reference/tb_fifo.sv", 
                                                         47);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.tb_fifo__DOT__wr_en = 1U;
    vlSelfRef.tb_fifo__DOT__rd_en = 0U;
    vlSelfRef.tb_fifo__DOT__data_in = __Vtask_tb_fifo__DOT__write_item__25__value;
    co_await vlSelfRef.__VtrigSched_h7211e072__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_fifo.clk)", 
                                                         "designs/fifo/reference/tb_fifo.sv", 
                                                         51);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(1ULL, nullptr, 
                                         "designs/fifo/reference/tb_fifo.sv", 
                                         52);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    if (VL_GTS_III(32, 4U, vlSelfRef.tb_fifo__DOT__expected_queue.size())) {
        vlSelfRef.tb_fifo__DOT__expected_queue.push_back(__Vtask_tb_fifo__DOT__write_item__25__value);
        ++(vlSymsp->__Vcoverage[26]);
    } else {
        ++(vlSymsp->__Vcoverage[27]);
    }
    if (VL_UNLIKELY(((0U == (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__count)) 
                     != (0U == vlSelfRef.tb_fifo__DOT__expected_queue.size())))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_fifo.sv:36: Assertion failed in %Ntb_fifo.check_flags: FAIL: empty mismatch at time %0t\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                     64,VL_TIME_UNITED_Q(1),-12);
        VL_STOP_MT("designs/fifo/reference/tb_fifo.sv", 36, "", false);
    } else {
        ++(vlSymsp->__Vcoverage[23]);
    }
    if (VL_UNLIKELY(((4U == (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__count)) 
                     != (4U == vlSelfRef.tb_fifo__DOT__expected_queue.size())))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_fifo.sv:39: Assertion failed in %Ntb_fifo.check_flags: FAIL: full mismatch at time %0t\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                     64,VL_TIME_UNITED_Q(1),-12);
        VL_STOP_MT("designs/fifo/reference/tb_fifo.sv", 39, "", false);
    } else {
        ++(vlSymsp->__Vcoverage[24]);
    }
    vlSelfRef.tb_fifo__DOT__checks = ((IData)(1U) + vlSelfRef.tb_fifo__DOT__checks);
    ++(vlSymsp->__Vcoverage[25]);
    ++(vlSymsp->__Vcoverage[28]);
    __Vtask_tb_fifo__DOT__write_item__27__value = 0xa2U;
    co_await vlSelfRef.__VtrigSched_h7211e033__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_fifo.clk)", 
                                                         "designs/fifo/reference/tb_fifo.sv", 
                                                         47);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.tb_fifo__DOT__wr_en = 1U;
    vlSelfRef.tb_fifo__DOT__rd_en = 0U;
    vlSelfRef.tb_fifo__DOT__data_in = __Vtask_tb_fifo__DOT__write_item__27__value;
    co_await vlSelfRef.__VtrigSched_h7211e072__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_fifo.clk)", 
                                                         "designs/fifo/reference/tb_fifo.sv", 
                                                         51);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(1ULL, nullptr, 
                                         "designs/fifo/reference/tb_fifo.sv", 
                                         52);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    if (VL_GTS_III(32, 4U, vlSelfRef.tb_fifo__DOT__expected_queue.size())) {
        vlSelfRef.tb_fifo__DOT__expected_queue.push_back(__Vtask_tb_fifo__DOT__write_item__27__value);
        ++(vlSymsp->__Vcoverage[26]);
    } else {
        ++(vlSymsp->__Vcoverage[27]);
    }
    if (VL_UNLIKELY(((0U == (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__count)) 
                     != (0U == vlSelfRef.tb_fifo__DOT__expected_queue.size())))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_fifo.sv:36: Assertion failed in %Ntb_fifo.check_flags: FAIL: empty mismatch at time %0t\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                     64,VL_TIME_UNITED_Q(1),-12);
        VL_STOP_MT("designs/fifo/reference/tb_fifo.sv", 36, "", false);
    } else {
        ++(vlSymsp->__Vcoverage[23]);
    }
    if (VL_UNLIKELY(((4U == (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__count)) 
                     != (4U == vlSelfRef.tb_fifo__DOT__expected_queue.size())))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_fifo.sv:39: Assertion failed in %Ntb_fifo.check_flags: FAIL: full mismatch at time %0t\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                     64,VL_TIME_UNITED_Q(1),-12);
        VL_STOP_MT("designs/fifo/reference/tb_fifo.sv", 39, "", false);
    } else {
        ++(vlSymsp->__Vcoverage[24]);
    }
    vlSelfRef.tb_fifo__DOT__checks = ((IData)(1U) + vlSelfRef.tb_fifo__DOT__checks);
    ++(vlSymsp->__Vcoverage[25]);
    ++(vlSymsp->__Vcoverage[28]);
    __Vtask_tb_fifo__DOT__simultaneous_item__29__value = 0xa3U;
    co_await vlSelfRef.__VtrigSched_h7211e033__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_fifo.clk)", 
                                                         "designs/fifo/reference/tb_fifo.sv", 
                                                         87);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.tb_fifo__DOT__wr_en = 1U;
    vlSelfRef.tb_fifo__DOT__rd_en = 1U;
    vlSelfRef.tb_fifo__DOT__data_in = __Vtask_tb_fifo__DOT__simultaneous_item__29__value;
    __Vtask_tb_fifo__DOT__simultaneous_item__29__had_read 
        = VL_LTS_III(32, 0U, vlSelfRef.tb_fifo__DOT__expected_queue.size());
    __Vtask_tb_fifo__DOT__simultaneous_item__29__had_write 
        = VL_GTS_III(32, 4U, vlSelfRef.tb_fifo__DOT__expected_queue.size());
    if (__Vtask_tb_fifo__DOT__simultaneous_item__29__had_read) {
        __Vtask_tb_fifo__DOT__simultaneous_item__29__expected_value 
            = vlSelfRef.tb_fifo__DOT__expected_queue.pop_front();
        ++(vlSymsp->__Vcoverage[33]);
    } else {
        ++(vlSymsp->__Vcoverage[34]);
    }
    if (__Vtask_tb_fifo__DOT__simultaneous_item__29__had_write) {
        vlSelfRef.tb_fifo__DOT__expected_queue.push_back(__Vtask_tb_fifo__DOT__simultaneous_item__29__value);
        ++(vlSymsp->__Vcoverage[35]);
    } else {
        ++(vlSymsp->__Vcoverage[36]);
    }
    co_await vlSelfRef.__VtrigSched_h7211e072__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_fifo.clk)", 
                                                         "designs/fifo/reference/tb_fifo.sv", 
                                                         99);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(1ULL, nullptr, 
                                         "designs/fifo/reference/tb_fifo.sv", 
                                         100);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    if (VL_UNLIKELY(((IData)(__Vtask_tb_fifo__DOT__simultaneous_item__29__had_read) 
                     & ((IData)(__Vtask_tb_fifo__DOT__simultaneous_item__29__expected_value) 
                        != (IData)(vlSelfRef.tb_fifo__DOT__data_out))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_fifo.sv:102: Assertion failed in %Ntb_fifo.simultaneous_item: FAIL: simultaneous read mismatch: expected %0# got %0#\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                     8,(IData)(__Vtask_tb_fifo__DOT__simultaneous_item__29__expected_value),
                     8,vlSelfRef.tb_fifo__DOT__data_out);
        VL_STOP_MT("designs/fifo/reference/tb_fifo.sv", 102, "", false);
    } else {
        ++(vlSymsp->__Vcoverage[37]);
    }
    if (VL_UNLIKELY(((0U == (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__count)) 
                     != (0U == vlSelfRef.tb_fifo__DOT__expected_queue.size())))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_fifo.sv:36: Assertion failed in %Ntb_fifo.check_flags: FAIL: empty mismatch at time %0t\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                     64,VL_TIME_UNITED_Q(1),-12);
        VL_STOP_MT("designs/fifo/reference/tb_fifo.sv", 36, "", false);
    } else {
        ++(vlSymsp->__Vcoverage[23]);
    }
    if (VL_UNLIKELY(((4U == (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__count)) 
                     != (4U == vlSelfRef.tb_fifo__DOT__expected_queue.size())))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_fifo.sv:39: Assertion failed in %Ntb_fifo.check_flags: FAIL: full mismatch at time %0t\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                     64,VL_TIME_UNITED_Q(1),-12);
        VL_STOP_MT("designs/fifo/reference/tb_fifo.sv", 39, "", false);
    } else {
        ++(vlSymsp->__Vcoverage[24]);
    }
    vlSelfRef.tb_fifo__DOT__checks = ((IData)(1U) + vlSelfRef.tb_fifo__DOT__checks);
    ++(vlSymsp->__Vcoverage[25]);
    ++(vlSymsp->__Vcoverage[38]);
    co_await vlSelfRef.__VtrigSched_h7211e033__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_fifo.clk)", 
                                                         "designs/fifo/reference/tb_fifo.sv", 
                                                         64);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.tb_fifo__DOT__wr_en = 0U;
    vlSelfRef.tb_fifo__DOT__rd_en = 1U;
    __Vtask_tb_fifo__DOT__read_item__31__had_read = 
        VL_LTS_III(32, 0U, vlSelfRef.tb_fifo__DOT__expected_queue.size());
    if (__Vtask_tb_fifo__DOT__read_item__31__had_read) {
        __Vtask_tb_fifo__DOT__read_item__31__expected_value 
            = vlSelfRef.tb_fifo__DOT__expected_queue.pop_front();
        ++(vlSymsp->__Vcoverage[29]);
    } else {
        ++(vlSymsp->__Vcoverage[30]);
    }
    co_await vlSelfRef.__VtrigSched_h7211e072__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_fifo.clk)", 
                                                         "designs/fifo/reference/tb_fifo.sv", 
                                                         71);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(1ULL, nullptr, 
                                         "designs/fifo/reference/tb_fifo.sv", 
                                         72);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    if (VL_UNLIKELY(((IData)(__Vtask_tb_fifo__DOT__read_item__31__had_read) 
                     & ((IData)(__Vtask_tb_fifo__DOT__read_item__31__expected_value) 
                        != (IData)(vlSelfRef.tb_fifo__DOT__data_out))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_fifo.sv:74: Assertion failed in %Ntb_fifo.read_item: FAIL: read data mismatch: expected %0# got %0#\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                     8,(IData)(__Vtask_tb_fifo__DOT__read_item__31__expected_value),
                     8,vlSelfRef.tb_fifo__DOT__data_out);
        VL_STOP_MT("designs/fifo/reference/tb_fifo.sv", 74, "", false);
    } else {
        ++(vlSymsp->__Vcoverage[31]);
    }
    if (VL_UNLIKELY(((0U == (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__count)) 
                     != (0U == vlSelfRef.tb_fifo__DOT__expected_queue.size())))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_fifo.sv:36: Assertion failed in %Ntb_fifo.check_flags: FAIL: empty mismatch at time %0t\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                     64,VL_TIME_UNITED_Q(1),-12);
        VL_STOP_MT("designs/fifo/reference/tb_fifo.sv", 36, "", false);
    } else {
        ++(vlSymsp->__Vcoverage[23]);
    }
    if (VL_UNLIKELY(((4U == (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__count)) 
                     != (4U == vlSelfRef.tb_fifo__DOT__expected_queue.size())))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_fifo.sv:39: Assertion failed in %Ntb_fifo.check_flags: FAIL: full mismatch at time %0t\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                     64,VL_TIME_UNITED_Q(1),-12);
        VL_STOP_MT("designs/fifo/reference/tb_fifo.sv", 39, "", false);
    } else {
        ++(vlSymsp->__Vcoverage[24]);
    }
    vlSelfRef.tb_fifo__DOT__checks = ((IData)(1U) + vlSelfRef.tb_fifo__DOT__checks);
    ++(vlSymsp->__Vcoverage[25]);
    ++(vlSymsp->__Vcoverage[32]);
    co_await vlSelfRef.__VtrigSched_h7211e033__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_fifo.clk)", 
                                                         "designs/fifo/reference/tb_fifo.sv", 
                                                         64);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.tb_fifo__DOT__wr_en = 0U;
    vlSelfRef.tb_fifo__DOT__rd_en = 1U;
    __Vtask_tb_fifo__DOT__read_item__33__had_read = 
        VL_LTS_III(32, 0U, vlSelfRef.tb_fifo__DOT__expected_queue.size());
    if (__Vtask_tb_fifo__DOT__read_item__33__had_read) {
        __Vtask_tb_fifo__DOT__read_item__33__expected_value 
            = vlSelfRef.tb_fifo__DOT__expected_queue.pop_front();
        ++(vlSymsp->__Vcoverage[29]);
    } else {
        ++(vlSymsp->__Vcoverage[30]);
    }
    co_await vlSelfRef.__VtrigSched_h7211e072__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_fifo.clk)", 
                                                         "designs/fifo/reference/tb_fifo.sv", 
                                                         71);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(1ULL, nullptr, 
                                         "designs/fifo/reference/tb_fifo.sv", 
                                         72);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    if (VL_UNLIKELY(((IData)(__Vtask_tb_fifo__DOT__read_item__33__had_read) 
                     & ((IData)(__Vtask_tb_fifo__DOT__read_item__33__expected_value) 
                        != (IData)(vlSelfRef.tb_fifo__DOT__data_out))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_fifo.sv:74: Assertion failed in %Ntb_fifo.read_item: FAIL: read data mismatch: expected %0# got %0#\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                     8,(IData)(__Vtask_tb_fifo__DOT__read_item__33__expected_value),
                     8,vlSelfRef.tb_fifo__DOT__data_out);
        VL_STOP_MT("designs/fifo/reference/tb_fifo.sv", 74, "", false);
    } else {
        ++(vlSymsp->__Vcoverage[31]);
    }
    if (VL_UNLIKELY(((0U == (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__count)) 
                     != (0U == vlSelfRef.tb_fifo__DOT__expected_queue.size())))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_fifo.sv:36: Assertion failed in %Ntb_fifo.check_flags: FAIL: empty mismatch at time %0t\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                     64,VL_TIME_UNITED_Q(1),-12);
        VL_STOP_MT("designs/fifo/reference/tb_fifo.sv", 36, "", false);
    } else {
        ++(vlSymsp->__Vcoverage[23]);
    }
    if (VL_UNLIKELY(((4U == (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__count)) 
                     != (4U == vlSelfRef.tb_fifo__DOT__expected_queue.size())))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_fifo.sv:39: Assertion failed in %Ntb_fifo.check_flags: FAIL: full mismatch at time %0t\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                     64,VL_TIME_UNITED_Q(1),-12);
        VL_STOP_MT("designs/fifo/reference/tb_fifo.sv", 39, "", false);
    } else {
        ++(vlSymsp->__Vcoverage[24]);
    }
    vlSelfRef.tb_fifo__DOT__checks = ((IData)(1U) + vlSelfRef.tb_fifo__DOT__checks);
    ++(vlSymsp->__Vcoverage[25]);
    ++(vlSymsp->__Vcoverage[32]);
    __Vtask_tb_fifo__DOT__write_item__35__value = 0x55U;
    co_await vlSelfRef.__VtrigSched_h7211e033__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_fifo.clk)", 
                                                         "designs/fifo/reference/tb_fifo.sv", 
                                                         47);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.tb_fifo__DOT__wr_en = 1U;
    vlSelfRef.tb_fifo__DOT__rd_en = 0U;
    vlSelfRef.tb_fifo__DOT__data_in = __Vtask_tb_fifo__DOT__write_item__35__value;
    co_await vlSelfRef.__VtrigSched_h7211e072__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_fifo.clk)", 
                                                         "designs/fifo/reference/tb_fifo.sv", 
                                                         51);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(1ULL, nullptr, 
                                         "designs/fifo/reference/tb_fifo.sv", 
                                         52);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    if (VL_GTS_III(32, 4U, vlSelfRef.tb_fifo__DOT__expected_queue.size())) {
        vlSelfRef.tb_fifo__DOT__expected_queue.push_back(__Vtask_tb_fifo__DOT__write_item__35__value);
        ++(vlSymsp->__Vcoverage[26]);
    } else {
        ++(vlSymsp->__Vcoverage[27]);
    }
    if (VL_UNLIKELY(((0U == (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__count)) 
                     != (0U == vlSelfRef.tb_fifo__DOT__expected_queue.size())))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_fifo.sv:36: Assertion failed in %Ntb_fifo.check_flags: FAIL: empty mismatch at time %0t\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                     64,VL_TIME_UNITED_Q(1),-12);
        VL_STOP_MT("designs/fifo/reference/tb_fifo.sv", 36, "", false);
    } else {
        ++(vlSymsp->__Vcoverage[23]);
    }
    if (VL_UNLIKELY(((4U == (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__count)) 
                     != (4U == vlSelfRef.tb_fifo__DOT__expected_queue.size())))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_fifo.sv:39: Assertion failed in %Ntb_fifo.check_flags: FAIL: full mismatch at time %0t\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                     64,VL_TIME_UNITED_Q(1),-12);
        VL_STOP_MT("designs/fifo/reference/tb_fifo.sv", 39, "", false);
    } else {
        ++(vlSymsp->__Vcoverage[24]);
    }
    vlSelfRef.tb_fifo__DOT__checks = ((IData)(1U) + vlSelfRef.tb_fifo__DOT__checks);
    ++(vlSymsp->__Vcoverage[25]);
    ++(vlSymsp->__Vcoverage[28]);
    co_await vlSelfRef.__VtrigSched_h7211e033__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_fifo.clk)", 
                                                         "designs/fifo/reference/tb_fifo.sv", 
                                                         162);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.tb_fifo__DOT__rst = 1U;
    vlSelfRef.tb_fifo__DOT__wr_en = 1U;
    vlSelfRef.tb_fifo__DOT__rd_en = 1U;
    vlSelfRef.tb_fifo__DOT__data_in = 0xe7U;
    co_await vlSelfRef.__VtrigSched_h7211e072__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_fifo.clk)", 
                                                         "designs/fifo/reference/tb_fifo.sv", 
                                                         167);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_await vlSelfRef.__VdlySched.delay(1ULL, nullptr, 
                                         "designs/fifo/reference/tb_fifo.sv", 
                                         168);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.tb_fifo__DOT__expected_queue.clear();
    if (VL_UNLIKELY((0U != (IData)(vlSelfRef.tb_fifo__DOT__data_out)))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_fifo.sv:171: Assertion failed in %Ntb_fifo: FAIL: reset did not clear data_out\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("designs/fifo/reference/tb_fifo.sv", 171, "", false);
    } else {
        ++(vlSymsp->__Vcoverage[42]);
    }
    if (VL_UNLIKELY(((0U == (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__count)) 
                     != (0U == vlSelfRef.tb_fifo__DOT__expected_queue.size())))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_fifo.sv:36: Assertion failed in %Ntb_fifo.check_flags: FAIL: empty mismatch at time %0t\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                     64,VL_TIME_UNITED_Q(1),-12);
        VL_STOP_MT("designs/fifo/reference/tb_fifo.sv", 36, "", false);
    } else {
        ++(vlSymsp->__Vcoverage[23]);
    }
    if (VL_UNLIKELY(((4U == (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__count)) 
                     != (4U == vlSelfRef.tb_fifo__DOT__expected_queue.size())))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_fifo.sv:39: Assertion failed in %Ntb_fifo.check_flags: FAIL: full mismatch at time %0t\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                     64,VL_TIME_UNITED_Q(1),-12);
        VL_STOP_MT("designs/fifo/reference/tb_fifo.sv", 39, "", false);
    } else {
        ++(vlSymsp->__Vcoverage[24]);
    }
    vlSelfRef.tb_fifo__DOT__checks = ((IData)(1U) + vlSelfRef.tb_fifo__DOT__checks);
    ++(vlSymsp->__Vcoverage[25]);
    vlSelfRef.tb_fifo__DOT__rst = 0U;
    co_await vlSelfRef.__VtrigSched_h7211e033__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_fifo.clk)", 
                                                         "designs/fifo/reference/tb_fifo.sv", 
                                                         176);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.tb_fifo__DOT__wr_en = 0U;
    vlSelfRef.tb_fifo__DOT__rd_en = 0U;
    if (VL_UNLIKELY(((0U == (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__count)) 
                     != (0U == vlSelfRef.tb_fifo__DOT__expected_queue.size())))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_fifo.sv:36: Assertion failed in %Ntb_fifo.check_flags: FAIL: empty mismatch at time %0t\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                     64,VL_TIME_UNITED_Q(1),-12);
        VL_STOP_MT("designs/fifo/reference/tb_fifo.sv", 36, "", false);
    } else {
        ++(vlSymsp->__Vcoverage[23]);
    }
    if (VL_UNLIKELY(((4U == (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__count)) 
                     != (4U == vlSelfRef.tb_fifo__DOT__expected_queue.size())))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_fifo.sv:39: Assertion failed in %Ntb_fifo.check_flags: FAIL: full mismatch at time %0t\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name(),
                     64,VL_TIME_UNITED_Q(1),-12);
        VL_STOP_MT("designs/fifo/reference/tb_fifo.sv", 39, "", false);
    } else {
        ++(vlSymsp->__Vcoverage[24]);
    }
    vlSelfRef.tb_fifo__DOT__checks = ((IData)(1U) + vlSelfRef.tb_fifo__DOT__checks);
    ++(vlSymsp->__Vcoverage[25]);
    VL_WRITEF_NX("PASS: FIFO reference tests completed (%0d checks).\n",0,
                 32,vlSelfRef.tb_fifo__DOT__checks);
    VL_FINISH_MT("designs/fifo/reference/tb_fifo.sv", 182, "");
    ++(vlSymsp->__Vcoverage[43]);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
}

VL_INLINE_OPT VlCoroutine Vtb_fifo___024root___eval_initial__TOP__Vtiming__1(Vtb_fifo___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fifo___024root___eval_initial__TOP__Vtiming__1\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (1U) {
        co_await vlSelfRef.__VdlySched.delay(5ULL, 
                                             nullptr, 
                                             "designs/fifo/reference/tb_fifo.sv", 
                                             31);
        vlSelfRef.tb_fifo__DOT__clk = (1U & (~ (IData)(vlSelfRef.tb_fifo__DOT__clk)));
        ++(vlSymsp->__Vcoverage[22]);
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_fifo___024root___dump_triggers__act(Vtb_fifo___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_fifo___024root___eval_triggers__act(Vtb_fifo___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fifo___024root___eval_triggers__act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.set(0U, ((IData)(vlSelfRef.tb_fifo__DOT__clk) 
                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_fifo__DOT__clk__0))));
    vlSelfRef.__VactTriggered.set(1U, vlSelfRef.__VdlySched.awaitingCurrentTime());
    vlSelfRef.__VactTriggered.set(2U, ((~ (IData)(vlSelfRef.tb_fifo__DOT__clk)) 
                                       & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_fifo__DOT__clk__0)));
    vlSelfRef.__Vtrigprevexpr___TOP__tb_fifo__DOT__clk__0 
        = vlSelfRef.tb_fifo__DOT__clk;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_fifo___024root___dump_triggers__act(vlSelf);
    }
#endif
}

VL_INLINE_OPT void Vtb_fifo___024root___act_comb__TOP__0(Vtb_fifo___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fifo___024root___act_comb__TOP__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (((IData)(vlSelfRef.tb_fifo__DOT__clk) ^ (IData)(vlSelfRef.tb_fifo__DOT____Vtogcov__clk))) {
        ++(vlSymsp->__Vcoverage[0]);
        vlSelfRef.tb_fifo__DOT____Vtogcov__clk = vlSelfRef.tb_fifo__DOT__clk;
    }
    if (((IData)(vlSelfRef.tb_fifo__DOT__rst) ^ (IData)(vlSelfRef.tb_fifo__DOT____Vtogcov__rst))) {
        ++(vlSymsp->__Vcoverage[1]);
        vlSelfRef.tb_fifo__DOT____Vtogcov__rst = vlSelfRef.tb_fifo__DOT__rst;
    }
    if (((IData)(vlSelfRef.tb_fifo__DOT__wr_en) ^ (IData)(vlSelfRef.tb_fifo__DOT____Vtogcov__wr_en))) {
        ++(vlSymsp->__Vcoverage[2]);
        vlSelfRef.tb_fifo__DOT____Vtogcov__wr_en = vlSelfRef.tb_fifo__DOT__wr_en;
    }
    if (((IData)(vlSelfRef.tb_fifo__DOT__rd_en) ^ (IData)(vlSelfRef.tb_fifo__DOT____Vtogcov__rd_en))) {
        ++(vlSymsp->__Vcoverage[3]);
        vlSelfRef.tb_fifo__DOT____Vtogcov__rd_en = vlSelfRef.tb_fifo__DOT__rd_en;
    }
    vlSelfRef.tb_fifo__DOT__dut__DOT__write_accept 
        = ((4U != (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__count)) 
           & (IData)(vlSelfRef.tb_fifo__DOT__wr_en));
    vlSelfRef.tb_fifo__DOT__dut__DOT__read_accept = 
        ((0U != (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__count)) 
         & (IData)(vlSelfRef.tb_fifo__DOT__rd_en));
    if ((1U & ((IData)(vlSelfRef.tb_fifo__DOT__data_in) 
               ^ (IData)(vlSelfRef.tb_fifo__DOT____Vtogcov__data_in)))) {
        ++(vlSymsp->__Vcoverage[4]);
        vlSelfRef.tb_fifo__DOT____Vtogcov__data_in 
            = ((0xfeU & (IData)(vlSelfRef.tb_fifo__DOT____Vtogcov__data_in)) 
               | (1U & (IData)(vlSelfRef.tb_fifo__DOT__data_in)));
    }
    if ((2U & ((IData)(vlSelfRef.tb_fifo__DOT__data_in) 
               ^ (IData)(vlSelfRef.tb_fifo__DOT____Vtogcov__data_in)))) {
        ++(vlSymsp->__Vcoverage[5]);
        vlSelfRef.tb_fifo__DOT____Vtogcov__data_in 
            = ((0xfdU & (IData)(vlSelfRef.tb_fifo__DOT____Vtogcov__data_in)) 
               | (2U & (IData)(vlSelfRef.tb_fifo__DOT__data_in)));
    }
    if ((4U & ((IData)(vlSelfRef.tb_fifo__DOT__data_in) 
               ^ (IData)(vlSelfRef.tb_fifo__DOT____Vtogcov__data_in)))) {
        ++(vlSymsp->__Vcoverage[6]);
        vlSelfRef.tb_fifo__DOT____Vtogcov__data_in 
            = ((0xfbU & (IData)(vlSelfRef.tb_fifo__DOT____Vtogcov__data_in)) 
               | (4U & (IData)(vlSelfRef.tb_fifo__DOT__data_in)));
    }
    if ((8U & ((IData)(vlSelfRef.tb_fifo__DOT__data_in) 
               ^ (IData)(vlSelfRef.tb_fifo__DOT____Vtogcov__data_in)))) {
        ++(vlSymsp->__Vcoverage[7]);
        vlSelfRef.tb_fifo__DOT____Vtogcov__data_in 
            = ((0xf7U & (IData)(vlSelfRef.tb_fifo__DOT____Vtogcov__data_in)) 
               | (8U & (IData)(vlSelfRef.tb_fifo__DOT__data_in)));
    }
    if ((0x10U & ((IData)(vlSelfRef.tb_fifo__DOT__data_in) 
                  ^ (IData)(vlSelfRef.tb_fifo__DOT____Vtogcov__data_in)))) {
        ++(vlSymsp->__Vcoverage[8]);
        vlSelfRef.tb_fifo__DOT____Vtogcov__data_in 
            = ((0xefU & (IData)(vlSelfRef.tb_fifo__DOT____Vtogcov__data_in)) 
               | (0x10U & (IData)(vlSelfRef.tb_fifo__DOT__data_in)));
    }
    if ((0x20U & ((IData)(vlSelfRef.tb_fifo__DOT__data_in) 
                  ^ (IData)(vlSelfRef.tb_fifo__DOT____Vtogcov__data_in)))) {
        ++(vlSymsp->__Vcoverage[9]);
        vlSelfRef.tb_fifo__DOT____Vtogcov__data_in 
            = ((0xdfU & (IData)(vlSelfRef.tb_fifo__DOT____Vtogcov__data_in)) 
               | (0x20U & (IData)(vlSelfRef.tb_fifo__DOT__data_in)));
    }
    if ((0x40U & ((IData)(vlSelfRef.tb_fifo__DOT__data_in) 
                  ^ (IData)(vlSelfRef.tb_fifo__DOT____Vtogcov__data_in)))) {
        ++(vlSymsp->__Vcoverage[10]);
        vlSelfRef.tb_fifo__DOT____Vtogcov__data_in 
            = ((0xbfU & (IData)(vlSelfRef.tb_fifo__DOT____Vtogcov__data_in)) 
               | (0x40U & (IData)(vlSelfRef.tb_fifo__DOT__data_in)));
    }
    if ((0x80U & ((IData)(vlSelfRef.tb_fifo__DOT__data_in) 
                  ^ (IData)(vlSelfRef.tb_fifo__DOT____Vtogcov__data_in)))) {
        ++(vlSymsp->__Vcoverage[11]);
        vlSelfRef.tb_fifo__DOT____Vtogcov__data_in 
            = ((0x7fU & (IData)(vlSelfRef.tb_fifo__DOT____Vtogcov__data_in)) 
               | (0x80U & (IData)(vlSelfRef.tb_fifo__DOT__data_in)));
    }
    if (((IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__write_accept) 
         ^ (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__write_accept))) {
        ++(vlSymsp->__Vcoverage[83]);
        vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__write_accept 
            = vlSelfRef.tb_fifo__DOT__dut__DOT__write_accept;
    }
    if (((IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__read_accept) 
         ^ (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__read_accept))) {
        ++(vlSymsp->__Vcoverage[84]);
        vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__read_accept 
            = vlSelfRef.tb_fifo__DOT__dut__DOT__read_accept;
    }
}

VL_INLINE_OPT void Vtb_fifo___024root___nba_sequent__TOP__0(Vtb_fifo___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fifo___024root___nba_sequent__TOP__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*1:0*/ __Vdly__tb_fifo__DOT__dut__DOT__read_pointer;
    __Vdly__tb_fifo__DOT__dut__DOT__read_pointer = 0;
    CData/*1:0*/ __Vdly__tb_fifo__DOT__dut__DOT__write_pointer;
    __Vdly__tb_fifo__DOT__dut__DOT__write_pointer = 0;
    CData/*2:0*/ __Vdly__tb_fifo__DOT__dut__DOT__count;
    __Vdly__tb_fifo__DOT__dut__DOT__count = 0;
    CData/*7:0*/ __VdlyVal__tb_fifo__DOT__dut__DOT__memory__v0;
    __VdlyVal__tb_fifo__DOT__dut__DOT__memory__v0 = 0;
    CData/*1:0*/ __VdlyDim0__tb_fifo__DOT__dut__DOT__memory__v0;
    __VdlyDim0__tb_fifo__DOT__dut__DOT__memory__v0 = 0;
    CData/*0:0*/ __VdlySet__tb_fifo__DOT__dut__DOT__memory__v0;
    __VdlySet__tb_fifo__DOT__dut__DOT__memory__v0 = 0;
    // Body
    __Vdly__tb_fifo__DOT__dut__DOT__read_pointer = vlSelfRef.tb_fifo__DOT__dut__DOT__read_pointer;
    __Vdly__tb_fifo__DOT__dut__DOT__write_pointer = vlSelfRef.tb_fifo__DOT__dut__DOT__write_pointer;
    __Vdly__tb_fifo__DOT__dut__DOT__count = vlSelfRef.tb_fifo__DOT__dut__DOT__count;
    __VdlySet__tb_fifo__DOT__dut__DOT__memory__v0 = 0U;
    if (vlSelfRef.tb_fifo__DOT__rst) {
        ++(vlSymsp->__Vcoverage[96]);
        __Vdly__tb_fifo__DOT__dut__DOT__read_pointer = 0U;
        __Vdly__tb_fifo__DOT__dut__DOT__write_pointer = 0U;
        __Vdly__tb_fifo__DOT__dut__DOT__count = 0U;
        vlSelfRef.tb_fifo__DOT__data_out = 0U;
    } else {
        if (vlSelfRef.tb_fifo__DOT__dut__DOT__write_accept) {
            __VdlyVal__tb_fifo__DOT__dut__DOT__memory__v0 
                = vlSelfRef.tb_fifo__DOT__data_in;
            __VdlyDim0__tb_fifo__DOT__dut__DOT__memory__v0 
                = vlSelfRef.tb_fifo__DOT__dut__DOT__write_pointer;
            __VdlySet__tb_fifo__DOT__dut__DOT__memory__v0 = 1U;
            if ((3U == (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__write_pointer))) {
                ++(vlSymsp->__Vcoverage[85]);
                __Vdly__tb_fifo__DOT__dut__DOT__write_pointer = 0U;
            } else {
                __Vdly__tb_fifo__DOT__dut__DOT__write_pointer 
                    = (3U & ((IData)(1U) + (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__write_pointer)));
                ++(vlSymsp->__Vcoverage[86]);
            }
            ++(vlSymsp->__Vcoverage[87]);
        } else {
            ++(vlSymsp->__Vcoverage[88]);
        }
        if (vlSelfRef.tb_fifo__DOT__dut__DOT__read_accept) {
            vlSelfRef.tb_fifo__DOT__data_out = vlSelfRef.tb_fifo__DOT__dut__DOT__memory
                [vlSelfRef.tb_fifo__DOT__dut__DOT__read_pointer];
            if ((3U == (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__read_pointer))) {
                ++(vlSymsp->__Vcoverage[89]);
                __Vdly__tb_fifo__DOT__dut__DOT__read_pointer = 0U;
            } else {
                __Vdly__tb_fifo__DOT__dut__DOT__read_pointer 
                    = (3U & ((IData)(1U) + (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__read_pointer)));
                ++(vlSymsp->__Vcoverage[90]);
            }
            ++(vlSymsp->__Vcoverage[91]);
        } else {
            ++(vlSymsp->__Vcoverage[92]);
        }
        if ((2U == (((IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__write_accept) 
                     << 1U) | (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__read_accept)))) {
            __Vdly__tb_fifo__DOT__dut__DOT__count = 
                (7U & ((IData)(1U) + (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__count)));
            ++(vlSymsp->__Vcoverage[93]);
        } else if ((1U == (((IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__write_accept) 
                            << 1U) | (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__read_accept)))) {
            __Vdly__tb_fifo__DOT__dut__DOT__count = 
                (7U & ((IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__count) 
                       - (IData)(1U)));
            ++(vlSymsp->__Vcoverage[94]);
        } else {
            __Vdly__tb_fifo__DOT__dut__DOT__count = vlSelfRef.tb_fifo__DOT__dut__DOT__count;
            ++(vlSymsp->__Vcoverage[95]);
        }
        ++(vlSymsp->__Vcoverage[97]);
    }
    ++(vlSymsp->__Vcoverage[98]);
    vlSelfRef.tb_fifo__DOT__dut__DOT__read_pointer 
        = __Vdly__tb_fifo__DOT__dut__DOT__read_pointer;
    vlSelfRef.tb_fifo__DOT__dut__DOT__write_pointer 
        = __Vdly__tb_fifo__DOT__dut__DOT__write_pointer;
    vlSelfRef.tb_fifo__DOT__dut__DOT__count = __Vdly__tb_fifo__DOT__dut__DOT__count;
    if (__VdlySet__tb_fifo__DOT__dut__DOT__memory__v0) {
        vlSelfRef.tb_fifo__DOT__dut__DOT__memory[__VdlyDim0__tb_fifo__DOT__dut__DOT__memory__v0] 
            = __VdlyVal__tb_fifo__DOT__dut__DOT__memory__v0;
    }
    if ((1U & ((IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__read_pointer) 
               ^ (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__read_pointer)))) {
        ++(vlSymsp->__Vcoverage[76]);
        vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__read_pointer 
            = ((2U & (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__read_pointer)) 
               | (1U & (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__read_pointer)));
    }
    if ((2U & ((IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__read_pointer) 
               ^ (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__read_pointer)))) {
        ++(vlSymsp->__Vcoverage[77]);
        vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__read_pointer 
            = ((1U & (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__read_pointer)) 
               | (2U & (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__read_pointer)));
    }
    if ((1U & ((IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__write_pointer) 
               ^ (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__write_pointer)))) {
        ++(vlSymsp->__Vcoverage[78]);
        vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__write_pointer 
            = ((2U & (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__write_pointer)) 
               | (1U & (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__write_pointer)));
    }
    if ((2U & ((IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__write_pointer) 
               ^ (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__write_pointer)))) {
        ++(vlSymsp->__Vcoverage[79]);
        vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__write_pointer 
            = ((1U & (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__write_pointer)) 
               | (2U & (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__write_pointer)));
    }
    if (((4U == (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__count)) 
         ^ (IData)(vlSelfRef.tb_fifo__DOT____Vtogcov__full))) {
        ++(vlSymsp->__Vcoverage[20]);
        vlSelfRef.tb_fifo__DOT____Vtogcov__full = (4U 
                                                   == (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__count));
    }
    if (((0U == (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__count)) 
         ^ (IData)(vlSelfRef.tb_fifo__DOT____Vtogcov__empty))) {
        ++(vlSymsp->__Vcoverage[21]);
        vlSelfRef.tb_fifo__DOT____Vtogcov__empty = 
            (0U == (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__count));
    }
    if ((1U & ((IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__count) 
               ^ (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__count)))) {
        ++(vlSymsp->__Vcoverage[80]);
        vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__count 
            = ((6U & (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__count)) 
               | (1U & (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__count)));
    }
    if ((2U & ((IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__count) 
               ^ (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__count)))) {
        ++(vlSymsp->__Vcoverage[81]);
        vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__count 
            = ((5U & (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__count)) 
               | (2U & (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__count)));
    }
    if ((4U & ((IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__count) 
               ^ (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__count)))) {
        ++(vlSymsp->__Vcoverage[82]);
        vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__count 
            = ((3U & (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__count)) 
               | (4U & (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__count)));
    }
    if ((1U & ((IData)(vlSelfRef.tb_fifo__DOT__data_out) 
               ^ (IData)(vlSelfRef.tb_fifo__DOT____Vtogcov__data_out)))) {
        ++(vlSymsp->__Vcoverage[12]);
        vlSelfRef.tb_fifo__DOT____Vtogcov__data_out 
            = ((0xfeU & (IData)(vlSelfRef.tb_fifo__DOT____Vtogcov__data_out)) 
               | (1U & (IData)(vlSelfRef.tb_fifo__DOT__data_out)));
    }
    if ((2U & ((IData)(vlSelfRef.tb_fifo__DOT__data_out) 
               ^ (IData)(vlSelfRef.tb_fifo__DOT____Vtogcov__data_out)))) {
        ++(vlSymsp->__Vcoverage[13]);
        vlSelfRef.tb_fifo__DOT____Vtogcov__data_out 
            = ((0xfdU & (IData)(vlSelfRef.tb_fifo__DOT____Vtogcov__data_out)) 
               | (2U & (IData)(vlSelfRef.tb_fifo__DOT__data_out)));
    }
    if ((4U & ((IData)(vlSelfRef.tb_fifo__DOT__data_out) 
               ^ (IData)(vlSelfRef.tb_fifo__DOT____Vtogcov__data_out)))) {
        ++(vlSymsp->__Vcoverage[14]);
        vlSelfRef.tb_fifo__DOT____Vtogcov__data_out 
            = ((0xfbU & (IData)(vlSelfRef.tb_fifo__DOT____Vtogcov__data_out)) 
               | (4U & (IData)(vlSelfRef.tb_fifo__DOT__data_out)));
    }
    if ((8U & ((IData)(vlSelfRef.tb_fifo__DOT__data_out) 
               ^ (IData)(vlSelfRef.tb_fifo__DOT____Vtogcov__data_out)))) {
        ++(vlSymsp->__Vcoverage[15]);
        vlSelfRef.tb_fifo__DOT____Vtogcov__data_out 
            = ((0xf7U & (IData)(vlSelfRef.tb_fifo__DOT____Vtogcov__data_out)) 
               | (8U & (IData)(vlSelfRef.tb_fifo__DOT__data_out)));
    }
    if ((0x10U & ((IData)(vlSelfRef.tb_fifo__DOT__data_out) 
                  ^ (IData)(vlSelfRef.tb_fifo__DOT____Vtogcov__data_out)))) {
        ++(vlSymsp->__Vcoverage[16]);
        vlSelfRef.tb_fifo__DOT____Vtogcov__data_out 
            = ((0xefU & (IData)(vlSelfRef.tb_fifo__DOT____Vtogcov__data_out)) 
               | (0x10U & (IData)(vlSelfRef.tb_fifo__DOT__data_out)));
    }
    if ((0x20U & ((IData)(vlSelfRef.tb_fifo__DOT__data_out) 
                  ^ (IData)(vlSelfRef.tb_fifo__DOT____Vtogcov__data_out)))) {
        ++(vlSymsp->__Vcoverage[17]);
        vlSelfRef.tb_fifo__DOT____Vtogcov__data_out 
            = ((0xdfU & (IData)(vlSelfRef.tb_fifo__DOT____Vtogcov__data_out)) 
               | (0x20U & (IData)(vlSelfRef.tb_fifo__DOT__data_out)));
    }
    if ((0x40U & ((IData)(vlSelfRef.tb_fifo__DOT__data_out) 
                  ^ (IData)(vlSelfRef.tb_fifo__DOT____Vtogcov__data_out)))) {
        ++(vlSymsp->__Vcoverage[18]);
        vlSelfRef.tb_fifo__DOT____Vtogcov__data_out 
            = ((0xbfU & (IData)(vlSelfRef.tb_fifo__DOT____Vtogcov__data_out)) 
               | (0x40U & (IData)(vlSelfRef.tb_fifo__DOT__data_out)));
    }
    if ((0x80U & ((IData)(vlSelfRef.tb_fifo__DOT__data_out) 
                  ^ (IData)(vlSelfRef.tb_fifo__DOT____Vtogcov__data_out)))) {
        ++(vlSymsp->__Vcoverage[19]);
        vlSelfRef.tb_fifo__DOT____Vtogcov__data_out 
            = ((0x7fU & (IData)(vlSelfRef.tb_fifo__DOT____Vtogcov__data_out)) 
               | (0x80U & (IData)(vlSelfRef.tb_fifo__DOT__data_out)));
    }
    if ((1U & (vlSelfRef.tb_fifo__DOT__dut__DOT__memory
               [0U] ^ vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory
               [0U]))) {
        ++(vlSymsp->__Vcoverage[44]);
        vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory[0U] 
            = ((0xfeU & vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory
                [0U]) | (1U & vlSelfRef.tb_fifo__DOT__dut__DOT__memory
                         [0U]));
    }
    if ((2U & (vlSelfRef.tb_fifo__DOT__dut__DOT__memory
               [0U] ^ vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory
               [0U]))) {
        ++(vlSymsp->__Vcoverage[45]);
        vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory[0U] 
            = ((0xfdU & vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory
                [0U]) | (2U & vlSelfRef.tb_fifo__DOT__dut__DOT__memory
                         [0U]));
    }
    if ((4U & (vlSelfRef.tb_fifo__DOT__dut__DOT__memory
               [0U] ^ vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory
               [0U]))) {
        ++(vlSymsp->__Vcoverage[46]);
        vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory[0U] 
            = ((0xfbU & vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory
                [0U]) | (4U & vlSelfRef.tb_fifo__DOT__dut__DOT__memory
                         [0U]));
    }
    if ((8U & (vlSelfRef.tb_fifo__DOT__dut__DOT__memory
               [0U] ^ vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory
               [0U]))) {
        ++(vlSymsp->__Vcoverage[47]);
        vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory[0U] 
            = ((0xf7U & vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory
                [0U]) | (8U & vlSelfRef.tb_fifo__DOT__dut__DOT__memory
                         [0U]));
    }
    if ((0x10U & (vlSelfRef.tb_fifo__DOT__dut__DOT__memory
                  [0U] ^ vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[48]);
        vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory[0U] 
            = ((0xefU & vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory
                [0U]) | (0x10U & vlSelfRef.tb_fifo__DOT__dut__DOT__memory
                         [0U]));
    }
    if ((0x20U & (vlSelfRef.tb_fifo__DOT__dut__DOT__memory
                  [0U] ^ vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[49]);
        vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory[0U] 
            = ((0xdfU & vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory
                [0U]) | (0x20U & vlSelfRef.tb_fifo__DOT__dut__DOT__memory
                         [0U]));
    }
    if ((0x40U & (vlSelfRef.tb_fifo__DOT__dut__DOT__memory
                  [0U] ^ vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[50]);
        vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory[0U] 
            = ((0xbfU & vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory
                [0U]) | (0x40U & vlSelfRef.tb_fifo__DOT__dut__DOT__memory
                         [0U]));
    }
    if ((0x80U & (vlSelfRef.tb_fifo__DOT__dut__DOT__memory
                  [0U] ^ vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory
                  [0U]))) {
        ++(vlSymsp->__Vcoverage[51]);
        vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory[0U] 
            = ((0x7fU & vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory
                [0U]) | (0x80U & vlSelfRef.tb_fifo__DOT__dut__DOT__memory
                         [0U]));
    }
    if ((1U & (vlSelfRef.tb_fifo__DOT__dut__DOT__memory
               [1U] ^ vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory
               [1U]))) {
        ++(vlSymsp->__Vcoverage[52]);
        vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory[1U] 
            = ((0xfeU & vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory
                [1U]) | (1U & vlSelfRef.tb_fifo__DOT__dut__DOT__memory
                         [1U]));
    }
    if ((2U & (vlSelfRef.tb_fifo__DOT__dut__DOT__memory
               [1U] ^ vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory
               [1U]))) {
        ++(vlSymsp->__Vcoverage[53]);
        vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory[1U] 
            = ((0xfdU & vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory
                [1U]) | (2U & vlSelfRef.tb_fifo__DOT__dut__DOT__memory
                         [1U]));
    }
    if ((4U & (vlSelfRef.tb_fifo__DOT__dut__DOT__memory
               [1U] ^ vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory
               [1U]))) {
        ++(vlSymsp->__Vcoverage[54]);
        vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory[1U] 
            = ((0xfbU & vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory
                [1U]) | (4U & vlSelfRef.tb_fifo__DOT__dut__DOT__memory
                         [1U]));
    }
    if ((8U & (vlSelfRef.tb_fifo__DOT__dut__DOT__memory
               [1U] ^ vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory
               [1U]))) {
        ++(vlSymsp->__Vcoverage[55]);
        vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory[1U] 
            = ((0xf7U & vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory
                [1U]) | (8U & vlSelfRef.tb_fifo__DOT__dut__DOT__memory
                         [1U]));
    }
    if ((0x10U & (vlSelfRef.tb_fifo__DOT__dut__DOT__memory
                  [1U] ^ vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[56]);
        vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory[1U] 
            = ((0xefU & vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory
                [1U]) | (0x10U & vlSelfRef.tb_fifo__DOT__dut__DOT__memory
                         [1U]));
    }
    if ((0x20U & (vlSelfRef.tb_fifo__DOT__dut__DOT__memory
                  [1U] ^ vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[57]);
        vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory[1U] 
            = ((0xdfU & vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory
                [1U]) | (0x20U & vlSelfRef.tb_fifo__DOT__dut__DOT__memory
                         [1U]));
    }
    if ((0x40U & (vlSelfRef.tb_fifo__DOT__dut__DOT__memory
                  [1U] ^ vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[58]);
        vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory[1U] 
            = ((0xbfU & vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory
                [1U]) | (0x40U & vlSelfRef.tb_fifo__DOT__dut__DOT__memory
                         [1U]));
    }
    if ((0x80U & (vlSelfRef.tb_fifo__DOT__dut__DOT__memory
                  [1U] ^ vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory
                  [1U]))) {
        ++(vlSymsp->__Vcoverage[59]);
        vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory[1U] 
            = ((0x7fU & vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory
                [1U]) | (0x80U & vlSelfRef.tb_fifo__DOT__dut__DOT__memory
                         [1U]));
    }
    if ((1U & (vlSelfRef.tb_fifo__DOT__dut__DOT__memory
               [2U] ^ vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory
               [2U]))) {
        ++(vlSymsp->__Vcoverage[60]);
        vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory[2U] 
            = ((0xfeU & vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory
                [2U]) | (1U & vlSelfRef.tb_fifo__DOT__dut__DOT__memory
                         [2U]));
    }
    if ((2U & (vlSelfRef.tb_fifo__DOT__dut__DOT__memory
               [2U] ^ vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory
               [2U]))) {
        ++(vlSymsp->__Vcoverage[61]);
        vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory[2U] 
            = ((0xfdU & vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory
                [2U]) | (2U & vlSelfRef.tb_fifo__DOT__dut__DOT__memory
                         [2U]));
    }
    if ((4U & (vlSelfRef.tb_fifo__DOT__dut__DOT__memory
               [2U] ^ vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory
               [2U]))) {
        ++(vlSymsp->__Vcoverage[62]);
        vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory[2U] 
            = ((0xfbU & vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory
                [2U]) | (4U & vlSelfRef.tb_fifo__DOT__dut__DOT__memory
                         [2U]));
    }
    if ((8U & (vlSelfRef.tb_fifo__DOT__dut__DOT__memory
               [2U] ^ vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory
               [2U]))) {
        ++(vlSymsp->__Vcoverage[63]);
        vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory[2U] 
            = ((0xf7U & vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory
                [2U]) | (8U & vlSelfRef.tb_fifo__DOT__dut__DOT__memory
                         [2U]));
    }
    if ((0x10U & (vlSelfRef.tb_fifo__DOT__dut__DOT__memory
                  [2U] ^ vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory
                  [2U]))) {
        ++(vlSymsp->__Vcoverage[64]);
        vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory[2U] 
            = ((0xefU & vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory
                [2U]) | (0x10U & vlSelfRef.tb_fifo__DOT__dut__DOT__memory
                         [2U]));
    }
    if ((0x20U & (vlSelfRef.tb_fifo__DOT__dut__DOT__memory
                  [2U] ^ vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory
                  [2U]))) {
        ++(vlSymsp->__Vcoverage[65]);
        vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory[2U] 
            = ((0xdfU & vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory
                [2U]) | (0x20U & vlSelfRef.tb_fifo__DOT__dut__DOT__memory
                         [2U]));
    }
    if ((0x40U & (vlSelfRef.tb_fifo__DOT__dut__DOT__memory
                  [2U] ^ vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory
                  [2U]))) {
        ++(vlSymsp->__Vcoverage[66]);
        vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory[2U] 
            = ((0xbfU & vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory
                [2U]) | (0x40U & vlSelfRef.tb_fifo__DOT__dut__DOT__memory
                         [2U]));
    }
    if ((0x80U & (vlSelfRef.tb_fifo__DOT__dut__DOT__memory
                  [2U] ^ vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory
                  [2U]))) {
        ++(vlSymsp->__Vcoverage[67]);
        vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory[2U] 
            = ((0x7fU & vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory
                [2U]) | (0x80U & vlSelfRef.tb_fifo__DOT__dut__DOT__memory
                         [2U]));
    }
    if ((1U & (vlSelfRef.tb_fifo__DOT__dut__DOT__memory
               [3U] ^ vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory
               [3U]))) {
        ++(vlSymsp->__Vcoverage[68]);
        vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory[3U] 
            = ((0xfeU & vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory
                [3U]) | (1U & vlSelfRef.tb_fifo__DOT__dut__DOT__memory
                         [3U]));
    }
    if ((2U & (vlSelfRef.tb_fifo__DOT__dut__DOT__memory
               [3U] ^ vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory
               [3U]))) {
        ++(vlSymsp->__Vcoverage[69]);
        vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory[3U] 
            = ((0xfdU & vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory
                [3U]) | (2U & vlSelfRef.tb_fifo__DOT__dut__DOT__memory
                         [3U]));
    }
    if ((4U & (vlSelfRef.tb_fifo__DOT__dut__DOT__memory
               [3U] ^ vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory
               [3U]))) {
        ++(vlSymsp->__Vcoverage[70]);
        vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory[3U] 
            = ((0xfbU & vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory
                [3U]) | (4U & vlSelfRef.tb_fifo__DOT__dut__DOT__memory
                         [3U]));
    }
    if ((8U & (vlSelfRef.tb_fifo__DOT__dut__DOT__memory
               [3U] ^ vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory
               [3U]))) {
        ++(vlSymsp->__Vcoverage[71]);
        vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory[3U] 
            = ((0xf7U & vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory
                [3U]) | (8U & vlSelfRef.tb_fifo__DOT__dut__DOT__memory
                         [3U]));
    }
    if ((0x10U & (vlSelfRef.tb_fifo__DOT__dut__DOT__memory
                  [3U] ^ vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory
                  [3U]))) {
        ++(vlSymsp->__Vcoverage[72]);
        vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory[3U] 
            = ((0xefU & vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory
                [3U]) | (0x10U & vlSelfRef.tb_fifo__DOT__dut__DOT__memory
                         [3U]));
    }
    if ((0x20U & (vlSelfRef.tb_fifo__DOT__dut__DOT__memory
                  [3U] ^ vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory
                  [3U]))) {
        ++(vlSymsp->__Vcoverage[73]);
        vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory[3U] 
            = ((0xdfU & vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory
                [3U]) | (0x20U & vlSelfRef.tb_fifo__DOT__dut__DOT__memory
                         [3U]));
    }
    if ((0x40U & (vlSelfRef.tb_fifo__DOT__dut__DOT__memory
                  [3U] ^ vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory
                  [3U]))) {
        ++(vlSymsp->__Vcoverage[74]);
        vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory[3U] 
            = ((0xbfU & vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory
                [3U]) | (0x40U & vlSelfRef.tb_fifo__DOT__dut__DOT__memory
                         [3U]));
    }
    if ((0x80U & (vlSelfRef.tb_fifo__DOT__dut__DOT__memory
                  [3U] ^ vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory
                  [3U]))) {
        ++(vlSymsp->__Vcoverage[75]);
        vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory[3U] 
            = ((0x7fU & vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__memory
                [3U]) | (0x80U & vlSelfRef.tb_fifo__DOT__dut__DOT__memory
                         [3U]));
    }
}

VL_INLINE_OPT void Vtb_fifo___024root___nba_comb__TOP__0(Vtb_fifo___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fifo___024root___nba_comb__TOP__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (((IData)(vlSelfRef.tb_fifo__DOT__clk) ^ (IData)(vlSelfRef.tb_fifo__DOT____Vtogcov__clk))) {
        ++(vlSymsp->__Vcoverage[0]);
        vlSelfRef.tb_fifo__DOT____Vtogcov__clk = vlSelfRef.tb_fifo__DOT__clk;
    }
    if (((IData)(vlSelfRef.tb_fifo__DOT__rst) ^ (IData)(vlSelfRef.tb_fifo__DOT____Vtogcov__rst))) {
        ++(vlSymsp->__Vcoverage[1]);
        vlSelfRef.tb_fifo__DOT____Vtogcov__rst = vlSelfRef.tb_fifo__DOT__rst;
    }
    if (((IData)(vlSelfRef.tb_fifo__DOT__wr_en) ^ (IData)(vlSelfRef.tb_fifo__DOT____Vtogcov__wr_en))) {
        ++(vlSymsp->__Vcoverage[2]);
        vlSelfRef.tb_fifo__DOT____Vtogcov__wr_en = vlSelfRef.tb_fifo__DOT__wr_en;
    }
    if (((IData)(vlSelfRef.tb_fifo__DOT__rd_en) ^ (IData)(vlSelfRef.tb_fifo__DOT____Vtogcov__rd_en))) {
        ++(vlSymsp->__Vcoverage[3]);
        vlSelfRef.tb_fifo__DOT____Vtogcov__rd_en = vlSelfRef.tb_fifo__DOT__rd_en;
    }
    if ((1U & ((IData)(vlSelfRef.tb_fifo__DOT__data_in) 
               ^ (IData)(vlSelfRef.tb_fifo__DOT____Vtogcov__data_in)))) {
        ++(vlSymsp->__Vcoverage[4]);
        vlSelfRef.tb_fifo__DOT____Vtogcov__data_in 
            = ((0xfeU & (IData)(vlSelfRef.tb_fifo__DOT____Vtogcov__data_in)) 
               | (1U & (IData)(vlSelfRef.tb_fifo__DOT__data_in)));
    }
    if ((2U & ((IData)(vlSelfRef.tb_fifo__DOT__data_in) 
               ^ (IData)(vlSelfRef.tb_fifo__DOT____Vtogcov__data_in)))) {
        ++(vlSymsp->__Vcoverage[5]);
        vlSelfRef.tb_fifo__DOT____Vtogcov__data_in 
            = ((0xfdU & (IData)(vlSelfRef.tb_fifo__DOT____Vtogcov__data_in)) 
               | (2U & (IData)(vlSelfRef.tb_fifo__DOT__data_in)));
    }
    if ((4U & ((IData)(vlSelfRef.tb_fifo__DOT__data_in) 
               ^ (IData)(vlSelfRef.tb_fifo__DOT____Vtogcov__data_in)))) {
        ++(vlSymsp->__Vcoverage[6]);
        vlSelfRef.tb_fifo__DOT____Vtogcov__data_in 
            = ((0xfbU & (IData)(vlSelfRef.tb_fifo__DOT____Vtogcov__data_in)) 
               | (4U & (IData)(vlSelfRef.tb_fifo__DOT__data_in)));
    }
    if ((8U & ((IData)(vlSelfRef.tb_fifo__DOT__data_in) 
               ^ (IData)(vlSelfRef.tb_fifo__DOT____Vtogcov__data_in)))) {
        ++(vlSymsp->__Vcoverage[7]);
        vlSelfRef.tb_fifo__DOT____Vtogcov__data_in 
            = ((0xf7U & (IData)(vlSelfRef.tb_fifo__DOT____Vtogcov__data_in)) 
               | (8U & (IData)(vlSelfRef.tb_fifo__DOT__data_in)));
    }
    if ((0x10U & ((IData)(vlSelfRef.tb_fifo__DOT__data_in) 
                  ^ (IData)(vlSelfRef.tb_fifo__DOT____Vtogcov__data_in)))) {
        ++(vlSymsp->__Vcoverage[8]);
        vlSelfRef.tb_fifo__DOT____Vtogcov__data_in 
            = ((0xefU & (IData)(vlSelfRef.tb_fifo__DOT____Vtogcov__data_in)) 
               | (0x10U & (IData)(vlSelfRef.tb_fifo__DOT__data_in)));
    }
    if ((0x20U & ((IData)(vlSelfRef.tb_fifo__DOT__data_in) 
                  ^ (IData)(vlSelfRef.tb_fifo__DOT____Vtogcov__data_in)))) {
        ++(vlSymsp->__Vcoverage[9]);
        vlSelfRef.tb_fifo__DOT____Vtogcov__data_in 
            = ((0xdfU & (IData)(vlSelfRef.tb_fifo__DOT____Vtogcov__data_in)) 
               | (0x20U & (IData)(vlSelfRef.tb_fifo__DOT__data_in)));
    }
    if ((0x40U & ((IData)(vlSelfRef.tb_fifo__DOT__data_in) 
                  ^ (IData)(vlSelfRef.tb_fifo__DOT____Vtogcov__data_in)))) {
        ++(vlSymsp->__Vcoverage[10]);
        vlSelfRef.tb_fifo__DOT____Vtogcov__data_in 
            = ((0xbfU & (IData)(vlSelfRef.tb_fifo__DOT____Vtogcov__data_in)) 
               | (0x40U & (IData)(vlSelfRef.tb_fifo__DOT__data_in)));
    }
    if ((0x80U & ((IData)(vlSelfRef.tb_fifo__DOT__data_in) 
                  ^ (IData)(vlSelfRef.tb_fifo__DOT____Vtogcov__data_in)))) {
        ++(vlSymsp->__Vcoverage[11]);
        vlSelfRef.tb_fifo__DOT____Vtogcov__data_in 
            = ((0x7fU & (IData)(vlSelfRef.tb_fifo__DOT____Vtogcov__data_in)) 
               | (0x80U & (IData)(vlSelfRef.tb_fifo__DOT__data_in)));
    }
    vlSelfRef.tb_fifo__DOT__dut__DOT__write_accept 
        = ((4U != (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__count)) 
           & (IData)(vlSelfRef.tb_fifo__DOT__wr_en));
    vlSelfRef.tb_fifo__DOT__dut__DOT__read_accept = 
        ((0U != (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__count)) 
         & (IData)(vlSelfRef.tb_fifo__DOT__rd_en));
    if (((IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__write_accept) 
         ^ (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__write_accept))) {
        ++(vlSymsp->__Vcoverage[83]);
        vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__write_accept 
            = vlSelfRef.tb_fifo__DOT__dut__DOT__write_accept;
    }
    if (((IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__read_accept) 
         ^ (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__read_accept))) {
        ++(vlSymsp->__Vcoverage[84]);
        vlSelfRef.tb_fifo__DOT__dut__DOT____Vtogcov__read_accept 
            = vlSelfRef.tb_fifo__DOT__dut__DOT__read_accept;
    }
}
