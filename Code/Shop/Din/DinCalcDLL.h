
#ifndef DinCalcDLLH
#define DinCalcDLLH

#ifdef __BUILDING_THE_DLL
#define __EXPORT_TYPE __export
#else
#define __EXPORT_TYPE __import
#endif

//------------------------------------------------------------------------------

typedef struct
{
    int iAge;
    int iWeight;
    int iHeight;
    int iSkiierType;
    int iBootSoleLength;
}SkiierStatsData;
//------------------------------------------------------------------------------

typedef __EXPORT_TYPE struct
{
    double iDIN;
    char cCode;
    int iTorsion;
    int iForwardFlex;
}SkiierDIN;
//------------------------------------------------------------------------------

int __EXPORT_TYPE WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void*);

void __EXPORT_TYPE StartUpDIN_DLL();
void __EXPORT_TYPE ShutDownDIN_DLL();
SkiierDIN __EXPORT_TYPE GetDIN(SkiierStatsData sd);

//------------------------------------------------------------------------------
#endif
