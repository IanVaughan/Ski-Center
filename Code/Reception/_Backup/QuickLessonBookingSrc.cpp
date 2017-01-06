//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "QuickLessonBookingSrc.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TQuickLessonBooking *QuickLessonBooking;
//---------------------------------------------------------------------------

__fastcall TQuickLessonBooking::TQuickLessonBooking(TComponent* Owner) : TForm(Owner)
{
    custDetails->Cells[0][0] = "Name";
    custDetails->Cells[1][0] = "Telephone";
    custDetails->Cells[2][0] = "P.d/T.P.";
}
//---------------------------------------------------------------------------

void __fastcall TQuickLessonBooking::CancelBTNClick(TObject *Sender)
{
    Close();    
}
//---------------------------------------------------------------------------

void __fastcall TQuickLessonBooking::FormShow(TObject *Sender)
{
    lessonFormCB->ItemIndex = 0;
    lessonTypeCB->ItemIndex = 0;
    custNumAdultCB->ItemIndex = 0;
    custNumChildCB->ItemIndex = 0;

}
//---------------------------------------------------------------------------


void __fastcall TQuickLessonBooking::custNumAdultCBChange(TObject *Sender)
{
    int count = custNumAdultCB->Text.ToIntDef(0) + custNumChildCB->Text.ToIntDef(0);
    if(count >0)
        custDetails->RowCount = count+1;
    else
        custDetails->RowCount = 2;
}
//---------------------------------------------------------------------------

void __fastcall TQuickLessonBooking::custNumChildCBChange(TObject *Sender)
{
    custNumAdultCBChange(this);
}
//---------------------------------------------------------------------------

void __fastcall TQuickLessonBooking::SaveBTNClick(TObject *Sender)
{
    ModalResult = mrOk;
}
//---------------------------------------------------------------------------

