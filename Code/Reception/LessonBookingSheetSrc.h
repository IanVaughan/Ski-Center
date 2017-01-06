//---------------------------------------------------------------------------
#ifndef LessonBookingSheetSrcH
#define LessonBookingSheetSrcH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <Menus.hpp>
#include <ComCtrls.hpp>
#include <Tabs.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <ToolWin.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------

#include "MVC_Model.h"

class BookingSheetUtils;
class MVCControler;

class TLessonBookingSheet : public TForm
{
__published:	
    TMainMenu *MainMenu1;
    TMenuItem *FileMI;
    TMenuItem *ExitMI;
    TStatusBar *StatusBar1;
    TPopupMenu *LessonRowPU;
    TPopupMenu *InstructorRowPU;
    TMenuItem *SetInstructorPUMI;
    TMenuItem *ChangeInstructorPUMI;
    TMenuItem *ClearInstrcutorPUMI;
    TMenuItem *CreateLessonPUMI;
    TMenuItem *EditLessonPUMI;
    TMenuItem *RemoveLessonPUMI;
    TTabControl *weekSelector;
    TMenuItem *HelpMI;
    TMenuItem *AboutMI;
    TMenuItem *BookingsMI;
    TMenuItem *LessonBookingWizardMI;
    TMenuItem *N2;
    TMenuItem *NormalLessonBookingMI;
    TMenuItem *PartyBookingsMI;
    TPopupMenu *TimeRowPU;
    TMenuItem *AddTimeSlotPUMI;
    TMenuItem *EditTimeSlotPUMI;
    TMenuItem *RemoveTimeSlotPUMI;
    TToolBar *ToolBar;
    TTimer *Timer1;
    TFindDialog *FindDialog1;
    TMenuItem *N1;
    TMenuItem *N11;
    TToolButton *LessonBookingNormalBTN;
    TImageList *ToolBarImageList;
    TToolButton *LessonHoldBTN;
    TScrollBar *WeekChangerSB;
    TMenuItem *N3;
    TMenuItem *AddnewRowPUMI;
    TMenuItem *RemoveRowPUMI;
    TSpeedButton *GotoTodayBTN;
    TSpeedButton *GotoDateBTN;
    TToolButton *LessonBookingWizzardBTN;
    TStringGrid *LessonSG;
    void __fastcall FormResize(TObject *Sender);
    void __fastcall SetInstructorPUMIClick(TObject *Sender);
    void __fastcall ChangeInstructorPUMIClick(TObject *Sender);
    void __fastcall ClearInstrcutorPUMIClick(TObject *Sender);
    void __fastcall CreateLessonPUMIClick(TObject *Sender);
    void __fastcall LessonBookingWizardMIClick(TObject *Sender);
    void __fastcall NormalLessonBookingMIClick(TObject *Sender);
    void __fastcall ExitMIClick(TObject *Sender);
    void __fastcall weekSelectorChange(TObject *Sender);
    void __fastcall AboutMIClick(TObject *Sender);
    void __fastcall FormDestroy(TObject *Sender);
    void __fastcall LessonBookingNormalBTNClick(TObject *Sender);
    void __fastcall WeekChangerSBChange(TObject *Sender);
    void __fastcall LessonRowPUPopup(TObject *Sender);
    void __fastcall InstructorRowPUPopup(TObject *Sender);
    void __fastcall AddnewRowPUMIClick(TObject *Sender);
    void __fastcall RemoveRowPUMIClick(TObject *Sender);
    void __fastcall LessonBookingWizzardBTNClick(TObject *Sender);
    void __fastcall GotoDateBTNClick(TObject *Sender);
    void __fastcall LessonSGMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall AddTimeSlotPUMIClick(TObject *Sender);
    void __fastcall EditTimeSlotPUMIClick(TObject *Sender);
    void __fastcall RemoveTimeSlotPUMIClick(TObject *Sender);
    void __fastcall EditLessonPUMIClick(TObject *Sender);
    void __fastcall RemoveLessonPUMIClick(TObject *Sender);
    void __fastcall LessonHoldBTNClick(TObject *Sender);
    void __fastcall GotoTodayBTNClick(TObject *Sender);
    void __fastcall LessonSGClick(TObject *Sender);
    void __fastcall LessonSGDblClick(TObject *Sender);
    void __fastcall LessonSGDrawCell(TObject *Sender, int Col, int Row,
          TRect &Rect, TGridDrawState State);
    void __fastcall LessonSGMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
    
    void __fastcall FormShow(TObject *Sender);

private:
    int m_iCurrentRow;

    BookingSheetUtils *m_pkBookingSheetUtils;

    void __fastcall WMGetMinMaxInfo(TWMGetMinMaxInfo &Msg);

    MVCControler *m_pkControler;

    DaySheet *m_pkCurrentDaySheet;

public:
    __fastcall TLessonBookingSheet(TComponent* Owner);

    void SetControler(MVCControler *pkControler) {m_pkControler = pkControler;};
    void SetDate(TDate);

    //for min/max resizing of form, only allows a defined min/max in WMGetMinMAxInfo method
    BEGIN_MESSAGE_MAP
        MESSAGE_HANDLER(WM_GETMINMAXINFO, TWMGetMinMaxInfo, WMGetMinMaxInfo)
    END_MESSAGE_MAP(TForm)
};
//---------------------------------------------------------------------------
extern PACKAGE TLessonBookingSheet *LessonBookingSheet;
//---------------------------------------------------------------------------
#endif
