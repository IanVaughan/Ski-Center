//---------------------------------------------------------------------------
#ifndef Chart1H
#define Chart1H
//---------------------------------------------------------------------------
#include "DinChartSrc.h"

class Chart1
{
private:
    int GetWeightRow(int iWeight);
    int GetHeightRow(int iHeight);
    int OffsetRowWithAge(int iRow, int iAge);
    int OffsetRowWithType(int iRow, int iType);

public:
    Chart1();

    int GetSkiierCode(SkiierStatsData tStats);

};
//------------------------------------------------------------------------------
#endif

