//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "logon.h"
#include "bookingSheetSrc.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TlogonScreen *logonScreen;
//---------------------------------------------------------------------------
__fastcall TlogonScreen::TlogonScreen(TComponent* Owner) : TForm(Owner)
{
    userName->Text = "";
    password->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TlogonScreen::closeBTNClick(TObject *Sender)
{
    Close();    
}
//---------------------------------------------------------------------------

void __fastcall TlogonScreen::okBTNClick(TObject *Sender)
{
    if(ValidName(userName->Text) && ValidPassword(password->Text))
    {
        OkToRun();
    }
    else
    {
        Application->MessageBox("Either the User Name or the Password are incorrect.\nPlease check your User Name and reenter your password.\n(Note: They are NOT case sensitive)","Cannot Login", MB_OK|MB_ICONWARNING);
    }
}
//---------------------------------------------------------------------------

bool TlogonScreen::ValidName(String name)
{
    if(name == "ian")
        return true;
    else
        return false;
}

bool TlogonScreen::ValidPassword(String name)
{
    if(name == "admin")
        return true;
    else
        return false;
}

void TlogonScreen::OkToRun()
{
    Hide();
    bookingSheet->ShowModal();
    Show();
}
void __fastcall TlogonScreen::FormCloseQuery(TObject *Sender,
      bool &CanClose)
{
    CanClose = false;
}
//---------------------------------------------------------------------------



