//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "TCellComboBox.h"

#include <Grids.hpp>

//---------------------------------------------------------------------------
#pragma package(smart_init)

__fastcall TCellComboBox::TCellComboBox(TComponent* AOwner) : TComboBox(AOwner)
{
    Enabled = false;
    Visible = false;
    DropDownCount = 3;
    Color = clWindow;
    Ctl3D = true;
    Cursor = crDefault;
    DragCursor = crDrag;
    ParentFont = true;
    Style = Stdctrls::csDropDownList;
    TabStop = false;
    OnExit = ComboExit;
    Focusing = false;    
}
// -----------------------------------------------------------------------------

void __fastcall TCellComboBox::WndProc(TMessage &message)
{
    if (message.Msg == WM_KEYDOWN || message.Msg == WM_SYSKEYDOWN)
    {
        if(message.WParam == VK_TAB
        || message.WParam == VK_LEFT
        || message.WParam == VK_RIGHT)
        {
            Visible = false;
            Enabled = false;
            Focusing = true;
            m_pkCaller->SetFocus();

            //163/979-010301      PostMessage(Caller->Handle,message.Msg,message.WParam,0);
        }
        else
        {
            TComboBox::WndProc(message);
        }
    }
    else
    {
        TComboBox::WndProc(message);
    }
}
// -----------------------------------------------------------------------------

void __fastcall TCellComboBox::ComboExit(TObject* Sender)
{
    Enabled = false;
    Visible = false;

    TStringGrid *pkSG = dynamic_cast<TStringGrid*> (Owner);
    if(pkSG)
    {
        pkSG->Cells[pkSG->Col][pkSG->Row] = Text;
    }
}
//---------------------------------------------------------------------------

