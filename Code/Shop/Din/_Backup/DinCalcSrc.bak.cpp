//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "DinCalcSrc.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TDINCalculator *DINCalculator;
//---------------------------------------------------------------------------
__fastcall TDINCalculator::TDINCalculator(TComponent* Owner) : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TDINCalculator::FormShow(TObject *Sender)
{
    ageEdit->Text = "";
    weightEdit->Text = "";
    heightEdit->Text = "";

    Type1->Checked = true;

    soleEdit->Text = "";

    dinEdit->Text = "";
}
//---------------------------------------------------------------------------

int TDINCalculator::GetAge()
{
    int returnValue = -1;
    int age = ageEdit->Text.ToIntDef(-1);

    if(age == -1)
    {
        Application->MessageBox("The Age Value is not a correct number.", "Age Value Incorect", MB_OK|MB_ICONINFORMATION);
        returnValue = -1;
    }
    else
    {
        if(age > 0 && age < 50) returnValue = 0;
        else if(age > 50 && age < 99) returnValue = 1;
        else returnValue = -1;
    }

    return returnValue;
}

int TDINCalculator::GetWeight()
{
    int returnValue = -1;
    int weight = weightEdit->Text.ToIntDef(-1);

    if(weight == -1)
    {
        Application->MessageBox("The Weight Value is not a correct number.", "Weight Value Incorect", MB_OK|MB_ICONINFORMATION);
        returnValue = -1;
    }
    else
    {
        if(weight >= 22 && weight < 30) returnValue = 0;
        else if(weight >= 30 && weight < 39) returnValue = 1;
        else if(weight >= 39 && weight < 48) returnValue = 2;
        else if(weight >= 48 && weight < 57) returnValue = 3;
        else if(weight >= 57 && weight < 67) returnValue = 4;
        else if(weight >= 67 && weight < 79) returnValue = 5;
        else if(weight >= 79 && weight < 92) returnValue = 6;
        else if(weight >= 92 && weight < 108) returnValue = 7;
        else if(weight >= 108 && weight < 126) returnValue = 8;
        else if(weight >= 126 && weight < 148) returnValue = 9;
        else if(weight >= 148 && weight < 175) returnValue = 10;
        else if(weight >= 175 && weight < 210) returnValue = 11;
        else if(weight >= 210) returnValue = 12;
        else returnValue = -1;
    }

    return returnValue;
}

int TDINCalculator::GetHeight()
{
    int returnValue = -1;
    int height = heightEdit->Text.ToIntDef(-1);

    if(height == -1)
    {
        Application->MessageBox("The Height Value is not a correct number.", "Height Value Incorect", MB_OK|MB_ICONINFORMATION);
        returnValue = -1;
    }
    else
    {
        if(height <= 148) returnValue = 0;
        else if(height >= 149 && height < 158) returnValue = 1;
        else if(height >= 158 && height < 167) returnValue = 2;
        else if(height >= 167 && height < 179) returnValue = 3;
        else if(height >= 179 && height < 195) returnValue = 4;
        else if(height >= 195) returnValue = 5;
        else returnValue = -1;
    }

    return returnValue;
}

int TDINCalculator::GetSoleLength()
{
    int returnValue = -1;
    int sole = soleEdit->Text.ToIntDef(-1);

    if(sole == -1)
    {
        Application->MessageBox("The Sole Length Value is not a correct number.", "Sole Length Value Incorect", MB_OK|MB_ICONINFORMATION);
        returnValue = -1;
    }
    else
    {
        if(sole <= 250) returnValue = 0;
        else if(sole > 250 && sole <= 270) returnValue = 1;
        else if(sole > 270 && sole <= 290) returnValue = 2;
        else if(sole > 290 && sole <= 310) returnValue = 3;
        else if(sole > 310 && sole <= 330) returnValue = 4;
        else if(sole > 330) returnValue = 5;
        else returnValue = -1;
    }

    return returnValue;
}

void __fastcall TDINCalculator::GoBTNClick(TObject *Sender)
{
    int age;
    int weight;
    int height;
    int sole;

    age = GetAge();
    if(age >= 0)
    {
        weight = GetWeight();

        if(weight >= 0)
        {
            height = GetHeight();

            if(height >= 0)
            {
                sole = GetSoleLength();
                if(sole >= 0)
                {
                }
                else
                    soleEdit->SetFocus();
            }
            else
                heightEdit->SetFocus();
        }
        else
            weightEdit->SetFocus();
    }
    else
        ageEdit->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TDINCalculator::ageEditExit(TObject *Sender)
{
    GetAge();
}
//---------------------------------------------------------------------------

void __fastcall TDINCalculator::weightEditExit(TObject *Sender)
{
    GetWeight();
}
//---------------------------------------------------------------------------

void __fastcall TDINCalculator::heightEditExit(TObject *Sender)
{
    GetHeight();    
}
//---------------------------------------------------------------------------

void __fastcall TDINCalculator::soleEditExit(TObject *Sender)
{
    GetSoleLength();    
}
//---------------------------------------------------------------------------

