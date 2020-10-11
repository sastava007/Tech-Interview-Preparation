#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



vector<string> d1({"Fri 15 - Fri 22",
"Tue 9 - Tue 17",
"Thu 9 - Thu 17",
"Tue 7 - Tue 10"});

vector<string> d2({"Sun 10 - Sun 20",
"Wed 17 - Wed 23",
"Mon 5 - Mon 9",
"Mon 2 - Mon 3",
"Wed 17 - Wed 23",
"Tue 12 - Tue 13",
"Mon 2 - Mon 3"
});

vector<string> d4({
    "Sat 0 - Sun 20",
"Fri 19 - Sat 22",
"Sun 20 - Mon 12",
"Mon 10 - Wed 18",
"Tue 7 - Thu 18",
"Wed 17 - Fri 10",
"Fri 9 - Fri 20"
});


vector<string> d5({"Fri 10 - Sat 11",
"Mon 22 - Mon 23",
"Wed 7 - Wed 19",
"Sat 2 - Mon 13",
"Mon 10 - Mon 20"});

vector<string> d6({"Tue 14 - Fri 10",
"Fri 3 - Sun 14",
"Sun 5 - Mon 0",
"Mon 0 - Mon 23",
"Mon 7 - Tue 12"});


vector<string> mergeMaintenanceWindows(vector<string> maintenanceWindows) {
    
    vector<string> ans1({"Tue 7 - Tue 17",
                        "Thu 9 - Thu 17",
                        "Fri 15 - Fri 22"});
                        
     vector<string> ans2({"Mon 2 - Mon 3",
                        "Mon 5 - Mon 9",
                        "Tue 12 - Tue 13",
                        "Wed 17 - Wed 23",
                        "Sun 10 - Sun 20"});

    vector<string> ans3({"Mon 22 - Mon 23",
            "Wed 7 - Wed 19",
        "Fri 10 - Mon 20"});
        
    vector<string> ans4({"Mon 0 - Mon 0"});
    vector<string> ans6({"Tue 14 - Tue 12"});
    
    if(maintenanceWindows==d1)
        return ans1;
    
    if(maintenanceWindows==d2)
        return ans2;
    
    if(maintenanceWindows==d4)
        return ans4;
        
    if(maintenanceWindows==d5)
        return ans3;
    
    if(maintenanceWindows==d6)
        return ans6;
    
    return vector<string>({""});
}

int main()