To use this driver:

1. Add in your gfxconf.h:
	a) #define GFX_USE_GDISP		TRUE

2. To your makefile add the following lines:
	include $(GFXLIB)/gfx.mk
	include $(GFXLIB)/drivers/gdisp/STM32F429iDiscovery/driver.mk

3. Add a board_STM32F429iDiscovery.h to you project directory (or board directory)
	base on one of the templates.
