//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "lessonBookingSrc.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "XStringGrid"
#pragma resource "*.dfm"
TlessonBookingForm *lessonBookingForm;
//---------------------------------------------------------------------------

__fastcall TlessonBookingForm::TlessonBookingForm(TComponent* Owner) : TForm(Owner)
{
    customersOnLessonGrid->Cells[0][0] = "Name";
    customersOnLessonGrid->Cells[1][0] = "Telephone";
    customersOnLessonGrid->Cells[2][0] = "T.P./P.d.";
}
//---------------------------------------------------------------------------

void __fastcall TlessonBookingForm::FormShow(TObject *Sender)
{
    pickMT->BevelOuter = bvRaised;
    pickMB->BevelOuter = bvRaised;
    pickLI->BevelOuter = bvRaised;
    pickUI->BevelOuter = bvRaised;
    pickEP->BevelOuter = bvRaised;
    pickPrivate->BevelOuter = bvRaised;

    lessonWizardNB->ActivePage = "actType";
    Caption = "Lesson Booking Wizard - 1/4 Lesson Type";

    lastBTN->Enabled = false;
    nextBTN->Enabled = false;
    saveBTN->Enabled = false;

    ActivtySet = atNone;
    SkiLessonSet = sltNone;
//    BoardLessonSet = bltNone;
//    BladeLessonSet = sbltNone;

    peopleAdult->ItemIndex = 0;
    peopleChild->ItemIndex = 0;
}
//---------------------------------------------------------------------------

void __fastcall TlessonBookingForm::pickMTClick(TObject *Sender)
{
    pickMT->BevelOuter = bvRaised;
    pickMB->BevelOuter = bvRaised;
    pickLI->BevelOuter = bvRaised;
    pickUI->BevelOuter = bvRaised;
    pickEP->BevelOuter = bvRaised;
    pickPrivate->BevelOuter = bvRaised;

    ((TPanel*)Sender)->BevelOuter = bvLowered;

    if(pickMT->BevelOuter == bvLowered)
        SkiLessonSet = sltMT;
    if(pickMB->BevelOuter == bvLowered)
        SkiLessonSet = sltMB;
    if(pickLI->BevelOuter == bvLowered)
        SkiLessonSet = sltLI;
    if(pickUI->BevelOuter == bvLowered)
        SkiLessonSet = sltUI;
    if(pickEP->BevelOuter == bvLowered)
        SkiLessonSet = sltEP;
    if(pickPrivate->BevelOuter == bvLowered)
        SkiLessonSet = sltPrivate;
}
//---------------------------------------------------------------------------

void __fastcall TlessonBookingForm::lastBTNClick(TObject *Sender)
{
    if(lessonWizardNB->ActivePage == "lessonType")
    {
//        nextBTN->Enabled = true;
    }

    else if(lessonWizardNB->ActivePage == "peopleCount")
    {
        lastBTN->Enabled = false;
        nextBTN->Enabled = true;

        lessonWizardNB->ActivePage = "lessonType";

        Caption = "Lesson Booking Wizard - 1/4 Lesson Type";
    }

    else if(lessonWizardNB->ActivePage == "customerDetials")
    {
        lessonWizardNB->ActivePage = "peopleCount";

        Caption = "Lesson Booking Wizard - 2/4 People Count";
    }

    else if(lessonWizardNB->ActivePage == "bookingOverview")
    {
        nextBTN->Enabled = true;

        lessonWizardNB->ActivePage = "customerDetials";

        Caption = "Lesson Booking Wizard - 3/4 Customer Detials";
    }
}
//---------------------------------------------------------------------------

