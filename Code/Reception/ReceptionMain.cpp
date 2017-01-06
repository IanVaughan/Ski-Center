//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
USERES("ReceptionMain.res");
USEFORM("LoginScreenSrc.cpp", LoginScreen);
USEUNIT("MVCControler.cpp");
USEFORM("LessonBookingSheetSrc.cpp", LessonBookingSheet);
USEUNIT("BookingSheetUtils.cpp");
USEFORM("DatePickerSrc.cpp", DatePicker);
USEFORM("BookingWizzardSrc.cpp", BookingWizard);
USEFORM("QuickLessonBookingSrc.cpp", QuickLessonBooking);
USEFORM("Help.cpp", HelpForm);
USEFORM("InstructorNameSrc.cpp", InstructorNameEdit);
USEFORM("InstructorSrc.cpp", InstructorForm);
USEFORM("SearchFor.cpp", SearchForm);
USEUNIT("TCellComboBox.cpp");
USEUNIT("LBS_MouseDownEvents.cpp");
USEUNIT("LBS_MenuItemsAndButtons.cpp");
USEUNIT("MVC_Model.cpp");
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    try
    {
        Application->Initialize();
        Application->CreateForm(__classid(TLoginScreen), &LoginScreen);
        Application->CreateForm(__classid(TDatePicker), &DatePicker);
        Application->CreateForm(__classid(TBookingWizard), &BookingWizard);
        Application->CreateForm(__classid(TQuickLessonBooking), &QuickLessonBooking);
        Application->CreateForm(__classid(THelpForm), &HelpForm);
        Application->CreateForm(__classid(TInstructorNameEdit), &InstructorNameEdit);
        Application->CreateForm(__classid(TInstructorForm), &InstructorForm);
        Application->CreateForm(__classid(TSearchForm), &SearchForm);
        Application->Run();
    }
    catch (Exception &exception)
    {
        Application->ShowException(&exception);
    }
    return 0;
}
//---------------------------------------------------------------------------
