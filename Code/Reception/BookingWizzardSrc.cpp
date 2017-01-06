//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "BookingWizzardSrc.h"
#include "TCellComboBox.h"
#include "MVCControler.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "ccalendr"
#pragma resource "*.dfm"

TBookingWizard *BookingWizard;
//---------------------------------------------------------------------------

__fastcall TBookingWizard::TBookingWizard(TComponent* Owner) : TForm(Owner)
{
    PeopleOnLessonSG->Cells[0][0] = "Names";
    PeopleOnLessonSG->Cells[1][0] = "Telephone No.";
    PeopleOnLessonSG->Cells[2][0] = "P.d/T.P";

    m_pkCellCB = new TCellComboBox(PeopleOnLessonSG);
    m_pkCellCB->Parent = BookingWizard;
    m_pkCellCB->Items->Add("Paid");
    m_pkCellCB->Items->Add("T.P.");
    m_pkCellCB->Items->Add("Paid deposit of...");
    m_pkCellCB->m_pkCaller = PeopleOnLessonSG;

    bPeopleCountPage_AddedPeople = false;
}
//---------------------------------------------------------------------------

void __fastcall TBookingWizard::FormDestroy(TObject *Sender)
{
    delete m_pkCellCB;
}
//---------------------------------------------------------------------------

void __fastcall TBookingWizard::FormShow(TObject *Sender)
{
    LessonWizardNB->ActivePage = "LessonTypePage";
    LastBTN->Enabled = false;
    NextBTN->Enabled = false;
    SaveBTN->Enabled = false;

    AdultCombo->ItemIndex = 0;
    ChildCombo->ItemIndex = 0;

    tActivty = atNone;
    tLesson = lsNone;

//    ComboCellEditor->Items->Add("Paid");
//    ComboCellEditor->Items->Add("To Pay");
//    ComboCellEditor->Items->Add("Paid Dep");

    ResetLessonTypePageChoices();
    ResetCourseTypePageChoices();

    AdultCombo->ItemIndex = 0;
    ChildCombo->ItemIndex = 0;
}
//---------------------------------------------------------------------------

void TBookingWizard::ResetLessonTypePageChoices()
{
    SkiPanel->BevelOuter = bvRaised;
    BoardPanel->BevelOuter = bvRaised;
    BladePanel->BevelOuter = bvRaised;
}
//------------------------------------------------------------------------------

void TBookingWizard::ResetCourseTypePageChoices()
{
    TasterPanel->BevelOuter = bvRaised;
    MBPanel->BevelOuter = bvRaised;
    LIPanel->BevelOuter = bvRaised;
    UIPanel->BevelOuter = bvRaised;
}
//------------------------------------------------------------------------------

void __fastcall TBookingWizard::SkiPanelClick(TObject *Sender)
{
    //rase them all
    ResetLessonTypePageChoices();

    //set the one pressed down
    ((TPanel*)Sender)->BevelOuter = bvLowered;

    //test for the one down to set users choice
    if(SkiPanel->BevelOuter == bvLowered)      tActivty = atSki;
    if(BoardPanel->BevelOuter == bvLowered)    tActivty = atBoard;
    if(BladePanel->BevelOuter == bvLowered)    tActivty = atBlade;

    CourseTypePage_SetCourse();

    NextBTN->Enabled = true;
}
//---------------------------------------------------------------------------

void TBookingWizard::CourseTypePage_SetCourse()
{
    CourseTypePage_SkiLessonsPanel->Top = 0;
    CourseTypePage_BoardLessonsPanel->Top = 0;
    CourseTypePage_SkiLessonsPanel->Visible = false;
    CourseTypePage_BoardLessonsPanel->Visible = false;

    switch(tActivty)
    {
        case atSki : CourseTypePage_SkiLessonsPanel->Visible = true; break;
        case atBoard : CourseTypePage_BoardLessonsPanel->Visible = true; break;
        case atBlade : break;
    }
}
//------------------------------------------------------------------------------


void __fastcall TBookingWizard::LastBTNClick(TObject *Sender)
{
    //last
    if(LessonWizardNB->ActivePage == "LessonTypePage")
    {
    }
    else if(LessonWizardNB->ActivePage == "CourseTypePage")
    {
        LessonWizardNB->ActivePage = "LessonTypePage";
        LastBTN->Enabled = false;
        NextBTN->Enabled = true;
        Caption = "Booking Wizard - Step 1 of 5";

        HelpLabel->Caption = "Pick the type of activity your customer whould like to book for, Skiing, Snowboarding or Blading.";
    }
    else if(LessonWizardNB->ActivePage == "PeopleCountPage")
    {
        LessonWizardNB->ActivePage = "CourseTypePage";
        Caption = "Booking Wizard - Step 2 of 5";
        HelpLabel->Caption = "";
    }
    else if(LessonWizardNB->ActivePage == "DatesTimesPage")
    {
        LessonWizardNB->ActivePage = "PeopleCountPage";
        Caption = "Booking Wizard - Step 3 of 5";
        HelpLabel->Caption = "";
    }
    else if(LessonWizardNB->ActivePage == "ConfirmationPage")
    {
        LessonWizardNB->ActivePage = "DatesTimesPage";
        Caption = "Booking Wizard - Step 4 of 5";
        HelpLabel->Caption = "";

        NextBTN->Enabled = true;
    }
}
//---------------------------------------------------------------------------

