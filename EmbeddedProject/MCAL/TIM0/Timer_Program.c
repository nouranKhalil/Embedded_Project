
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "Timers_Config.h"
#include "Timer_Interface.h"
#include "Timer_Private.h"

void vTIMER0_Init(void)
{
	/*1. Select Mode*/
	vTimer0_SetMode(TIMER0_MODE);

	/*2- Select OC0 Pin Mode*/
	vTimer0_OC0_SetMode(TIMER0_OC0_MODE);

	/*3- Set Pre-load "Initial Counting Value" Value*/
	vTimer0_SetPreLoad(TIMER0_INITIAL_VALUE);

	/*4- Set Compare Match Value*/
	vTimer0_SetOCRValue(TIMER0_OCR0_VALUE);

	/*5- Enable/ Disable OV Interrupt*/
	vTimer0_OVF_InterruptDisable();

	/*6- Enable/ Disable OC Interrupt*/
	vTimer0_OCM_InterruptDisable();
}

void vTimer0_OVF_InterruptEnable(void)
{
	SET_BIT(TIMSK,TOIE0);
}

void vTimer0_OVF_InterruptDisable(void)
{
	CLR_BIT(TIMSK,TOIE0);
}

void vTimer0_OCM_InterruptEnable(void)
{
	SET_BIT(TIMSK,OCIE0);
}

void vTimer0_OCM_InterruptDisable(void)
{
	CLR_BIT(TIMSK,OCIE0);
}

void vTimer0_SetPreLoad(u8 value)
{
	TCNT0 = value;
}

void vTimer0_SetOCRValue(u8 value)
{
	OCR0 = value;
}

void vTimer0_SetMode(u8 mode)
{
	switch(mode)
	{
	case TIMER0_NORMAL_MODE:
		CLR_BIT(TCCR0,WGM01);
		CLR_BIT(TCCR0,WGM00);
		break;

	case TIMER0_PHASECORRECT_MODE:
		CLR_BIT(TCCR0,WGM01);
		SET_BIT(TCCR0,WGM00);
		break;

	case TIMER0_CTC_MODE:
		SET_BIT(TCCR0,WGM01);
		CLR_BIT(TCCR0,WGM00);
		break;

	case TIMER0_FASTPWM_MODE:
		SET_BIT(TCCR0,WGM01);
		SET_BIT(TCCR0,WGM00);
		break;

	default:
		/*error handling*/
		break;
	}
}

void vTimer0_OC0_SetMode(u8 mode)
{
	switch(mode)
	{
	case TIMER_OC_DISCONNECTED:
		CLR_BIT(TCCR0,COM00);
		CLR_BIT(TCCR0,COM01);
		break;

	case TIMER_OC_TOGGLE:
		SET_BIT(TCCR0,COM00);
		CLR_BIT(TCCR0,COM01);
		break;

	case TIMER_OC_NON_INVERTING:
		CLR_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);
		break;

	case TIMER_OC_INVERTING:
		SET_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);
		break;

	default:
		/*error handling*/
		break;
	}
}

void vTIMER0_Start(void)
{
	vTimer0_PrescalerSelect(TIMER0_PRESCALER);
}

void vTIMER0_Stop(void)
{
	CLR_BIT(TCCR0,CS00);
	CLR_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS02);
}

void vTimer0_PrescalerSelect(u8 prescaler)
{
	switch(prescaler)
	{
	case TIMER_SCALER_1:
		SET_BIT(TCCR0,CS00);
		CLR_BIT(TCCR0,CS01);
		CLR_BIT(TCCR0,CS02);
		break;
	case TIMER_SCALER_8:
		CLR_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		CLR_BIT(TCCR0,CS02);
		break;
	case TIMER_SCALER_64:
		SET_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		CLR_BIT(TCCR0,CS02);
		break;
	case TIMER_SCALER_256:
		CLR_BIT(TCCR0,CS00);
		CLR_BIT(TCCR0,CS01);
		SET_BIT(TCCR0,CS02);
		break;
	case TIMER_SCALER_1024:
		SET_BIT(TCCR0,CS00);
		CLR_BIT(TCCR0,CS01);
		SET_BIT(TCCR0,CS02);
		break;
	case EXTERNALl_FALLING:
		CLR_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		SET_BIT(TCCR0,CS02);
		break;
	case EXTERNAL_RISING:
		SET_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		SET_BIT(TCCR0,CS02);
		break;
	default:
		/*error handling*/
		break;
	}
}

