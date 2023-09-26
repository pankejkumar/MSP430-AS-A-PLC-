#include <msp430plc.h>


/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	while(1)
	{
	    LD IX(1,1);
	    OR IX(1,2);
	    _OUT(TR0);
	    LDN(IX(1,3));
	    ORN(IX(1,4));
	    OR IX(1,5);
	    AND TR0;
	    _OUT(TR1);
	    LD IX(1,6);
	    ORN(IX(1,7));
	    AND TR1;
	    _OUT(TR0);
	    LDN(IX(2,0));
	    OR IX(2,1);
	    ORN(IX(2,2));
	    OR IX(2,3);
	    AND TR0;
	    AND IX(2,4);
	    AND IX(2,5);
	    AND IX(3,0);
	    ADD(accumulator,10,20);
	    AND IX(3,1);
	    ST(6,6);
	    MOV(output,TR10);
	    LD IX(3,2);
	    OR IX(3,3);
	    OR IX(3,4);
	    _OUT(TR2);
	    LD IX(3,5);
	    ANDN(IX(3,6));
	    _OUT(TR3);
	    LDN(IX(3,7));
	    AND IX(4,0);
	    OR TR3;
	    AND TR2;
	    ADD(accumulator,1000,2000);
	    MOV(output,TR11);
	    ADD(accumulator,7000,TR11);
	    MOV(output,TR12);
	    MOV(TR12,TR13);
	    ST(1,0);


	    LD IX(4,4);
	    _OUT(TR4);
	    LD IX(4,5);
	    OR IX(4,6);
	    OR IX(4,7);
	    OR IX(5,0);
	    AND TR4;
	    _OUT(TR5);
	    LD IX(5,1);
	    OR IX(5,2);
	    AND TR5;
	    AND IX(5,3);
	    _OUT(TR6);
	    LD IX(5,4);
	    OR IX(6,0);
	    AND TR6;
	    AND IX(1,1);
	    ADD(accumulator,10,20);
	    MOV(output,TR14);
	    SUB(accumulator,output,1000);
        MOV(output,TR15);
	    _OUT(TR7);
	    LD IX(1,2);
	    OR IX(1,3);
	    OR IX(1,4);
	    AND TR7;
	    ST(6,4);
	    LD IX(1,5);
	    OR IX(1,6);
	    OR IX(1,7);
	    _OUT(TR8);
	    LD IX(2,0);
	    AND IX(2,1);
	    AND IX(2,2);
	    AND IX(2,3);
	    _OUT(TR9);
	    LD IX(2,4);
	    AND IX(2,5);
	    AND IX(3,0);
	    AND IX(3,1);
	    OR TR9;
	    AND TR8;
	    ADD(accumulator,1000,3000);
	    MOV(output,TR16);
	    AND IX(3,2);
	    SUB(accumulator,100,500);
	    MOV(output,TR17);
	    ANDN(IX(3,3));
	    ANDN(IX(3,4));
	    ANDN(IX(3,5));
	    ST(6,6);
	    LDN(IX(3,6));
	    ANDN(IX(3,7));
	    ANDN(IX(4,0));
	    _OUT(TR0);
	    LD IX(4,4);
	    ORN(IX(4,5));
	    ORN(IX(4,6));
	    ORN(IX(4,7));
	    AND TR0;
	    _OUT(TR1);
	    LD IX(5,0);
	    AND IX(5,1);
	    _OUT(TR2);
	    LD IX(5,2);
	    AND IX(5,3);
	    OR TR2;
	    AND TR1;
	    ST(1,0);

	}
	return 0;
}
