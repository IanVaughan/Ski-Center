//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "DinCalculatorSrc.h"
#include "HelpAboutSrc.h"

#include "DinCalcDLL.h"
#include "StatsConverterDLL.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TDinCalcForm *DinCalcForm;
//---------------------------------------------------------------------------

__fastcall TDinCalcForm::TDinCalcForm(TComponent* Owner) : TForm(Owner)
{
    StatsConverterDLL_StartUp();
    StartUpDIN_DLL();
}
//---------------------------------------------------------------------------

void __fastcall TDinCalcForm::FormDestroy(TObject *Sender)
{
    StatsConverterDLL_ShutDown();
    ShutDownDIN_DLL();
}
//---------------------------------------------------------------------------

void __fastcall TDinCalcForm::FormShow(TObject *Sender)
{
    WeightUnitsCB->ItemIndex = 0;
    HeightUnitsCB->ItemIndex = 0;
    SkiierTypeCB->ItemIndex = 0;
    SkiierTypeCBChange(this);

    DinHistorySG->Cells[0][0] = "Age";
    DinHistorySG->Cells[1][0] = "Weight";
    DinHistorySG->Cells[2][0] = "Height";
    DinHistorySG->Cells[3][0] = "Type";
    DinHistorySG->Cells[4][0] = "BSL";
    DinHistorySG->Cells[5][0] = "DIN";

    m_iDemoCounter = 0;
}
//---------------------------------------------------------------------------

void __fastcall TDinCalcForm::CloseBTNClick(TObject *Sender)
{
    if(Width > 500)
    {
        Width = 236;
        ViewBTN->Caption = "&View >>";
    }
    else
    {
        Width = 561;
        ViewBTN->Caption = "<< &View";
    }
}
//---------------------------------------------------------------------------

void __fastcall TDinCalcForm::CalcDinBTNClick(TObject *Sender)
{
    SkiierStatsData sd;

    sd.iAge = PopAgeCorrectly();
    if(sd.iAge > 0)
    {
        sd.iWeight = PopWeightCorrectly();

        if(sd.iWeight > 0)
        {
            WeightKGEdit->Text = String(PopWeightCorrectly()) + "kg";

            sd.iHeight = PopHeightCorrectly();

            if(sd.iHeight > 0)
            {
                HeightCMEdit->Text = String(PopHeightCorrectly()) + "cm";

                sd.iSkiierType = PopTypeCorrectly();

                if(sd.iSkiierType >= 0)
                {
                    sd.iBootSoleLength = PopBSLCorrectly();

                    if(sd.iBootSoleLength > 0)
                    {
                        SkiierDIN tDIN = GetDIN(sd);

                        if(tDIN.iDIN == -1)
                        {
                            Application->MessageBox("There was some invalid data entered.\nPlease check that the Age is correct,\nthe Weight and Height are in the correct units,\nand the BSL is in mm.", "Invalid Data", MB_OK|MB_ICONWARNING);
                            DinEdit->Text = "N/A";
                        }
                        else
                        {
                            DinEdit->Text = tDIN.iDIN;
                            //TorsionEdit->Text = tDIN.iTorsion;
                            //ForwardFlexEdit->Text = tDIN.iForwardFlex;

                            CopyDINDetialstoChart(sd, tDIN);

                            m_iDemoCounter++;
                            if(m_iDemoCounter == 10)
                            {
                                CalcDinBTN->Enabled = false;
                            }
                        }
                    }
                    else
                    {
                        Application->MessageBox("Please enter a valid Boot Sole Length Value.", "Invalid BSL", MB_OK|MB_ICONINFORMATION);
                        BootSoleLengthEdit->SetFocus();
                    }
                }
                else
                {
                }
            }
            else
            {
                Application->MessageBox("Please enter a valid Height Value.\nEnter feet and inchs as feet/inchs, e.g. five foot and three inchs = 5/3.", "Invalid Height", MB_OK|MB_ICONINFORMATION);
                HeightEdit->SetFocus();
            }
        }
        else
        {
            Application->MessageBox("Please enter a valid Weight Value.\nEnter stone and pounds as stone/pound, e.g. 10 and a half stone = 10/7, or 10.5.", "Invalid Weight", MB_OK|MB_ICONINFORMATION);
            WeightEdit->SetFocus();
        }
    }
}
//---------------------------------------------------------------------------

int TDinCalcForm::PopAgeCorrectly()
{
    int iAge = 0;

    if(AgeEdit->Text == "")
    {
        int iDay = 0;
        int iMonth = 0;
        int iYear = 0;

        if(ValidDOB(iDay, iMonth, iYear))
        {
            iYear += 1900;
            iAge = CalcAge(iDay, iMonth, iYear);

            AgeEdit->Text = iAge;
        }
        else
        {
            String kErrText = "";
            if(iDay == -1 && iMonth == -1 && iYear == -1)
            {
                kErrText = "Please enter a Date of Birth, or the Age of the Customer.";
            }
            else if(iDay == -1 || (iDay < 0 && iDay > 31))
            {
                kErrText = "The Day of the Month is not valid.";
            }
            else if(iMonth == -1 || (iMonth < 0 && iMonth > 12))
            {
                kErrText = "The Month of the Year is not valid.";
            }
            else if(iYear == -1 || (iYear < 0 && iYear > 2002))
            {
                kErrText = "The Year is not valid.";
            }

            Application->MessageBox(kErrText.c_str(), "Invalid Age Data", MB_OK|MB_ICONINFORMATION);
            DOBEdit->SetFocus();
        }
    }
    else
    {
        iAge = ValidAge(AgeEdit->Text);
    }

    return iAge;
}
//------------------------------------------------------------------------------

