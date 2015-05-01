/*
 * This file is subject to the terms of the GFX License. If a copy of
 * the license was not distributed with this file, you can obtain one at:
 *
 *              http://ugfx.org/license.html
 */

#ifndef _GINPUT_LLD_MOUSE_BOARD_H
#define _GINPUT_LLD_MOUSE_BOARD_H

#define TOUCH_XP_PORT	IOPORT7
#define TOUCH_YM_PORT	IOPORT7

#define TOUCH_YP_PORT	IOPORT8
#define TOUCH_XM_PORT	IOPORT8

#define TOUCH_YP		1
#define TOUCH_XM		2

#define TOUCH_YM		4
#define TOUCH_XP		3

#define ADC_NUM_CHANNELS   1
#define ADC_BUF_DEPTH      10

ADCConfig adcConfig = {
    ANALOG_REFERENCE_AVCC //condensatore su aref. riferimento avcc
  };

static const ADCConversionGroup adc_y_config = {
    FALSE,
    ADC_NUM_CHANNELS,
    0,
    0,
	0b00000010 //enabled channels
};

static const ADCConversionGroup adc_x_config = {
    FALSE,
    ADC_NUM_CHANNELS,
    0,
    0,
	0b00000100 //enabled channels
};

static inline void init_board(void) {
	adcStart(&ADCD1, &adcConfig);
}

static inline void aquire_bus(void) {

}

static inline void release_bus(void) {

}

static inline void setup_x(void) {
	palSetPadMode(TOUCH_XP_PORT, TOUCH_XP, PAL_MODE_INPUT_PULLUP);
	palSetPadMode(TOUCH_XM_PORT, TOUCH_XM, PAL_MODE_INPUT_PULLUP);
	palSetPadMode(TOUCH_YP_PORT, TOUCH_YP, PAL_MODE_OUTPUT_PUSHPULL);
	palSetPadMode(TOUCH_YM_PORT, TOUCH_YM, PAL_MODE_OUTPUT_PUSHPULL);

//	palSetPad(TOUCH_YP_PORT, TOUCH_YP);
	PORTH |= (1 << TOUCH_YP);
	palClearPad(TOUCH_YM_PORT, TOUCH_YM);
	gfxSleepMilliseconds(1);
}

static inline void setup_y(void) {
	palSetPadMode(TOUCH_YP_PORT, TOUCH_YP, PAL_MODE_INPUT_PULLUP);
	palSetPadMode(TOUCH_YM_PORT, TOUCH_YM, PAL_MODE_INPUT_PULLUP);
	palSetPadMode(TOUCH_XP_PORT, TOUCH_XP, PAL_MODE_OUTPUT_PUSHPULL);
	palSetPadMode(TOUCH_XM_PORT, TOUCH_XM, PAL_MODE_OUTPUT_PUSHPULL);

	palSetPad(TOUCH_XP_PORT, TOUCH_XP);
//	PORTF |= (1 << TOUCH_XP);
//	palClearPad(TOUCH_XM_PORT, TOUCH_XM);
	PORTH &= ~(1 << TOUCH_XM);

	gfxSleepMilliseconds(1);
}

static inline void setup_z(void) {
//	palSetPadMode(TOUCH_XP_PORT, TOUCH_XP, PAL_MODE_INPUT_PULLDOWN);
//	palSetPadMode(GPIOC, 1, PAL_MODE_INPUT);
//	palSetPadMode(GPIOC, 2, PAL_MODE_INPUT);
//	palSetPadMode(GPIOC, 3, PAL_MODE_OUTPUT_PUSHPULL);
//	palSetPad(GPIOC, 3);

	palSetPadMode(TOUCH_XP_PORT, TOUCH_XP, PAL_MODE_OUTPUT_PUSHPULL);
	palClearPad(TOUCH_XP_PORT, TOUCH_XP);

	palSetPadMode(TOUCH_YM_PORT, TOUCH_YM, PAL_MODE_OUTPUT_PUSHPULL);
	palSetPad(TOUCH_YM_PORT, TOUCH_YM);

	palSetPadMode(TOUCH_XM_PORT, TOUCH_XM, PAL_MODE_INPUT_PULLUP);
	palSetPadMode(TOUCH_YP_PORT, TOUCH_YP, PAL_MODE_INPUT_PULLUP);
}

static inline uint16_t read_x(void) {
	uint16_t val1, val2;
	adcsample_t samples[ADC_NUM_CHANNELS * ADC_BUF_DEPTH];

//	palSetPad(TOUCH_YP_PORT, TOUCH_YP);
	PORTH |= (1 << TOUCH_YP);

	palClearPad(TOUCH_YM_PORT, TOUCH_YM);
	gfxSleepMilliseconds(1);
	adcConvert(&ADCD1, &adc_x_config, samples, ADC_BUF_DEPTH);
	val1 = ((samples[0] + samples[1])/2);
	printf(&SD1,"risultatoX:");
	for(int i = 0; i < ADC_BUF_DEPTH*ADC_NUM_CHANNELS;i++)
	{
		adcsample_t  temp = samples[i];
		printf(&SD1," %x", temp);
	}
	printf(&SD1,"\n");

//	palSetPad(TOUCH_YP_PORT, TOUCH_YP);
	PORTH |= (1 << TOUCH_YP);

	palClearPad(TOUCH_YM_PORT, TOUCH_YM);

	gfxSleepMilliseconds(1);
	adcConvert(&ADCD1, &adc_x_config, samples, ADC_BUF_DEPTH);
	val2 = ((samples[0] + samples[1])/2);

	return ((val1+((1<<12)-val2))/4);
}

static inline uint16_t read_y(void) {
	uint16_t val1, val2;
    adcsample_t samples[ADC_NUM_CHANNELS * ADC_BUF_DEPTH];

	palSetPad(TOUCH_XP_PORT, TOUCH_XP);
//	PORTF |= (1 << TOUCH_XP);
//    palClearPad(TOUCH_XM_PORT, TOUCH_XM);
	PORTH &= ~(1 << TOUCH_XM);

    gfxSleepMilliseconds(1);
    adcConvert(&ADCD1, &adc_y_config, samples, ADC_BUF_DEPTH);
    val1 = ((samples[0] + samples[1*ADC_NUM_CHANNELS])/2);
    printf(&SD1,"risultatoY:");
    for(int i = 0; i < ADC_BUF_DEPTH*ADC_NUM_CHANNELS;i++)
    {
    	adcsample_t  temp = samples[i];
    	printf(&SD1," %x", temp);
    }
    printf(&SD1,"\n");

	palSetPad(TOUCH_XP_PORT, TOUCH_XP);
//	PORTF |= (1 << TOUCH_XP);

//    palClearPad(TOUCH_XM_PORT, TOUCH_XM);
	PORTH &= ~(1 << TOUCH_XM);

    gfxSleepMilliseconds(1);
    adcConvert(&ADCD1, &adc_y_config, samples, ADC_BUF_DEPTH);
    val2 = ((samples[0] + samples[1*ADC_NUM_CHANNELS])/2);

	return ((val1+((1<<12)-val2))/4);
}

static inline uint16_t read_z(void) {
	if (palReadPad(TOUCH_YP_PORT, TOUCH_YP))
		return 100;
	else
		return 0;
}

#endif /* _GINPUT_LLD_MOUSE_BOARD_H */

