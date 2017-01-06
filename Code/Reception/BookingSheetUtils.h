//---------------------------------------------------------------------------
#ifndef bookingSheetUtilsH
#define bookingSheetUtilsH

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
const int MAX_COL = 10;
const int MAX_ROW = 10;


//------------------------------------------------------------------------------

class BookingSheetUtils
{
private:
    TStringGrid *m_pkLessonSG;

public:
    BookingSheetUtils(TStringGrid *pointer);
    ~BookingSheetUtils();

    bool RowEven(int rowNum);

    bool LessonBooked(int col = -1, int row = -1);
    bool InstructorBooked(int col = -1, int row = -1);

    bool SetRowHeights();

    typedef enum {dowMonday, dowTuesday, dowWednesday, dowThursday, dowFriday, dowSaturday, dowSunday} DayOfWeek;
    String GetStringDOW(DayOfWeek dow);
    DayOfWeek GetDOW(String dow);

    //    LessonIndex GetCellInfo(int iCol, int iRow);
    void SetCellColor(int iCol, int iRow, TColor kColor);
    TColor GetCellColor(int iCol, int iRow);

    void SetCellText(int iCol, int iRow, String kText);
    String GetCellText(int iCol, int iRow);
};
//---------------------------------------------------------------------------
#endif
