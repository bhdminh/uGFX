/*
 * This file is subject to the terms of the GFX License. If a copy of
 * the license was not distributed with this file, you can obtain one at:
 *
 *              http://ugfx.org/license.html
 */

#ifndef _GDISP_LLD_BOARD_H
#define _GDISP_LLD_BOARD_H

static inline void init_board(GDisplay *g) {
	(void) g;
}

static inline void post_init_board(GDisplay *g) {
	(void) g;
}

static inline void setpin_reset(GDisplay *g, bool_t state) {
	(void) g;
	(void) state;
}

static inline void set_backlight(GDisplay *g, uint8_t percent) {
	(void) g;
	(void) percent;
}

static inline void acquire_bus(GDisplay *g) {
	(void) g;
}

static inline void release_bus(GDisplay *g) {
	(void) g;
}

static inline void write_index(GDisplay *g, uint16_t index) {
	(void) g;
	(void) index;
}

static inline void write_data(GDisplay *g, uint16_t data) {
	(void) g;
	(void) data;
}

static inline void setreadmode(GDisplay *g) {
	(void) g;
}

static inline void setwritemode(GDisplay *g) {
	(void) g;
}

static inline uint16_t read_data(GDisplay *g) {
	(void) g;
	return 0;
}

#if defined(GDISP_USE_DMA) || defined(__DOXYGEN__)
	//#error "GDISP - ST7781: This interface does not support DMA"

	static inline void dma_with_noinc(GDisplay *g, color_t *buffer, int area) {
		(void) g;
		(void) buffer;
		(void) area;
	}

	static inline void dma_with_inc(GDisplay *g, color_t *buffer, int area) {
		(void) g;
		(void) buffer;
		(void) area;
	}
#endif

#endif /* _GDISP_LLD_BOARD_H */
