//
//  BIT_MATH.h
//  DIOTask
//
//  Created by Amr Zain on 29/02/2024.
//

#ifndef BIT_MATH_h
#define BIT_MATH_h


#define SET_BIT(REG,BIT_NUMBER)    REG |=  (1<<BIT_NUMBER)
#define CLR_BIT(REG,BIT_NUMBER)    REG &= ~(1<<BIT_NUMBER)
#define TOG_BIT(REG,BIT_NUMBER)    REG ^=  (1<<BIT_NUMBER)
#define GET_BIT(REG,BIT_NUMBER)    (1 & (REG>>BIT_NUMBER))

#define IS_BIT_SET(REG,BIT_NUMBER)    (1 & (REG>>BIT_NUMBER)) >> BIT_NUMBER
#define IS_BIT_CLR(REG,BIT_NUMBER)    ~((1 & (REG>>BIT_NUMBER)) >> BIT_NUMBER)


#endif /* BIT_MATH_h */
