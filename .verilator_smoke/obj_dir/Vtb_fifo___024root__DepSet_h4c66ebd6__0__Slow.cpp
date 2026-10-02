// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_fifo.h for the primary calling header

#include "Vtb_fifo__pch.h"
#include "Vtb_fifo___024root.h"

VL_ATTR_COLD void Vtb_fifo___024root___eval_static(Vtb_fifo___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fifo___024root___eval_static\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vtb_fifo___024root___eval_final(Vtb_fifo___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fifo___024root___eval_final\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_fifo___024root___dump_triggers__stl(Vtb_fifo___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtb_fifo___024root___eval_phase__stl(Vtb_fifo___024root* vlSelf);

VL_ATTR_COLD void Vtb_fifo___024root___eval_settle(Vtb_fifo___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fifo___024root___eval_settle\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            Vtb_fifo___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("designs/fifo/reference/tb_fifo.sv", 1, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vtb_fifo___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_fifo___024root___dump_triggers__stl(Vtb_fifo___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fifo___024root___dump_triggers__stl\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_fifo___024root___stl_sequent__TOP__0(Vtb_fifo___024root* vlSelf);

VL_ATTR_COLD void Vtb_fifo___024root___eval_stl(Vtb_fifo___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fifo___024root___eval_stl\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vtb_fifo___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vtb_fifo___024root___eval_triggers__stl(Vtb_fifo___024root* vlSelf);

VL_ATTR_COLD bool Vtb_fifo___024root___eval_phase__stl(Vtb_fifo___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fifo___024root___eval_phase__stl\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtb_fifo___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vtb_fifo___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_fifo___024root___dump_triggers__act(Vtb_fifo___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fifo___024root___dump_triggers__act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge tb_fifo.clk)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @(negedge tb_fifo.clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_fifo___024root___dump_triggers__nba(Vtb_fifo___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fifo___024root___dump_triggers__nba\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge tb_fifo.clk)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
    if ((4ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @(negedge tb_fifo.clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_fifo___024root___ctor_var_reset(Vtb_fifo___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fifo___024root___ctor_var_reset\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->tb_fifo__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->tb_fifo__DOT__rst = VL_RAND_RESET_I(1);
    vlSelf->tb_fifo__DOT__wr_en = VL_RAND_RESET_I(1);
    vlSelf->tb_fifo__DOT__rd_en = VL_RAND_RESET_I(1);
    vlSelf->tb_fifo__DOT__data_in = VL_RAND_RESET_I(8);
    vlSelf->tb_fifo__DOT__data_out = VL_RAND_RESET_I(8);
    vlSelf->tb_fifo__DOT__expected_queue.atDefault() = VL_RAND_RESET_I(8);
    vlSelf->tb_fifo__DOT__checks = VL_RAND_RESET_I(32);
    vlSelf->tb_fifo__DOT____Vtogcov__clk = VL_RAND_RESET_I(1);
    vlSelf->tb_fifo__DOT____Vtogcov__rst = VL_RAND_RESET_I(1);
    vlSelf->tb_fifo__DOT____Vtogcov__wr_en = VL_RAND_RESET_I(1);
    vlSelf->tb_fifo__DOT____Vtogcov__rd_en = VL_RAND_RESET_I(1);
    vlSelf->tb_fifo__DOT____Vtogcov__data_in = VL_RAND_RESET_I(8);
    vlSelf->tb_fifo__DOT____Vtogcov__data_out = VL_RAND_RESET_I(8);
    vlSelf->tb_fifo__DOT____Vtogcov__full = VL_RAND_RESET_I(1);
    vlSelf->tb_fifo__DOT____Vtogcov__empty = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->tb_fifo__DOT__dut__DOT__memory[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->tb_fifo__DOT__dut__DOT__read_pointer = VL_RAND_RESET_I(2);
    vlSelf->tb_fifo__DOT__dut__DOT__write_pointer = VL_RAND_RESET_I(2);
    vlSelf->tb_fifo__DOT__dut__DOT__count = VL_RAND_RESET_I(3);
    vlSelf->tb_fifo__DOT__dut__DOT__write_accept = VL_RAND_RESET_I(1);
    vlSelf->tb_fifo__DOT__dut__DOT__read_accept = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->tb_fifo__DOT__dut__DOT____Vtogcov__memory[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->tb_fifo__DOT__dut__DOT____Vtogcov__read_pointer = VL_RAND_RESET_I(2);
    vlSelf->tb_fifo__DOT__dut__DOT____Vtogcov__write_pointer = VL_RAND_RESET_I(2);
    vlSelf->tb_fifo__DOT__dut__DOT____Vtogcov__count = VL_RAND_RESET_I(3);
    vlSelf->tb_fifo__DOT__dut__DOT____Vtogcov__write_accept = VL_RAND_RESET_I(1);
    vlSelf->tb_fifo__DOT__dut__DOT____Vtogcov__read_accept = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_fifo__DOT__clk__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
