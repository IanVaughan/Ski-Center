//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "LessonBookingSheetSrc.h"
#include "InstructorSrc.h"
#include "QuickLessonBookingSrc.h"
#include "BookingWizzardSrc.h"
#include "BookingSheetUtils.h"
#include "Help.h"
//#include "vcl/sysdefs.h" //date/time
#include "DatePickerSrc.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TLessonBookingSheet *LessonBookingSheet;
//---------------------------------------------------------------------------

int NUM_ROWS = 10;
int SelectedCol;
int SelectedRow;

__fastcall TLessonBookingSheet::TLessonBookingSheet(TComponent* Owner) : TForm(Owner)
{
    m_pkBookingSheetUtils = new BookingSheetUtils(LessonSG);

    m_pkBookingSheetUtils->SetRowHeights();

    weekSelector->Tabs->Add("Monday");
    weekSelector->Tabs->Add("Tuesday");
    weekSelector->Tabs->Add("Wednesday");
    weekSelector->Tabs->Add("Thursday");
    weekSelector->Tabs->Add("Friday");
    weekSelector->Tabs->Add("Saturday");
    weekSelector->Tabs->Add("Sunday");

//    TDateTime *Date;
//    DateTimePicker->Date = Date->CurrentDate();
}
//---------------------------------------------------------------------------

void __fastcall TLessonBookingSheet::FormDestroy(TObject *Sender)
{
    delete m_pkBookingSheetUtils;
}
//---------------------------------------------------------------------------

void __fastcall TLessonBookingSheet::FormResize(TObject *Sender)
{
    double dWidth = ClientWidth/NUM_ROWS;
    LessonSG->DefaultColWidth = dWidth-1.5;//ClientWidth/10 -2;
    weekSelector->TabWidth = ClientWidth/7 -1;
}
//---------------------------------------------------------------------------

void __fastcall TLessonBookingSheet::SetInstructorClick(TObject *Sender)
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
    SaveAll();
}
//---------------------------------------------------------------------------

void __fastcall TLessonBookingSheet::ChangeInstructorClick(TObject *Sender)
{
    SetInstructorClick(this);
}
//---------------------------------------------------------------------------

void __fastcall TLessonBookingSheet::ClearInstrcutorClick(TObject *Sender)
{
    TGridRect myRect;
    myRect = LessonSG->Selection;

    for (int i=myRect.Left; i <= myRect.Right; i++)
        LessonSG->Cells[i][LessonSG->Row] = "";

    SaveAll();
}
//---------------------------------------------------------------------------

void __fastcall TLessonBookingSheet::CreateLessonClick(TObject *Sender)
{
    QuickLessonBooking->ShowModal();
//    LessonXSG->Cells[LessonXSG->Col][LessonXSG->Row] = "test";
}
//---------------------------------------------------------------------------

