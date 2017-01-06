//---------------------------------------------------------------------------
#ifndef bookingSheetSrcH
#define bookingSheetSrcH
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
#include "XStringGrid.hpp"
//---------------------------------------------------------------------------

class BookingSheetUtils;


class TbookingSheet : public TForm
{
__published:	// IDE-managed Components
    TMainMenu *MainMenu1;
    TMenuItem *File1;
    TMenuItem *Exit1;
    TStatusBar *StatusBar1;
    TPopupMenu *lessonPopup;
    TPopupMenu *instructorPopup;
    TMenuItem *SetInstructor1;
    TMenuItem *ChangeInstructor1;
    TMenuItem *ClearInstrcutor1;
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
    TToolBar *ToolBar1;
    TTimer *Timer1;
    TFindDialog *FindDialog1;
    TDateTimePicker *DateTimePicker1;
    TMenuItem *N1;
    TMenuItem *N11;
    TSpeedButton *bookingWizardBTN;
    TSpeedButton *SpeedButton2;
    TToolButton *ToolButton1;
    TToolButton *ToolButton2;
    TXStringGrid *LessonGrid;
    TToolButton *ToolButton3;
    TToolButton *ToolButton4;
    void __fastcall FormResize(TObject *Sender);
    void __fastcall LessonGridMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
    void __fastcall LessonGridDblClick(TObject *Sender);
    void __fastcall SetInstructor1Click(TObject *Sender);
    void __fastcall ChangeInstructor1Click(TObject *Sender);
    void __fastcall ClearInstrcutor1Click(TObject *Sender);
    void __fastcall lessonPopupPopup(TObject *Sender);
    void __fastcall CreateLessonClick(TObject *Sender);
    void __fastcall LessonGridClick(TObject *Sender);
    void __fastcall LessonBookingWizard1Click(TObject *Sender);
    void __fastcall NormalLessonBooking1Click(TObject *Sender);
    void __fastcall Exit1Click(TObject *Sender);
    void __fastcall weekSelectorChange(TObject *Sender);
    void __fastcall LessonGridMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
    void __fastcall lessonGrid1DrawCell(TObject *Sender, int Col, int Row,
          TRect &Rect, TGridDrawState State);
    void __fastcall bookingWizardBTNClick(TObject *Sender);
    void __fastcall lessonGridDrawCell(TObject *Sender, int Col, int Row,
          TRect &Rect, TGridDrawState State);
    void __fastcall AboutMIClick(TObject *Sender);

    void __fastcall FormDestroy(TObject *Sender);
private:
    bool RowEven(int rowNum);

    bool SaveAll();
    bool LoadAll();

    int m_iCurrentRow;

    //bool LoadDow(BookingSheetUtils::DayOfWeek);

    BookingSheetUtils *m_pkBookingSheetUtils;


public:
    __fastcall TbookingSheet(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TbookingSheet *bookingSheet;
//---------------------------------------------------------------------------
#endif
