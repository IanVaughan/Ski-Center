//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------

USEUNIT("DinCalcDLL\Chart1.cpp");
USEUNIT("DinCalcDLL\DinChartSrc.cpp");
USEFILE("DinCalcDLL.h");
USERES("DinCalcDLL.res");
//---------------------------------------------------------------------------
#include "DinChartSrc.h"
//---------------------------------------------------------------------------

DinChart *g_pkDinChart;

int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void*)
{
    return 1;
}
//---------------------------------------------------------------------------

void __EXPORT_TYPE StartUpDIN_DLL()
{
    g_pkDinChart = new DinChart();
}
//------------------------------------------------------------------------------

void ShutDownDIN_DLL()
{
    delete g_pkDinChart;
}
//------------------------------------------------------------------------------

SkiierDIN GetDIN(SkiierStatsData sd)
{
    return g_pkDinChart->GetDIN(sd);
}
//------------------------------------------------------------------------------






