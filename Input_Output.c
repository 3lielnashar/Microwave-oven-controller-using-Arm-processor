#include "Input_Output.h"

void RGB_LED_INIT(void){

	SYSCTL_RCGCGPIO_R |=  0x20;
	while((SYSCTL_PRGPIO_R & 0x20) == 0 ){};
	GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY;
	GPIO_PORTF_CR_R |= 0x0E;
	GPIO_PORTF_AFSEL_R &= ~0x0E;
	GPIO_PORTF_PCTL_R &= ~0x00000FFF0;
	GPIO_PORTF_AMSEL_R &= ~0x0E;
	GPIO_PORTF_DEN_R |= 0x0E;
	GPIO_PORTF_DIR_R |= 0x0E;
	GPIO_PORTF_DATA_R &= ~0x0E;
	}

	void SW1_INIT(void){
	
	GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY;
	GPIO_PORTF_CR_R |= 0x10;
	GPIO_PORTF_AFSEL_R &= ~0x10;
	GPIO_PORTF_PCTL_R &= ~0x000F0000;
	GPIO_PORTF_AMSEL_R &= ~0x10;
	GPIO_PORTF_DEN_R |= 0x10;
	GPIO_PORTF_DIR_R &= ~0x10;
	GPIO_PORTF_PUR_R |= 0x10;
	}

	void SW2_INIT(void){
	
	GPIO_PORTF_LOCK_R =  GPIO_LOCK_KEY;
	GPIO_PORTF_CR_R  |= 0x01;
	GPIO_PORTF_AFSEL_R &= ~0x01;
	GPIO_PORTF_PCTL_R &= ~0x0000000F;
	GPIO_PORTF_AMSEL_R &= ~0x01;
	GPIO_PORTF_DEN_R |= 0x01;
	GPIO_PORTF_DIR_R &= ~0x01;
	GPIO_PORTF_PUR_R |= 0x01;
	}
	
	void SW3_INIT(void){
	
	GPIO_PORTA_LOCK_R =  GPIO_LOCK_KEY;
	GPIO_PORTA_CR_R  |= 0x04;
	GPIO_PORTA_AFSEL_R &= ~0x04;
	GPIO_PORTA_PCTL_R &= ~0x00000F00;
	GPIO_PORTA_AMSEL_R &= ~0x04;
	GPIO_PORTA_DEN_R |= 0x04;
	GPIO_PORTA_DIR_R &= ~0x04;
	}

	uint8_t SW1_INPUT(){
	
		return (GPIO_PORTF_DATA_R & 0x10);
	}
	
	uint8_t SW2_INPUT(){
	
		return (GPIO_PORTF_DATA_R & 0x01);
	}
	
	uint8_t SW3_INPUT(){
	
		return (GPIO_PORTF_DATA_R & 0x04);
	}
	
	void RGB_OUTPUT(uint8_t led){
	
		GPIO_PORTF_DATA_R &= ~0x0E;
		GPIO_PORTF_DATA_R |= led;
	}
	