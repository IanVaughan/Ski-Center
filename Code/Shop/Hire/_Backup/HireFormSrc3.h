//---------------------------------------------------------------------------
#ifndef HireFormSrc3H
#define HireFormSrc3H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
#include <checklst.hpp>
//---------------------------------------------------------------------------

class THireForm : public TForm
{
__published:
    TPanel *SaveCancelPanel;
    TBitBtn *SearchBTN;
    TBitBtn *SaveNextBTN;
    TBitBtn *SaveCloseBTN;
    TBitBtn *CancelBTN;
    TScrollBox *ScrollBox1;
    TPanel *CustInfoNamePanel;
    TSpeedButton *SpeedButton1;
    TPanel *CI_CustInfoDetailsPanel;
    TSpeedButton *CI_NameLastBTN;
    TLabel *CI_SalutationLabel;
    TLabel *CI_NameFirstLabel;
    TEdit *CI_NameFirstEdit;
    TEdit *CI_NameLastEdit;
    TComboBox *CI_SalutationCB;
    TGroupBox *CI_TelephoneGB;
    TLabel *CI_TelWorkLabel;
    TLabel *CI_TelHomeLabel;
    TLabel *CI_TelMobelLabel;
    TEdit *CI_TelWorkEdit;
    TEdit *CI_TelHomeEdit;
    TEdit *CI_TelMobileEdit;
    TGroupBox *CI_CustPersonalDetials;
    TLabel *CI_DOBLabel;
    TLabel *CI_WeightLabel;
    TLabel *CI_HeightLabel;
    TLabel *CI_AbilityLabel;
    TEdit *CI_DOBEdit;
    TComboBox *CI_WeightCB;
    TComboBox *CI_HeightCB;
    TComboBox *CI_AbilityCB;
    TGroupBox *CI_AddressGB;
    TLabel *Label2;
    TLabel *Label3;
    TLabel *Label4;
    TLabel *CI_TownLabel;
    TLabel *Label6;
    TSpeedButton *SpeedButton2;
    TEdit *CI_AddressHouseNameEdit;
    TEdit *CI_AddressHouseNumberEdit;
    TEdit *CI_AddressStreetEdit;
    TEdit *CI_AddressTownEdit;
    TEdit *CI_AddressCountyEdit;
    TEdit *CI_AddressPostcodeEdit;
    TPanel *SkiHireNamePanel;
    TCheckBox *SkiHireTB;
    TPanel *SkiHireDetialsPanel;
    TLabel *SH_MakeLabel;
    TLabel *SH_LengthLabel;
    TLabel *SH_ModelLabel;
    TLabel *Label7;
    TLabel *Label1;
    TComboBox *SH_MakeCB;
    TComboBox *SH_LengthCB;
    TRadioButton *SH_MustHaveSkisRB;
    TRadioButton *SH_MustHaveLengthRB;
    TComboBox *SH_ModelCB;
    TPanel *OwnBootsNamePanel;
    TLabel *SHOB_BootsLocationLabel;
    TCheckBox *SH_OwnBootsTB;
    TComboBox *SHOB_BootLocation;
    TPanel *OwnBootsDetialsPanel;
    TLabel *SHOB_MakeLabel;
    TLabel *SHOB_ModelLabel;
    TLabel *SHOB_SizeLabel;
    TComboBox *SHOB_MakeCB;
    TComboBox *SHOB_ModelCB;
    TComboBox *SHOB_SizeCB;
    TEdit *Edit1;
    TCheckBox *SH_AddNotesTB;
    TPanel *BootHireNamePanel;
    TCheckBox *BootHireTB;
    TPanel *BootHireDetialsPanel;
    TLabel *BH_MakeLabel;
    TLabel *BH_ModelLabel;
    TLabel *BH_SizeLabel;
    TComboBox *BH_MakeCB;
    TComboBox *BH_ModelCB;
    TComboBox *BH_SizeCB;
    TCheckBox *BH_AddNotesTB;
    TPanel *BoardHireNamePanel;
    TCheckBox *BoardHireTB;
    TPanel *BoardHireDetialsPanel;
    TLabel *SBH_MakeLabel;
    TLabel *Label24;
    TLabel *SBH_ModelLabel;
    TRadioButton *SBH_StanceRegular;
    TRadioButton *SBH_StanceGoffie;
    TComboBox *SBH_MakeCB;
    TComboBox *SBH_LengthCB;
    TComboBox *SBH_ModelCB;
    TPanel *BoardBootsHireNamePanel;
    TCheckBox *BoardBootHireTB;
    TPanel *BoardBootsHireDetialsPanel;
    TLabel *BBH_MakeLabel;
    TLabel *BBH_ModelLabel;
    TLabel *BBH_SizeLabel;
    TComboBox *BBH_MakeCB;
    TComboBox *BBH_ModelCB;
    TComboBox *BBH_SizeCB;
    TPanel *BladeHireDetialsPanel;
    TLabel *BLH_NotLabel;
    TPanel *BladeHireNamePanel;
    TCheckBox *BlaneHireTB;
    void __fastcall FormShow(TObject *Sender);
    void __fastcall AnyHireCBClick(TObject *Sender);
    void __fastcall CancelBTNClick(TObject *Sender);
    void __fastcall SaveCloseBTNClick(TObject *Sender);
    void __fastcall SaveNextBTNClick(TObject *Sender);
    void __fastcall SearchBTNClick(TObject *Sender);
    void __fastcall CI_NameLastBTNClick(TObject *Sender);
    void __fastcall CI_AddressPostcodeBTNClick(TObject *Sender);
    void __fastcall CI_NameLastEditChange(TObject *Sender);
    void __fastcall CI_SalutationCBChange(TObject *Sender);
    void __fastcall SpeedButton1Click(TObject *Sender);
    void __fastcall SH_AddNotesTBClick(TObject *Sender);
    void __fastcall BH_AddNotesTBClick(TObject *Sender);

private:
    void AnimateBox(TPanel *pkPanel, int iTo);
    bool ValidateCustomerDetails();

public:
    __fastcall THireForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE THireForm *HireForm;
//---------------------------------------------------------------------------
#endif
