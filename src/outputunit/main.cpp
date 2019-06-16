/*
version : v1.0.0-alpha

MIT License

Copyright (c) 2019 nulLeeKH <i_am@nulleekh.com>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
 */

#include "mbed.h"
#include "ShiftReg.h"
 
 //SER, SRCLK, RCLK
 ShiftReg   fir(D0, D1, D2);
 ShiftReg   sec(D3, D4, D5);
 ShiftReg   thr(D6, D7, D8);
 ShiftReg   fou(D9, D10, D11);
 ShiftReg   fif(D12, D13, D14);
 
 int main() {
     
     Serial input(NC, A5);
    
     char temp, trash;
            
     fir.ShiftByte(0, ShiftReg::MSBFirst); fir.Latch();
     sec.ShiftByte(0, ShiftReg::MSBFirst); sec.Latch();
     thr.ShiftByte(0, ShiftReg::MSBFirst); thr.Latch();
     fou.ShiftByte(0, ShiftReg::MSBFirst); fou.Latch();
     fif.ShiftByte(0, ShiftReg::MSBFirst); fif.Latch();
     
     while(1) {
         if (input.getc() == '"') {
            int value[5] = {0, 0, 0, 0, 0};
            for (int i = 0 ; i<5 ; i++) {
                
                trash = input.getc();
                
                if (input.getc() == '1') {
                    value[i] += 0b00000010;
                }
                
                if (input.getc() == '1') {
                    value[i] += 0b00000100;
                }
                
                if (input.getc() == '1') {
                    value[i] += 0b00001000;
                }
                
                if (input.getc() == '1') {
                    value[i] += 0b00010000;
                }
                
                if (input.getc() == '1') {
                    value[i] += 0b00100000;
                }
                
                if (input.getc() == '1') {
                    value[i] += 0b01000000;
                }
        
                trash = input.getc();
            }
            trash = input.getc();
            wait(0.1);
            
            
            fir.ShiftByte(value[0], ShiftReg::MSBFirst); fir.Latch(); wait(0.1);
            sec.ShiftByte(value[1], ShiftReg::MSBFirst); sec.Latch(); wait(0.1);
            thr.ShiftByte(value[2], ShiftReg::MSBFirst); thr.Latch(); wait(0.1);
            fou.ShiftByte(value[3], ShiftReg::MSBFirst); fou.Latch(); wait(0.1);
            fif.ShiftByte(value[4], ShiftReg::MSBFirst); fif.Latch(); wait(0.1);
        }
     }
 }