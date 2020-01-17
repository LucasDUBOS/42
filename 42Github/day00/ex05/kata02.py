import sys


vtimes = (3,30,2019,9,25)

times = {
    'hour': vtimes[0],
    'minutes': vtimes[1],
    'year': vtimes[2],
    'month': vtimes[3],
    'day': vtimes[4],
    }

for time in times:
    if times[time] < 10:
        times[time] = '0' + str(times[time])
    else:
       times[time] = str(times[time])
print(times['month'] + "/" + times['day'] + "/" + times['year'] + " " + times['hour'] + ":" + times['minutes'])


