#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

class Classroom {
public:
    string name;
    string lecture[7];// Array of lectures for each day
    
    Classroom(){
        name="";
        for (int i=0;i<7;i++){
            lecture[i]="";
        }
        
    }
    
    void setClassName (string n) {
        name=n;
    }
    
    void setLecture(int slot, const string& subject) {
        if (slot >= 0 && slot < 7) {
            lecture[slot] = subject;
        }
    }
    
    void print() {
        cout << "Classroom: " << name << endl;
        cout << "Time slots and Lectures:" << endl;
        for (int i = 0; i < 7; ++i) {
            
            switch (i) {
                case 0:
                    cout << "8:30-9:50: " << lecture[i] << endl;
                    break;
                case 1:
                    cout << "10:00-11:20: " << lecture[i] << endl;
                    break;
                case 2:
                    cout << "11:30-12:50: " << lecture[i] << endl;
                    break;
                case 3:
                    cout << "1:00-2:20: " << lecture[i] << endl;
                    break;
                case 4:
                    cout << "2:30-3:50: " << lecture[i] << endl;
                    break;
                case 5:
                    cout << "4:00-5:20: " << lecture[i] << endl;
                    break;
                case 6:
                    cout << "5:30-6:50: " << lecture[i] << endl;
                    break;
                    
                default:
                    break;
            }
            
            
        }
    }
};

class daySchedule{
public:
    string dayname;
    Classroom details [50];
    
    daySchedule(){
        dayname="";
        for (int i=0;i<50;i++){
            details[i]=Classroom();
        }
    }
    
    daySchedule(string dn) {
        dayname=dn;
    }
    
};

class TTADT {
public:
    
    daySchedule root[6];
    
public:
    
    TTADT() {
        root[0]=daySchedule("Monday");
        root[1]=daySchedule("Tuesday");
        root[2]=daySchedule("Wednesday");
        root[3]=daySchedule("Thursday");
        root[4]=daySchedule("Friday");
        root[5]=daySchedule("Saturday");
    }
    
    ifstream load(char filename[]) {
        ifstream ip(filename);
        
        if (!ip.is_open()) {
            cout << "Error opening file." << endl;
            return ifstream();
        }
        else{
            cout << "File opened successfully." << endl;
        }
        return ip;
    }
    
