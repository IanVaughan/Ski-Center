//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Chart1.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

Chart1::Chart1()
{
}
//------------------------------------------------------------------------------

int Chart1::GetSkiierCode(SkiierStatsData tStats)
{
    int w = GetWeightRow(tStats.iWeight);
    int h = GetHeightRow(tStats.iHeight);

    int iCode = w;
    if(w < h) iCode = w;
    if(h < w) iCode = h;

    iCode = OffsetRowWithAge(iCode, tStats.iAge);
    iCode = OffsetRowWithType(iCode, tStats.iSkiierType);

    return iCode;
}
//------------------------------------------------------------------------------

int Chart1::GetWeightRow(int iWeight)
{
    int iReturnValue = -1;

    if(iWeight >= 10 && iWeight <= 13) iReturnValue = 0;
    else if(iWeight >= 14 && iWeight <= 17) iReturnValue = 1;
    else if(iWeight >= 18 && iWeight <= 21) iReturnValue = 2;
    else if(iWeight >= 22 && iWeight <= 25) iReturnValue = 3;
    else if(iWeight >= 26 && iWeight <= 30) iReturnValue = 4;
    else if(iWeight >= 31 && iWeight <= 35) iReturnValue = 5;
    else if(iWeight >= 36 && iWeight <= 41) iReturnValue = 6;
    else if(iWeight >= 42 && iWeight <= 48) iReturnValue = 7;
    else if(iWeight >= 49 && iWeight <= 57) iReturnValue = 8;
    else if(iWeight >= 58 && iWeight <= 66) iReturnValue = 9;
    else if(iWeight >= 67 && iWeight <= 78) iReturnValue = 10;
    else if(iWeight >= 79 && iWeight <= 97) iReturnValue = 11;
    else if(iWeight >= 95) iReturnValue = 12;
    else iReturnValue = -1;

    return iReturnValue;
}
//------------------------------------------------------------------------------

int Chart1::GetHeightRow(int iHeight)
{
    int iReturnValue = -1;

    if(iHeight <= 148) iReturnValue = 7;
    else if(iHeight >= 149 && iHeight < 158) iReturnValue = 8;
    else if(iHeight >= 158 && iHeight < 167) iReturnValue = 9;
    else if(iHeight >= 167 && iHeight < 179) iReturnValue = 10;
    else if(iHeight >= 179 && iHeight < 195) iReturnValue = 11;
    else if(iHeight >= 195) iReturnValue = 12;

    return iReturnValue;
}
//------------------------------------------------------------------------------

int Chart1::OffsetRowWithAge(int iRow, int iAge)
{
    if(iAge < 50)
    {
    }
    else
    {
        iRow --;
    }

    return iRow;
}
//------------------------------------------------------------------------------

int Chart1::OffsetRowWithType(int iRow, int iType)
{
    switch(iType)
    {
        case 1 : break;
        case 2 : iRow += 1; break;
        case 3 : iRow += 2; break;
    }

    return iRow;
}
//------------------------------------------------------------------------------



