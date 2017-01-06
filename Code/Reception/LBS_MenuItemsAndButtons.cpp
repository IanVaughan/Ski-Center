//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "LBS_MenuItemsAndButtons.h"
#include "LessonBookingSheetSrc.h"
#include "QuickLessonBookingSrc.h"
#include "BookingWizzardSrc.h"
#include "Help.h"
#include "DatePickerSrc.h"
#include "BookingSheetUtils.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

//******************************************************************************
//Popup Menu Items
//******************************************************************************

void __fastcall TLessonBookingSheet::InstructorRowPUPopup(TObject *Sender)
{
    SetInstructorPUMI->Enabled = true;
    ChangeInstructorPUMI->Enabled = true;
    ClearInstrcutorPUMI->Enabled = true;

    if(m_pkBookingSheetUtils->InstructorBooked())
    {
        ChangeInstructorPUMI->Enabled = true;
        ClearInstrcutorPUMI->Enabled = true;
    }
    else
    {
        ChangeInstructorPUMI->Enabled = false;
        ClearInstrcutorPUMI->Enabled = false;
    }
}
//---------------------------------------------------------------------------

void __fastcall TLessonBookingSheet::LessonRowPUPopup(TObject *Sender)
{
    if(m_pkBookingSheetUtils->LessonBooked())
    {
        CreateLessonPUMI->Enabled = false;
    }
    else
    {
        CreateLessonPUMI->Enabled = true;
    }

    if(LessonSG->Cells[LessonSG->Col][LessonSG->Row] == "")
    {
        EditLessonPUMI->Enabled = false;
        RemoveLessonPUMI->Enabled = false;
    }
    else
    {
        EditLessonPUMI->Enabled = true;
        RemoveLessonPUMI->Enabled = true;
    }
}
//---------------------------------------------------------------------------

//******************************************************************************
//Menu Items
//******************************************************************************

void __fastcall TLessonBookingSheet::ExitMIClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------

void __fastcall TLessonBookingSheet::LessonBookingWizardMIClick(TObject *Sender)
{
    BookingWizard->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TLessonBookingSheet::NormalLessonBookingMIClick(TObject *Sender)
{
    if(BookingWizard->ShowModal() == mrOk)
    {
        LessonSG->Cells[LessonSG->Col][LessonSG->Row] = "Booked";
    }
}
//---------------------------------------------------------------------------

void __fastcall TLessonBookingSheet::AboutMIClick(TObject *Sender)
{
    HelpForm->ShowModal();
}
//---------------------------------------------------------------------------


//******************************************************************************
//Buttons
//******************************************************************************

void __fastcall TLessonBookingSheet::LessonBookingNormalBTNClick(TObject *Sender)
{
    if(QuickLessonBooking->ShowModal() == mrOk)
    {

    }
}
//---------------------------------------------------------------------------

void __fastcall TLessonBookingSheet::LessonBookingWizzardBTNClick(TObject *Sender)
{
    BookingWizard->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TLessonBookingSheet::LessonHoldBTNClick(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------

void __fastcall TLessonBookingSheet::GotoDateBTNClick(TObject *Sender)
{
    if(DatePicker->Visible)
    {
        DatePicker->Hide();
    }
    else
    {
        DatePicker->Top = LessonBookingSheet->Top + ToolBar->Top + ToolBar->Height + ToolBar->Height + 14;
        DatePicker->Left = LessonBookingSheet->Left + GotoDateBTN->Left;
        DatePicker->Show();
    }

}
//---------------------------------------------------------------------------

void __fastcall TLessonBookingSheet::GotoTodayBTNClick(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------


