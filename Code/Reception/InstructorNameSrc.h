//---------------------------------------------------------------------------
#ifndef InstructorNameSrcH
#define InstructorNameSrcH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TInstructorNameEdit : public TForm
{
__published:	// IDE-managed Components
    TEdit *nameEdit;
    TBitBtn *SaveBTN;
    TBitBtn *CancelBTN;
    TLabel *Label1;
    void __fastcall CancelBTNClick(TObject *Sender);
    void __fastcall SaveBTNClick(TObject *Sender);
    
private:	// User declarations
public:		// User declarations
    __fastcall TInstructorNameEdit(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TInstructorNameEdit *InstructorNameEdit;
//---------------------------------------------------------------------------
#endif
