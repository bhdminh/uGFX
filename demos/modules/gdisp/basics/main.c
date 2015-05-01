/*
 * Copyright (c) 2012, 2013, Joel Bodenmann aka Tectu <joel@unormal.org>
 * Copyright (c) 2012, 2013, Andrew Hannam aka inmarket
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *    * Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *    * Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer in the
 *      documentation and/or other materials provided with the distribution.
 *    * Neither the name of the <organization> nor the
 *      names of its contributors may be used to endorse or promote products
 *      derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "gfx.h"
//#include "ch.h"
//#include "hal.h"
//#include "test.h"
//
//static WORKING_AREA(waThread1, 32);
//static msg_t Thread1(void *arg) {
//
//  while (TRUE) {
//    palTogglePad(IOPORT2, PORTB_LED1);
//    chThdSleepMilliseconds(1000);
//  }
//  return 0;
//}

int main(void) {
	coord_t		width, height;
	coord_t		i, j;

    // Initialize and clear the display
    gfxInit();
    gdispSetOrientation(GDISP_ROTATE_180);

    // Get the screen size
    width = gdispGetWidth();
    height = gdispGetHeight();

    // Code Here
	gdispDrawBox(10, 10, width/2, height/2, Yellow);
    gdispFillArea(width/2, height/2, width/2-10, height/2-10, Blue);
    gdispDrawLine(5, 30, width-50, height-40, Red);
    
	for(i = 5, j = 0; i < width && j < height; i += 7, j += i/20)
    	gdispDrawPixel(i, j, Red);

//	/*
//	 * Activates the serial driver 1 using the driver default configuration.
//	 */
//	palClearPad(IOPORT2, PORTB_LED1);
//	sdStart(&SD1, NULL);
//
//	/*
//	 * Starts the LED blinker thread.
//	 */
//	chThdCreateStatic(waThread1, sizeof(waThread1), NORMALPRIO, Thread1, NULL);
//
//	TestThread(&SD1);
    while(TRUE) {
    	gfxSleepMilliseconds(500);
    }   
}