    void initializeTT(char filename[]) {
        ifstream file = load(filename);
        if (!file.is_open()) {
            cout << "Error opening file." << endl;
            return;
        }
        
        string line;
        int linenumber = 1;
        
        while (getline(file,line)){
            if (linenumber >= 3 && linenumber <=52){
                stringstream ss(line);
                string classname;
                getline(ss, classname, ','); // Assuming the class name is before the first comma
                //cout << "Class Name: " << classname << endl;
                root[0].details[linenumber-3].setClassName(classname);
                
                int slot=0;
                string lecture;
                while (getline(ss,lecture,',')){
                    //cout<<lecture<<endl;
                    root[0].details[linenumber-3].setLecture(slot, lecture);
                    slot++;
                }
                slot=0;
            }
            else if (linenumber >= 55 && linenumber <=104){
                stringstream ss(line);
                string classname;
                getline(ss, classname, ','); // Assuming the class name is before the first comma
                //cout << "Class Name: " << classname << endl;
                root[1].details[linenumber-55].setClassName(classname);
                
                int slot=0;
                string lecture;
                while (getline(ss,lecture,',')){
                    //cout<<lecture<<endl;
                    root[1].details[linenumber-55].setLecture(slot, lecture);
                    slot++;
                }
                slot=0;
            }
            else if (linenumber >= 107 && linenumber <=156){
                stringstream ss(line);
                string classname;
                getline(ss, classname, ','); // Assuming the class name is before the first comma
                //cout << "Class Name: " << classname << endl;
                root[2].details[linenumber-107].setClassName(classname);
                
                int slot=0;
                string lecture;
                while (getline(ss,lecture,',')){
                    //cout<<lecture<<endl;
                    root[2].details[linenumber-107].setLecture(slot, lecture);
                    slot++;
                }
                slot=0;
            }
            else if (linenumber >= 159 && linenumber <=208){
                stringstream ss(line);
                string classname;
                getline(ss, classname, ','); // Assuming the class name is before the first comma
                //cout << "Class Name: " << classname << endl;
                root[3].details[linenumber-159].setClassName(classname);
                
                int slot=0;
                string lecture;
                while (getline(ss,lecture,',')){
                    //cout<<lecture<<endl;
                    root[3].details[linenumber-159].setLecture(slot, lecture);
                    slot++;
                }
                slot=0;
            }
            else if (linenumber >= 211 && linenumber <=260){
                stringstream ss(line);
                string classname;
                getline(ss, classname, ','); // Assuming the class name is before the first comma
                //cout << "Class Name: " << classname << endl;
                root[4].details[linenumber-211].setClassName(classname);
                
                int slot=0;
                string lecture;
                while (getline(ss,lecture,',')){
                    //cout<<lecture<<endl;
                    root[4].details[linenumber-211].setLecture(slot, lecture);
                    slot++;
                }
                slot=0;
            }
            else if (linenumber >= 263 && linenumber <=279){
                stringstream ss(line);
                string classname;
                getline(ss, classname, ','); // Assuming the class name is before the first comma
                //cout << "Class Name: " << classname << endl;
                root[5].details[linenumber-263].setClassName(classname);
                
                int slot=0;
                string lecture;
                while (getline(ss,lecture,',')){
                    //cout<<lecture<<endl;
                    root[5].details[linenumber-263].setLecture(slot, lecture);
                    slot++;
                }
                slot=0;
            }
            linenumber++;
        }
        file.close();
    }
    
    
    void printTimetable(string forday) {
        if (forday== "Monday" || forday=="monday"){
            cout<<"Day= "<<root[0].dayname<<endl<<endl;
            for (int j = 0; j < 50; ++j) {
                if (!root[0].details[j].name.empty()) {
                    root[0].details[j].print();
                }
            }
        }
        if (forday== "Tuesday" || forday=="tuesday"){
            cout<<"Day= "<<root[1].dayname<<endl<<endl;
            for (int j = 0; j < 50; ++j) {
                if (!root[1].details[j].name.empty()) {
                    root[1].details[j].print();
                }
            }
        }
        
        if (forday== "Wednesday" || forday=="wednesday"){
            cout<<endl<<"Day= "<<root[2].dayname<<endl<<endl;
            for (int j = 0; j < 50; ++j) {
                if (!root[2].details[j].name.empty()) {
                    root[2].details[j].print();
                }
            }
        }
        if (forday== "Thursday" || forday=="thursday"){
            cout<<endl<<"Day= "<<root[3].dayname<<endl<<endl;
            for (int j = 0; j < 50; ++j) {
                if (!root[3].details[j].name.empty()) {
                    root[3].details[j].print();
                }
            }
        }
        if (forday== "Friday"   || forday=="friday"){
            cout<<endl<<"Day= "<<root[4].dayname<<endl<<endl;
            for (int j = 0; j < 50; ++j) {
                if (!root[4].details[j].name.empty()) {
                    root[4].details[j].print();
                }
            }
        }
        if (forday== "Saturday" || forday=="saturday"){
            cout<<endl<<"Day= "<<root[5].dayname<<endl<<endl;
            for (int j = 0; j < 50; ++j) {
                if (!root[5].details[j].name.empty()) {
                    root[5].details[j].print();
                }
            }
        }
    }
    
};

int main() {
    
    TTADT timetable;
    char filename[]="/Users/hashibk/Downloads/book1.csv";
    timetable.initializeTT(filename);
    
    
    int x=1;
    
    string forday;
    while (x==1){
        cout<<"Enter Day= "<<endl;
        cin>>forday;
        timetable.printTimetable(forday);
        cout<<"Press 1 to display timetable= "<<endl;
        cin>>x;
    }
    
    return 0;
}
