GFXINC	+= $(GFXLIB)/boards/base/ARDUINO-MEGA2560
GFXSRC	+=
GFXDEFS += -DGFX_USE_CHIBIOS=TRUE

include $(GFXLIB)/boards/base/ARDUINO-MEGA2560/chibios_board/board.mk
include $(GFXLIB)/drivers/gdisp/ST7781/driver.mk
include $(GFXLIB)/drivers/ginput/touch/MCU/driver.mk

