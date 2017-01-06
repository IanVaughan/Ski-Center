//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "InstructorSrc.h"
#include "InstructorNameSrc.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TInstructorForm *InstructorForm;
//---------------------------------------------------------------------------

const String INSTRUCTOR_FILE = "..\\Instructors\\Instructors.txt";

__fastcall TInstructorForm::TInstructorForm(TComponent* Owner) : TForm(Owner)
{
}
//---------------------------------------------------------------------------

String TInstructorForm::GetSelectedName()
{
    int iSelected = InstructorListBox->ItemIndex;
    return InstructorListBox->Items->Strings[iSelected];
}
// -----------------------------------------------------------------------------

void __fastcall TInstructorForm::InstructorListBoxClick(TObject *Sender)
{
    if(InstructorListBox->ItemIndex > -1)
    {
        SaveBTN->Enabled = true;
    }
    else
    {
        SaveBTN->Enabled = false;
    }
}
//---------------------------------------------------------------------------

void __fastcall TInstructorForm::AddMIClick(TObject *Sender)
{
    //add
    if(InstructorNameEdit->ShowModal() == mrOk)
    {
        InstructorListBox->Items->Add(InstructorNameEdit->nameEdit->Text);
    }
}
//---------------------------------------------------------------------------

void __fastcall TInstructorForm::EditMIClick(TObject *Sender)
{
    //edit
    int sel = InstructorListBox->ItemIndex;
    InstructorNameEdit->nameEdit->Text = GetSelectedName();
    if(InstructorNameEdit->ShowModal()== mrOk)
    {
        InstructorListBox->Items->Delete(sel);
        InstructorListBox->Items->Add(InstructorNameEdit->nameEdit->Text);
    }
}
//---------------------------------------------------------------------------

void __fastcall TInstructorForm::DeleteMIClick(TObject *Sender)
{
    //delete
    InstructorListBox->Items->Delete(InstructorListBox->ItemIndex);
}
//---------------------------------------------------------------------------


void __fastcall TInstructorForm::InstructorListBoxDblClick(TObject *Sender)
{
    SaveBTNClick(this);
}
//---------------------------------------------------------------------------

void __fastcall TInstructorForm::SaveBTNClick(TObject *Sender)
{
    InstructorListBox->Items->SaveToFile(INSTRUCTOR_FILE);
    //Close();
    ModalResult = mrOk;    
}
//---------------------------------------------------------------------------

void __fastcall TInstructorForm::FormShow(TObject *Sender)
{
    String filename = INSTRUCTOR_FILE;

    bool bFound = FileExists(filename);
    if(!bFound)
    {
        Application->MessageBox("Thw Instructors file was not found.\nA new blank one has been created for you.",
                                "File not found", MB_OK|MB_ICONERROR);
        InstructorListBox->Items->SaveToFile(filename);
    }

    InstructorListBox->Items->LoadFromFile(filename);
}
//---------------------------------------------------------------------------

void __fastcall TInstructorForm::PopupMenu1Popup(TObject *Sender)
{
    if(InstructorListBox->ItemIndex == -1)
    {
        EditMI->Enabled = false;
        DeleteMI->Enabled = false;
    }
    else
    {
        EditMI->Enabled = true;
        DeleteMI->Enabled = true;
    }
}
//---------------------------------------------------------------------------

