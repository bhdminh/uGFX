GFXINC	+= $(GFXLIB)/boards/base/STM32F4-Discovery
GFXSRC	+=
GFXDEFS += -DGFX_USE_CHIBIOS=TRUE

include $(GFXLIB)/boards/base/STM32F4-Discovery/chibios_board/board.mk
include $(GFXLIB)/drivers/gdisp/ST7781/driver.mk
#include $(GFXLIB)/drivers/ginput/touch/MCU/driver.mk

