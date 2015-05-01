/*
 * This file is subject to the terms of the GFX License. If a copy of
 * the license was not distributed with this file, you can obtain one at:
 *
 *              http://ugfx.org/license.html
 */

#ifndef _GDISP_LLD_BOARD_H
#define _GDISP_LLD_BOARD_H

// For a multiple display configuration we would put all this in a structure and then
//	set g->board to that structure.
#define SET_CS		palSetPad(IOPORT6, 3);
#define CLR_CS		palClearPad(IOPORT6, 3);
#define SET_RS		palSetPad(IOPORT6, 2);
#define CLR_RS		palClearPad(IOPORT6, 2);
#define SET_WR		palSetPad(IOPORT6, 1);
#define CLR_WR		palClearPad(IOPORT6, 1);
#define SET_RD		palSetPad(IOPORT6, 0);
#define CLR_RD		palClearPad(IOPORT6, 0);

static inline void init_board(GDisplay *g)
{

	// As we are not using multiple displays we set g->board to NULL as we don't use it.
	g->board = 0;

	switch(g->controllerdisplay) {
	case 0:											// Set up for Display 0

		// Arduino Mega2560 Pinout

		palSetGroupMode(IOPORT5, (ioportmask_t)0x07, 3, PAL_MODE_OUTPUT_PUSHPULL);
		palSetGroupMode(IOPORT7, (ioportmask_t)0x01, 5, PAL_MODE_OUTPUT_PUSHPULL);
		palSetGroupMode(IOPORT8, (ioportmask_t)0x0F, 3, PAL_MODE_OUTPUT_PUSHPULL);

		palSetPadMode(IOPORT6, 0, PAL_MODE_OUTPUT_PUSHPULL);
		palSetPadMode(IOPORT6, 1, PAL_MODE_OUTPUT_PUSHPULL);
		palSetPadMode(IOPORT6, 2, PAL_MODE_OUTPUT_PUSHPULL);
		palSetPadMode(IOPORT6, 3, PAL_MODE_OUTPUT_PUSHPULL);
		palSetPadMode(IOPORT6, 4, PAL_MODE_OUTPUT_PUSHPULL);

		// Configure the pins to a well know state
		SET_RS;
		SET_RD;
		SET_WR;
		SET_CS;

		break;
	}
}

static inline void post_init_board(GDisplay *g)
{
	(void) g;
}

static inline void setpin_reset(GDisplay *g, bool_t state)
{
	(void) g;
	(void) state;

	/* Nothing to do here - reset pin tied to Vcc */
	if(state == TRUE) {
		palClearPad(IOPORT6, 4);
	} else {
		palSetPad(IOPORT6, 4);
	}
}

static inline void set_backlight(GDisplay *g, uint8_t percent)
{
	(void) g;
	(void) percent;

	/* Nothing to do here - Backlight always on */
}

static inline void acquire_bus(GDisplay *g)
{
	(void) g;
//	CLR_CS;
}

static inline void release_bus(GDisplay *g)
{
	(void) g;
//	SET_CS;
}

static inline write_byte(uint8_t data)
{
//	//	palWritePort(PORTE, (index & 0xFF00) >> 8);
	PORTE = (PORTE & 0b11001111) | ((data << 2) & 0b00110000);
	PORTE = (PORTE & 0b11110111) | ((data >> 2) & 0b00001000);
	PORTG = (PORTG & 0b11011111) | ((data << 1) & 0b00100000);
	PORTH = (PORTH & 0b11100111) | ((data >> 3) & 0b00011000);
	PORTH = (PORTH & 0b10011111) | ((data << 5) & 0b01100000);

	CLR_WR;
	SET_WR;
}

static inline void write_index(GDisplay *g, uint16_t index)
{
	(void) g;
	CLR_CS;
	CLR_RS;
	SET_RD;

//	palWritePort(PORTE, (index & 0xFF00) >> 8);
//	CLR_WR;
//	SET_WR;

//	palWritePort(PORTE, index & 0xFF);
//	CLR_WR;
//	SET_WR;

	write_byte((index&0xFF00) >> 8);
	write_byte((index&0xFF));

	SET_RS;
	SET_CS;
}

static inline void write_data(GDisplay *g, uint16_t data)
{
	(void) g;
	CLR_CS;
	SET_RS;
	SET_RS;

//	palWritePort(GPIOE, (data & 0xFF00) >> 8);
//	CLR_WR;
//	SET_WR;
//	palWritePort(GPIOE, data & 0xFF);
//	CLR_WR;
//	SET_WR;

	write_byte((data&0xFF00) >> 8);
	write_byte((data&0xFF));

	SET_CS;
}

static inline void setreadmode(GDisplay *g)
{
	(void) g;

	// change pin mode to digital input
//	palSetGroupMode(GPIOE, PAL_WHOLE_PORT, 0, PAL_MODE_INPUT);
	palSetGroupMode(IOPORT5, (ioportmask_t)0x07, 3, PAL_MODE_INPUT);
	palSetGroupMode(IOPORT7, (ioportmask_t)0x01, 5, PAL_MODE_INPUT);
	palSetGroupMode(IOPORT8, (ioportmask_t)0x0F, 3, PAL_MODE_INPUT);
	CLR_RD;
}

static inline void setwritemode(GDisplay *g)
{
	(void) g;
	
	// change pin mode back to digital output
	SET_RD;
//	palSetGroupMode(GPIOE, PAL_WHOLE_PORT, 0, PAL_MODE_OUTPUT_PUSHPULL);
	palSetGroupMode(IOPORT5, (ioportmask_t)0x07, 3, PAL_MODE_OUTPUT_PUSHPULL);
	palSetGroupMode(IOPORT7, (ioportmask_t)0x01, 5, PAL_MODE_OUTPUT_PUSHPULL);
	palSetGroupMode(IOPORT8, (ioportmask_t)0x0F, 3, PAL_MODE_OUTPUT_PUSHPULL);
}

static inline uint16_t read_data(GDisplay *g) {
	(void) g;

//	return palReadPort(GPIOE);
	uint16_t result = 0;
	result = ((PINH & 0b00011000) << 3) | 	\
			 ((PINE & 0b00001000) << 2) | 	\
			 ((PING & 0b00100000) >> 1) |	\
			 ((PINE & 0b00110000) >> 2) | 	\
			 ((PINH & 0b01100000) >> 5);
	return result;
}

#if defined(GDISP_USE_DMA)
	#error "GDISP - ST7781: The GPIO interface does not support DMA"
#endif

#endif /* _GDISP_LLD_BOARD_H */