/***************************Timer 1************************************/


void vTimer1_Init(void)
{
	/*1. Select Mode*/
	vTimer1_SetMode(TIMER1_MODE);

	/*2- Select OC1A Pin Mode*/
	vTimer1_OC1A_SetMode(TIMER1_OC1A_MODE);
	/*3- Select OC1B Pin Mode*/
	vTimer1_OC1B_SetMode(TIMER1_OC1B_MODE);

	/*3- Set Pre-load "Initial Counting Value" Value*/
	vTimer1_SetPreLoad(TIMER1_INITIAL_VALUE);

	/*4- Set Compare Match Value*/
	vTimer1_SetOCR_A_Value(TIMER1_OCR1A_VALUE);
	vTimer1_SetOCR_B_Value(TIMER1_OCR1B_VALUE);

	/*6- Set ICR Value*/
	vTimer1_SetICR_Value(TIMER1_ICR_VALUE);

	/*7- Disable Interrupts*/
	vTimer1_OVF_InterruptDisable();
	vTimer1_OCM_A_InterruptDisable();
	vTimer1_OCM_B_InterruptDisable();
}

void vTimer1_Start(void)
{
	vTimer1_PrescalerSelect(TIMER1_PRESCALER);
}

void vTimer1_Stop(void)
{
	CLR_BIT(TCCR1B,CS10);
	CLR_BIT(TCCR1B,CS11);
	CLR_BIT(TCCR1B,CS12);
}
void vTimer1_SetMode(u8 mode)
{
    switch(mode)
    {
        case TIMER1_NORMAL_MODE:
            // Normal mode: WGM13 = 0, WGM12 = 0, WGM11 = 0, WGM10 = 0
            CLR_BIT(TCCR1A, WGM10);
            CLR_BIT(TCCR1A, WGM11);
            CLR_BIT(TCCR1B, WGM12);
            CLR_BIT(TCCR1B, WGM13);
            break;

        case TIMER1_PWM_PHASE_CORRECT_MODE_8:
            // Phase Correct PWM, 8-bit: WGM13 = 0, WGM12 = 0, WGM11 = 0, WGM10 = 1
            CLR_BIT(TCCR1A, WGM11);
            CLR_BIT(TCCR1B, WGM12);
            CLR_BIT(TCCR1B, WGM13);
            SET_BIT(TCCR1A, WGM10);
            break;

        case TIMER1_PWM_PHASE_CORRECT_MODE_9:
            // Phase Correct PWM, 9-bit: WGM13 = 0, WGM12 = 0, WGM11 = 1, WGM10 = 0
            CLR_BIT(TCCR1A, WGM10);
            CLR_BIT(TCCR1B, WGM12);
            CLR_BIT(TCCR1B, WGM13);
            SET_BIT(TCCR1A, WGM11);
            break;

        case TIMER1_PWM_PHASE_CORRECT_MODE_10:
            // Phase Correct PWM, 10-bit: WGM13 = 0, WGM12 = 0, WGM11 = 1, WGM10 = 1
            SET_BIT(TCCR1A, WGM10);
            SET_BIT(TCCR1A, WGM11);
            CLR_BIT(TCCR1B, WGM12);
            CLR_BIT(TCCR1B, WGM13);
            break;

        case TIMER1_CTC_MODE_OCRA_IS_TOP:
            // CTC with OCRA as top: WGM13 = 0, WGM12 = 1, WGM11 = 0, WGM10 = 0
            CLR_BIT(TCCR1A, WGM10);
            CLR_BIT(TCCR1A, WGM11);
            SET_BIT(TCCR1B, WGM12);
            CLR_BIT(TCCR1B, WGM13);
            break;

        case TIMER1_PWM_FAST_MODE_8:
            // Fast PWM, 8-bit: WGM13 = 0, WGM12 = 1, WGM11 = 0, WGM10 = 1
            SET_BIT(TCCR1A, WGM10);
            CLR_BIT(TCCR1A, WGM11);
            SET_BIT(TCCR1B, WGM12);
            CLR_BIT(TCCR1B, WGM13);
            break;

        case TIMER1_PWM_FAST_MODE_9:
            // Fast PWM, 9-bit: WGM13 = 0, WGM12 = 1, WGM11 = 1, WGM10 = 0
            CLR_BIT(TCCR1A, WGM10);
            SET_BIT(TCCR1A, WGM11);
            SET_BIT(TCCR1B, WGM12);
            CLR_BIT(TCCR1B, WGM13);
            break;

        case TIMER1_PWM_FAST_MODE_10:
            // Fast PWM, 10-bit: WGM13 = 0, WGM12 = 1, WGM11 = 1, WGM10 = 1
            SET_BIT(TCCR1A, WGM10);
            SET_BIT(TCCR1A, WGM11);
            SET_BIT(TCCR1B, WGM12);
            CLR_BIT(TCCR1B, WGM13);
            break;

        case TIMER1_PWM_PHASE_FREQ_CORRECT_ICR_IS_TOP:
            // Phase Frequency Correct PWM, ICR as top: WGM13 = 1, WGM12 = 0, WGM11 = 0, WGM10 = 0
            CLR_BIT(TCCR1A, WGM10);
            CLR_BIT(TCCR1A, WGM11);
            CLR_BIT(TCCR1B, WGM12);
            SET_BIT(TCCR1B, WGM13);
            break;

        case TIMER1_PWM_PHASE_FREQ_CORRECT_OCRA_IS_TOP:
            // Phase Frequency Correct PWM, OCRA as top: WGM13 = 1, WGM12 = 0, WGM11 = 1, WGM10 = 0
            CLR_BIT(TCCR1A, WGM10);
            SET_BIT(TCCR1A, WGM11);
            CLR_BIT(TCCR1B, WGM12);
            SET_BIT(TCCR1B, WGM13);
            break;

        case TIMER1_PWM_PHASE_CORRECT_ICR_IS_TOP:
            // Phase Correct PWM, ICR as top: WGM13 = 1, WGM12 = 0, WGM11 = 1, WGM10 = 0
            CLR_BIT(TCCR1A, WGM10);
            SET_BIT(TCCR1A, WGM11);
            CLR_BIT(TCCR1B, WGM12);
            SET_BIT(TCCR1B, WGM13);
            break;

        case TIMER1_PWM_PHASE_CORRECT_OCRA_IS_TOP:
            // Phase Correct PWM, OCRA as top: WGM13 = 1, WGM12 = 0, WGM11 = 1, WGM10 = 1
            SET_BIT(TCCR1A, WGM10);
            SET_BIT(TCCR1A, WGM11);
            CLR_BIT(TCCR1B, WGM12);
            SET_BIT(TCCR1B, WGM13);
            break;

        case TIMER1_CTC_MODE_ICR_IS_TOP:
            // CTC with ICR as top: WGM13 = 1, WGM12 = 1, WGM11 = 0, WGM10 = 0
            CLR_BIT(TCCR1A, WGM10);
            CLR_BIT(TCCR1A, WGM11);
            SET_BIT(TCCR1B, WGM12);
            SET_BIT(TCCR1B, WGM13);
            break;

        case TIMER1_PWM_FAST_MODE_ICR_IS_TOP:
            // Fast PWM, ICR as top: WGM13 = 1, WGM12 = 1, WGM11 = 0, WGM10 = 1
            SET_BIT(TCCR1A, WGM10);
            CLR_BIT(TCCR1A, WGM11);
            SET_BIT(TCCR1B, WGM12);
            SET_BIT(TCCR1B, WGM13);
            break;

        case TIMER1_PWM_FAST_MODE_OCRA_IS_TOP:
            // Fast PWM, OCRA as top: WGM13 = 1, WGM12 = 1, WGM11 = 1, WGM10 = 0
            CLR_BIT(TCCR1A, WGM10);
            SET_BIT(TCCR1A, WGM11);
            SET_BIT(TCCR1B, WGM12);
            SET_BIT(TCCR1B, WGM13);
            break;

        default:
            // Invalid mode
            break;
    }
}


