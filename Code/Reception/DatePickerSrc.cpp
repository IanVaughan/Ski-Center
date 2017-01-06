//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "DatePickerSrc.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "ccalendr"
#pragma resource "*.dfm"
TDatePicker *DatePicker;
//---------------------------------------------------------------------------

__fastcall TDatePicker::TDatePicker(TComponent* Owner) : TForm(Owner)
{
//    TDateTime *Date = new TDateTime();
/*    TDateTime Date = TDateTime::CurrentDate();

    unsigned short* year;
    unsigned short* month;
    unsigned short* day;
    String kMonth = Date.DateString();

    Date.DecodeDate(year, month, day);   */

//    ->CurrentDate();
//     DateString()

   // CalendarPicker->Month = kMonth;
//    MonthCombo->ItemIndex = kMonth;

//    CalendarPicker->Year = kYear;
//    YearCombo->ItemIndex = YearCombo->IndefOf(kYear);
}
//---------------------------------------------------------------------------

void __fastcall TDatePicker::MonthComboChange(TObject *Sender)
{
    CalendarPicker->Month = MonthCombo->ItemIndex;
}
//---------------------------------------------------------------------------

void __fastcall TDatePicker::YearComboChange(TObject *Sender)
{
    CalendarPicker->Year = YearCombo->Text.ToIntDef(2000);
}
//---------------------------------------------------------------------------

void __fastcall TDatePicker::BitBtn2Click(TObject *Sender)
{
    Close();    
}
//---------------------------------------------------------------------------

void __fastcall TDatePicker::FormDeactivate(TObject *Sender)
{
    if(AutoHideCB->Checked)
        Hide();
}
//---------------------------------------------------------------------------

