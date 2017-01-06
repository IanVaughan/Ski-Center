//---------------------------------------------------------------------------
#ifndef MVC_ModelLayoutTimeH
#define MVC_ModelLayoutTimeH
//---------------------------------------------------------------------------

#include <vector>

class MVC_ModelLayoutTime
{

public:
    typedef struct _LessonTimes
    {
        String kStartTime;
        String kEndTime;
        bool bBookableTime;
    }LessonTimesData;

//    std::vector <LessonTimesData> SingleRowLessonTimes;
    typedef std::vector <LessonTimesData> SingleRowLessonTimes;

private:
    SingleRowLessonTimes *m_tSingleRowLessonTimes;

public:
    MVC_ModelLayoutTime();
    ~MVC_ModelLayoutTime();

    bool LoadTimes();
    SingleRowLessonTimes *GetTimes() {return m_tSingleRowLessonTimes;};

};
//------------------------------------------------------------------------------
#endif
 