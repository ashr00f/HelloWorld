/*
 * Utils.h
 *
 * Created: 3/4/2021 3:26:16 PM
 *  Author: mohamed
 */ 


#ifndef UTILS_H_
#define UTILS_H_

#define  SET_BIT(reg,bit)   (reg=reg|(1<<bit))
#define  CLR_BIT(reg,bit)   (reg=reg&~(1<<bit))
#define  READ_BIT(reg,bit)  ((reg>>bit)&1)

#define  TOG_BIT(reg,bit)   (reg=reg^(1<<bit))



#endif /* UTILS_H_ */