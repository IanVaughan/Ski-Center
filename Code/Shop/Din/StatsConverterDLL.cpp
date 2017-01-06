//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------

USEUNIT("StatsConcerterDLL\StatsConverter.cpp");
USEFILE("StatsConverterDLL.h");
USERES("StatsConverterDLL.res");
//---------------------------------------------------------------------------
#include "StatsConverter.h"
//---------------------------------------------------------------------------
StatsConverter *g_pkStatsConverter;

int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void*)
{
    return 1;
}
//---------------------------------------------------------------------------

void __EXPORT_TYPE StatsConverterDLL_StartUp()
{
    g_pkStatsConverter = new StatsConverter();
}
//------------------------------------------------------------------------------

void __EXPORT_TYPE StatsConverterDLL_ShutDown()
{
    delete g_pkStatsConverter;
}
//------------------------------------------------------------------------------

double __EXPORT_TYPE ConvertWeight(String kValue, WeightType wvFromUnit, WeightType wvToUnit)
{
    return g_pkStatsConverter->ConvertWeight(kValue, wvFromUnit, wvToUnit);
}
//------------------------------------------------------------------------------

double __EXPORT_TYPE ConvertHeight(String kValue, HeightType hvFromUnit, HeightType hvToUnit)
{
    return g_pkStatsConverter->ConvertHeight(kValue, hvFromUnit, hvToUnit);
}
//------------------------------------------------------------------------------