void vTimer1_OC1A_SetMode(u8 mode)
{
	switch(mode)
	{
	case TIMER_OC_DISCONNECTED:
		CLR_BIT(TCCR1A,COM1A0);
		CLR_BIT(TCCR1A,COM1A1);
		break;

	case TIMER_OC_TOGGLE:
		SET_BIT(TCCR1A,COM1A0);
		CLR_BIT(TCCR1A,COM1A1);
		break;

	case TIMER_OC_NON_INVERTING:
		CLR_BIT(TCCR1A,COM1A0);
		SET_BIT(TCCR1A,COM1A1);
		break;

	case TIMER_OC_INVERTING:
		SET_BIT(TCCR1A,COM1A0);
		SET_BIT(TCCR1A,COM1A1);
		break;

	default:
		/*error handling*/
		break;
	}
}

void vTimer1_OC1B_SetMode(u8 mode)
{
	switch(mode)
	{
	case TIMER_OC_DISCONNECTED:
		CLR_BIT(TCCR1A,COM1B0);
		CLR_BIT(TCCR1A,COM1B1);
		break;

	case TIMER_OC_TOGGLE:
		SET_BIT(TCCR1A,COM1B0);
		CLR_BIT(TCCR1A,COM1B1);
		break;

	case TIMER_OC_NON_INVERTING:
		CLR_BIT(TCCR1A,COM1B0);
		SET_BIT(TCCR1A,COM1B1);
		break;

	case TIMER_OC_INVERTING:
		SET_BIT(TCCR1A,COM1B0);
		SET_BIT(TCCR1A,COM1B1);
		break;

	default:
		/*error handling*/
		break;
	}}

