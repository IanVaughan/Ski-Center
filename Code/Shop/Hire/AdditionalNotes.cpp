//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "AdditionalNotes.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TAdditionalNotesForm *AdditionalNotesForm;
//---------------------------------------------------------------------------
__fastcall TAdditionalNotesForm::TAdditionalNotesForm(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TAdditionalNotesForm::SaveBTNClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------

void __fastcall TAdditionalNotesForm::ClearBTNClick(TObject *Sender)
{
//    NotesMemo->Items->Clear();
}
//---------------------------------------------------------------------------
