//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "MVCControler.h"
#include "LessonBookingSheetSrc.cpp"
#include "MVC_Model.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

MVCControler::MVCControler(TComponent* Owner)
{
    LessonBookingSheet = new TLessonBookingSheet(Owner);
    LessonBookingSheet->SetControler(this);

    pkModel = new MVC_Model;
}
//------------------------------------------------------------------------------

MVCControler::~MVCControler()
{
    if(m_pkUsersList)
    {
        delete m_pkUsersList;
        m_pkUsersList = NULL;
    }

    delete pkModel;

    delete LessonBookingSheet;
}
//------------------------------------------------------------------------------

bool MVCControler::LoadLoginFile()
{
    bool bRet = false;

    //if we have a list, then dont create a new one, and return true to say ok.
    if(m_pkUsersList) return true;

    if(FileExists("Password.csc"))
    {
        m_pkUsersList = new TStringList;
        m_pkUsersList->LoadFromFile("Password.csc");
        bRet = true;
    }
    else
    {
        Application->MessageBox("The file containing the Booking System Password List can not be found in the Booking System folder.\n"
                                "This is a critial file needed to run, so the program will now shutdown.\n"
                                "Please contact the System Administrator for more help.",
                                "Password file not found", MB_OK|MB_ICONWARNING);
    }

    return bRet;
}
//------------------------------------------------------------------------------

bool MVCControler::ValidLogin(String userName, String userPassword)
{
    bool bFound = false;

    if(LoadLoginFile())
    {
        //loop round all password lines
        for(int i=0; i<m_pkUsersList->Count; i++)
        {
            //if we find a match with the user name
            if(m_pkUsersList->Strings[i] == userName)
            {
                //check if the user name has the password on the next line
                if(i < m_pkUsersList->Count-1)
                if(m_pkUsersList->Strings[i+1] == userPassword)
                {
                    bFound = true;
                    break;
                }
            }
        }
    }
    
    return bFound;
}
//---------------------------------------------------------------------------

bool MVCControler::ShowForm(TForm *pkForm)
{
    if(pkForm) pkForm->ShowModal();

    return true;
}
//------------------------------------------------------------------------------

bool MVCControler::GetSheet(TDateTime kDateIn, DaySheet *&tDaySheetOut)
{
    if(pkModel)
    {
        return pkModel->GetSheet(kDateIn, tDaySheetOut);
    }
    else
    {
        return false;
    }
}
//------------------------------------------------------------------------------

void MVCControler::SetShowDay(TDateTime kDate)
{
    LessonBookingSheet->SetDate(kDate);
}
//------------------------------------------------------------------------------

