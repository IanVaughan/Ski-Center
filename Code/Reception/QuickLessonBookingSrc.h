//---------------------------------------------------------------------------
#ifndef quickLessonBookingSrcH
#define quickLessonBookingSrcH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
#include <Grids.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TQuickLessonBooking : public TForm
{
__published:	// IDE-managed Components
    TGroupBox *PeopleGB;
    TComboBox *custNumAdultCB;
    TLabel *Label3;
    TLabel *Label5;
    TComboBox *custNumChildCB;
    TGroupBox *LessonGB;
    TComboBox *lessonTypeCB;
    TLabel *Label1;
    TLabel *Label2;
    TComboBox *lessonFormCB;
    TBitBtn *SaveBTN;
    TBitBtn *CancelBTN;
    TBitBtn *HelpBTN;
    TBitBtn *WizardBTN;
    TGroupBox *GroupBox1;
    TLabel *Label4;
    TLabel *Label6;
    TLabel *Label7;
    TLabel *Label8;
    TStringGrid *custDetails;
    TLabel *Label9;
    TBevel *Bevel1;
    TDateTimePicker *DateTimePicker1;
    TDateTimePicker *DateTimePicker2;
    TDateTimePicker *DateTimePicker3;
    TDateTimePicker *DateTimePicker4;
    TGroupBox *GroupBox2;
    TLabel *Label10;
    TLabel *Label11;
    TLabel *Label12;
    TLabel *Label13;
    TDateTimePicker *DateTimePicker5;
    TDateTimePicker *DateTimePicker6;
    TDateTimePicker *DateTimePicker7;
    TDateTimePicker *DateTimePicker8;
    void __fastcall CancelBTNClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall custNumAdultCBChange(TObject *Sender);
    void __fastcall custNumChildCBChange(TObject *Sender);
    void __fastcall SaveBTNClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TQuickLessonBooking(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TQuickLessonBooking *QuickLessonBooking;
//---------------------------------------------------------------------------
#endif