void vTimer1_SetPreLoad(u16 value)
{
	TCNT1 = value;
}

void vTimer1_SetOCR_A_Value(u16 value)
{
	OCR1A = value;
}

void vTimer1_SetOCR_B_Value(u16 value)
{
	OCR1B = value;
}

void vTimer1_SetICR_Value(u16 value)
{
	ICR1 = value;
}

void vTimer1_OVF_InterruptEnable(void)
{
    SET_BIT(TIMSK, TOIE1);
}

void vTimer1_OVF_InterruptDisable(void)
{
    CLR_BIT(TIMSK, TOIE1);
}

void vTimer1_OCM_A_InterruptEnable(void)
{
    SET_BIT(TIMSK, OCIE1A);
}

void vTimer1_OCM_A_InterruptDisable(void)
{
    CLR_BIT(TIMSK, OCIE1A);
}

void vTimer1_OCM_B_InterruptEnable(void)
{
    SET_BIT(TIMSK, OCIE1B);
}

void vTimer1_OCM_B_InterruptDisable(void)
{
    CLR_BIT(TIMSK, OCIE1B);
}

void vTimer1_PrescalerSelect(u8 prescaler)
{
    switch (prescaler)
    {
        case TIMER_SCALER_1:
            SET_BIT(TCCR1B,CS10);
            CLR_BIT(TCCR1B,CS11);
            CLR_BIT(TCCR1B,CS12);
            break;
        case TIMER_SCALER_8:
            CLR_BIT(TCCR1B,CS10);
            SET_BIT(TCCR1B,CS11);
            CLR_BIT(TCCR1B,CS12);
            break;
        case TIMER_SCALER_64:
            SET_BIT(TCCR1B,CS10);
            SET_BIT(TCCR1B,CS11);
            CLR_BIT(TCCR1B,CS12);
            break;
        case TIMER_SCALER_256:
            CLR_BIT(TCCR1B,CS10);
            CLR_BIT(TCCR1B,CS11);
            SET_BIT(TCCR1B,CS12);
            break;
        case TIMER_SCALER_1024:
            SET_BIT(TCCR1B,CS10);
            CLR_BIT(TCCR1B,CS11);
            SET_BIT(TCCR1B,CS12);
            break;
        default:
            // Error handling
            break;
    }
}
/**********************************Timer 2**************************************/

// Timer2 Initialization
void vTIMER2_Init(void)
{
    /*1. Select Mode*/
    vTimer2_SetMode(TIMER2_MODE);

    /*2- Select OC2 Pin Mode*/
    vTimer2_OC2_SetMode(TIMER2_OC2_MODE);

    /*3- Set Pre-load "Initial Counting Value" Value*/
    vTimer2_SetPreLoad(TIMER2_INITIAL_VALUE);

    /*4- Set Compare Match Value*/
    vTimer2_SetOCRValue(TIMER2_OCR2_VALUE);

    /*5- Enable/ Disable OV Interrupt*/
    vTimer2_OVF_InterruptDisable();

    /*6- Enable/ Disable OC Interrupt*/
    vTimer2_OCM_InterruptDisable();
}

// Timer2 Start
void vTIMER2_Start(void)
{
    vTimer2_PrescalerSelect(TIMER2_PRESCALER);
}

