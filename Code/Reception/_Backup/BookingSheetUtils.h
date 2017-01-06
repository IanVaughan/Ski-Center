//---------------------------------------------------------------------------
#ifndef bookingSheetUtilsH
#define bookingSheetUtilsH
//---------------------------------------------------------------------------
class BookingSheetUtils
{
private:
    TStringGrid *m_pkLessonSG;

protected:

public:
  __fastcall BookingSheetUtils(TStringGrid *pointer) {m_pkLessonSG = pointer;};
  __fastcall ~BookingSheetUtils() {};

    bool RowEven(int rowNum);

    bool LessonBooked(int col = -1, int row = -1);
    bool InstructorBooked(int col = -1, int row = -1);

    bool SetRowHeights();

    typedef enum {dowMonday, dowTuesday, dowWednesday, dowThursday, dowFriday, dowSaturday, dowSunday} DayOfWeek;
    String GetStringDOW(DayOfWeek dow);
    DayOfWeek GetDOW(String dow);
 
};
//---------------------------------------------------------------------------
#endif
