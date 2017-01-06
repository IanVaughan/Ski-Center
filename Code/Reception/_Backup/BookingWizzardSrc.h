//---------------------------------------------------------------------------
#ifndef BookingWizzardSrcH
#define BookingWizzardSrcH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <Menus.hpp>
#include "ccalendr.h"

class TCellComboBox;
//---------------------------------------------------------------------------
class TBookingWizard : public TForm
{
__published:
    TBitBtn *SaveBTN;
    TBitBtn *CancelBTN;
    TBitBtn *LastBTN;
    TBitBtn *NextBTN;
    TNotebook *LessonWizardNB;
    TBevel *Bevel1;
    TLabel *Label1;
    TPanel *SkiPanel;
    TPanel *BoardPanel;
    TPanel *BladePanel;
    TPanel *Panel3;
    TLabel *Label2;
    TScrollBox *CourseTypePage_ScrollBox;
    TPanel *CourseTypePage_SkiLessonsPanel;
    TPanel *TasterPanel;
    TPanel *MBPanel;
    TPanel *LIPanel;
    TPanel *UIPanel;
    TPanel *Panel6;
    TLabel *Label3;
    TPanel *Panel7;
    TLabel *Label4;
    TGroupBox *PeopleCount;
    TLabel *Label5;
    TLabel *Label6;
    TComboBox *AdultCombo;
    TComboBox *ChildCombo;
    TPopupMenu *PopupMenu1;
    TLabel *Label8;
    TStringGrid *PeopleOnLessonSG;
    TLabel *HelpLabel;
    TCCalendar *CCalendar1;
    TPanel *Panel1;
    TLabel *Label9;
    TGroupBox *DateGB;
    TDateTimePicker *DateTimePicker1;
    TDateTimePicker *DateTimePicker2;
    TDateTimePicker *DateTimePicker3;
    TDateTimePicker *DateTimePicker4;
    TLabel *Label10;
    TLabel *Label11;
    TLabel *Label12;
    TLabel *Label13;
    TBitBtn *ConfirmBTN;
    TPanel *Panel2;
    TLabel *Label14;
    TMemo *Memo1;
    TBitBtn *PrintBTN;
    TBevel *Bevel2;
    TBevel *Bevel3;
    TLabel *Label15;
    TLabel *Label16;
    TImage *Image1;
    TImage *Image2;
    TImage *Image3;
    TDateTimePicker *DateTimePicker5;
    TDateTimePicker *DateTimePicker6;
    TDateTimePicker *DateTimePicker7;
    TDateTimePicker *DateTimePicker8;
    TPanel *CourseTypePage_BoardLessonsPanel;
    TPanel *Panel5;
    TPanel *Panel8;
    void __fastcall CancelBTNClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall SkiPanelClick(TObject *Sender);
    void __fastcall LastBTNClick(TObject *Sender);
    void __fastcall NextBTNClick(TObject *Sender);
    void __fastcall SaveBTNClick(TObject *Sender);
    void __fastcall TasterPanelClick(TObject *Sender);
    void __fastcall AdultComboChange(TObject *Sender);
    void __fastcall ChildComboChange(TObject *Sender);
    void __fastcall FormDestroy(TObject *Sender);
    void __fastcall PeopleOnLessonSGSelectCell(TObject *Sender, int Col,
          int Row, bool &CanSelect);
    void __fastcall ConfirmBTNClick(TObject *Sender);
private:

    TCellComboBox *m_pkCellCB;

typedef enum {atNone, atSki, atBoard, atBlade }ActivtySet;

    ActivtySet tActivty;

typedef enum {lsNone, lsTaster, lsMB, lsLI, lsUI} LessonSet;

    LessonSet tLesson;

    void ResetLessonTypePageChoices();
    void ResetCourseTypePageChoices();

    void PeopleCountPage_UpdatePeopleCountXTG();

    bool bPeopleCountPage_AddedPeople;

    void CourseTypePage_SetCourse();

public:
    __fastcall TBookingWizard(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TBookingWizard *BookingWizard;
//---------------------------------------------------------------------------
#endif
