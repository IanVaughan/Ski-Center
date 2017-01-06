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

class BookingSheetUtils;


class TLessonBookingSheet : public TForm
{
__published:	// IDE-managed Components
    TMainMenu *MainMenu1;
    TMenuItem *File1;
    TMenuItem *Exit1;
    TStatusBar *StatusBar1;
    TPopupMenu *lessonPopup;
    TPopupMenu *instructorPopup;
    TMenuItem *SetInstructor;
    TMenuItem *ChangeInstructor;
    TMenuItem *ClearInstrcutor;
    TMenuItem *CreateLesson;
    TMenuItem *EditLesson;
    TMenuItem *RemoveLesson;
    TTabControl *weekSelector;
    TMenuItem *Help1;
    TMenuItem *AboutMI;
    TMenuItem *Bookings1;
    TMenuItem *LessonBookingWizard1;
    TMenuItem *N2;
    TMenuItem *NormalLessonBooking1;
    TMenuItem *PartyBookings1;
    TPopupMenu *columnPU;
    TMenuItem *AddTimeSlot1;
    TMenuItem *EditTimeSlot1;
    TMenuItem *RemoveTimeSlot1;
    TToolBar *ToolBar;
    TTimer *Timer1;
    TFindDialog *FindDialog1;
    TMenuItem *N1;
    TMenuItem *N11;
    TToolButton *normalLessonBookingBTN;
    TImageList *ToolBarImageList;
    TToolButton *holdLessonBTN;
    TScrollBar *weekChangerSB;
    TMenuItem *N3;
    TMenuItem *AddnewRow;
    TMenuItem *RemoveRow1;
    TSpeedButton *SpeedButton1;
    TSpeedButton *GotoSBTN;
    TToolButton *ToolButton1;
    TStringGrid *LessonSG;
    void __fastcall FormResize(TObject *Sender);
    void __fastcall SetInstructorClick(TObject *Sender);
    void __fastcall ChangeInstructorClick(TObject *Sender);
    void __fastcall ClearInstrcutorClick(TObject *Sender);
    void __fastcall CreateLessonClick(TObject *Sender);
    void __fastcall LessonBookingWizard1Click(TObject *Sender);
    void __fastcall NormalLessonBooking1Click(TObject *Sender);
    void __fastcall Exit1Click(TObject *Sender);
    void __fastcall weekSelectorChange(TObject *Sender);
    void __fastcall bookingWizardBTNClick(TObject *Sender);
    void __fastcall AboutMIClick(TObject *Sender);
    void __fastcall FormDestroy(TObject *Sender);
    void __fastcall LessonXSGMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y);
    void __fastcall LessonXSGDblClick(TObject *Sender);
    void __fastcall LessonXSGClick(TObject *Sender);
    void __fastcall LessonXSGMouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
    void __fastcall LessonXSGDrawCell(TObject *Sender, int Col, int Row, TRect &Rect, TGridDrawState State);
    void __fastcall normalLessonBookingBTNClick(TObject *Sender);
    void __fastcall weekChangerSBChange(TObject *Sender);
    void __fastcall lessonPopupPopup(TObject *Sender);
    void __fastcall instructorPopupPopup(TObject *Sender);

    void __fastcall AddnewRowClick(TObject *Sender);
    void __fastcall RemoveRow1Click(TObject *Sender);
    
    void __fastcall ToolButton1Click(TObject *Sender);
    
    void __fastcall GotoSBTNClick(TObject *Sender);
private:
//    bool RowEven(int rowNum);

    bool SaveAll();

    int m_iCurrentRow;

    //bool LoadDow(BookingSheetUtils::DayOfWeek);

    BookingSheetUtils *m_pkBookingSheetUtils;

    void __fastcall WMGetMinMaxInfo(TWMGetMinMaxInfo &Msg);

public:
    __fastcall TLessonBookingSheet(TComponent* Owner);

 //for min/max resizing of form, only allows a defined min/max in WMGetMinMAxInfo method
    BEGIN_MESSAGE_MAP
        MESSAGE_HANDLER(WM_GETMINMAXINFO, TWMGetMinMaxInfo, WMGetMinMaxInfo)
    END_MESSAGE_MAP(TForm)
};
//---------------------------------------------------------------------------
extern PACKAGE TLessonBookingSheet *LessonBookingSheet;
//---------------------------------------------------------------------------
#endif