// Timer2 Stop
void vTIMER2_Stop(void)
{
    CLR_BIT(TCCR2, CS20);
    CLR_BIT(TCCR2, CS21);
    CLR_BIT(TCCR2, CS22);
}

// Set Timer2 Pre-load
void vTimer2_SetPreLoad(u8 value)
{
    TCNT2 = value;
}

// Set Timer2 Compare Match Value
void vTimer2_SetOCRValue(u8 value)
{
    OCR2 = value;
}

// Set Timer2 Mode
void vTimer2_SetMode(u8 mode)
{
    switch(mode)
    {
        case TIMER2_NORMAL_MODE:
            CLR_BIT(TCCR2, WGM20);
            CLR_BIT(TCCR2, WGM21);
            break;

        case TIMER2_PWM_PHASE_CORRECT_MODE:
            SET_BIT(TCCR2, WGM20);
            CLR_BIT(TCCR2, WGM21);
            break;

        case TIMER2_CTC_MODE:
            CLR_BIT(TCCR2, WGM20);
            SET_BIT(TCCR2, WGM21);
            break;

        case TIMER2_FASTPWM_MODE:
            SET_BIT(TCCR2, WGM20);
            SET_BIT(TCCR2, WGM21);
            break;

        default:
            // Error handling
            break;
    }
}

// Set Timer2 OC2 Mode
void vTimer2_OC2_SetMode(u8 mode)
{
    switch(mode)
    {
        case TIMER_OC_DISCONNECTED:
            CLR_BIT(TCCR2, COM20);
            CLR_BIT(TCCR2, COM21);
            break;

        case TIMER_OC_TOGGLE:
            SET_BIT(TCCR2, COM20);
            CLR_BIT(TCCR2, COM21);
            break;

        case TIMER_OC_NON_INVERTING:
            CLR_BIT(TCCR2, COM20);
            SET_BIT(TCCR2, COM21);
            break;

        case TIMER_OC_INVERTING:
            SET_BIT(TCCR2, COM20);
            SET_BIT(TCCR2, COM21);
            break;

        default:
            // Error handling
            break;
    }
}

// Timer2 OVF Interrupt Enable
void vTimer2_OVF_InterruptEnable(void)
{
    SET_BIT(TIMSK, TOIE2);
}

// Timer2 OVF Interrupt Disable
void vTimer2_OVF_InterruptDisable(void)
{
    CLR_BIT(TIMSK, TOIE2);
}

// Timer2 OCM Interrupt Enable
void vTimer2_OCM_InterruptEnable(void)
{
    SET_BIT(TIMSK, OCIE2);
}

// Timer2 OCM Interrupt Disable
void vTimer2_OCM_InterruptDisable(void)
{
    CLR_BIT(TIMSK, OCIE2);
}

// Set Timer2 Prescaler
void vTimer2_PrescalerSelect(u8 prescaler)
{
    switch(prescaler)
    {
        case TIMER2_SCALER_1:
            SET_BIT(TCCR2, CS20);
            CLR_BIT(TCCR2, CS21);
            CLR_BIT(TCCR2, CS22);
            break;
        case TIMER2_SCALER_8:
            CLR_BIT(TCCR2, CS20);
            SET_BIT(TCCR2, CS21);
            CLR_BIT(TCCR2, CS22);
            break;
        case TIMER2_SCALER_32:
            SET_BIT(TCCR2, CS20);
            SET_BIT(TCCR2, CS21);
            CLR_BIT(TCCR2, CS22);
            break;
        case TIMER2_SCALER_64:
            CLR_BIT(TCCR2, CS20);
            CLR_BIT(TCCR2, CS21);
            SET_BIT(TCCR2, CS22);
            break;
        case TIMER2_SCALER_128:
            SET_BIT(TCCR2, CS20);
            CLR_BIT(TCCR2, CS21);
            SET_BIT(TCCR2, CS22);
            break;
        case TIMER2_SCALER_256:
            CLR_BIT(TCCR2, CS20);
            SET_BIT(TCCR2, CS21);
            SET_BIT(TCCR2, CS22);
            break;
        case TIMER2_SCALER_1024:
            SET_BIT(TCCR2, CS20);
            SET_BIT(TCCR2, CS21);
            SET_BIT(TCCR2, CS22);
            break;
        default:
            // Error handling
            break;
    }
}
