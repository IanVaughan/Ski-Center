//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
USERES("DinCalculator.res");
USEFORM("DinCalculator\DinCalculatorSrc.cpp", DinCalcForm);
USEFORM("DinCalculator\HelpAboutSrc.cpp", HelpAbout);
USELIB("DinCalcDLL.lib");
USELIB("StatsConverterDLL.lib");
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    try
    {
        Application->Initialize();
        Application->Title = "Din Calculator";
        Application->CreateForm(__classid(TDinCalcForm), &DinCalcForm);
        Application->CreateForm(__classid(THelpAbout), &HelpAbout);
        Application->Run();
    }
    catch (Exception &exception)
    {
        Application->ShowException(&exception);
    }
    return 0;
}
//---------------------------------------------------------------------------
