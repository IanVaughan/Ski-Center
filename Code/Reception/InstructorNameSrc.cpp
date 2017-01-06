//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "InstructorNameSrc.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TInstructorNameEdit *InstructorNameEdit;
//---------------------------------------------------------------------------

__fastcall TInstructorNameEdit::TInstructorNameEdit(TComponent* Owner) : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TInstructorNameEdit::SaveBTNClick(TObject *Sender)
{
    ModalResult = mrOk;
}
//---------------------------------------------------------------------------

void __fastcall TInstructorNameEdit::CancelBTNClick(TObject *Sender)
{
    ModalResult = mrCancel;
}
//---------------------------------------------------------------------------

