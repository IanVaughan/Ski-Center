//---------------------------------------------------------------------------
#ifndef DinCalcSrcH
#define DinCalcSrcH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TDINCalculator : public TForm
{
__published:
    TEdit *ageEdit;
    TEdit *weightEdit;
    TEdit *heightEdit;
    TLabel *Label1;
    TLabel *Label2;
    TLabel *Label3;
    TEdit *soleEdit;
    TLabel *Label4;
    TLabel *Label5;
    TRadioButton *Type1;
    TRadioButton *Type2;
    TRadioButton *Type3;
    TUpDown *UpDown1;
    TUpDown *UpDown2;
    TUpDown *UpDown3;
    TUpDown *UpDown4;
    TBevel *Bevel1;
    TBevel *Bevel2;
    TBevel *Bevel3;
    TLabel *Label6;
    TLabel *Label7;
    TBitBtn *GoBTN;
    TBitBtn *CloseBTN;
    TEdit *dinEdit;
    TLabel *Label8;
    TBevel *Bevel4;
    void __fastcall FormShow(TObject *Sender);
    void __fastcall GoBTNClick(TObject *Sender);
    void __fastcall ageEditExit(TObject *Sender);
    void __fastcall weightEditExit(TObject *Sender);
    void __fastcall heightEditExit(TObject *Sender);
    void __fastcall soleEditExit(TObject *Sender);

private:
    int GetAge();
    int GetWeight();
    int GetHeight();
    int GetSoleLength();

public:
    __fastcall TDINCalculator(TComponent* Owner);

};
//---------------------------------------------------------------------------
extern PACKAGE TDINCalculator *DINCalculator;
//---------------------------------------------------------------------------
#endif
