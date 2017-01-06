//---------------------------------------------------------------------------
#ifndef instructorSrcH
#define instructorSrcH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TInstructorForm : public TForm
{
__published:	// IDE-managed Components
    TListBox *instructorList;
    TBitBtn *saveBTN;
    TBitBtn *BitBtn2;
    TPopupMenu *PopupMenu1;
    TMenuItem *AddMI;
    TMenuItem *EditMI;
    TMenuItem *DeleteMI;
    void __fastcall instructorListClick(TObject *Sender);
    
    void __fastcall AddMIClick(TObject *Sender);
    void __fastcall EditMIClick(TObject *Sender);
    void __fastcall DeleteMIClick(TObject *Sender);
    void __fastcall instructorListDblClick(TObject *Sender);
    void __fastcall saveBTNClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall PopupMenu1Popup(TObject *Sender);
private:	// User declarations

public:		// User declarations
    __fastcall TInstructorForm(TComponent* Owner);

    String GetSelectedName();
};
//---------------------------------------------------------------------------
extern PACKAGE TInstructorForm *InstructorForm;
//---------------------------------------------------------------------------
#endif
