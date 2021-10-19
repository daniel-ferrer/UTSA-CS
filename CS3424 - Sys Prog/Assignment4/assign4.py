import sys, os

def main():

    # store cmd line args
    _dir = str(sys.argv[1])
    _template = str(sys.argv[2])
    _date = str(sys.argv[3])
    _outPath = str(sys.argv[4])

    # set optional args if provided
    if len(sys.argv) > 5:
        tag_start = str(sys.argv[5])
        tag_end = str(sys.argv[6])
    else:
        tag_start = "[["
        tag_end = "]]"

    # strip apostrophes (homework example input had apostrophes)
    tag_start = tag_start.replace("'", "")
    tag_end = tag_end.replace("'", "")

    # loop through dir
    for file in os.listdir(_dir):
        data = extract_data(_dir, file)
        fill_template(data, _template, _date, _outPath, file, tag_start, tag_end)
        
def extract_data(_dir, file):
    # create list to store .crs data
    data = []

    # open .crs file
    f = open(_dir + '/' + file, "r")
    
    # read and store data line by line (5 given lines everytime)
    line = f.readline()
    line = line.split(' ')   
    dept_code = line[0]
    dept_name = line[1]

    course_name = f.readline()

    line = f.readline()
    line = line.split(' ')
    course_sched = line[0] # this var is never used
    course_start = line[1]
    course_end = line[2]

    credit_hours = f.readline()
    num_students = f.readline()

    # close .crs file
    f.close()

    # append all data to list
    data.append(dept_code.rstrip())
    data.append(dept_name.rstrip())
    data.append(course_name.rstrip())
    data.append(course_sched.rstrip())
    data.append(course_start.rstrip())
    data.append(course_end.rstrip())
    data.append(credit_hours.rstrip())
    data.append(num_students.rstrip())

    return data

    
def fill_template(data, _template, _date, _outPath, file, tag_start, tag_end):
    # check if outPath folder exists
    isExist = os.path.exists(_outPath)

    # strip extension to get new file name
    file_name = file.strip('.crs')

    # strip dept_name to get course_num
    course_num = file_name.replace(data[0], "")

    # open template file and read text
    template = open(_template, "r")
    text = template.read()

    # close template file
    template.close()

    # replace plceholder values
    text = text.replace(tag_start + "dept_code" + tag_end, data[0])
    text = text.replace(tag_start + "dept_name" + tag_end, data[1])
    text = text.replace(tag_start + "course_name" + tag_end, data[2])
    text = text.replace(tag_start + "course_sched" + tag_end, data[3]) # no placeholder in sample template 
    text = text.replace(tag_start + "course_start" + tag_end, data[4])
    text = text.replace(tag_start + "course_end" + tag_end, data[5])
    text = text.replace(tag_start + "credit_hours" + tag_end, data[6])
    text = text.replace(tag_start + "num_students" + tag_end, data[7])
    text = text.replace(tag_start + "date" + tag_end, _date)
    text = text.replace(tag_start + "course_num" + tag_end, course_num)

    # create dir if does not exist
    if not isExist:
        os.mkdir(_outPath)

    # open outfile, write text, close file 
    f = open(_outPath + '/' + file_name + ".warn", "w")
    f.write(text)
    f.close()

if __name__ == '__main__':
    main()