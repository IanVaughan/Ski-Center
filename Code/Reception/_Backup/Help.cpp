//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "help.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
THelpForm *HelpForm;
//---------------------------------------------------------------------------
__fastcall THelpForm::THelpForm(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall THelpForm::BitBtn1Click(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------
