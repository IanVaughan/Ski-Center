//---------------------------------------------------------------------------
#ifndef HireFormSrc2H
#define HireFormSrc2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TGroupBox *CI_CustPersonalDetials;
    TLabel *CI_DOBLabel;
    TLabel *CI_WeightLabel;
    TLabel *CI_HeightLabel;
    TLabel *CI_AbilityLabel;
    TEdit *CI_DOBEdit;
    TComboBox *CI_WeightCB;
    TComboBox *CI_HeightCB;
    TComboBox *CI_AbilityCB;
    TGroupBox *CI_TelephoneGB;
    TLabel *CI_TelWorkLabel;
    TLabel *CI_TelHomeLabel;
    TLabel *CI_TelMobelLabel;
    TEdit *CI_TelWorkEdit;
    TEdit *CI_TelHomeEdit;
    TEdit *CI_TelMobileEdit;
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
    TGroupBox *GroupBox1;
    TSpeedButton *CI_NameLastBTN;
    TLabel *CI_SalutationLabel;
    TLabel *CI_NameFirstLabel;
    TEdit *CI_NameFirstEdit;
    TEdit *CI_NameLastEdit;
    TComboBox *CI_SalutationCB;
private:	// User declarations
public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
