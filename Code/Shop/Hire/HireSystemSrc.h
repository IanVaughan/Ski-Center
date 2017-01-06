//---------------------------------------------------------------------------
#ifndef HireSystemSrcH
#define HireSystemSrcH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class MVCControler;
class THireForm;

class THireSystem : public TForm
{
__published:
    TComboBox *NameCB;
    TEdit *PasswordEdit;
    TLabel *Label1;
    TLabel *Label2;
    TLabel *Label3;
    TImage *Image1;
    TBevel *Bevel1;
    TBitBtn *LoginBTN;
    TBitBtn *CancelBTN;
    TBitBtn *BitBtn1;
    void __fastcall FormShow(TObject *Sender);
    void __fastcall CloseBTNClick(TObject *Sender);
    void __fastcall LoginBTNClick(TObject *Sender);
    void __fastcall FormDestroy(TObject *Sender);
    void __fastcall BitBtn1Click(TObject *Sender);

private:
    MVCControler *m_pkMVCControler;
    THireForm *m_pkHireForm;

public:
    __fastcall THireSystem(TComponent* Owner);

    MVCControler* GetMVCControler() {return m_pkMVCControler;};
};
//---------------------------------------------------------------------------
extern PACKAGE THireSystem *HireSystem;
//---------------------------------------------------------------------------
#endif
