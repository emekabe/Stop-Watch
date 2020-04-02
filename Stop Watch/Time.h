#ifndef _TIME_H
#define _TIME_H

class Time
{
private:
	int sec, min, hour, cSec;

public:
	Time()
	{
		//sec = min = hour = 0;
		sec = 0;
		min = 0;
		hour = 0;
		cSec = 0;
	}
	void Reset()
	{
		cSec = sec = min = hour = 0;
	}

	int get_sec() { return sec; }
	int get_min() { return min; }
	int get_hour() { return hour; }
	int get_cSec() { return cSec; }

	void operator ++()
	{
		cSec++;
		if (cSec == 100)
		{
			sec++;
			cSec = 0;
			if (sec == 60)
			{
				min++;
				sec = 0;
				if (min == 60)
				{
					hour++;
					min = 0;
				}
			}
		}

	}
};

#endif