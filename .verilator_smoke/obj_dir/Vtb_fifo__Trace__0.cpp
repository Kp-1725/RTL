// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtb_fifo__Syms.h"


void Vtb_fifo___024root__trace_chg_0_sub_0(Vtb_fifo___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtb_fifo___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fifo___024root__trace_chg_0\n"); );
    // Init
    Vtb_fifo___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_fifo___024root*>(voidSelf);
    Vtb_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtb_fifo___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtb_fifo___024root__trace_chg_0_sub_0(Vtb_fifo___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fifo___024root__trace_chg_0_sub_0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U] 
                     | vlSelfRef.__Vm_traceActivity
                     [2U]))) {
        bufp->chgBit(oldp+0,(vlSelfRef.tb_fifo__DOT__rst));
        bufp->chgBit(oldp+1,(vlSelfRef.tb_fifo__DOT__wr_en));
        bufp->chgBit(oldp+2,(vlSelfRef.tb_fifo__DOT__rd_en));
        bufp->chgCData(oldp+3,(vlSelfRef.tb_fifo__DOT__data_in),8);
        bufp->chgIData(oldp+4,(vlSelfRef.tb_fifo__DOT__checks),32);
    }
    if (VL_UNLIKELY(vlSelfRef.__Vm_traceActivity[3U])) {
        bufp->chgCData(oldp+5,(vlSelfRef.tb_fifo__DOT__data_out),8);
        bufp->chgBit(oldp+6,((4U == (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__count))));
        bufp->chgBit(oldp+7,((0U == (IData)(vlSelfRef.tb_fifo__DOT__dut__DOT__count))));
        bufp->chgCData(oldp+8,(vlSelfRef.tb_fifo__DOT__dut__DOT__memory[0]),8);
        bufp->chgCData(oldp+9,(vlSelfRef.tb_fifo__DOT__dut__DOT__memory[1]),8);
        bufp->chgCData(oldp+10,(vlSelfRef.tb_fifo__DOT__dut__DOT__memory[2]),8);
        bufp->chgCData(oldp+11,(vlSelfRef.tb_fifo__DOT__dut__DOT__memory[3]),8);
        bufp->chgCData(oldp+12,(vlSelfRef.tb_fifo__DOT__dut__DOT__read_pointer),2);
        bufp->chgCData(oldp+13,(vlSelfRef.tb_fifo__DOT__dut__DOT__write_pointer),2);
        bufp->chgCData(oldp+14,(vlSelfRef.tb_fifo__DOT__dut__DOT__count),3);
    }
    bufp->chgBit(oldp+15,(vlSelfRef.tb_fifo__DOT__clk));
    bufp->chgBit(oldp+16,(vlSelfRef.tb_fifo__DOT__dut__DOT__write_accept));
    bufp->chgBit(oldp+17,(vlSelfRef.tb_fifo__DOT__dut__DOT__read_accept));
}

void Vtb_fifo___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fifo___024root__trace_cleanup\n"); );
    // Init
    Vtb_fifo___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_fifo___024root*>(voidSelf);
    Vtb_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
}
