GFXINC  +=	$(GFXLIB)/boards/base/STM32F429i-Discovery
GFXSRC  +=	$(GFXLIB)/boards/base/STM32F429i-Discovery/stm32f429i_discovery_sdram.c \
			$(GFXLIB)/boards/base/STM32F429i-Discovery/stm32f4xx_fmc.c

GFXDEFS += -DGFX_USE_OS_CHIBIOS=TRUE
include $(GFXLIB)/drivers/gdisp/STM32F429iDiscovery/driver.mk
#include $(GFXLIB)/drivers/ginput/touch/MCU/driver.mk
#include $(GFXLIB)/drivers/gaudio/vs1053/driver.mk
