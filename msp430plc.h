/*
 * msp430plc.h
 *  Created on: 13-Sep-2023
 *      Author: santh
 */
// IN THIS HEADER FILE I HAVE CONFIGURED ONLY 6 PORTS
#ifndef MSP430PLC_H_
#define MSP430PLC_H_
#include <msp430.h>
unsigned int accumulator;
unsigned int TR0=0;
unsigned int TR1=0;
unsigned int TR2=0;
unsigned int TR3=0;
unsigned int TR4=0;
unsigned int TR5=0;
unsigned int TR6=0;
unsigned int TR7=0;
unsigned int TR8=0;
unsigned int TR9=0;
int TR10=0;
int TR11=0;
int TR12=0;
int TR13=0;
int TR14=0;
int TR15=0;
int TR16=0;
int TR17=0;
int TR18=0;
int TR19=0;
int TR20=0;
int output;
int BIT[15]={0x0001,0x0002,0x0004,0x0008,0x0010,0x0020,0x0040,0x0080,0x0100,0x0200,0x0400,0x0800,0x1000,0x2000,0x4000,0x8000};
unsigned int inter=0;
inline int IX(a,b)
{
   PM5CTL0 &= ~LOCKLPM5;
   if(a==1)
   {
       P1DIR &=~BIT[b];
       P1REN |=BIT[b];
       P1OUT |=BIT[b];
       if(P1IN & BIT[b]){
       return 1;}
       else{
           return 0;}}

    if(a==2)
      {
       P2DIR &=~BIT[b];
       P2REN |=BIT[b];
       P2OUT |=BIT[b];
       if(P2IN & BIT[b]){
       return 1;}
       else{
           return 0;}}

    if(a==3)
          {
           P3DIR &=~BIT[b];
           P3REN |=BIT[b];
           P3OUT |=BIT[b];
           if(P3IN & BIT[b]){
           return 1;}
           else{
               return 0;}}

    if(a==4)
      {
       P4DIR &=~BIT[b];
       P4REN |=BIT[b];
       P4OUT |=BIT[b];
       if(P4IN & BIT[b]){
       return 1;}
       else{
           return 0;}}

    if(a==5)
  {
   P5DIR &=~BIT[b];
   P5REN |=BIT[b];
   P5OUT |=BIT[b];
   if(P5IN & BIT[b]){
   return 1;}
   else{
       return 0;}}

if(a==6)
  {
   P6DIR &=~BIT[b];
   P6REN |=BIT[b];
   P6OUT |=BIT[b];
   if(P6IN & BIT[b]){
   return 1;}
   else{
       return 0;}}

}
inline void ANDN(int (*x)(int))
{
  inter =(*x);
  inter=~inter;
  accumulator= accumulator & inter;

}
inline void ORN(int (*x)(int))
{
  inter =(*x);
  inter=~inter;
  if(inter==65534)
    {
        inter=0;
        accumulator= accumulator | inter;
    }
    else if(inter==65535)
    {
        inter=1;
        accumulator= accumulator | inter;
    }
}
inline void XORN(int (*x)(int))
{
  inter =(*x);
  inter=~inter;
  if(inter==65534)
    {
        inter=0;
        accumulator= accumulator ^ inter;
    }
    else if(inter==65535)
    {
        inter=1;
        accumulator= accumulator ^ inter;
    }
}
inline void ST(a,b)
{
    PM5CTL0 &= ~LOCKLPM5;
    if(a==1)
    {
        P1DIR |=BIT[b];
        if(accumulator)
        {
        P1OUT |= BIT[b];
        }
        else
        {
        P1OUT &=~ BIT[b];
        }
    }
    if(a==2)
        {
            P2DIR |=BIT[b];
            if(accumulator)
            {
            P2OUT |= BIT[b];
            }
            else
            {
            P2OUT &=~ BIT[b];
            }
        }
    if(a==3)
   {
       P3DIR |=BIT[b];
       if(accumulator)
       {
       P3OUT |= BIT[b];
       }
       else
       {
       P3OUT &=~ BIT[b];
       }
   }
    if(a==4)
   {
       P4DIR |=BIT[b];
       if(accumulator)
       {
       P4OUT |= BIT[b];
       }
       else
       {
       P4OUT &=~ BIT[b];
       }
   }
    if(a==5)
    {
        P5DIR |=BIT[b];
        if(accumulator)
        {
        P5OUT |= BIT[b];
        }
        else
        {
        P5OUT &=~ BIT[b];
        }
      }
    if(a==6)
    {
        P6DIR |=BIT[b];
        if(accumulator)
        {
        P6OUT |= BIT[b];
        }
        else
        {
        P6OUT &=~ BIT[b];
        }
      }

}
inline void SET(a,b)
{
    PM5CTL0 &= ~LOCKLPM5;
    if(a==1)
    {
        P1OUT|=BIT[b];
    }
    if(a==2)
    {
        P2OUT|=BIT[b];
    }
    if(a==3)
    {
        P3OUT|=BIT[b];
    }
   if(a==4)
   {
       P4OUT|=BIT[b];
   }
  if(a==5)
  {
      P5OUT|=BIT[b];
  }
  if(a==6)
     {
         P6OUT|=BIT[b];
     }
}
inline void RESET(a,b)
{
    PM5CTL0 &= ~LOCKLPM5;
    if(a==1)
    {
        P1OUT&=~BIT[b];
    }
    if(a==2)
    {
        P2OUT&=~BIT[b];
    }
    if(a==3)
    {
        P3OUT&=~BIT[b];
    }
   if(a==4)
   {
       P4OUT&=~BIT[b];
   }
  if(a==5)
  {
      P5OUT&=~BIT[b];
  }
  if(a==6)
     {
         P6OUT&=~BIT[b];
     }
}
#define _OUT(x) x=accumulator
#define LD accumulator=
inline void LDN(int (*x)(int))
{
  inter =(*x);
  inter=~inter;
  if(inter==65534)
    {
        inter=0;
        accumulator=inter;
    }
    else if(inter==65535)
    {
        inter=1;
        accumulator=inter;
    }
}
#define AND accumulator=accumulator &
#define OR accumulator=accumulator |
#define XOR accumulator=accumulator ^
inline void ADD(EN,A,B)
{

    if(EN)
    {
      output=A+B;
    }
}
inline void SUB(EN,A,B)
{
    if(EN)
    {
      output=A-B;
    }
}
#define MOV(A,B) do{\
                        if(accumulator)\
                        {\
                            B=A;\
                        }\
                        }while(0)

#endif /* MSP430PLC_H_ */
