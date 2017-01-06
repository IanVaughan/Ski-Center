//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "bookingSheetSrc.h"
#include "instructorSrc.h"
//#include "LessonBookingSrc.h"
#include "BookingSheetUtils.h"
#include "quickLessonBookingSrc.h"
#include "BookingSheetUtils.h"
#include "help.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "XStringGrid"
#pragma resource "*.dfm"
TbookingSheet *bookingSheet;
//---------------------------------------------------------------------------

int NUM_ROWS = 3;

__fastcall TbookingSheet::TbookingSheet(TComponent* Owner) : TForm(Owner)
{
    LessonGrid->RowHeights[2] = 50;
    LessonGrid->RowHeights[4] = 50;
    LessonGrid->RowHeights[6] = 50;
    LessonGrid->RowHeights[8] = 50;
    LessonGrid->RowHeights[10] = 50;

    weekSelector->Tabs->Add("Monday");
    weekSelector->Tabs->Add("Tuesday");
    weekSelector->Tabs->Add("Wednesday");
    weekSelector->Tabs->Add("Thursday");
    weekSelector->Tabs->Add("Friday");
    weekSelector->Tabs->Add("Saturday");
    weekSelector->Tabs->Add("Sunday");

    m_pkBookingSheetUtils = new BookingSheetUtils(LessonGrid);

//    LoadDow(dowMonday);
}
//---------------------------------------------------------------------------

void __fastcall TbookingSheet::FormDestroy(TObject *Sender)
{
    delete m_pkBookingSheetUtils;
}
//---------------------------------------------------------------------------

void __fastcall TbookingSheet::FormResize(TObject *Sender)
{
    double dWidth = ClientWidth/NUM_ROWS;
    LessonGrid->DefaultColWidth = dWidth-1.5;//ClientWidth/10 -2;
    weekSelector->TabWidth = ClientWidth/7 -1;
}
//---------------------------------------------------------------------------

void __fastcall TbookingSheet::LessonGridMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    //when autp selecting cell, the selection is lose, so save it
    TGridRect myRect;
	myRect = LessonGrid->Selection;

    // Auto select cell on right click context menu show
    //get cell mouse click was in
    int ACol;
    int ARow;
    LessonGrid->MouseToCell(X, Y, ACol, ARow);

    if(ACol == -1 || ARow == -1) return;

    //if right clicked inside selection
    if(ACol >= myRect.Left && ACol <= myRect.Right && ARow >= myRect.Top && ARow <= myRect.Bottom)
    {
        //set the selected cell to the one found under the mouse
        LessonGrid->Selection = myRect;
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
            LessonGrid->Selection = myRect;
        }
        else
        {
            LessonGrid->Col = ACol;
            LessonGrid->Row = ARow;
        }
    }

    //now show the correct menu type, Lesson or Instructor
    if(ARow == 0)
        LessonGrid->PopupMenu = columnPU;
    else if(RowEven(LessonGrid->Row))
        LessonGrid->PopupMenu = lessonPopup;
    else
        LessonGrid->PopupMenu = instructorPopup;
}
//---------------------------------------------------------------------------

