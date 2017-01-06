//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "searchFor.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TSearchForm *SearchForm;
//---------------------------------------------------------------------------
__fastcall TSearchForm::TSearchForm(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TSearchForm::Button2Click(TObject *Sender)
{
    Close();    
}
//---------------------------------------------------------------------------

