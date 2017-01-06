//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "BookingSheetUtils.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

bool BookingSheetUtils::RowEven(int rowNum)
{
    switch(rowNum)
    {
        case 2 :
        case 4 :
        case 6 :
        case 8 :
        case 10 :
        case 12 :
        case 14 :
        case 16 :
        case 18 : return true;
        default : return false;
    }
}
//---------------------------------------------------------------------------

BookingSheetUtils::DayOfWeek BookingSheetUtils::GetDOW(String dow)
{
    DayOfWeek d;

    dow = dow.UpperCase();

    if(dow == "MONDAY") d = dowMonday;
    else if(dow == "TUESDAY") d = dowTuesday;
    else if(dow == "WEDNESDAY") d = dowWednesday;
    else if(dow == "THURSDAY") d = dowThursday;
    else if(dow == "FRIDAY") d = dowFriday;
    else if(dow == "SATURDAY") d = dowSaturday;
    else if(dow == "SUNDAY") d = dowSunday;

    return d;
}
// -----------------------------------------------------------------------------

String BookingSheetUtils::GetStringDOW(DayOfWeek dow)
{
    String name = "";
    switch(dow)
    {
        case dowMonday      : name = "Monday";      break;
        case dowTuesday     : name = "Tuesday";     break;
        case dowWednesday   : name = "Wednesday";   break;
        case dowThursday    : name = "Thursday";    break;
        case dowFriday      : name = "Friday";      break;
        case dowSaturday    : name = "Saturday";    break;
        case dowSunday      : name = "Sunday";      break;
    }
    return name;
}
// -----------------------------------------------------------------------------

bool BookingSheetUtils::InstructorBooked(int col, int row)
{
    if(col == -1) col = m_pkLessonSG->Col;
    if(row == -1) row = m_pkLessonSG->Row;

    if(!RowEven(row) && m_pkLessonSG->Cells[col][row] == "")
        return false;
    else
        return true;
}
//---------------------------------------------------------------------------

bool BookingSheetUtils::LessonBooked(int col, int row)
{
    if(col == -1) col = m_pkLessonSG->Col;
    if(row == -1) row = m_pkLessonSG->Row;

    if(RowEven(row) && m_pkLessonSG->Cells[col][row-1] == "")
        return true;
    else
        return false;
}
// -----------------------------------------------------------------------------

bool BookingSheetUtils::SetRowHeights()
{
    for(int i = 2; i <= m_pkLessonSG->RowCount; i++)
    {
        if(!RowEven(i))
            m_pkLessonSG->RowHeights[i-1] = 50;
    }



/*    switch(m_pkLessonXTG->RowCount)
    {
        case 11 : m_pkLessonXTG->RowHeights[10] = 50;
        case 9 : m_pkLessonXTG->RowHeights[8] = 50;
        case 7 : m_pkLessonXTG->RowHeights[6] = 50;
        case 5 : m_pkLessonXTG->RowHeights[4] = 50;
        case 3 : m_pkLessonXTG->RowHeights[2] = 50;
    }
*/
    return false;
}
//------------------------------------------------------------------------------

