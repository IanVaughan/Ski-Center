//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "MVCControler.h"

//#include "LessonBookingSheetSrc.cpp"
//#include "InstructorSrc.cpp"
//#include "InstructorNameSrc.cpp"
//#include "SearchFor.cpp"
//#include "Help.cpp"
//#include "BookingSheetUtils.cpp"
//#include "DatePickerSrc.cpp"
//#include "BookingWizzardSrc.cpp"
//#include "QuickLessonBookingSrc.cpp"
//#include "TCellComboBox.cpp"

//---------------------------------------------------------------------------
#pragma package(smart_init)

MVCControler::MVCControler()
{
/*    Application->CreateForm(__classid(TLessonBookingSheet), &LessonBookingSheet);
    Application->CreateForm(__classid(TBookingWizard), &BookingWizard);
    Application->CreateForm(__classid(TinstructorForm), &instructorForm);
    Application->CreateForm(__classid(TInstructorNameEdit), &InstructorNameEdit);
    Application->CreateForm(__classid(Tsearch), &search);
    Application->CreateForm(__classid(ThelpForm), &helpForm);
    Application->CreateForm(__classid(TDatePicker), &DatePicker);
    Application->CreateForm(__classid(TQuickLessonBooking), &QuickLessonBooking); */
}
//------------------------------------------------------------------------------

MVCControler::~MVCControler()
{
}
//------------------------------------------------------------------------------

bool MVCControler::ValidLogin(String userName, String userPassword)
{
/*    bool bFound = false;

    //loop round all password lines
    for(int i=0; i<usersList->Count; i++)
    {
        //if we find a match with the user name
        if(usersList->Strings[i] == userName)
        {
            //check if the user name has the password on the next line
            if(i < usersList->Count-1)
            if(usersList->Strings[i+1] == userPassword)
            {
                bFound = true;
                break;
            }
        }
    }

    return bFound;   */
}
//---------------------------------------------------------------------------

