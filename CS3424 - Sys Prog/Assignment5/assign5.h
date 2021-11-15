typedef struct {
    char course_Name[80];
    char course_Sched[4];
    unsigned course_Hours;
    unsigned course_Size;
    unsigned paddings;
} COURSE;

// create course record 
void CreateRecord(FILE*);

// read course record
void ReadRecord(FILE*);

// update course record
void UpdateRecord(FILE*);

// delete course record
void DeleteRecord(FILE*);

// helper function to check if record exists
bool DoesRecordExist(FILE*, int _num);