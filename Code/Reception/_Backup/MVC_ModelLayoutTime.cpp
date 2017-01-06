//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "MVC_ModelLayoutTime.h"

#define REC_TIMESHEET_TIMES "ReceptionTimesheetTimes.txt"

//---------------------------------------------------------------------------
#pragma package(smart_init)


MVC_ModelLayoutTime::MVC_ModelLayoutTime()
{
    m_pkLessonTimes = new TList;
}
//------------------------------------------------------------------------------

MVC_ModelLayoutTime::~MVC_ModelLayoutTime()
{
    for(int i=0; i<m_pkLessonTimes->Count; i++)
    {
        delete m_pkLessonTimes->Items[i];
    }
    delete m_pkLessonTimes;
}
//------------------------------------------------------------------------------

bool MVC_ModelLayoutTime::LoadTimes()
{
    if(FileExists(REC_TIMESHEET_TIMES))
    {
        TStringList *pkTimesSL = new TStringList();
        pkTimesSL->LoadFromFile(REC_TIMESHEET_TIMES);

        String kTimesCount = pkTimesSL->Strings[0];
        int iTimesCount = kTimesCount.ToIntDef(-1);
        if(iTimesCount == -1)
        {
            //error
        }
        else
        {
            /*m_pkLessonSG->ColCount*/ int iColCount = iTimesCount;
            
            int i=1;
            while(i<iTimesCount+iTimesCount)
            {
                LessonTimesData *pkLessonTimes = new LessonTimesData;
                pkLessonTimes->kStartTime = pkTimesSL->Strings[i];//.ToIntDef(-1);
                pkLessonTimes->kEndTime = pkTimesSL->Strings[++i];//.ToIntDef(-1);
                pkLessonTimes->kBreak = 0;
                pkLessonTimes->Next = NULL;

                m_pkLessonTimes->Add(pkLessonTimes);
                i++;
            }
        }

        delete pkTimesSL;
    }

    return true;
}
//------------------------------------------------------------------------------
