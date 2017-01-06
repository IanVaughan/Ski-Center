//---------------------------------------------------------------------------
#ifndef MVC_ModelH
#define MVC_ModelH
//---------------------------------------------------------------------------
#include "vector.h"

//togo into class MVC_ModelLessons 
typedef struct
{
    String kLessonType; //typedef as in lessonBookingForm
    int iPeopleBooked;
    char* Names[12][12];
}LessonBooked;


typedef struct
{
    String kInstructorName;
    LessonBooked tLesson;
}LessonCell;
typedef std::vector <LessonCell> LessonCellData;

typedef struct
{
//    int iNumOfBlocks;         <- dont want 2 deal with variable amount of blocks on differnt rows ! ahhh
    TTime BlockStartTime;
    TTime BlockEndTime;
    LessonCellData tLessonCellList;
}LessonRow;
typedef std::vector <LessonRow> LessonRowData;

typedef struct
{
    TDate kDate;
    int iNumOfRows;
    int iNumOfBlocks;
    LessonRowData tLessonRowList;
}DaySheet;

typedef std::vector<DaySheet> DaySheetAll;

class MVC_Model
{
    DaySheetAll *m_ptDaySheetAll;
    DaySheet *m_ptBlankSheet;

public:
    MVC_Model();
    ~MVC_Model();

    bool LoadData();
    bool SaveData();

    bool GetSheet(TDateTime kDateIn, DaySheet *&tDaySheetOut);

};
//------------------------------------------------------------------------------
#endif
