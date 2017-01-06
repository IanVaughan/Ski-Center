//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "HireFormSrc.h"
#include "MVCControler.h"
#include "AdditionalNotes.h"
#include "HireSystemSrc.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
THireForm *HireForm;
//---------------------------------------------------------------------------

#define HEIGHT_CUSTDETAILS 200
#define HEIGHT_DATES 56
#define HEIGHT_SKIPANEL 105
#define HEIGHT_SKIOWNBOOTSPANEL 59
#define HEIGHT_BOOTSPANEL 56
#define HEIGHT_BOARDPANEL 56
#define HEIGHT_BOARDBOOTSPANEL 56
#define HEIGHT_BLADEPANEL 40

//------------------------------------------------------------------------------

__fastcall THireForm::THireForm(TComponent* Owner, MVCControler *Controler) : TForm(Owner)
{
    m_iAnimateBoxSpeed = 20;

    m_pkMVCControler = Controler;
}
//---------------------------------------------------------------------------

void __fastcall THireForm::FormShow(TObject *Sender)
{
    Height = 580;

    SkiHireTB->Checked = false;
    BootHireTB->Checked = false;
    BoardHireTB->Checked = false;
    BoardBootHireTB->Checked = false;

    int iH = HEIGHT_CUSTDETAILS;
    CI_CustInfoDetailsPanel->Height = iH;

    SkiBootsHireDetialsPanel->Height = 0;
    OwnBootsDetialsPanel->Height = 0;
    BootHireDetialsPanel->Height = 0;
    BoardHireDetialsPanel->Height = 0;
    BoardBootsHireDetialsPanel->Height = 0;
    BladeHireDetialsPanel->Height = 0;

    //Cust Detials
    CI_NameFirstEdit->Text = "";
    CI_NameLastEdit->Text = "";
    CI_AddressHouseNameEdit->Text = "";
    CI_AddressHouseNumberEdit->Text = "";
    CI_AddressStreetEdit->Text = "";
    CI_AddressTownEdit->Text = "";
    CI_AddressCountyEdit->Text = "";
    CI_AddressPostcodeEdit->Text = "";
    CI_TelWorkEdit->Text = "";
    CI_TelHomeEdit->Text = "";
    CI_TelMobileEdit->Text = "";
    CI_DOBEdit->Text = "";
    CI_HeightCB->Text = "";
    CI_WeightCB->Text = "";

    SH_MakeCB->Text = "";
    SH_LengthCB->Text = "";
    SH_ModelCB->Text = "";

    CI_SalutationCB->ItemIndex = 0;
    CI_AbilityCB->ItemIndex = 0;

    BladeHireDetialsPanel->Top = BladeHireNamePanel->Top + BladeHireNamePanel->Height;

    CI_NameFirstEdit->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall THireForm::AnyHireCBClick(TObject *Sender)
{
    TCheckBox *pkSelectedCB = (TCheckBox*)Sender;

    TPanel *pkSelectedPanel = NULL;
    int iHeight = 0;

    if(pkSelectedCB == SkiHireTB)
    {
        pkSelectedPanel = SkiBootsHireDetialsPanel;
        iHeight = HEIGHT_SKIPANEL;

        //untick boots as well
        if(SH_OwnBootsTB->Checked && !SkiHireTB->Checked)
        {
            SH_OwnBootsTB->Checked = !SH_OwnBootsTB->Checked;
        }
        else if(SH_OwnBootsTB->Checked)
        {
            iHeight += HEIGHT_SKIOWNBOOTSPANEL;
        }
    }
    else if(pkSelectedCB == SH_OwnBootsTB)
    {
        AnyHireCBClick(SkiHireTB);

        pkSelectedPanel = OwnBootsDetialsPanel;
        iHeight = HEIGHT_SKIOWNBOOTSPANEL;

        SHOB_BootLocationCB->Enabled = SH_OwnBootsTB->Checked;
        SHOB_BootLocationCB->ItemIndex = 0;
    }
    else if(pkSelectedCB == BootHireTB)
    {
        pkSelectedPanel = BootHireDetialsPanel;
        iHeight = HEIGHT_BOOTSPANEL;
    }
    else if(pkSelectedCB == BoardHireTB)
    {
        pkSelectedPanel = BoardHireDetialsPanel;
        iHeight = HEIGHT_BOARDPANEL;
    }
    else if(pkSelectedCB == BoardBootHireTB)
    {
        pkSelectedPanel = BoardBootsHireDetialsPanel;
        iHeight = HEIGHT_BOARDBOOTSPANEL;
    }
    else if(pkSelectedCB == BlaneHireTB)
    {
        pkSelectedPanel = BladeHireDetialsPanel;
        iHeight = HEIGHT_BLADEPANEL;
    }

    if(pkSelectedCB->Checked)
    {
        AnimateBox(pkSelectedPanel, iHeight);
    }
    else
    {
        AnimateBox(pkSelectedPanel, 0);
    }

    BladeHireDetialsPanel->Top = BladeHireNamePanel->Top + BladeHireNamePanel->Height;
}
//---------------------------------------------------------------------------

void THireForm::AnimateBox(TPanel *pkPanel, int iTo)
{
    int iAmount = 1;
    int iSpeed = 1;

    //fold down
    if(pkPanel->Height < iTo)
    {
        while(pkPanel->Height < iTo)
        {
            pkPanel->Height += iAmount;
            Application->ProcessMessages();

            iSpeed++;
            iAmount = iSpeed / m_iAnimateBoxSpeed;
        }
    }
    //fold up
    else if(pkPanel->Height > iTo)
    {
        while(pkPanel->Height > iTo)
        {
            pkPanel->Height -= iAmount;
            Application->ProcessMessages();

            iSpeed++;
            iAmount = iSpeed / m_iAnimateBoxSpeed;
        }
    }

    pkPanel->Height = iTo;
}
// -----------------------------------------------------------------------------

void __fastcall THireForm::CI_NameLastBTNClick(TObject *Sender)
{
    Application->MessageBox("The Search feature is not yet done. Sorry.",
                            "Search not implemented yet", MB_OK|MB_ICONINFORMATION);
}
//---------------------------------------------------------------------------

void __fastcall THireForm::CI_AddressPostcodeBTNClick(TObject *Sender)
{
    Application->MessageBox("If we buy a Postcode Database from Royal Mail, then we could get address just from people telling us there poscodes.",
                            "No Postcode database setup", MB_OK|MB_ICONINFORMATION);
}
//---------------------------------------------------------------------------

void __fastcall THireForm::CancelBTNClick(TObject *Sender)
{
    int iAns = 0;
    iAns = Application->MessageBox("You have entered/changed the Customer Information,\nwould you like to save the Customer Details for future reference."
                                  /* "The details entered will be stored on our DataBase and may be used for marketing perpouses, please intercate if you would not like\n"
                                   "your information to be used. (This all complys with the Data Protection Act 1964 Section C)."*/,
                                   "Save Customer Information", MB_YESNO|MB_ICONQUESTION);//|MB_HELP);

    if(iAns == ID_YES)
    {
        ValidateCustomerDetails();
    }
    else if(iAns == ID_HELP)
    {
        HelpBTNClick(this);
    }

    Close();
}
//---------------------------------------------------------------------------

void __fastcall THireForm::SaveCloseBTNClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------

void __fastcall THireForm::SaveNextBTNClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------

void __fastcall THireForm::SearchBTNClick(TObject *Sender)
{
    Application->MessageBox("Sorry but the Search is not avaible yet.","No Search Avaible", MB_OK|MB_ICONINFORMATION);
}
//---------------------------------------------------------------------------

void __fastcall THireForm::HelpBTNClick(TObject *Sender)
{
    Application->MessageBox("Sorry but there is no help avaible yet.","No Help Avaible", MB_OK|MB_ICONINFORMATION);
}
//---------------------------------------------------------------------------

void __fastcall THireForm::CI_NameLastEditChange(TObject *Sender)
{
    CustInfoNamePanel->Caption = "    Customer Information - "
                               + CI_SalutationCB->Text
                               + " "
                               + CI_NameLastEdit->Text;

}
//---------------------------------------------------------------------------

void __fastcall THireForm::CI_SalutationCBChange(TObject *Sender)
{
    CI_NameLastEditChange(this);                    
}
//---------------------------------------------------------------------------

void __fastcall THireForm::HideCustInfoTBClick(TObject *Sender)
{
    if(HideCustInfoTB->Checked)
    {
        AnimateBox(CI_CustInfoDetailsPanel, 0);
    }
    else
    {
        AnimateBox(CI_CustInfoDetailsPanel, HEIGHT_CUSTDETAILS);
    }
    BladeHireDetialsPanel->Top = BladeHireNamePanel->Top + BladeHireNamePanel->Height;
}
//---------------------------------------------------------------------------

void __fastcall THireForm::HideDatesTBClick(TObject *Sender)
{
    if(HideDatesTB->Checked)
    {
        AnimateBox(SkiDatesPanel, 0);
    }
    else
    {
        SkiDatesPanel->Top = CustInfoNamePanel->Height + CI_CustInfoDetailsPanel->Height + SkiDatesNamePanel->Height;//270;
        AnimateBox(SkiDatesPanel, HEIGHT_DATES);
    }
    BladeHireDetialsPanel->Top = BladeHireNamePanel->Top + BladeHireNamePanel->Height;
}
//---------------------------------------------------------------------------

void __fastcall THireForm::SH_AddNotesTBClick(TObject *Sender)
{
    AdditionalNotesForm->ShowModal();// == mrOk);
}
//---------------------------------------------------------------------------

void __fastcall THireForm::BH_AddNotesTBClick(TObject *Sender)
{
    AdditionalNotesForm->ShowModal();
}
//---------------------------------------------------------------------------

bool THireForm::ValidateCustomerDetails()
{
    CustomerDetials tCustDetials;

    tCustDetials.kTitle = CI_SalutationCB->Text;
    tCustDetials.kNameFirst = CI_NameFirstEdit->Text;
    tCustDetials.kNameLast = CI_NameLastEdit->Text;

    tCustDetials.kAddressName = CI_AddressHouseNameEdit->Text;
    tCustDetials.kAddressNumber = CI_AddressHouseNumberEdit->Text;
    tCustDetials.kAddressStreet = CI_AddressStreetEdit->Text;
    tCustDetials.kAddressTown = CI_AddressTownEdit->Text;
    tCustDetials.kAddressCounty = CI_AddressCountyEdit->Text;
    tCustDetials.kAddressPostcode = CI_AddressPostcodeEdit->Text;

    tCustDetials.kTelephoneDay = CI_TelWorkEdit->Text;
    tCustDetials.kTelephoneEve = CI_TelHomeEdit->Text;
    tCustDetials.kTelephoneMob = CI_TelMobileEdit->Text;

    tCustDetials.kDOB = CI_DOBEdit->Text;
    tCustDetials.kWeight = CI_WeightCB->Text;
    tCustDetials.kHeight = CI_HeightCB->Text;
    tCustDetials.kAbility = CI_AbilityCB->Text;

    HireSystem->GetMVCControler()->ValidateCustomerDetails(tCustDetials);

    return false;
}
// -----------------------------------------------------------------------------

//only allow min & max form sizes
void __fastcall THireForm::WMGetMinMaxInfo(TWMGetMinMaxInfo &Msg)
{
    Msg.MinMaxInfo->ptMinTrackSize.x=474; //ptMinTrackSize = min size allowed
    Msg.MinMaxInfo->ptMinTrackSize.y=431;//500; //by dragging with the mouse.

    Msg.MinMaxInfo->ptMaxTrackSize.x=474; //ptMaxTrackSize = max size allowed
    Msg.MinMaxInfo->ptMaxTrackSize.y=986; //by dragging with the mouse
}
//------------------------------------------------------------------------------

void __fastcall THireForm::SpeedButton2Click(TObject *Sender)
{
    Application->MessageBox("There is no Postcode Database to do an Address lookup.\n"
                            "If a Royal Mail Postcode DataBase was bought then the customer would only have to give there House Number and Postcode.\n"
                            "This message will removed for release.",
                            "No Postcode Database", MB_OK|MB_ICONINFORMATION);
}
//---------------------------------------------------------------------------

void __fastcall THireForm::SpeedButton1Click(TObject *Sender)
{
    //    
}
//---------------------------------------------------------------------------



void __fastcall THireForm::SH_MakeCBEnter(TObject *Sender)
{
    //Get SkiMake list
    SkiMakes skis = m_pkMVCControler->GetSkiMakeList();

    SkiMake ski = (skis)[0];

    SH_MakeCB->Items->Add(ski.kMake);
}
//---------------------------------------------------------------------------

void __fastcall THireForm::SH_LengthCBEnter(TObject *Sender)
{
    //Get SkiMake list
    SkiSizes sizes = m_pkMVCControler->GetSkiSizes();

    for(int i=0; i<sizes.size() ;i++)
    {
        SkiSize size = (sizes)[i];

        SH_LengthCB->Items->Add(size.kSize);
    }
}
//---------------------------------------------------------------------------

