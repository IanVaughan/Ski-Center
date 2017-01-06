//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "InstructorSrc.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TInstructorForm *InstructorForm;
//---------------------------------------------------------------------------

__fastcall TInstructorForm::TInstructorForm(TComponent* Owner) : TForm(Owner)
{
}
//---------------------------------------------------------------------------

String TInstructorForm::GetSelectedName()
{
    int sel = instructorList->ItemIndex;
    return instructorList->Items->Strings[sel];
}
// -----------------------------------------------------------------------------

void __fastcall TInstructorForm::instructorListClick(TObject *Sender)
{
    if(instructorList->ItemIndex > -1)
        saveBTN->Enabled = true;
    else
        saveBTN->Enabled = false;
}
//---------------------------------------------------------------------------

#include "InstructorNameSrc.h"
void __fastcall TInstructorForm::AddMIClick(TObject *Sender)
{
    //add
    if(InstructorNameEdit->ShowModal() == mrOk)
    {
        instructorList->Items->Add(InstructorNameEdit->nameEdit->Text);
    }
}
//---------------------------------------------------------------------------

void __fastcall TInstructorForm::EditMIClick(TObject *Sender)
{
    //edit
    int sel = instructorList->ItemIndex;
    InstructorNameEdit->nameEdit->Text = GetSelectedName();
    if(InstructorNameEdit->ShowModal()== mrOk)
    {
        instructorList->Items->Delete(sel);
        instructorList->Items->Add(InstructorNameEdit->nameEdit->Text);
    }
}
//---------------------------------------------------------------------------

void __fastcall TInstructorForm::DeleteMIClick(TObject *Sender)
{
    //delete
    instructorList->Items->Delete(instructorList->ItemIndex);
}
//---------------------------------------------------------------------------


void __fastcall TInstructorForm::instructorListDblClick(TObject *Sender)
{
    saveBTNClick(this);        
}
//---------------------------------------------------------------------------

void __fastcall TInstructorForm::saveBTNClick(TObject *Sender)
{
    instructorList->Items->SaveToFile("Instructors\\Instructors.ins");
    //Close();
    ModalResult = mrOk;    
}
//---------------------------------------------------------------------------

void __fastcall TInstructorForm::FormShow(TObject *Sender)
{
    String filename = "Instructors\\Instructors.txt";

    bool yes = FileExists(filename);
    if(!yes)
    {
        Application->MessageBox("That Instructors file was not found, sorry!\nI have created a new blank one for you.", "File not found", MB_OK|MB_ICONERROR);
        //return false;
        instructorList->Items->SaveToFile(filename);
    }

    instructorList->Items->LoadFromFile(filename);
}
//---------------------------------------------------------------------------

void __fastcall TInstructorForm::PopupMenu1Popup(TObject *Sender)
{
    if(instructorList->ItemIndex == -1)
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

