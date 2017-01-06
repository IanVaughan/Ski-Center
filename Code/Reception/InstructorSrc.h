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
__published:
    TListBox *InstructorListBox;
    TBitBtn *SaveBTN;
    TBitBtn *CancelBTN;
    TPopupMenu *PopupMenu1;
    TMenuItem *AddMI;
    TMenuItem *EditMI;
    TMenuItem *DeleteMI;
    void __fastcall InstructorListBoxClick(TObject *Sender);
    void __fastcall AddMIClick(TObject *Sender);
    void __fastcall EditMIClick(TObject *Sender);
    void __fastcall DeleteMIClick(TObject *Sender);
    void __fastcall InstructorListBoxDblClick(TObject *Sender);
    void __fastcall SaveBTNClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall PopupMenu1Popup(TObject *Sender);

private:

public:
    __fastcall TInstructorForm(TComponent* Owner);

    String GetSelectedName();
};
//---------------------------------------------------------------------------
extern PACKAGE TInstructorForm *InstructorForm;
//---------------------------------------------------------------------------
#endif
