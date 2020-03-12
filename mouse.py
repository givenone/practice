# -- </path/to/output/dir> </path/to/input/object>

import sched, time, pyautogui, os, sys

s = sched.scheduler(time.time, time.sleep)

def get_position(sc, t, f): 
    print(pyautogui.position().x, pyautogui.position().y)
    s.enter(t, 1, get_position, (sc, t, f, ))

def get_output_file_path() -> str:
    return str(sys.argv[sys.argv.index('--') + 1])


def get_time_interval() -> float:
    return float(sys.argv[sys.argv.index('--') + 2])

def save(file, data) :
    return 


file = "output/" + get_output_file_path() + ".xslx"
t = get_time_interval
print("Time Interval :", t)
if not os.path.exists(file) :
    f = open(file, 'w')
else :
    print("Existing file name")
    sys.exit()

s.enter(1, 1, get_position, (s, t, f,))
s.run()



