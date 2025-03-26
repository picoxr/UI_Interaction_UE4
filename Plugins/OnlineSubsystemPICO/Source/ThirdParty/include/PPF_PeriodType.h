#ifndef MATRIX_PPF_PERIODTYPE_H
#define MATRIX_PPF_PERIODTYPE_H

/// @file PPF_PeriodType.h
/// @ingroup IAP

typedef enum ppfPeriodType_ {
    ppfPeriodType_Invalid=-1    ,	//Invalid
    ppfPeriodType_None=0        ,	//None
    ppfPeriodType_Hour=1        ,	//Hour
    ppfPeriodType_Day=2         ,	//Day
    ppfPeriodType_Week=3        ,	//Week
    ppfPeriodType_Month=4       ,	//Month
    ppfPeriodType_Quarter=5     ,	//Quarter
    ppfPeriodType_Year=6        ,	//Year

} ppfPeriodType;

#endif //MATRIX_PPF_PERIODTYPE_H
