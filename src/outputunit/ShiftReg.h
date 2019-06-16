/* mbed Shift Register Library, such as for NXP 74HC595
 * Copyright (c) 2012, YoongHM
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
 
#ifndef _SHIFTREG_H
#define _SHIFTREG_H
 
#include "mbed.h"
 
/** A interface to drive shifter register as such 74HCT595
 *
 * @code
 * #include "mbed.h"
 * #include "ShiftReg.h"
 * 
 * ShiftReg   HC595(p21, p22, p23);
 * 
 * int main() {
 *     // clear shift and store registers initially
 *     HC595.ShiftByte(0x00, ShiftReg::MSBFirst); HC595.Latch(); wait(0.2);
 *     
 *     while(1) {
 *         // Demostrate to shift in bit by bit
 *         HC595.ShiftBit(1); HC595.Latch(); wait(0.2);
 *         for (int i = 0; i < 8; i++) {
 *             HC595.ShiftBit(0); HC595.Latch(); wait(0.2);
 *         }
 
 *         // Demostrate to shift in byte-by-byte
 *      // HC595.ShiftByte(0x80, ShiftReg::MSBFirst); HC595.Latch(); wait(0.2);
 *         HC595.ShiftByte(0x40, ShiftReg::MSBFirst); HC595.Latch(); wait(0.2);
 *         HC595.ShiftByte(0x20, ShiftReg::MSBFirst); HC595.Latch(); wait(0.2);
 *         HC595.ShiftByte(0x10, ShiftReg::MSBFirst); HC595.Latch(); wait(0.2);
 *         HC595.ShiftByte(0x08, ShiftReg::MSBFirst); HC595.Latch(); wait(0.2);
 *         HC595.ShiftByte(0x04, ShiftReg::MSBFirst); HC595.Latch(); wait(0.2);
 *         HC595.ShiftByte(0x02, ShiftReg::MSBFirst); HC595.Latch(); wait(0.2);
 *         HC595.ShiftByte(0x01, ShiftReg::MSBFirst); HC595.Latch(); wait(0.2);
 *         HC595.ShiftByte(0x00, ShiftReg::MSBFirst); HC595.Latch(); wait(0.2);
 *     }
 * }
 * @endcode
 */
 
 class ShiftReg
{
public:
    /** Bit order out format */
     enum BitOrd {
         MSBFirst = 0x80,  /**< Most  significant bit first */
         LSBFirst = 0x01   /**< Least significant bit first */
    };
 
    /** Create a ShiftReg interface to shift register
     *
     * @param data     Pin to serial input to shift register
     * @param store    Pin to store register
     * @param clock    Pin to shift into register
     */
    ShiftReg
    (PinName data
    ,PinName store
    ,PinName clock
    );
 
    /** Shift out 8-bit data via the serial pin
     *
     * @param data    Data to be shifted out via the serial pin
     * @param order   Bit order to shift out data. Default is MSBFirst
     */
    void 
    ShiftByte
    (int8_t  data
    ,BitOrd  ord    = MSBFirst
    );
    
    /** Shift out 1-bit data via the serial pin
     *
     * @param data    Data to be shifted out via the serial pin
     */
    void
    ShiftBit
    (int8_t  data = 0
    );
 
    /** Latch data out 
     */
    void 
    Latch();
 
private:
    DigitalOut _ds;          // Serial in
    DigitalOut _st;          // store register or latch
    DigitalOut _sh;          // shift register
    BitOrd     _ord;         // Bit order to shift out data
};
 
#endif // _SHIFTREG_H