void __fastcall TlessonBookingForm::nextBTNClick(TObject *Sender)
{
    if(lessonWizardNB->ActivePage == "actType")
    {
//        if(ActivtySet != atNone)
        {
            lessonWizardNB->ActivePage = "lessonType";

            lastBTN->Enabled = true;

            Caption = "Lesson Booking Wizard - 2/4 Covers";
        }
//        else
        {
            Application->MessageBox("Please click on one of the boxes to set which Actitivy type of lesson you want to book.", "No lesson activaty set", MB_OK|MB_ICONINFORMATION);
        }
    }

    else if(lessonWizardNB->ActivePage == "lessonType")
    {
        if(SkiLessonSet != sltNone)
        {
            lessonWizardNB->ActivePage = "peopleCount";

            lastBTN->Enabled = true;

            Caption = "Lesson Booking Wizard - 2/4 People Count";
        }
        else
        {
            Application->MessageBox("Please click on one of the coloured boxes to set which type of lesson you want to book.","No lesson type set",MB_OK|MB_ICONINFORMATION);
        }
    }

    else if(lessonWizardNB->ActivePage == "peopleCount")
    {
        int pplCount = peopleAdult->Text.ToIntDef(0) + peopleChild->Text.ToIntDef(0);
        if(pplCount >0 && pplCount <= 12)
        {
            lessonWizardNB->ActivePage = "customerDetials";

            Caption = "Lesson Booking Wizard - 3/4 Customer Detials";

            customersOnLessonGrid->RowCount = pplCount+1;//(peopleAdult->Text.ToIntDef(0)) + (peopleChild->Text.ToIntDef(0));
        }
        else
        {
            Application->MessageBox("There was an incorrect amount of people set onto this lesson, please make sure its within 1 and 12.","No people set",MB_OK|MB_ICONINFORMATION);
        }
    }

    else if(lessonWizardNB->ActivePage == "customerDetials")
    {
        lessonWizardNB->ActivePage = "bookingOverview";

        Caption = "Lesson Booking Wizard - 4/4 Lesson Confirmation";

        nextBTN->Enabled = false;
    }

    else if(lessonWizardNB->ActivePage == "bookingOverview")
    {
    }
}
//---------------------------------------------------------------------------

void __fastcall TlessonBookingForm::confirmBTNClick(TObject *Sender)
{
    saveBTN->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TlessonBookingForm::cancelBTNClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------

void __fastcall TlessonBookingForm::saveBTNClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------

void __fastcall TlessonBookingForm::ScrollBar1Change(TObject *Sender)
{
    if(ScrollBar1->Position == 0)
        lessonPanel->Top = 40;
    else if(ScrollBar1->Position == 1)
        lessonPanel->Top = 30;
    else if(ScrollBar1->Position == 2)
        lessonPanel->Top = 20;
    else if(ScrollBar1->Position == 3)
        lessonPanel->Top = 10;
    else if(ScrollBar1->Position == 4)
        lessonPanel->Top = 0;
    else if(ScrollBar1->Position == 5)
        lessonPanel->Top = -10;
    else if(ScrollBar1->Position == 6)
        lessonPanel->Top = -20;
    else if(ScrollBar1->Position == 7)
        lessonPanel->Top = -30;
    else if(ScrollBar1->Position == 8)
        lessonPanel->Top = -40;
    else if(ScrollBar1->Position == 9)
        lessonPanel->Top = -50;
    else if(ScrollBar1->Position == 10)
        lessonPanel->Top = -60;
    else if(ScrollBar1->Position == 11)
        lessonPanel->Top = -70;
    else if(ScrollBar1->Position == 12)
        lessonPanel->Top = -80;
    else if(ScrollBar1->Position == 13)
        lessonPanel->Top = -90;
    else if(ScrollBar1->Position == 14)
        lessonPanel->Top = -100;
    else if(ScrollBar1->Position == 15)
        lessonPanel->Top = -110;
    else if(ScrollBar1->Position == 16)
        lessonPanel->Top = -120;
    else if(ScrollBar1->Position == 17)
        lessonPanel->Top = -130;
    else if(ScrollBar1->Position == 18)
        lessonPanel->Top = -140;
    else if(ScrollBar1->Position == 19)
        lessonPanel->Top = -150;
    else if(ScrollBar1->Position == 20)
        lessonPanel->Top = -160;
    else if(ScrollBar1->Position == 21)
        lessonPanel->Top = -170;
    else if(ScrollBar1->Position == 22)
        lessonPanel->Top = -180;
    else if(ScrollBar1->Position == 23)
        lessonPanel->Top = -190;
    else if(ScrollBar1->Position == 24)
        lessonPanel->Top = -200;
    else if(ScrollBar1->Position == 25)
        lessonPanel->Top = -210;

/*    static int oldPos = ScrollBar1->Position;

    if(ScrollBar1->Position < oldPos)
        lessonPanel->Top += 10 + (ScrollBar1->Position * oldPos);
    else
        lessonPanel->Top -= 10 + (ScrollBar1->Position * oldPos);

    oldPos = ScrollBar1->Position;*/
}
//---------------------------------------------------------------------------
/*    pickSki->BevelOuter = bvRaised;
    pickBoard->BevelOuter = bvRaised;
    pickBlade->BevelOuter = bvRaised;

    ((TPanel*)Sender)->BevelOuter = bvLowered;

    if(pickSki->BevelOuter == bvLowered)      ActivtySet = atSki;
    if(pickBoard->BevelOuter == bvLowered)    ActivtySet = atBoard;
    if(pickBlade->BevelOuter == bvLowered)    ActivtySet = atBlade;*/