int TDinCalcForm::PopWeightCorrectly()
{
    String kInputWeight = WeightEdit->Text;
    WeightType tInputWeightType;

    if(kInputWeight != "")
    {
        if(WeightUnitsCB->ItemIndex == 0) tInputWeightType = wtSTONES;
        else if(WeightUnitsCB->ItemIndex == 1) tInputWeightType = wtPOUNDS;
        else if(WeightUnitsCB->ItemIndex == 2) tInputWeightType = wtKILOS;

        return ConvertWeight(kInputWeight, tInputWeightType, wtKILOS);
    }
    else
    {
        return -1;
    }
}
//------------------------------------------------------------------------------

int TDinCalcForm::PopHeightCorrectly()
{
    String kInputHeight = HeightEdit->Text;
    HeightType tInputHeightType;
    double dHeight = -1.0;

    if(kInputHeight != "")
    {
        if(HeightUnitsCB->ItemIndex == 0) tInputHeightType = htFEET;
        else if(HeightUnitsCB->ItemIndex == 1) tInputHeightType = htINCHES;
        else if(HeightUnitsCB->ItemIndex == 2) tInputHeightType = htCMS;

        dHeight = ConvertHeight(kInputHeight, tInputHeightType, htCMS);
    }

    return dHeight;
}
//------------------------------------------------------------------------------

int TDinCalcForm::PopTypeCorrectly()
{
    return SkiierTypeCB->ItemIndex +1;
}
//------------------------------------------------------------------------------

int TDinCalcForm::PopBSLCorrectly()
{
    int iBSL = BootSoleLengthEdit->Text.ToIntDef(-1);

    if(iBSL == -1)
    {
        return -1;
    }
    else
    {
        return iBSL;
    }
}
//------------------------------------------------------------------------------

void __fastcall TDinCalcForm::SkiierTypeCBChange(TObject *Sender)
{
    if(SkiierTypeCB->ItemIndex == 0) SkiierTypeDescriptionLabel->Caption = TEXT_SKITYPE1;
    else if(SkiierTypeCB->ItemIndex == 1) SkiierTypeDescriptionLabel->Caption = TEXT_SKITYPE2;
    else if(SkiierTypeCB->ItemIndex == 2) SkiierTypeDescriptionLabel->Caption = TEXT_SKITYPE3;
}
//---------------------------------------------------------------------------

int TDinCalcForm::CalcAge(int iDay, int iMonth, int iYear)
{
    TDateTime kCurrentDate;
    kCurrentDate = kCurrentDate.CurrentDate();
    unsigned short *year = new unsigned short;
    unsigned short *month = new unsigned short;
    unsigned short *day = new unsigned short;
    kCurrentDate.DecodeDate(year, month, day);

    int iAge = *year - iYear;

    //if its the persons birthday month,
    if(iMonth == *month)
    {
        // then check that there birthDAY hasnt past
        if(iDay > *day)
        {
            iAge++;
        }
    }
    // if its past the persons birthday month, then they are a year older than the year
    else if(*month > iMonth)
    {
        iAge++;
    }

    delete year;
    delete month;
    delete day;

    return iAge;
}
//------------------------------------------------------------------------------

bool TDinCalcForm::ValidDOB(int &iDay, int &iMonth, int &iYear)
{
    String kDOB = DOBEdit->Text;
    iDay = kDOB.SubString(0, kDOB.Pos("/")-1).ToIntDef(-1);
    kDOB = kDOB.Delete(1, kDOB.Pos("/"));
    iMonth = kDOB.SubString(0, kDOB.Pos("/")-1).ToIntDef(-1);
    kDOB = kDOB.Delete(1, kDOB.Pos("/"));
    iYear = kDOB.ToIntDef(-1);

    bool bError = false;

    if(iDay == -1 || iDay < 1 || iDay > 31)
    {
        bError = true;
        iDay = -1;
    }
    else if(iMonth == -1 || iMonth < 1 || iMonth > 12)
    {
        bError = true;
        iMonth = -1;
    }
    else if(iYear == -1 || iYear < 1 || iYear > 2002)
    {
        bError = true;
        iYear = -1;
    }

    return !bError;
}
//------------------------------------------------------------------------------

int TDinCalcForm::ValidAge(String kAge)
{
    int age = kAge.ToIntDef(-1);

    return age;
}
//------------------------------------------------------------------------------

void TDinCalcForm::PopDinChart()
{
    VisualDinChart->Cells[1][1] = "Weight LBS";
}
//------------------------------------------------------------------------------

void __fastcall TDinCalcForm::HelpAboutBTNClick(TObject *Sender)
{
    HelpAbout->ShowModal();
    
    CalcDinBTN->Enabled = true;
    m_iDemoCounter = 0;
}
//---------------------------------------------------------------------------

void TDinCalcForm::CopyDINDetialstoChart(SkiierStatsData sd, SkiierDIN tDIN)
{
    int iRow = DinHistorySG->RowCount -1;

    DinHistorySG->Cells[0][iRow] = sd.iAge;
    DinHistorySG->Cells[1][iRow] = sd.iWeight;
    DinHistorySG->Cells[2][iRow] = sd.iHeight;
    DinHistorySG->Cells[3][iRow] = sd.iSkiierType;
    DinHistorySG->Cells[4][iRow] = sd.iBootSoleLength;
    DinHistorySG->Cells[5][iRow] = tDIN.iDIN;

    DinHistorySG->RowCount++;
}
//------------------------------------------------------------------------------

