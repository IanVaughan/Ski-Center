//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "HelpAboutSrc.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
THelpAbout *HelpAbout;
//---------------------------------------------------------------------------

__fastcall THelpAbout::THelpAbout(TComponent* Owner) : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall THelpAbout::SpeedButton1Click(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------
