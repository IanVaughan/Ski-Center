//---------------------------------------------------------------------------
#ifndef lessonBookingSrcH
#define lessonBookingSrcH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include <Grids.hpp>
#include "XStringGrid.hpp"
//---------------------------------------------------------------------------
class TlessonBookingForm : public TForm
{
__published:	// IDE-managed Components
    TBevel *Bevel2;
    TBitBtn *saveBTN;
    TBitBtn *cancelBTN;
    TNotebook *lessonWizardNB;
    TLabel *Label4;
    TLabel *Adults;
    TLabel *Label5;
    TBitBtn *lastBTN;
    TBitBtn *nextBTN;
    TLabel *Label6;
    TMemo *Memo1;
    TBitBtn *printBTN;
    TLabel *Label7;
    TUpDown *UpDown1;
    TUpDown *UpDown2;
    TBevel *Bevel3;
    TBitBtn *confirmBTN;
    TComboBox *peopleAdult;
    TComboBox *peopleChild;
    TLabel *Label15;
    TLabel *Label16;
    TLabel *Label17;
    TLabel *Label18;
    TLabel *Label19;
    TLabel *Label20;
    TScrollBar *ScrollBar1;
    TPanel *lessonPanel;
    TPanel *pickLI;
    TPanel *pickMB;
    TPanel *pickMT;
    TLabel *Label1;
    TLabel *Label2;
    TLabel *Label3;
    TLabel *Label13;
    TLabel *Label12;
    TLabel *Label14;
    TLabel *Label9;
    TLabel *Label10;
    TBevel *Bevel1;
    TBevel *Bevel5;
    TPanel *topPanel;
    TBevel *Bevel4;
    TPanel *pickPrivate;
    TLabel *Label8;
    TPanel *pickSki;
    TPanel *pickBoard;
    TPanel *pickBlade;
    TBevel *Bevel6;
    TBevel *Bevel7;
    TLabel *Label11;
    TPanel *pickUI;
    TBevel *Bevel8;
    TPanel *pickEP;
    TBevel *Bevel9;
    TXStringGrid *customersOnLessonGrid;
    TComboCellEditor *ComboCellEditor1;
    TDateTimePicker *DateTimePicker1;
    TDateTimePicker *DateTimePicker2;
    TDateTimePicker *DateTimePicker3;
    TDateTimePicker *DateTimePicker4;
    TDateTimePicker *DateTimePicker5;
    TDateTimePicker *DateTimePicker6;
    TDateTimePicker *DateTimePicker7;
    TDateTimePicker *DateTimePicker8;
    TLabel *Label23;
    TLabel *Label24;
    TLabel *Label25;
    TLabel *Label26;
    TLabel *Label27;
    TLabel *Label28;
    TComboBox *ComboBox1;
    TLabel *Label29;
    TBevel *Bevel10;
    TDateTimePicker *DateTimePicker9;
    TDateTimePicker *DateTimePicker10;
    TDateTimePicker *DateTimePicker11;
    TDateTimePicker *DateTimePicker12;
    TBitBtn *BitBtn1;
    TBitBtn *addNotes;
    void __fastcall pickMTClick(TObject *Sender);
    void __fastcall lastBTNClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall nextBTNClick(TObject *Sender);
    void __fastcall confirmBTNClick(TObject *Sender);
    void __fastcall cancelBTNClick(TObject *Sender);
    void __fastcall saveBTNClick(TObject *Sender);
    void __fastcall ScrollBar1Change(TObject *Sender);
    
    
private:

    typedef enum {atSki, atBoard, atBlade, atNone} ActivityType;
    typedef enum {sltMT, sltMB, sltLI, sltUI, sltEP, sltPrivate, sltNone} SkiLessonType;
//    typedef enum {bltSBT, bltSBC, bltSBCLI, bltPrivate, bltNone} BoardLessonType;
//    typedef enum {sbltPrivate, sbltNone} BladeLessonType;

    ActivityType ActivtySet;
    SkiLessonType SkiLessonSet;
//    BoardLessonType BoardLessonSet;
//    BladeLessonType BladeLessonSet;

public:
    __fastcall TlessonBookingForm(TComponent* Owner);

};
//---------------------------------------------------------------------------
extern PACKAGE TlessonBookingForm *lessonBookingForm;
//---------------------------------------------------------------------------
#endif
