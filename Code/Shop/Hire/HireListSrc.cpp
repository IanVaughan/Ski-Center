//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "HireListSrc.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
THireList *HireList;
//---------------------------------------------------------------------------

__fastcall THireList::THireList(TComponent* Owner) : TForm(Owner)
{
    PopulateTickBoxes();
}  
//---------------------------------------------------------------------------

void __fastcall THireList::FormDestroy(TObject *Sender)
{
    RemoveTickBoxes();
}
//---------------------------------------------------------------------------

void __fastcall THireList::FormShow(TObject *Sender)
{
    HireListSG->Cells[0][0] = "";
    HireListSG->Cells[1][0] = "Dept. Date";
    HireListSG->Cells[2][0] = "Cust. Name";
    //HireListSG->Cells[3][0] = "Hiring...";
    HireListSG->Cells[3][0] = "Ski Make";
    HireListSG->Cells[4][0] = "Size";
    HireListSG->Cells[5][0] = "DIN";
    HireListSG->Cells[6][0] = "Boot Make";
    HireListSG->Cells[7][0] = "Size";
    HireListSG->Cells[8][0] = "Poles";
    HireListSG->Cells[9][0] = "Board Make";
    HireListSG->Cells[10][0] = "Size";
    HireListSG->Cells[11][0] = "Stans";
    HireListSG->Cells[12][0] = "Boot Make";
    HireListSG->Cells[13][0] = "Size";
    HireListSG->Cells[14][0] = "Done?";
}
//---------------------------------------------------------------------------

void THireList::PopulateTickBoxes()
{
    for(int i=0; i<HireListSG->RowCount-1; i++)
    {
        TCheckBox *pkCB = new TCheckBox(HireListSG);
        pkCB->Left = GetColWidth(15) - 10;
        pkCB->Top = 5 + (i+1) * (HireListSG->RowHeights[i] + 1);
        pkCB->Caption = "";
        pkCB->Width = 16;
        pkCB->Checked = false;
        pkCB->AllowGrayed = false;
        pkCB->Visible = true;
        pkCB->Color = clWhite;
        pkCB->Parent = this;

        HireListSG->Objects[14][i] = pkCB;
    }
}
//------------------------------------------------------------------------------

void THireList::RemoveTickBoxes()
{
    for(int i=0; i<HireListSG->RowCount; i++)
    {
        delete HireListSG->Objects[4][i];
    }
}
//------------------------------------------------------------------------------

int THireList::GetColWidth(int iCount)
{
    int i=0;
    int iSize = 0;

    while(i<iCount && i < HireListSG->ColCount)
    {
        iSize +=HireListSG->ColWidths[i];
        i++;
    }

    return iSize;
}
//------------------------------------------------------------------------------


