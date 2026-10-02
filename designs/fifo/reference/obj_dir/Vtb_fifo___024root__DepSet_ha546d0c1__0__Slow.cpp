// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_fifo.h for the primary calling header

#include "Vtb_fifo__pch.h"
#include "Vtb_fifo__Syms.h"
#include "Vtb_fifo___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_fifo___024root___dump_triggers__stl(Vtb_fifo___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_fifo___024root___eval_triggers__stl(Vtb_fifo___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fifo___024root___eval_triggers__stl\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered.set(0U, (IData)(vlSelfRef.__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_fifo___024root___dump_triggers__stl(vlSelf);
    }
#endif
}

VL_ATTR_COLD void Vtb_fifo___024root___stl_sequent__TOP__0(Vtb_fifo___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fifo___024root___stl_sequent__TOP__0\n"); );
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

VL_ATTR_COLD void Vtb_fifo___024root___configure_coverage(Vtb_fifo___024root* vlSelf, bool first) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_fifo___024root___configure_coverage\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    (void)first;  // Prevent unused variable warning
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[0]), first, "tb_fifo.sv", 5, 11, ".tb_fifo", "v_toggle/tb_fifo", "clk", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[1]), first, "tb_fifo.sv", 6, 11, ".tb_fifo", "v_toggle/tb_fifo", "rst", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[2]), first, "tb_fifo.sv", 7, 11, ".tb_fifo", "v_toggle/tb_fifo", "wr_en", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[3]), first, "tb_fifo.sv", 8, 11, ".tb_fifo", "v_toggle/tb_fifo", "rd_en", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[4]), first, "tb_fifo.sv", 9, 28, ".tb_fifo", "v_toggle/tb_fifo", "data_in[0]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[5]), first, "tb_fifo.sv", 9, 28, ".tb_fifo", "v_toggle/tb_fifo", "data_in[1]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[6]), first, "tb_fifo.sv", 9, 28, ".tb_fifo", "v_toggle/tb_fifo", "data_in[2]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[7]), first, "tb_fifo.sv", 9, 28, ".tb_fifo", "v_toggle/tb_fifo", "data_in[3]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[8]), first, "tb_fifo.sv", 9, 28, ".tb_fifo", "v_toggle/tb_fifo", "data_in[4]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[9]), first, "tb_fifo.sv", 9, 28, ".tb_fifo", "v_toggle/tb_fifo", "data_in[5]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[10]), first, "tb_fifo.sv", 9, 28, ".tb_fifo", "v_toggle/tb_fifo", "data_in[6]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[11]), first, "tb_fifo.sv", 9, 28, ".tb_fifo", "v_toggle/tb_fifo", "data_in[7]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[12]), first, "tb_fifo.sv", 10, 28, ".tb_fifo", "v_toggle/tb_fifo", "data_out[0]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[13]), first, "tb_fifo.sv", 10, 28, ".tb_fifo", "v_toggle/tb_fifo", "data_out[1]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[14]), first, "tb_fifo.sv", 10, 28, ".tb_fifo", "v_toggle/tb_fifo", "data_out[2]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[15]), first, "tb_fifo.sv", 10, 28, ".tb_fifo", "v_toggle/tb_fifo", "data_out[3]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[16]), first, "tb_fifo.sv", 10, 28, ".tb_fifo", "v_toggle/tb_fifo", "data_out[4]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[17]), first, "tb_fifo.sv", 10, 28, ".tb_fifo", "v_toggle/tb_fifo", "data_out[5]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[18]), first, "tb_fifo.sv", 10, 28, ".tb_fifo", "v_toggle/tb_fifo", "data_out[6]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[19]), first, "tb_fifo.sv", 10, 28, ".tb_fifo", "v_toggle/tb_fifo", "data_out[7]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[20]), first, "tb_fifo.sv", 11, 11, ".tb_fifo", "v_toggle/tb_fifo", "full", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[21]), first, "tb_fifo.sv", 12, 11, ".tb_fifo", "v_toggle/tb_fifo", "empty", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[22]), first, "tb_fifo.sv", 31, 5, ".tb_fifo", "v_line/tb_fifo", "block", "31");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[23]), first, "tb_fifo.sv", 35, 14, ".tb_fifo", "v_line/tb_fifo", "else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[24]), first, "tb_fifo.sv", 38, 14, ".tb_fifo", "v_line/tb_fifo", "else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[25]), first, "tb_fifo.sv", 33, 20, ".tb_fifo", "v_line/tb_fifo", "block", "33-34,41");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[26]), first, "tb_fifo.sv", 53, 13, ".tb_fifo", "v_branch/tb_fifo", "if", "53-54");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[27]), first, "tb_fifo.sv", 53, 14, ".tb_fifo", "v_branch/tb_fifo", "else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[28]), first, "tb_fifo.sv", 45, 20, ".tb_fifo", "v_line/tb_fifo", "block", "45-52,56");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[29]), first, "tb_fifo.sv", 68, 13, ".tb_fifo", "v_branch/tb_fifo", "if", "68-69");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[30]), first, "tb_fifo.sv", 68, 14, ".tb_fifo", "v_branch/tb_fifo", "else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[31]), first, "tb_fifo.sv", 73, 14, ".tb_fifo", "v_line/tb_fifo", "else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[32]), first, "tb_fifo.sv", 60, 20, ".tb_fifo", "v_line/tb_fifo", "block", "60,63-67,71-72,76");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[33]), first, "tb_fifo.sv", 93, 13, ".tb_fifo", "v_branch/tb_fifo", "if", "93-94");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[34]), first, "tb_fifo.sv", 93, 14, ".tb_fifo", "v_branch/tb_fifo", "else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[35]), first, "tb_fifo.sv", 96, 13, ".tb_fifo", "v_branch/tb_fifo", "if", "96-97");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[36]), first, "tb_fifo.sv", 96, 14, ".tb_fifo", "v_branch/tb_fifo", "else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[37]), first, "tb_fifo.sv", 101, 14, ".tb_fifo", "v_line/tb_fifo", "else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[38]), first, "tb_fifo.sv", 80, 20, ".tb_fifo", "v_line/tb_fifo", "block", "80,86-92,99-100,104");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[39]), first, "tb_fifo.sv", 119, 9, ".tb_fifo", "v_line/tb_fifo", "block", "119");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[40]), first, "tb_fifo.sv", 137, 10, ".tb_fifo", "v_line/tb_fifo", "else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[41]), first, "tb_fifo.sv", 149, 10, ".tb_fifo", "v_line/tb_fifo", "else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[42]), first, "tb_fifo.sv", 170, 10, ".tb_fifo", "v_line/tb_fifo", "else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[43]), first, "tb_fifo.sv", 108, 5, ".tb_fifo", "v_line/tb_fifo", "block", "108-110,112-117,119-123,126,129-130,133-136,142,145-148,154-158,161-169,173-174,176-179,181-182");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[0]), first, "fifo.sv", 5, 35, ".tb_fifo.dut", "v_toggle/fifo", "clk", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[1]), first, "fifo.sv", 6, 35, ".tb_fifo.dut", "v_toggle/fifo", "rst", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[2]), first, "fifo.sv", 7, 35, ".tb_fifo.dut", "v_toggle/fifo", "wr_en", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[3]), first, "fifo.sv", 8, 35, ".tb_fifo.dut", "v_toggle/fifo", "rd_en", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[4]), first, "fifo.sv", 9, 35, ".tb_fifo.dut", "v_toggle/fifo", "data_in[0]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[5]), first, "fifo.sv", 9, 35, ".tb_fifo.dut", "v_toggle/fifo", "data_in[1]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[6]), first, "fifo.sv", 9, 35, ".tb_fifo.dut", "v_toggle/fifo", "data_in[2]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[7]), first, "fifo.sv", 9, 35, ".tb_fifo.dut", "v_toggle/fifo", "data_in[3]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[8]), first, "fifo.sv", 9, 35, ".tb_fifo.dut", "v_toggle/fifo", "data_in[4]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[9]), first, "fifo.sv", 9, 35, ".tb_fifo.dut", "v_toggle/fifo", "data_in[5]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[10]), first, "fifo.sv", 9, 35, ".tb_fifo.dut", "v_toggle/fifo", "data_in[6]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[11]), first, "fifo.sv", 9, 35, ".tb_fifo.dut", "v_toggle/fifo", "data_in[7]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[12]), first, "fifo.sv", 10, 35, ".tb_fifo.dut", "v_toggle/fifo", "data_out[0]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[13]), first, "fifo.sv", 10, 35, ".tb_fifo.dut", "v_toggle/fifo", "data_out[1]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[14]), first, "fifo.sv", 10, 35, ".tb_fifo.dut", "v_toggle/fifo", "data_out[2]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[15]), first, "fifo.sv", 10, 35, ".tb_fifo.dut", "v_toggle/fifo", "data_out[3]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[16]), first, "fifo.sv", 10, 35, ".tb_fifo.dut", "v_toggle/fifo", "data_out[4]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[17]), first, "fifo.sv", 10, 35, ".tb_fifo.dut", "v_toggle/fifo", "data_out[5]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[18]), first, "fifo.sv", 10, 35, ".tb_fifo.dut", "v_toggle/fifo", "data_out[6]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[19]), first, "fifo.sv", 10, 35, ".tb_fifo.dut", "v_toggle/fifo", "data_out[7]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[20]), first, "fifo.sv", 11, 35, ".tb_fifo.dut", "v_toggle/fifo", "full", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[21]), first, "fifo.sv", 12, 35, ".tb_fifo.dut", "v_toggle/fifo", "empty", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[44]), first, "fifo.sv", 18, 28, ".tb_fifo.dut", "v_toggle/fifo", "memory[0][0]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[45]), first, "fifo.sv", 18, 28, ".tb_fifo.dut", "v_toggle/fifo", "memory[0][1]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[46]), first, "fifo.sv", 18, 28, ".tb_fifo.dut", "v_toggle/fifo", "memory[0][2]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[47]), first, "fifo.sv", 18, 28, ".tb_fifo.dut", "v_toggle/fifo", "memory[0][3]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[48]), first, "fifo.sv", 18, 28, ".tb_fifo.dut", "v_toggle/fifo", "memory[0][4]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[49]), first, "fifo.sv", 18, 28, ".tb_fifo.dut", "v_toggle/fifo", "memory[0][5]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[50]), first, "fifo.sv", 18, 28, ".tb_fifo.dut", "v_toggle/fifo", "memory[0][6]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[51]), first, "fifo.sv", 18, 28, ".tb_fifo.dut", "v_toggle/fifo", "memory[0][7]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[52]), first, "fifo.sv", 18, 28, ".tb_fifo.dut", "v_toggle/fifo", "memory[1][0]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[53]), first, "fifo.sv", 18, 28, ".tb_fifo.dut", "v_toggle/fifo", "memory[1][1]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[54]), first, "fifo.sv", 18, 28, ".tb_fifo.dut", "v_toggle/fifo", "memory[1][2]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[55]), first, "fifo.sv", 18, 28, ".tb_fifo.dut", "v_toggle/fifo", "memory[1][3]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[56]), first, "fifo.sv", 18, 28, ".tb_fifo.dut", "v_toggle/fifo", "memory[1][4]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[57]), first, "fifo.sv", 18, 28, ".tb_fifo.dut", "v_toggle/fifo", "memory[1][5]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[58]), first, "fifo.sv", 18, 28, ".tb_fifo.dut", "v_toggle/fifo", "memory[1][6]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[59]), first, "fifo.sv", 18, 28, ".tb_fifo.dut", "v_toggle/fifo", "memory[1][7]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[60]), first, "fifo.sv", 18, 28, ".tb_fifo.dut", "v_toggle/fifo", "memory[2][0]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[61]), first, "fifo.sv", 18, 28, ".tb_fifo.dut", "v_toggle/fifo", "memory[2][1]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[62]), first, "fifo.sv", 18, 28, ".tb_fifo.dut", "v_toggle/fifo", "memory[2][2]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[63]), first, "fifo.sv", 18, 28, ".tb_fifo.dut", "v_toggle/fifo", "memory[2][3]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[64]), first, "fifo.sv", 18, 28, ".tb_fifo.dut", "v_toggle/fifo", "memory[2][4]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[65]), first, "fifo.sv", 18, 28, ".tb_fifo.dut", "v_toggle/fifo", "memory[2][5]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[66]), first, "fifo.sv", 18, 28, ".tb_fifo.dut", "v_toggle/fifo", "memory[2][6]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[67]), first, "fifo.sv", 18, 28, ".tb_fifo.dut", "v_toggle/fifo", "memory[2][7]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[68]), first, "fifo.sv", 18, 28, ".tb_fifo.dut", "v_toggle/fifo", "memory[3][0]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[69]), first, "fifo.sv", 18, 28, ".tb_fifo.dut", "v_toggle/fifo", "memory[3][1]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[70]), first, "fifo.sv", 18, 28, ".tb_fifo.dut", "v_toggle/fifo", "memory[3][2]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[71]), first, "fifo.sv", 18, 28, ".tb_fifo.dut", "v_toggle/fifo", "memory[3][3]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[72]), first, "fifo.sv", 18, 28, ".tb_fifo.dut", "v_toggle/fifo", "memory[3][4]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[73]), first, "fifo.sv", 18, 28, ".tb_fifo.dut", "v_toggle/fifo", "memory[3][5]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[74]), first, "fifo.sv", 18, 28, ".tb_fifo.dut", "v_toggle/fifo", "memory[3][6]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[75]), first, "fifo.sv", 18, 28, ".tb_fifo.dut", "v_toggle/fifo", "memory[3][7]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[76]), first, "fifo.sv", 19, 27, ".tb_fifo.dut", "v_toggle/fifo", "read_pointer[0]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[77]), first, "fifo.sv", 19, 27, ".tb_fifo.dut", "v_toggle/fifo", "read_pointer[1]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[78]), first, "fifo.sv", 20, 27, ".tb_fifo.dut", "v_toggle/fifo", "write_pointer[0]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[79]), first, "fifo.sv", 20, 27, ".tb_fifo.dut", "v_toggle/fifo", "write_pointer[1]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[80]), first, "fifo.sv", 21, 29, ".tb_fifo.dut", "v_toggle/fifo", "count[0]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[81]), first, "fifo.sv", 21, 29, ".tb_fifo.dut", "v_toggle/fifo", "count[1]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[82]), first, "fifo.sv", 21, 29, ".tb_fifo.dut", "v_toggle/fifo", "count[2]", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[83]), first, "fifo.sv", 23, 10, ".tb_fifo.dut", "v_toggle/fifo", "write_accept", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[84]), first, "fifo.sv", 24, 10, ".tb_fifo.dut", "v_toggle/fifo", "read_accept", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[85]), first, "fifo.sv", 38, 17, ".tb_fifo.dut", "v_branch/fifo", "if", "38-39");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[86]), first, "fifo.sv", 38, 18, ".tb_fifo.dut", "v_branch/fifo", "else", "40-41");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[87]), first, "fifo.sv", 36, 13, ".tb_fifo.dut", "v_branch/fifo", "if", "36-37");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[88]), first, "fifo.sv", 36, 14, ".tb_fifo.dut", "v_branch/fifo", "else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[89]), first, "fifo.sv", 47, 17, ".tb_fifo.dut", "v_branch/fifo", "if", "47-48");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[90]), first, "fifo.sv", 47, 18, ".tb_fifo.dut", "v_branch/fifo", "else", "49-50");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[91]), first, "fifo.sv", 45, 13, ".tb_fifo.dut", "v_branch/fifo", "if", "45-46");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[92]), first, "fifo.sv", 45, 14, ".tb_fifo.dut", "v_branch/fifo", "else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[93]), first, "fifo.sv", 55, 22, ".tb_fifo.dut", "v_line/fifo", "case", "55");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[94]), first, "fifo.sv", 56, 22, ".tb_fifo.dut", "v_line/fifo", "case", "56");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[95]), first, "fifo.sv", 57, 17, ".tb_fifo.dut", "v_line/fifo", "case", "57");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[96]), first, "fifo.sv", 30, 9, ".tb_fifo.dut", "v_branch/fifo", "if", "30-34");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[97]), first, "fifo.sv", 30, 10, ".tb_fifo.dut", "v_branch/fifo", "else", "35,54");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[98]), first, "fifo.sv", 29, 5, ".tb_fifo.dut", "v_line/fifo", "block", "29");
}
