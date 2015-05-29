/*
 * File:   OLED.h
 * Author:  Eric Freund <eric@affinityengineering.com.au>
 *          Will Anthony <will@affinityengineering.com.au>
 * Description: This is the header file for the display module.
 * Function documentation can be found in the source file.
 *
 * Language: C (CCI)
 * Coding Standard: NASA JPL DOCID D-60411
 * Style: NASA SEL-94-003
 * License: GNU GPL version 3.0
 * Version: 1.0
 *
 * Dependencies:
 * USART.h
 * Compiler: Microchip XC16
 * Compiler Revision: 1.24
 * 
 * Reference Document: Product Specification OEL Display Module UG-2864HLBEG01
 * Document Number: SAS1-9068-A
 * Revision / Date: A / 7 SEP 2009
 *
 * Created on 27 April 2015, 11:23 AM
 * Copyright (C) 2010-2015  Affinity Engineering pty. ltd.
 * <http://www.affinityengineering.com.au>
 * <http://github.com/SPEEDLabCode>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef OLED_H
#define OLED_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <xc.h>

    /*********************************************************************
    Defines
     ********************************************************************/
/*
 * NOTE: These #defines have been placed in the TractionHardware.h header file
 * for the purposes of I/O definition housekeeping.  They are maintained here for
 * reference purposes.
 * 
#define HVEN	_LATC13
#define	OLEDVDD _LATC14
#define BS1		_LATD1
#define BS2		_LATD2
#define CS		_LATD3
#define	RES		_LATD4
#define D_C		_LATD5
#define R_W		_LATD6
#define E_R		_LATD7
 * /

    /*********************************************************************
    Function prototypes
     ********************************************************************/
    void initOLED(void);
    void OLEDcmd(uint8_t DATA);
    void OLEDdata(uint8_t DATA);
    void ClearOLED(void);
    void print_string(char*);
    void print_message(const char*);
    void print_char(char);
    void Gotoxy(int8_t, int8_t);
    void print_big_num(uint16_t, uint16_t, uint16_t);
    void print_string_XY(char*, unsigned char, unsigned char);
    void printSCN(char);

    /*********************************************************************
    variables
     ********************************************************************/
    static const unsigned char FontLookup[96][5] = {
        {0x00, 0x00, 0x00, 0x00, 0x00}, // (space) 
        {0x00, 0x00, 0x5F, 0x00, 0x00}, // ! 
        {0x00, 0x07, 0x00, 0x07, 0x00}, // " 
        {0x14, 0x7F, 0x14, 0x7F, 0x14}, // # 
        {0x24, 0x2A, 0x7F, 0x2A, 0x12}, // $ 
        {0x23, 0x13, 0x08, 0x64, 0x62}, // % 
        {0x36, 0x49, 0x55, 0x22, 0x50}, // & 
        {0x00, 0x05, 0x03, 0x00, 0x00}, // ' 
        {0x00, 0x1C, 0x22, 0x41, 0x00}, // ( 
        {0x00, 0x41, 0x22, 0x1C, 0x00}, // ) 
        {0x08, 0x2A, 0x1C, 0x2A, 0x08}, // * 
        {0x08, 0x08, 0x3E, 0x08, 0x08}, // + 
        {0x00, 0x50, 0x30, 0x00, 0x00}, // , 
        {0x08, 0x08, 0x08, 0x08, 0x08}, // - 
        {0x00, 0x30, 0x30, 0x00, 0x00}, // . 
        {0x20, 0x10, 0x08, 0x04, 0x02}, // / 
        {0x3E, 0x51, 0x49, 0x45, 0x3E}, // 0 
        {0x00, 0x42, 0x7F, 0x40, 0x00}, // 1 
        {0x42, 0x61, 0x51, 0x49, 0x46}, // 2 
        {0x21, 0x41, 0x45, 0x4B, 0x31}, // 3 
        {0x18, 0x14, 0x12, 0x7F, 0x10}, // 4 
        {0x27, 0x45, 0x45, 0x45, 0x39}, // 5 
        {0x3C, 0x4A, 0x49, 0x49, 0x30}, // 6 
        {0x01, 0x71, 0x09, 0x05, 0x03}, // 7 
        {0x36, 0x49, 0x49, 0x49, 0x36}, // 8 
        {0x06, 0x49, 0x49, 0x29, 0x1E}, // 9 
        {0x00, 0x36, 0x36, 0x00, 0x00}, // : 
        {0x00, 0x56, 0x36, 0x00, 0x00}, // ; 
        {0x00, 0x08, 0x14, 0x22, 0x41}, // < 
        {0x14, 0x14, 0x14, 0x14, 0x14}, // = 
        {0x41, 0x22, 0x14, 0x08, 0x00}, // > 
        {0x02, 0x01, 0x51, 0x09, 0x06}, // ? 
        {0x32, 0x49, 0x79, 0x41, 0x3E}, // @ 
        {0x7E, 0x11, 0x11, 0x11, 0x7E}, // A 
        {0x7F, 0x49, 0x49, 0x49, 0x36}, // B 
        {0x3E, 0x41, 0x41, 0x41, 0x22}, // C 
        {0x7F, 0x41, 0x41, 0x22, 0x1C}, // D 
        {0x7F, 0x49, 0x49, 0x49, 0x41}, // E 
        {0x7F, 0x09, 0x09, 0x01, 0x01}, // F 
        {0x3E, 0x41, 0x41, 0x51, 0x32}, // G 
        {0x7F, 0x08, 0x08, 0x08, 0x7F}, // H 
        {0x00, 0x41, 0x7F, 0x41, 0x00}, // I 
        {0x20, 0x40, 0x41, 0x3F, 0x01}, // J 
        {0x7F, 0x08, 0x14, 0x22, 0x41}, // K 
        {0x7F, 0x40, 0x40, 0x40, 0x40}, // L 
        {0x7F, 0x02, 0x04, 0x02, 0x7F}, // M 
        {0x7F, 0x04, 0x08, 0x10, 0x7F}, // N 
        {0x3E, 0x41, 0x41, 0x41, 0x3E}, // O 
        {0x7F, 0x09, 0x09, 0x09, 0x06}, // P 
        {0x3E, 0x41, 0x51, 0x21, 0x5E}, // Q 
        {0x7F, 0x09, 0x19, 0x29, 0x46}, // R 
        {0x46, 0x49, 0x49, 0x49, 0x31}, // S 
        {0x01, 0x01, 0x7F, 0x01, 0x01}, // T 
        {0x3F, 0x40, 0x40, 0x40, 0x3F}, // U 
        {0x1F, 0x20, 0x40, 0x20, 0x1F}, // V 
        {0x7F, 0x20, 0x18, 0x20, 0x7F}, // W 
        {0x63, 0x14, 0x08, 0x14, 0x63}, // X 
        {0x03, 0x04, 0x78, 0x04, 0x03}, // Y 
        {0x61, 0x51, 0x49, 0x45, 0x43}, // Z 
        {0x00, 0x00, 0x7F, 0x41, 0x41}, // [ 
        {0x02, 0x04, 0x08, 0x10, 0x20}, // "\" 
        {0x41, 0x41, 0x7F, 0x00, 0x00}, // ] 
        {0x04, 0x02, 0x01, 0x02, 0x04}, // ^ 
        {0x40, 0x40, 0x40, 0x40, 0x40}, // _ 
        {0x00, 0x01, 0x02, 0x04, 0x00}, // ` 
        {0x20, 0x54, 0x54, 0x54, 0x78}, // a 
        {0x7F, 0x48, 0x44, 0x44, 0x38}, // b 
        {0x38, 0x44, 0x44, 0x44, 0x20}, // c 
        {0x38, 0x44, 0x44, 0x48, 0x7F}, // d 
        {0x38, 0x54, 0x54, 0x54, 0x18}, // e 
        {0x08, 0x7E, 0x09, 0x01, 0x02}, // f 
        {0x08, 0x14, 0x54, 0x54, 0x3C}, // g 
        {0x7F, 0x08, 0x04, 0x04, 0x78}, // h 
        {0x00, 0x44, 0x7D, 0x40, 0x00}, // i 
        {0x20, 0x40, 0x44, 0x3D, 0x00}, // j 
        {0x00, 0x7F, 0x10, 0x28, 0x44}, // k 
        {0x00, 0x41, 0x7F, 0x40, 0x00}, // l 
        {0x7C, 0x04, 0x18, 0x04, 0x78}, // m 
        {0x7C, 0x08, 0x04, 0x04, 0x78}, // n 
        {0x38, 0x44, 0x44, 0x44, 0x38}, // o 
        {0x7C, 0x14, 0x14, 0x14, 0x08}, // p 
        {0x08, 0x14, 0x14, 0x18, 0x7C}, // q 
        {0x7C, 0x08, 0x04, 0x04, 0x08}, // r 
        {0x48, 0x54, 0x54, 0x54, 0x20}, // s 
        {0x04, 0x3F, 0x44, 0x40, 0x20}, // t 
        {0x3C, 0x40, 0x40, 0x20, 0x7C}, // u 
        {0x1C, 0x20, 0x40, 0x20, 0x1C}, // v 
        {0x3C, 0x40, 0x30, 0x40, 0x3C}, // w 
        {0x44, 0x28, 0x10, 0x28, 0x44}, // x 
        {0x0C, 0x50, 0x50, 0x50, 0x3C}, // y 
        {0x44, 0x64, 0x54, 0x4C, 0x44}, // z 
        {0x00, 0x08, 0x36, 0x41, 0x00}, // { 
        {0x00, 0x00, 0x7F, 0x00, 0x00}, // | 
        {0x00, 0x41, 0x36, 0x08, 0x00}, // } 
        {0x08, 0x08, 0x2A, 0x1C, 0x08}, // -> 
        {0x08, 0x1C, 0x2A, 0x08, 0x08} // <- 
    };

    static const unsigned char bignum[3][120] = {
        {0xC0, 0xE0, 0x70, 0x38, 0x18, 0x18, 0x18, 0x18, 0x38, 0x70, 0xE0, 0xC0, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x10, 0xF8, 0xF8, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xE0, 0x70, 0x38, 0x18, 0x18, 0x18, 0x18,
            0x38, 0x70, 0xE0, 0xC0, 0xC0, 0xE0, 0x70, 0x38, 0x18, 0x18, 0x18, 0x18, 0x38, 0x70, 0xE0, 0xC0,
            0x00, 0x00, 0x00, 0x00, 0x80, 0xE0, 0x78, 0x18, 0xF8, 0xF8, 0x00, 0x00, 0xF8, 0xF8, 0x18, 0x18,
            0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0xC0, 0xE0, 0x70, 0x38, 0x18, 0x18, 0x18, 0x18,
            0x38, 0x70, 0xE0, 0xC0, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0xF8, 0xF8,
            0xC0, 0xE0, 0x70, 0x38, 0x18, 0x18, 0x18, 0x18, 0x38, 0x70, 0xE0, 0xC0, 0xC0, 0xE0, 0x70, 0x38,
            0x18, 0x18, 0x18, 0x18, 0x38, 0x70, 0xE0, 0xC0},

        {0xFF, 0xFF, 0x80, 0xC0, 0x60, 0x30, 0x18, 0x0C, 0x06, 0x03, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xC0, 0xE0, 0x70, 0x38,
            0x1C, 0x0E, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x38, 0x7C, 0xEE, 0xC7, 0x83,
            0x80, 0xE0, 0xF8, 0x9E, 0x87, 0x81, 0x80, 0x80, 0xFF, 0xFF, 0x80, 0x80, 0x1F, 0x1F, 0x0C, 0x0E,
            0x06, 0x06, 0x06, 0x06, 0x0E, 0x1C, 0xF8, 0xF0, 0xFF, 0xFF, 0x38, 0x1C, 0x0C, 0x0C, 0x0C, 0x0C,
            0x1C, 0x38, 0xF0, 0xE0, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xE0, 0x70, 0x38, 0x1C, 0x0E, 0x07, 0x03,
            0xC7, 0xEF, 0x7C, 0x38, 0x18, 0x18, 0x18, 0x18, 0x38, 0x7C, 0xEF, 0xC7, 0x0F, 0x1F, 0x38, 0x70,
            0x60, 0x60, 0x60, 0x60, 0x70, 0x38, 0xFF, 0xFF},

        {0x07, 0x0F, 0x1D, 0x38, 0x30, 0x30, 0x30, 0x30, 0x38, 0x1C, 0x0F, 0x07, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x20, 0x3F, 0x3F, 0x20, 0x00, 0x00, 0x00, 0x38, 0x3E, 0x3F, 0x33, 0x31, 0x30, 0x30, 0x30,
            0x30, 0x30, 0x30, 0x38, 0x06, 0x0E, 0x1C, 0x38, 0x30, 0x30, 0x30, 0x30, 0x38, 0x1C, 0x0F, 0x07,
            0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x21, 0x3F, 0x3F, 0x21, 0x01, 0x06, 0x0E, 0x1C, 0x38,
            0x30, 0x30, 0x30, 0x30, 0x38, 0x1C, 0x0F, 0x07, 0x07, 0x0F, 0x1C, 0x38, 0x30, 0x30, 0x30, 0x30,
            0x38, 0x1C, 0x0F, 0x07, 0x00, 0x00, 0x00, 0x1F, 0x1F, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x0F, 0x1F, 0x38, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x38, 0x1F, 0x0F, 0x06, 0x0E, 0x1C, 0x38,
            0x30, 0x30, 0x30, 0x30, 0x38, 0x1C, 0x0F, 0x07}
    };
#ifdef	__cplusplus
}
#endif

#endif /* OLED_H */

