#ifndef FILE_H
#define FILE_H
#include<fstream>
#include<iostream>
#include<string>

class file{
    private:
        char month[10];
        int year;
        string artists;
        string songtitle;
        string recordlabel;
        int week;

    public:
        file(void){
            month;
            year=0;
            artists=" ";
            songtitle=" ";
            recordlabel=" ";
            week=0;

        }

        void readFile(){
            string name;
            char l;
            ifstream myReadFile;
            myReadFile.open("Catalog.dat", ios::binary);
            if(!myReadFile.is_open()){
                cout<<"Error occoured when opening the file...";
                return;
            }

            getline(myReadFile,name);
            
            
            while(!myReadFile.eof()){
               while(getline(myReadFile,month,'*')){
                cout<<month<<" ";
               }
                    cout<<month<<"\n";
                // myReadFile>>year;
            //     getline(myReadFile,artists,'*');
            //     getline(myReadFile,artists,'*');
            //     getline(myReadFile,songtitle,'*');
            //     getline(myReadFile,recordlabel,'*');
            //     myReadFile>>week;
    
            //     name = month+ ", ";
		    //     name.append(to_string(year)+", ");
		    //     name.append(artists+", ");
	        //     name.append(songtitle+", ");
	        //     name.append(recordlabel+", ");
	        //     name.append(to_string(week));
            //     if(month!=""){
            //     }
            }
        }
};

#endif
