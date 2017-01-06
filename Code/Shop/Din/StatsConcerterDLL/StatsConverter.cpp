//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "StatsConverter.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)


StatsConverter::StatsConverter()
{
}
//------------------------------------------------------------------------------

double StatsConverter::ConvertWeight(String dValue, WeightType wvFromUnit, WeightType wvToUnit)
{
    double dRetVal = 0;

    if(wvFromUnit == wvToUnit)
    {
        try
        {
            dRetVal = dValue.ToDouble();
        }
        catch(...)
        {
            dRetVal = -1;
//            Application->MessageBox("The either was no Weight value entered, or it was an invalid entry.\nPlease use numbers, '/' to seperate impearial units, and '.' to seperate metric units.\n E.g. 10 Stone 7 pounds = 10/7, or 10.5.", "Incorrect Weight Value", MB_OK|MB_ICONINFORMATION);
        }
    }
    else
    {
        switch(wvToUnit)
        {
            case wtKILOS : dRetVal = GetWeight_KG(dValue, wvFromUnit); break;
            case wtSTONES : break;
            case wtPOUNDS : break;
        }
    }

    return dRetVal;
}
//------------------------------------------------------------------------------

double StatsConverter::ConvertHeight(String dValue, HeightType hvFromUnit, HeightType hvToUnit)
{
    double dRetVal = 0;

    if(hvFromUnit == hvToUnit)
    {
        try
        {
            dRetVal = dValue.ToDouble();
        }
        catch(...)
        {
            dRetVal = -1;
        }
    }
    else
    {
        switch(hvToUnit)
        {
            case htCMS : dRetVal = GetHeight_CM(dValue, hvFromUnit); break;
            case htINCHES : break;
            case htFEET : break;
        }
    }
    
    return dRetVal;
}
//------------------------------------------------------------------------------

double StatsConverter::GetWeight_KG(String kValue, WeightType tFromUnit)
{
    double dValue = kValue.ToIntDef(-1);

    switch(tFromUnit)
    {
        case wtKILOS : break;
        case wtSTONES :
        {
            double dStone = kValue.SubString(0, kValue.Pos("/")-1).ToIntDef(-1);
            kValue = kValue.Delete(1, kValue.Pos("/"));
            int iPounds = kValue.ToIntDef(-1);

            //then they just entered stone with no pounds
            if(dStone == -1)
            {
                dStone = kValue.ToIntDef(-1);
                iPounds = 0;
            }
            //if stone still -1. then they entered a decimal
            if(dStone == -1)
            {
                dStone = kValue.ToDouble();
            }

            //convert stone to pounds
            dStone *= cdLBS_PER_STONE;
            //add any lose pounds
            dStone += iPounds;

            //then dont break, allow pounds-to-kg convert to execute
            dValue = dStone;
        }
        case wtPOUNDS :
        {
            if(dValue > 0)
            {
                dValue /= cdLBS_PER_KG;
            }
            break;
        }
    }

    return dValue;
}
//------------------------------------------------------------------------------

double StatsConverter::GetHeight_CM(String kValue, HeightType tFromUnit)
{
    double dValue = kValue.ToIntDef(-1);

    switch(tFromUnit)
    {
        case htCMS : break;
        case htFEET :
        {
            double dFeet = kValue.SubString(0, kValue.Pos("/")-1).ToIntDef(-1);
            kValue = kValue.Delete(1, kValue.Pos("/"));
            int iInchs = kValue.ToIntDef(-1);

            //then they just entered feet with no inchs
            if(dFeet == -1)
            {
                dFeet = kValue.ToIntDef(-1);
                iInchs = 0;
            }
            //if feet still -1. then they entered a decimal
            if(dFeet == -1)
            {
                dFeet = kValue.ToDouble();
            }
            
            //convert feet to inches
            dFeet *= cdIN_PER_FT;
            //add any lose inches
            dFeet += iInchs;

            //then dont break, allow pounds-to-kg convert to execute
            dValue = dFeet;
        }
        case htINCHES :
        {
            if(dValue > 0)
            {
                dValue /= cdIN_PER_CM;
            }
            break;
        }
    }

    return dValue;
}
//------------------------------------------------------------------------------

