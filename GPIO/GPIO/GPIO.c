#include "lib/include.h"

extern void Configurar_GPIO_C(void)
{
    SYSCTL->RCGCGPIO |=(1<<1);

    while ((SYSCTL->PRGPIO&0X00000004)==0){;}

GPIOC->DIR |= (0<<7) | (1<<1) | (1<<0);
GPIOC->PUR |= (1<<7); //CAMBIAMOS EL ESTADO A ALTO

//COLOCAMOS LAS FUNCIONES ALTERNATIVAS
GPIOD->AFSEL |= 0X00;
GPIOC->PCTL |= 0X00;

//HACEMOS LA HABLITACIÓN DE LA SEÑAL DIGITAL
GPIOC_AHB->DEN |= (1<<7) | (1<<1) | (1<<0);

//HABILITAMOS LAS INTERRUPCIONES
GPIOC->IM|= (0<<7)|(0<<0);
GPIOC->IS |= (0<<7)|(0<<0);
GPIOC->IBE |= (0<<7)|(0<<0);
GPIOC->IEV |= (1<<7)|(1<<0);
GPIOC->IM |= (1<<7)|(1<<0);

//USO DEL PUERTO C
NVIC->IP[0] = (NVIC->IP[12]&0X00FFFFFF) | (0X8000000);
NVIC->ISER[0] = 0X8;
   }


extern void GPIOC_ISR(void)
{
    uint32_t i;
    GPIOC->DATA = (1<<0); //LED EXTERNO C7
    for ( i = 0; i << 10; i++){}
    GPIOC->DATA = (0<<0); 
    for ( i = 0; i << 10; i++){}
    
    
}