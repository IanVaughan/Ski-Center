//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
USERES("ShopHireSystem.res");
USEFORM("HireSystemSrc.cpp", HireSystem);
USEFORM("HireFormSrc.cpp", HireForm);
USEUNIT("MVCControler.cpp");
USEFORM("AdditionalNotes.cpp", AdditionalNotesForm);
USEFORM("HireListSrc.cpp", HireList);
USEFORM("..\..\..\..\..\Electic Visions\Ski Centre\Code\Shop\Hire\BookingWizardSrc.cpp", BookingWizard);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    try
    {
        Application->Initialize();
        Application->Title = "Shop Hire Booking System";
        Application->CreateForm(__classid(THireSystem), &HireSystem);
        Application->CreateForm(__classid(TBookingWizard), &BookingWizard);
        Application->Run();
    }
    catch (Exception &exception)
    {
        Application->ShowException(&exception);
    }
    return 0;
}
//---------------------------------------------------------------------------



