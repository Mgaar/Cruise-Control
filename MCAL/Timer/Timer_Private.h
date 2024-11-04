//M.G3AR 30/10/2023
#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_


#define TIM2_BASE						0x40000000UL
#define TIM3_BASE						0x40000400UL

typedef struct
{
    u32 CR1;              /*!< TIM control register 1,              Address offset: 0x00 */
    u32 CR2;              /*!< TIM control register 2,              Address offset: 0x04 */
    u32 SMCR;             /*!< TIM slave mode control register,     Address offset: 0x08 */
    u32 DIER;             /*!< TIM DMA/interrupt enable register,   Address offset: 0x0C */
    u32 SR;               /*!< TIM status register,                 Address offset: 0x10 */
    u32 EGR;              /*!< TIM event generation register,       Address offset: 0x14 */
    u32 CCMR1;            /*!< TIM capture/compare mode register 1, Address offset: 0x18 */
    u32 CCMR2;            /*!< TIM capture/compare mode register 2, Address offset: 0x1C */
    u32 CCER;             /*!< TIM capture/compare enable register, Address offset: 0x20 */
    u32 CNT;              /*!< TIM counter register,                Address offset: 0x24 */
    u32 PSC;              /*!< TIM prescaler,                       Address offset: 0x28 */
    u32 ARR;              /*!< TIM auto-reload register,            Address offset: 0x2C */
    u32 RESERVED0;        /*!< Reserved,                            Address offset: 0x30 */
    u32 CCR1;             /*!< TIM capture/compare register 1,      Address offset: 0x34 */
    u32 CCR2;             /*!< TIM capture/compare register 2,      Address offset: 0x38 */
    u32 CCR3;             /*!< TIM capture/compare register 3,      Address offset: 0x3C */
    u32 CCR4;             /*!< TIM capture/compare register 4,      Address offset: 0x40 */
    u32 RESERVED1;        /*!< Reserved,                            Address offset: 0x44 */
    u32 DCR;              /*!< TIM DMA control register,            Address offset: 0x48 */
    u32 DMAR;             /*!< TIM DMA address for full transfer,   Address offset: 0x4C */
    u32 OR;               /*!< TIM option register,                 Address offset: 0x50 */
} TIMER_t;



#define TIMER3		((TIMER_t*)TIM3_BASE) 
#define TIM2		((TIMER_t*)TIM2_BASE)

#define ARR_Value 1000


//319

#define prescaler 319





#define TIM_CCMR1_OC1M_1 0x0020
#define TIM_CCMR1_OC1M_2 0x0040

#define TIM_CCMR1_OC2M_1 0x2000
#define TIM_CCMR1_OC2M_2 0x4000

#define TIM_CCMR2_OC3M_1 0x0020
#define TIM_CCMR2_OC3M_2 0x0040

#endif  
