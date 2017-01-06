//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "LoginScreenSrc.h"
#include "MVCControler.h"
//#include "LessonBookingSheetSrc.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TLoginScreen *LoginScreen;
//---------------------------------------------------------------------------

__fastcall TLoginScreen::TLoginScreen(TComponent* Owner) : TForm(Owner)
{
    m_pkMVCControler = new MVCControler();
}
//---------------------------------------------------------------------------

void __fastcall TLoginScreen::FormDestroy(TObject *Sender)
{
    delete m_pkMVCControler;
}
//---------------------------------------------------------------------------

void __fastcall TLoginScreen::FormShow(TObject *Sender)
{
    userNameEdit->SetFocus();
    userNameEdit->Text = "";
    passwordEdit->Text = "";

    m_bCanClose = false;

/*    if(FileExists("Password.csc"))
    {
        usersList = new TStringList;
        usersList->LoadFromFile("Password.csc");
    }
    else
    {
        Application->MessageBox("The file containing the Booking System Password List can not be found in the Booking System folder.\nThis is a critial file needed to run, so the program will now shutdown.\nPlease contact the System Administrator for more help.","Password file not found", MB_OK|MB_ICONWARNING);
        //Application->Terminate();
        m_bCanClose = true;
        Close();
    }  */
}
//---------------------------------------------------------------------------

void __fastcall TLoginScreen::OkBTNClick(TObject *Sender)
{
    if(m_pkMVCControler->ValidLogin(userNameEdit->Text, passwordEdit->Text))
    {
        Hide();
//    LessonBookingSheet->ShowModal();
        Show();
    }
    else
    {
        Application->MessageBox("Either the User Name or the Password are incorrect.\nPlease check your User Name and reenter your password.\n(Note: They are NOT case sensitive)","Cannot Login", MB_OK|MB_ICONWARNING);
        //select all off the current password
        passwordEdit->SetFocus();
        passwordEdit->SelStart = 0;
        passwordEdit->SelLength = passwordEdit->Text.Length();
    }
}
//---------------------------------------------------------------------------

void __fastcall TLoginScreen::CloseBTNClick(TObject *Sender)
{
    m_bCanClose = true;
    Close();
}
//---------------------------------------------------------------------------

        
void __fastcall TLoginScreen::FormCloseQuery(TObject *Sender,
      bool &CanClose)
{
    CanClose = m_bCanClose;
}
//---------------------------------------------------------------------------

    /*

void __fastcall TLoginScreen::FormHide(TObject *Sender)
{
    //delete and create on show/hide of form, not only save mem, but no mem hacks for password
    delete usersList;
}
//---------------------------------------------------------------------------

*/




