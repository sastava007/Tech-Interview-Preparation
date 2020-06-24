/* 
    Idea is to find the no. of days from 1971 till second date and no. of days from 1971 till first date and return difference of two.
    Input: [date1 = "2019-06-29", date2 = "2019-06-30"]
*/

class Solution {

public:
    int daysBetweenDates(string date1, string date2) 
    {
        return abs(get(date2)-get(date1));
    }
    
private:
    
    int mon[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    int get(string date)
    {
        int year=0,month=0,day=0;
        for(int i=0;i<4;i++)    // find year
        {
            year=year*10+date[i]-'0';
        }
        for(int i=5;i<7;i++)    // find month
        {
            month=month*10+date[i]-'0';
        }
        for(int i=8;i<10;i++)   // find day
        {
            day=day*10+date[i]-'0';
        }
        int res=0;
        for(int i=1971;i<year;i++)
        {
            res=res+365;
            if((i%4==0 && i%100!=0) || i%400==0)    //leap year
                res++;
        }
        for(int i=1;i<month;i++)
        {
            res=res+mon[i];
            if(i==2&&((year%4==0&&year%100!=0)||year%400==0))       //if leap year, then there will be 29 days in Feb
                res++;
        }
        return res+day;
    }
};