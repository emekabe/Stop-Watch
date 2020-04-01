#ifndef _TIME_H
#define _TIME_H

class Time
{
private:
	int sec, min, hour;

public:
	Time()
	{
		//sec = min = hour = 0;
		sec = 0;
		min = 0;
		hour = 0;
	}
	void Reset()
	{
		sec = min = hour = 0;
	}

	int get_sec() { return sec; }
	int get_min() { return min; }
	int get_hour() { return hour; }

	void operator ++()
	{
		sec++;
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
};

#endif