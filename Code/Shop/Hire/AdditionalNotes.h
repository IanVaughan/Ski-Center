//---------------------------------------------------------------------------
#ifndef AdditionalNotesH
#define AdditionalNotesH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TAdditionalNotesForm : public TForm
{
__published:	// IDE-managed Components
    TMemo *NotesMemo;
    TSpeedButton *ClearBTN;
    TSpeedButton *SaveBTN;
    void __fastcall SaveBTNClick(TObject *Sender);
    void __fastcall ClearBTNClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TAdditionalNotesForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TAdditionalNotesForm *AdditionalNotesForm;
//---------------------------------------------------------------------------
#endif
