//---------------------------------------------------------------------------
#ifndef logonH
#define logonH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TlogonScreen : public TForm
{
__published:	// IDE-managed Components
    TEdit *userName;
    TEdit *password;
    TLabel *Label1;
    TLabel *Label2;
    TBitBtn *okBTN;
    TBitBtn *closeBTN;
    TBevel *Bevel1;
    TImage *Image1;
    TImage *Image2;
    void __fastcall closeBTNClick(TObject *Sender);
    void __fastcall okBTNClick(TObject *Sender);

    void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
    
private:	// User declarations
    bool ValidName(String name);
    bool ValidPassword(String name);
    void OkToRun();

public:		// User declarations
    __fastcall TlogonScreen(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TlogonScreen *logonScreen;
//---------------------------------------------------------------------------
#endif