void __fastcall TbookingSheet::LessonGridDblClick(TObject *Sender)
{
    if(!RowEven(m_iCurrentRow))
    {
        TGridRect myRect;
	    myRect.Left =  0;
        myRect.Top =  LessonGrid->Row;
        myRect.Right =  NUM_ROWS;
        myRect.Bottom = LessonGrid->Row;
        LessonGrid->Selection = myRect;
    }
    else
    {
        if(m_pkBookingSheetUtils->InstructorBooked())
        if(QuickLessonBooking->ShowModal() == mrOk)
        {
            LessonGrid->Cells[LessonGrid->Col][LessonGrid->Row] = "Booked";
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall TbookingSheet::SetInstructor1Click(TObject *Sender)
{
    if(instructorForm->ShowModal() == mrOk)
    {
        String name = instructorForm->GetSelectedName();

        TGridRect myRect;
        myRect = LessonGrid->Selection;

        for (int i=myRect.Left; i <= myRect.Right; i++)
        {
            LessonGrid->Cells[i][LessonGrid->Row] = name;
        }
    }
    SaveAll();
}
//---------------------------------------------------------------------------

void __fastcall TbookingSheet::ChangeInstructor1Click(TObject *Sender)
{
    SetInstructor1Click(this);
}
//---------------------------------------------------------------------------

void __fastcall TbookingSheet::ClearInstrcutor1Click(TObject *Sender)
{
    TGridRect myRect;
    myRect = LessonGrid->Selection;

    for (int i=myRect.Left; i <= myRect.Right; i++)
        LessonGrid->Cells[i][LessonGrid->Row] = "";

    SaveAll();
}
//---------------------------------------------------------------------------

void __fastcall TbookingSheet::lessonPopupPopup(TObject *Sender)
{
    if(m_pkBookingSheetUtils->LessonBooked())
    {
        CreateLesson->Enabled = false;
    }
    else
    {
        CreateLesson->Enabled = true;
    }

    if(LessonGrid->Cells[LessonGrid->Col][LessonGrid->Row] == "")
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

void __fastcall TbookingSheet::CreateLessonClick(TObject *Sender)
{
//    LessonBookingForm->ShowModal();
//    LessonGrid->Cells[LessonGrid->Col][LessonGrid->Row] = "test";
}
//---------------------------------------------------------------------------

void __fastcall TbookingSheet::LessonGridClick(TObject *Sender)
{
    m_iCurrentRow = LessonGrid->Row;
}
//---------------------------------------------------------------------------

void __fastcall TbookingSheet::LessonBookingWizard1Click(TObject *Sender)
{
    lessonBookingForm->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TbookingSheet::NormalLessonBooking1Click(TObject *Sender)
{
    if(QuickLessonBooking->ShowModal() == mrOk)
    {
        LessonGrid->Cells[LessonGrid->Col][LessonGrid->Row] = "Booked";
    }
}
//---------------------------------------------------------------------------

void __fastcall TbookingSheet::Exit1Click(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------

void __fastcall TbookingSheet::weekSelectorChange(TObject *Sender)
{
    for(int i=1; i< LessonGrid->RowCount; i++)
        for(int j=0; j< LessonGrid->ColCount; j++)
            LessonGrid->Cells[j][i] = "";


    int index = weekSelector->TabIndex;
    //LoadDow(index);
}
//---------------------------------------------------------------------------

void __fastcall TbookingSheet::LessonGridMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
    //select correct hint
    LessonGrid->Hint = "";

    int ACol;
    int ARow;
    LessonGrid->MouseToCell(X, Y, ACol, ARow);

    if(m_pkBookingSheetUtils->LessonBooked(ACol, ARow))
    {
        LessonGrid->Hint = "No Lesson, double click to create one.";
    }
    else if(m_pkBookingSheetUtils->InstructorBooked(ACol, ARow))
    {
        LessonGrid->Hint = "No Instructor, right click to set one.";
    }
    else
        LessonGrid->Hint = "";

    Application->ShowHint = true;
}
//---------------------------------------------------------------------------

void __fastcall TbookingSheet::lessonGrid1DrawCell(TObject *Sender, int Col,
      int Row, TRect &Rect, TGridDrawState State)
{
/*    if(Col == 2 && Row == 4)
    {
        LessonGrid->Brush->Style = bsSolid;
        LessonGrid->Brush->Color = clRed;
        LessonGrid->Canvas->FillRect(Rect);
    }
*/
}
//---------------------------------------------------------------------------

bool TbookingSheet::SaveAll()
{
    //save instructors time/days etc
    //save the changes
    TStringList *list = new TStringList;
    String name;

    for (int i=0; i < LessonGrid->RowCount; i++)
    {
        if(!RowEven(i))
        for (int j=0; j < LessonGrid->ColCount; j++)
        {
            name = LessonGrid->Cells[j][i];

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

bool TbookingSheet::LoadAll()
{
    return false;
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

        LessonGrid->Cells[col][row] = name;

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
void __fastcall TbookingSheet::bookingWizardBTNClick(TObject *Sender)
{
    lessonBookingForm->ShowModal();
}
//---------------------------------------------------------------------------

int SelectedCol;
int SelectedRow;

void __fastcall TbookingSheet::lessonGridDrawCell(TObject *Sender, int Col,
      int Row, TRect &Rect, TGridDrawState State)
{
    TCanvas *canvas = LessonGrid->Canvas;

    bool bSelected = (Col == LessonGrid->Col && Row == LessonGrid->Row);//(Row == RowSelected || Row == RowRowReleased);

    canvas->Font->Color = clBlack;

    //if we want to set the cell color
    if(Col == SelectedCol && Row == SelectedRow)
    {
        canvas->Brush->Color = clRed;
    }
    //else uif its just a mouse select
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
    if(Row ==0)
    {
        canvas->Brush->Color = clLtGray;
    }

    canvas->FillRect(Rect);
    canvas->TextOut(Rect.Left+3, Rect.Top+3, LessonGrid->Cells[Col][Row]);
}
//---------------------------------------------------------------------------

void __fastcall TbookingSheet::AboutMIClick(TObject *Sender)
{
    helpForm->ShowModal();
}
//---------------------------------------------------------------------------