void __fastcall TLessonBookingSheet::LessonBookingWizard1Click(TObject *Sender)
{
    BookingWizard->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TLessonBookingSheet::NormalLessonBooking1Click(TObject *Sender)
{
    if(BookingWizard->ShowModal() == mrOk)
    {
        LessonSG->Cells[LessonSG->Col][LessonSG->Row] = "Booked";
    }
}
//---------------------------------------------------------------------------

void __fastcall TLessonBookingSheet::Exit1Click(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------

void __fastcall TLessonBookingSheet::weekSelectorChange(TObject *Sender)
{
    for(int i=1; i< LessonSG->RowCount; i++)
        for(int j=0; j< LessonSG->ColCount; j++)
            LessonSG->Cells[j][i] = "";


//    int index = weekSelector->TabIndex;
    //LoadDow(index);
}
//---------------------------------------------------------------------------

bool TLessonBookingSheet::SaveAll()
{
    //save instructors time/days etc
    //save the changes
    TStringList *list = new TStringList;
    String name;

    for (int i=0; i < LessonSG->RowCount; i++)
    {
        if(!m_pkBookingSheetUtils->RowEven(i))
        for (int j=0; j < LessonSG->ColCount; j++)
        {
            name = LessonSG->Cells[j][i];

            //add time on
            //name = (String)j +" - " + name;
            list->Add(name);
        }
    }

    name = m_pkBookingSheetUtils->GetStringDOW(weekSelector->TabIndex) + ".ins";

    list->SaveToFile("Instructors\\"+name);

    delete list;

    return true;
}
// -----------------------------------------------------------------------------

/*bool TbookingSheet::LoadDow(BookingSheetUtils::DayOfWeek dow)
{
/*    char days[7][10] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
    TDateTime dtDate = StrToDate(Edit1->Text);
    ShowMessage(Edit1->Text + AnsiString(" is a ") + days[dtDate.DayOfWeek()]);*/
/*
    String filename = GetStringDOW(dow);

    filename = "Instructors\\"+ filename + ".ins";

    bool yes = FileExists(filename);
    if(!yes)
    {
        int ans = Application->MessageBox("That day of the week file was not found, perhaps it wasnt saved!\nDo you want to create one now, if you dont one will get created as soon as a change is made anyway.", "File not found", MB_YESNO|MB_ICONQUESTION);
        if(ans == ID_YES)
        {
            TStringList *list = new TStringList;
            list->SaveToFile(filename);
            delete list;
        }
        else
            return false;
    }

    TStringList *list = new TStringList;
    list->LoadFromFile(filename);

    //load in times and intructors booked in
    String name;

    int col = 0;
    int row = 0;

    for(int i=0; i< list->Count; i++)
    {
        name = list->Strings[i];

        LessonSG->Cells[col][row] = name;

        if(col < 9)
            col++;
        else
        {
            col = 0;

            if(row <= 0)
                row ++;
            else
                row+=2;
        }
    }

    return true;
}
// -----------------------------------------------------------------------------
*/
void __fastcall TLessonBookingSheet::bookingWizardBTNClick(TObject *Sender)
{
    BookingWizard->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TLessonBookingSheet::AboutMIClick(TObject *Sender)
{
    HelpForm->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TLessonBookingSheet::LessonXSGMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    //when autp selecting cell, the selection is lose, so save it
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
}
//---------------------------------------------------------------------------

void __fastcall TLessonBookingSheet::LessonXSGDblClick(TObject *Sender)
{
    if(!m_pkBookingSheetUtils->RowEven(m_iCurrentRow))
    {
        TGridRect myRect;
	    myRect.Left =  0;
        myRect.Top =  LessonSG->Row;
        myRect.Right =  NUM_ROWS;
        myRect.Bottom = LessonSG->Row;
        LessonSG->Selection = myRect;
    }
    else
    {
        if(m_pkBookingSheetUtils->InstructorBooked())
        if(BookingWizard->ShowModal() == mrOk)
        {
            LessonSG->Cells[LessonSG->Col][LessonSG->Row] = "Booked";
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TLessonBookingSheet::LessonXSGClick(TObject *Sender)
{
    m_iCurrentRow = LessonSG->Row;    
}
//---------------------------------------------------------------------------

void __fastcall TLessonBookingSheet::LessonXSGMouseMove(TObject *Sender,
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
        LessonSG->Hint = "";

    Application->ShowHint = true;
    
}
//---------------------------------------------------------------------------

//only allow min & max form sizes
void __fastcall TLessonBookingSheet::WMGetMinMaxInfo(TWMGetMinMaxInfo &Msg)
{
    Msg.MinMaxInfo->ptMinTrackSize.x=443; //ptMinTrackSize = min size allowed
    Msg.MinMaxInfo->ptMinTrackSize.y=450;//500; //by dragging with the mouse.

    Msg.MinMaxInfo->ptMaxTrackSize.x=933; //ptMaxTrackSize = max size allowed
    Msg.MinMaxInfo->ptMaxTrackSize.y=752; //by dragging with the mouse
}
//------------------------------------------------------------------------------

void __fastcall TLessonBookingSheet::LessonXSGDrawCell(TObject *Sender,
      int Col, int Row, TRect &Rect, TGridDrawState State)
{
    TCanvas *canvas = LessonSG->Canvas;

    bool bSelected = (Col == LessonSG->Col && Row == LessonSG->Row);//(Row == RowSelected || Row == RowRowReleased);

    canvas->Font->Color = clBlack;

    //if we want to set the cell color
    if(Col == SelectedCol && Row == SelectedRow)
    {
        canvas->Brush->Color = clRed;
    }
    //else if its just a mouse select
    else if(bSelected)
    {
        canvas->Brush->Color = clBlue;
        canvas->Font->Color = clWhite;
    }
    //else no select
    else
    {
        canvas->Brush->Color = clWhite;
    }

    //the first row is fixed
    if(Row == 0)
    {
        canvas->Brush->Color = clLtGray;
    }

    canvas->FillRect(Rect);
    canvas->TextOut(Rect.Left+3, Rect.Top+3, LessonSG->Cells[Col][Row]);

    if (State.Contains(gdSelected))
    {
        canvas->Brush->Color = clBlue;
        canvas->FillRect(Rect);
        //canvas->DrawFocusRect(Rect);
        canvas->Font->Color = clWhite;
        canvas->TextOut(Rect.Left+3, Rect.Top+3, LessonSG->Cells[Col][Row]);
    }
}
//---------------------------------------------------------------------------

void __fastcall TLessonBookingSheet::normalLessonBookingBTNClick(TObject *Sender)
{
    if(QuickLessonBooking->ShowModal() == mrOk)
    {
        
    }
}
//---------------------------------------------------------------------------

void __fastcall TLessonBookingSheet::weekChangerSBChange(TObject *Sender)
{
    weekChangerSB->Position = 5;    
}
//---------------------------------------------------------------------------

void __fastcall TLessonBookingSheet::instructorPopupPopup(TObject *Sender)
{
    SetInstructor->Enabled = true;
    ChangeInstructor->Enabled = true;
    ClearInstrcutor->Enabled = true;

    if(m_pkBookingSheetUtils->InstructorBooked())
    {
        ChangeInstructor->Enabled = true;
        ClearInstrcutor->Enabled = true;
    }
    else
    {
        ChangeInstructor->Enabled = false;
        ClearInstrcutor->Enabled = false;
    }
}
//---------------------------------------------------------------------------

void __fastcall TLessonBookingSheet::lessonPopupPopup(TObject *Sender)
{
    if(m_pkBookingSheetUtils->LessonBooked())
    {
        CreateLesson->Enabled = false;
    }
    else
    {
        CreateLesson->Enabled = true;
    }

    if(LessonSG->Cells[LessonSG->Col][LessonSG->Row] == "")
    {
        EditLesson->Enabled = false;
        RemoveLesson->Enabled = false;
    }
    else
    {
        EditLesson->Enabled = true;
        RemoveLesson->Enabled = true;
    }
}
//---------------------------------------------------------------------------

void __fastcall TLessonBookingSheet::AddnewRowClick(TObject *Sender)
{
    LessonSG->RowCount += 2;
    m_pkBookingSheetUtils->SetRowHeights();
}
//---------------------------------------------------------------------------

void __fastcall TLessonBookingSheet::RemoveRow1Click(TObject *Sender)
{
    int ans = Application->MessageBox("If you removed this row, lessons can not be booked on them.", "Do you want to remove the selected instructor row?", MB_YESNO|MB_ICONQUESTION);
    if(ans == ID_YES)
    {
        LessonSG->RowCount -= 2;
        m_pkBookingSheetUtils->SetRowHeights();
    }
}
//---------------------------------------------------------------------------

void __fastcall TLessonBookingSheet::ToolButton1Click(TObject *Sender)
{
    BookingWizard->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TLessonBookingSheet::GotoSBTNClick(TObject *Sender)
{
    if(DatePicker->Visible)
    {
        DatePicker->Hide();
    }
    else
    {
        DatePicker->Top = LessonBookingSheet->Top + ToolBar->Top + ToolBar->Height + ToolBar->Height + 14;
        DatePicker->Left = LessonBookingSheet->Left + GotoSBTN->Left;
        DatePicker->Show();
    }

}
//---------------------------------------------------------------------------

