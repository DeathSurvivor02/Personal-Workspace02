using System;

namespace Lab_08_Time;

public class Time
{
    private static TimeFormat TIME_FORMAT = TimeFormat.Hour12;
    public int Hour { get; }
    public int Minute { get; }

    public Time(int hour = 0, int minute = 0)
    {
        Hour = (hour >= 0 && hour < 24) ? hour : 0;
        Minute = (minute >= 0 && minute < 60) ? minute : 0;
    }

    public override string ToString()
    {
        switch (TIME_FORMAT)
        {
            case TimeFormat.Hour12:
                int displayHour = (Hour % 12 == 0) ? 12 : Hour % 12;
                string period = (Hour < 12) ? "AM" : "PM";
                return $"{displayHour:D2}:{Minute:D2} {period}";

            case TimeFormat.Hour24:
                return $"{Hour:D2}:{Minute:D2}";

            case TimeFormat.Mil:
                return $"{Hour:D2}{Minute:D2}";

            default:
                return $"{Hour}:{Minute}";
        }
    }

    public static void SetFormat(TimeFormat time_format)
    {
        TIME_FORMAT = time_format;
    }
}
