//---------------------------------------------------------------------------
#ifndef LoginScreenSrcH
#define LoginScreenSrcH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class MVCControler;

class TLoginScreen : public TForm
{
__published:
    TEdit *userNameEdit;
    TEdit *passwordEdit;
    TLabel *Label1;
    TLabel *Label2;
    TBitBtn *OkBTN;
    TBitBtn *CloseBTN;
    TBevel *Bevel1;
    TImage *Image1;
    TImage *Image2;
    TBevel *Bevel2;
    void __fastcall OkBTNClick(TObject *Sender);
    void __fastcall FormDestroy(TObject *Sender);
    void __fastcall CloseBTNClick(TObject *Sender);
    void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
    void __fastcall FormShow(TObject *Sender);

private:
    MVCControler *m_pkMVCControler;

    bool m_bCanClose;

public:
    __fastcall TLoginScreen(TComponent* Owner);

};
//---------------------------------------------------------------------------
extern PACKAGE TLoginScreen *LoginScreen;
//---------------------------------------------------------------------------
#endif
