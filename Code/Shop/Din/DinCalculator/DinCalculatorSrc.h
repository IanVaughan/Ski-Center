//---------------------------------------------------------------------------
#ifndef DinCalculatorSrcH
#define DinCalculatorSrcH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <Mask.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
#include "..\DinCalcDLL.h"

const String TEXT_SKITYPE1 = "Ski conservatively.\nPrefer slower speeds.\nSki on easy to moderate slopes.";
const String TEXT_SKITYPE2 = "Ski moderately.\nPrefer variety of speeds.\nSki on varied terrain, including most\ndifficult trails.";
const String TEXT_SKITYPE3 = "Ski aggressively.\nNormally at high speeds.\nPrefer moderate to steep terrain.";
//------------------------------------------------------------------------------

class TDinCalcForm : public TForm
{                                                      
__published:
    TGroupBox *PersonalDetialsGB;
    TLabel *WeightLabel;
    TLabel *HeightLabel;
    TComboBox *WeightUnitsCB;
    TComboBox *HeightUnitsCB;
    TEdit *WeightEdit;
    TEdit *HeightEdit;
    TLabel *DOBLabel;
    TGroupBox *TechInfoGB;
    TLabel *BootSoleLengthLabel;
    TEdit *BootSoleLengthEdit;
    TLabel *DINLabel;
    TEdit *DinEdit;
    TLabel *TorsionLabel;
    TLabel *ForwardFlexlabel;
    TEdit *TorsionEdit;
    TEdit *ForwardFlexEdit;
    TBitBtn *CloseBTN;
    TMaskEdit *DOBEdit;
    TBitBtn *PrintBTN;
    TBitBtn *ViewBTN;
    TEdit *WeightKGEdit;
    TEdit *HeightCMEdit;
    TGroupBox *SkiierTypeGB;
    TComboBox *SkiierTypeCB;
    TLabel *TypeLabel;
    TLabel *SkiierTypeDescriptionLabel;
    TBitBtn *CalcDinBTN;
    TLabel *Label4;
    TStringGrid *VisualDinChart;
    TEdit *AgeEdit;
    TStringGrid *DinHistorySG;
    TSpeedButton *HelpAboutBTN;
    TBitBtn *BitBtn1;
    void __fastcall CloseBTNClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall CalcDinBTNClick(TObject *Sender);
    void __fastcall FormDestroy(TObject *Sender);
    void __fastcall SkiierTypeCBChange(TObject *Sender);
    void __fastcall HelpAboutBTNClick(TObject *Sender);
    
private:
    int PopAgeCorrectly();
    int PopWeightCorrectly();
    int PopHeightCorrectly();
    int PopTypeCorrectly();
    int PopBSLCorrectly();

    int CalcAge(int iDay, int iMonth, int iYear);
    bool ValidDOB(int &iDay, int &iMonth, int &iYear);
    int ValidAge(String kAge);

    void PopDinChart();

    void CopyDINDetialstoChart(SkiierStatsData sd, SkiierDIN tDIN);

    int m_iDemoCounter;

public:
    __fastcall TDinCalcForm(TComponent* Owner);
    
};
//---------------------------------------------------------------------------
extern PACKAGE TDinCalcForm *DinCalcForm;
//---------------------------------------------------------------------------
#endif