void __fastcall TBookingWizard::NextBTNClick(TObject *Sender)
{
    //next
    if(LessonWizardNB->ActivePage == "LessonTypePage")
    {
        LessonWizardNB->ActivePage = "CourseTypePage";
        LastBTN->Enabled = true;
        if(tLesson == lsNone)
            NextBTN->Enabled = false;

        Caption = "Booking Wizard - Step 2 of 5";

        HelpLabel->Caption = "";
    }
    else if(LessonWizardNB->ActivePage == "CourseTypePage")
    {
        LessonWizardNB->ActivePage = "PeopleCountPage";
        Caption = "Booking Wizard - Step 3 of 5";
        NextBTN->Enabled = bPeopleCountPage_AddedPeople;

        HelpLabel->Caption = "";
    }
    else if(LessonWizardNB->ActivePage == "PeopleCountPage")
    {
        LessonWizardNB->ActivePage = "DatesTimesPage";
        Caption = "Booking Wizard - Step 4 of 5";

        HelpLabel->Caption = "";
    }
    else if(LessonWizardNB->ActivePage == "DatesTimesPage")
    {
        LessonWizardNB->ActivePage = "ConfirmationPage";
        Caption = "Booking Wizard - Step 5 of 5";

        NextBTN->Enabled = false;
        //SaveBTN->Enabled

        HelpLabel->Caption = "";
    }
    else if(LessonWizardNB->ActivePage == "ConfirmationPage")
    {
    }
}
//---------------------------------------------------------------------------

void __fastcall TBookingWizard::SaveBTNClick(TObject *Sender)
{
    //save

}
//---------------------------------------------------------------------------

void __fastcall TBookingWizard::CancelBTNClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------

void __fastcall TBookingWizard::TasterPanelClick(TObject *Sender)
{
    ResetCourseTypePageChoices();

    //set the one pressed down
    ((TPanel*)Sender)->BevelOuter = bvLowered;

    //test for the one down to set users choice
    if(TasterPanel->BevelOuter == bvLowered)tLesson = lsTaster;
    if(MBPanel->BevelOuter == bvLowered)    tLesson = lsMB;
    if(LIPanel->BevelOuter == bvLowered)    tLesson = lsLI;
    if(UIPanel->BevelOuter == bvLowered)    tLesson = lsUI;

    NextBTN->Enabled = true;
}
//---------------------------------------------------------------------------

void TBookingWizard::PeopleCountPage_UpdatePeopleCountXTG()
{
    int iMore = AdultCombo->ItemIndex + ChildCombo->ItemIndex > 0 ? 1 : 2;
    int iRows = AdultCombo->ItemIndex + ChildCombo->ItemIndex + iMore;

    if(iRows > 12)
    {
        Application->MessageBox("The Maximum number of people are already on this lesson,\n"
                                "you will not be able to book the about of people you want on this lesson.\n"
                                "Please either reduce the number of people you want to book on this lesson,\n"
                                "or find another lesson to book your customers on.",
                                "Maximum People On Lesson", MB_OK|MB_ICONINFORMATION);
        iRows = 12;
    }

    bPeopleCountPage_AddedPeople = iRows > 1;
    NextBTN->Enabled = bPeopleCountPage_AddedPeople;

    PeopleOnLessonSG->RowCount = iRows;
}
//------------------------------------------------------------------------------

void __fastcall TBookingWizard::AdultComboChange(TObject *Sender)
{
    PeopleCountPage_UpdatePeopleCountXTG();

    //now remove the numbers from the other combo box so cant select more that max
}
//---------------------------------------------------------------------------

void __fastcall TBookingWizard::ChildComboChange(TObject *Sender)
{
    PeopleCountPage_UpdatePeopleCountXTG();
}
//---------------------------------------------------------------------------

void __fastcall TBookingWizard::PeopleOnLessonSGSelectCell(
      TObject *Sender, int Col, int Row, bool &CanSelect)
{
    if (Col == 2)
    {
        TRect rec = PeopleOnLessonSG->CellRect(Col, Row);
        m_pkCellCB->Left = LessonWizardNB->Left + PeopleOnLessonSG->Left + rec.Left-46;
        m_pkCellCB->Top = LessonWizardNB->Top + PeopleOnLessonSG->Top + rec.Top;
        m_pkCellCB->Width = rec.Right - rec.Left + 48;

        m_pkCellCB->Visible = true;
        m_pkCellCB->Enabled = true;
        m_pkCellCB->DroppedDown = true;
        m_pkCellCB->SetFocus();
    }
    else
    {
    }
}
//---------------------------------------------------------------------------

void __fastcall TBookingWizard::ConfirmBTNClick(TObject *Sender)
{
    SaveBTN->Enabled = true;
    ConfirmBTN->Enabled = false;
}
//---------------------------------------------------------------------------

