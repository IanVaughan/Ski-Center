//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "LBS_MouseDownEvents.h"
#include "LessonBookingSheetSrc.h"
#include "InstructorSrc.h"
#include "BookingSheetUtils.h"
#include "QuickLessonBookingSrc.h"
#include "BookingWizzardSrc.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

//******************************************************************************
//Mouse Events
//******************************************************************************

void __fastcall TLessonBookingSheet::LessonSGClick(TObject *Sender)
{
    m_iCurrentRow = LessonSG->Row;
}
//---------------------------------------------------------------------------

void __fastcall TLessonBookingSheet::LessonSGDblClick(TObject *Sender)
{
    if(!m_pkBookingSheetUtils->RowEven(m_iCurrentRow))
    {
        TGridRect myRect;
	    myRect.Left =  0;
        myRect.Top =  LessonSG->Row;
        myRect.Right = LessonSG->ColCount;
        myRect.Bottom = LessonSG->Row;
        LessonSG->Selection = myRect;
    }
    else
    {
        if(m_pkBookingSheetUtils->InstructorBooked()
        && BookingWizard->ShowModal() == mrOk)
        {
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TLessonBookingSheet::LessonSGMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    if(Button == mbRight)
    {
        TGridCoord cord = LessonSG->MouseCoord(X, Y);
        LessonSG->Col = cord.X;
        LessonSG->Row = cord.Y;
        
        X += LessonBookingSheet->Left + 5;
        Y += LessonBookingSheet->Top + ToolBar->Height + 30 + 25;
        if(cord.Y == 0)
        {
            TimeRowPU->Popup(X, Y);
        }
        else if(!m_pkBookingSheetUtils->RowEven(cord.Y))
        {
            InstructorRowPU->Popup(X, Y);
        }
        else
        {
            LessonRowPU->Popup(X, Y);
        }
    }
    /*
    //when auto selecting cell, the selection is lose, so save it
    TGridRect myRect;
	myRect = LessonSG->Selection;

    // Auto select cell on right click context menu show
    //get cell mouse click was in
    int ACol;
    int ARow;
    LessonSG->MouseToCell(X, Y, ACol, ARow);

    if(ACol == -1 || ARow == -1) return;

    //if right clicked inside selection
    if(ACol >= myRect.Left && ACol <= myRect.Right && ARow >= myRect.Top && ARow <= myRect.Bottom)
    {
        //set the selected cell to the one found under the mouse
        LessonSG->Selection = myRect;
    }
    else
    {
        if(ARow == 0)
        {
            TGridRect myRect;
	        myRect.Left =  ACol;
            myRect.Top =  0;
            myRect.Right =  ACol;
            myRect.Bottom = NUM_ROWS;
            LessonSG->Selection = myRect;
        }
        else
        {
            LessonSG->Col = ACol;
            LessonSG->Row = ARow;
        }
    }

    //now show the correct menu type, Lesson or Instructor
    if(ARow == 0)
        LessonSG->PopupMenu = columnPU;
    else if(m_pkBookingSheetUtils->RowEven(LessonSG->Row))
        LessonSG->PopupMenu = lessonPopup;
    else
        LessonSG->PopupMenu = instructorPopup;
    */
}
//---------------------------------------------------------------------------

void __fastcall TLessonBookingSheet::LessonSGMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
    //select correct hint
    LessonSG->Hint = "";

    int ACol;
    int ARow;
    LessonSG->MouseToCell(X, Y, ACol, ARow);

    if(m_pkBookingSheetUtils->LessonBooked(ACol, ARow))
    {
        LessonSG->Hint = "No Lesson, double click to create one.";
    }
    else if(m_pkBookingSheetUtils->InstructorBooked(ACol, ARow))
    {
        LessonSG->Hint = "No Instructor, right click to set one.";
    }
    else
    {
        LessonSG->Hint = "";
    }
    
    Application->ShowHint = true;
}
//---------------------------------------------------------------------------

//******************************************************************************
//Popups
//******************************************************************************

//TimeColumnPU

void __fastcall TLessonBookingSheet::AddTimeSlotPUMIClick(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------

void __fastcall TLessonBookingSheet::EditTimeSlotPUMIClick(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------

void __fastcall TLessonBookingSheet::RemoveTimeSlotPUMIClick(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------

//InstructorRowPU

void __fastcall TLessonBookingSheet::SetInstructorPUMIClick(TObject *Sender)
{
    if(InstructorForm->ShowModal() == mrOk)
    {
        String name = InstructorForm->GetSelectedName();

        TGridRect myRect;
        myRect = LessonSG->Selection;

        for (int i=myRect.Left; i <= myRect.Right; i++)
        {
            LessonSG->Cells[i][LessonSG->Row] = name;
        }
    }
//    SaveAll();
}
//---------------------------------------------------------------------------

void __fastcall TLessonBookingSheet::ChangeInstructorPUMIClick(TObject *Sender)
{
    SetInstructorPUMIClick(this);
}
//---------------------------------------------------------------------------

void __fastcall TLessonBookingSheet::ClearInstrcutorPUMIClick(TObject *Sender)
{
    TGridRect myRect;
    myRect = LessonSG->Selection;

    for (int i=myRect.Left; i <= myRect.Right; i++)
        LessonSG->Cells[i][LessonSG->Row] = "";

//    SaveAll();
}
//---------------------------------------------------------------------------

void __fastcall TLessonBookingSheet::AddnewRowPUMIClick(TObject *Sender)
{
    LessonSG->RowCount += 2;
    m_pkBookingSheetUtils->SetRowHeights();
}
//---------------------------------------------------------------------------

void __fastcall TLessonBookingSheet::RemoveRowPUMIClick(TObject *Sender)
{
    int ans = Application->MessageBox("If you removed this row, lessons can not be booked on them.", "Do you want to remove the selected instructor row?", MB_YESNO|MB_ICONQUESTION);
    if(ans == ID_YES)
    {
        LessonSG->RowCount -= 2;
        m_pkBookingSheetUtils->SetRowHeights();
    }
}
//---------------------------------------------------------------------------

//LessonRowPU

void __fastcall TLessonBookingSheet::CreateLessonPUMIClick(TObject *Sender)
{
    QuickLessonBooking->ShowModal();
//    LessonXSG->Cells[LessonXSG->Col][LessonXSG->Row] = "test";
}
//---------------------------------------------------------------------------

void __fastcall TLessonBookingSheet::EditLessonPUMIClick(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------

void __fastcall TLessonBookingSheet::RemoveLessonPUMIClick(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------
