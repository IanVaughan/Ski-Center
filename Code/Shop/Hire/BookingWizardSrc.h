//---------------------------------------------------------------------------
#ifndef BookingWizardSrcH
#define BookingWizardSrcH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Tabs.hpp>
//---------------------------------------------------------------------------
class TBookingWizard : public TForm
{
__published:	// IDE-managed Components
    TButton *NextBTN;
    TButton *PrevBTN;
    TButton *CancelBTN;
    TButton *HelpBTN;
    TTabSet *TabSet1;
    TNotebook *Notebook1;
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
    TButton *SaveBTN;
private:	// User declarations
public:		// User declarations
    __fastcall TBookingWizard(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TBookingWizard *BookingWizard;
//---------------------------------------------------------------------------
#endif
