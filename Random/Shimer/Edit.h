#ifndef EDIT_H
#define EDIT_H

#include <fstream>

template <typename T>
class record{
public:
    void store();
    T data;
    record<T> *next;

    record(T data) {
        this-> data = data;
        next = nullptr;
    }
};

template <typename T> 
record<T>* createRecord(T data) {
    record<T>* newRecord = new record<T>(data);
    return newRecord;
}


// void record::store(){

//     ifstream infile;
//     infile.open("Catalog.dat", ios::binary);
//     if (!infile.is_open())
//     {
//         return ( "Failed to open File.");
//     }
//     vector<logs> logslist;
//     while (!infile.eof())
//     {
//         logs logentry;
//         infile.read(&logentry, sizeof(logentry));
//         logslist.push_back(logentry);
//     }

//     // for(const logs& logentry : loglist)
//     // {
//     //     string entrytext;
//     //     entrytext.append(logentry.month+logentry.year+logentry.artist+ logEntry.songTitle,
//     //                         logentry.label+logentry.topOfCharts);
//     //     cout<<entrytext;
//     // }

//     };

    

#endif