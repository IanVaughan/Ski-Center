//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "DataPickerSrc.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "ccalendr"
#pragma resource "*.dfm"
TDatePicker *DatePicker;
//---------------------------------------------------------------------------
__fastcall TDatePicker::TDatePicker(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
