//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "LessonBookingSheetSrc.h"
#include "BookingSheetUtils.h"
#include "MVCControler.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TLessonBookingSheet *LessonBookingSheet;
//---------------------------------------------------------------------------

__fastcall TLessonBookingSheet::TLessonBookingSheet(TComponent* Owner) : TForm(Owner)
{
    m_pkBookingSheetUtils = new BookingSheetUtils(LessonSG);

    weekSelector->Tabs->Add("Monday");
    weekSelector->Tabs->Add("Tuesday");
    weekSelector->Tabs->Add("Wednesday");
    weekSelector->Tabs->Add("Thursday");
    weekSelector->Tabs->Add("Friday");
    weekSelector->Tabs->Add("Saturday");
    weekSelector->Tabs->Add("Sunday");
}
//---------------------------------------------------------------------------

void __fastcall TLessonBookingSheet::FormDestroy(TObject *Sender)
{
    delete m_pkBookingSheetUtils;
}
//---------------------------------------------------------------------------

void __fastcall TLessonBookingSheet::FormShow(TObject *Sender)
{
    TDateTime today;
    today = today.CurrentDate();
    if(m_pkControler->GetSheet(today, m_pkCurrentDaySheet))
    {
        LessonSG->RowCount = m_pkCurrentDaySheet->iNumOfRows;
        LessonSG->ColCount = m_pkCurrentDaySheet->iNumOfBlocks;

        m_pkBookingSheetUtils->SetRowHeights();
    }
}
//---------------------------------------------------------------------------

void __fastcall TLessonBookingSheet::FormResize(TObject *Sender)
{
    double dWidth = ClientWidth / LessonSG->ColCount;
    LessonSG->DefaultColWidth = dWidth-1.5;
    weekSelector->TabWidth = ClientWidth/7 -1;
}
//---------------------------------------------------------------------------

void __fastcall TLessonBookingSheet::weekSelectorChange(TObject *Sender)
{
    for(int i=1; i< LessonSG->RowCount; i++)
        for(int j=0; j< LessonSG->ColCount; j++)
            LessonSG->Cells[j][i] = "";
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

void __fastcall TLessonBookingSheet::WeekChangerSBChange(TObject *Sender)
{
    WeekChangerSB->Position = 5;    
}
//---------------------------------------------------------------------------

void __fastcall TLessonBookingSheet::LessonSGDrawCell(TObject *Sender,
      int Col, int Row, TRect &Rect, TGridDrawState State)
{
    TCanvas *canvas = LessonSG->Canvas;

    bool bSelected = (Col == LessonSG->Col && Row == LessonSG->Row);

    if(bSelected)
    {
        canvas->Brush->Color = clBlue;
        canvas->Font->Color = clWhite;
    }
    //else no select
    else
    {
//        canvas->Brush->Color = m_pkBookingSheetUtils->GetCellColor(Col, Row);
    }

    //the first row is fixed
    if(Row == 0)
    {
        canvas->Brush->Color = clLtGray;
    }

    canvas->Font->Color = clBlack;

    canvas->FillRect(Rect);
    canvas->TextOut(Rect.Left+3, Rect.Top+3, LessonSG->Cells[Col][Row]);
//    canvas->TextOut(Rect.Left+3, Rect.Top+3, m_pkBookingSheetUtils->GetCellText(Col, Row));

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

void TLessonBookingSheet::SetDate(TDate)
{
}
//------------------------------------------------------------------------------


