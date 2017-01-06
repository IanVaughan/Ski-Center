//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "DinChartSrc.h"
#include "Chart1.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

DinChart::DinChart()
{
    m_pkChart1 = new Chart1();
}
//------------------------------------------------------------------------------

DinChart::~DinChart()
{
    delete m_pkChart1;
}
//------------------------------------------------------------------------------

SkiierDIN DinChart::GetDIN(SkiierStatsData sd)
{
    int iCode = m_pkChart1->GetSkiierCode(sd);

    SkiierDIN sDin;

    if(iCode == -1)
    {
        sDin.iDIN = -1;
    }
    else
    {
        sDin.iDIN = FindDIN(iCode, sd.iBootSoleLength);
        FindInspParams(iCode, sDin.iTorsion, sDin.iForwardFlex);
    }

    return sDin;
}
//------------------------------------------------------------------------------

double DinChart::FindDIN(int iCode, int iBSL)
{
//    double dRetVal = -1;
    int col = FindBSLColumn(iBSL);

    return Chart2[iCode][col];
}
//------------------------------------------------------------------------------

void DinChart::FindInspParams(int iCode, int &riTorsion, int &riForwardFlex)
{
    riTorsion = InspParams[iCode][0];
    riForwardFlex = InspParams[iCode][1];
}
//------------------------------------------------------------------------------

int DinChart::FindBSLColumn(int iBSL)
{
    int returnValue = -1;

    if(iBSL <= 250) returnValue = 0;
    else if(iBSL > 250 && iBSL <= 270) returnValue = 1;
    else if(iBSL > 270 && iBSL <= 290) returnValue = 2;
    else if(iBSL > 290 && iBSL <= 310) returnValue = 3;
    else if(iBSL > 310 && iBSL <= 330) returnValue = 4;
    else if(iBSL > 330) returnValue = 5;
    else returnValue = -1;

    return returnValue;
}
//------------------------------------------------------------------------------

