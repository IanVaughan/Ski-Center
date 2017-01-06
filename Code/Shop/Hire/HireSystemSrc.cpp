//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "HireSystemSrc.h"
#include "HireFormSrc.h"
#include "MVCControler.h"
#include "HireListSrc.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
THireSystem *HireSystem;
//---------------------------------------------------------------------------

__fastcall THireSystem::THireSystem(TComponent* Owner) : TForm(Owner)
{
    m_pkMVCControler = new MVCControler;
    m_pkHireForm = new THireForm(this, m_pkMVCControler);
}
//---------------------------------------------------------------------------

void __fastcall THireSystem::FormDestroy(TObject *Sender)
{
    delete m_pkMVCControler;
    delete m_pkHireForm;
}
//---------------------------------------------------------------------------

void __fastcall THireSystem::FormShow(TObject *Sender)
{
    NameCB->Text = "";
    PasswordEdit->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall THireSystem::CloseBTNClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------

void __fastcall THireSystem::LoginBTNClick(TObject *Sender)
{
    SystemUser tUser;
    tUser.kName = NameCB->Text;
    tUser.kPassword = PasswordEdit->Text;

//    if(m_pkMVCControler->MVCControler_ValidateUser(tUser))
    {
        Hide();
        m_pkHireForm->ShowModal();
        Show();
    }
/*    else
    {
        Application->MessageBox("The login details you have given are not valid, you will not be able to use the System.\n"
                                "Please provide correct Login information, or seek help from Nick or Si.",
                                "Invalid Login", MB_OK|MB_ICONWARNING);
    }*/
}
//---------------------------------------------------------------------------

void __fastcall THireSystem::BitBtn1Click(TObject *Sender)
{
    Hide();
    HireList->ShowModal();
    Show();
}
//---------------------------------------------------------------------------

