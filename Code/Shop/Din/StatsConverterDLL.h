
#ifdef __BUILDING_THE_DLL
#define __EXPORT_TYPE __export
#else
#define __EXPORT_TYPE __import
#endif

//------------------------------------------------------------------------------

typedef enum
{
    wtKILOS,
    wtSTONES,
    wtPOUNDS
}WeightType;

typedef enum
{
    htCMS,
    htINCHES,
    htFEET
}HeightType;

//------------------------------------------------------------------------------

void __EXPORT_TYPE StatsConverterDLL_StartUp();
void __EXPORT_TYPE StatsConverterDLL_ShutDown();

double __EXPORT_TYPE ConvertWeight(String kValue, WeightType wvFromUnit, WeightType wvToUnit);
double __EXPORT_TYPE ConvertHeight(String kValue, HeightType hvFromUnit, HeightType hvToUnit);
