//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "LoginScreenSrc.h"
#include "MVCControler.h"
#include "LessonBookingSheetSrc.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TLoginScreen *LoginScreen;
//---------------------------------------------------------------------------

__fastcall TLoginScreen::TLoginScreen(TComponent* Owner) : TForm(Owner)
{
    m_pkMVCControler = new MVCControler(this);
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

//    m_bCanClose = false;
}
//---------------------------------------------------------------------------

void __fastcall TLoginScreen::OkBTNClick(TObject *Sender)
{
//    if(m_pkMVCControler->ValidLogin(userNameEdit->Text, passwordEdit->Text))
    {
        Hide();
        m_pkMVCControler->ShowForm(LessonBookingSheet);

//    TDateTime *Date;
//    DateTimePicker->Date = Date->CurrentDate();
        TDate date;
        m_pkMVCControler->SetShowDay(date);
//    LessonBookingSheet->ShowModal();
        Show();
    }
/*    else
    {
//        Application->MessageBox("Either the User Name or the Password are incorrect.\nPlease check your User Name and reenter your password.\n(Note: They are NOT case sensitive)","Cannot Login", MB_OK|MB_ICONWARNING);
        //select all off the current password
        passwordEdit->SetFocus();
        passwordEdit->SelStart = 0;
        passwordEdit->SelLength = passwordEdit->Text.Length();
    } */
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


