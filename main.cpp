#include <iostream>
#include<bits/stdc++.h>
using namespace std;
class DailyEntry
{
    string title,content;
    time_t timestamp;

public:
    DailyEntry(const string &title,const string &content):title(title),content(content),timestamp(time(nullptr)){}
    string getTitle()const{
      return title;
      }
      void display()const{
          cout<<"Title: "<<title<<endl;
          cout<<"Content: "<<content<<endl;
          cout<<"Date: "<<ctime(&timestamp)<<endl;
      }
};
class PersonalDiary
{
    vector<DailyEntry>entries;
public:
   void AddDiary(const string &title,const string &content)
   {

       entries.emplace_back(title,content);//add elements to a vector and the object you're adding has a constructor that takes arguments.
   }
   void SearchDiaryByTitle(const string &title)const
   {
       for (const auto& entry : entries) {
            if (entry.getTitle() == title) {
                entry.display();
                return;
            }
       }
       cout << "Entry with title " << title << " not found.\n";
   }
   void DisplayAllEntries()const{
        for (const auto& entry : entries) {
            entry.display();
            cout << "----------------------\n";
        }

   }
};
int main()
{
   PersonalDiary newDiary;
   int choice;
   string title,content;
   while(true)
   {
       cout << " 1. Add Entry\n 2. Display All Entries\n 3. Search Entry by Title\n 4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        switch(choice)
        {
        case 1:
            cout<<"Enter The Title: ";
            getline(cin,title);
            cout<<"Enter The Content: ";
            getline(cin,content);
            newDiary.AddDiary(title,content);
            break;
        case 2:
            newDiary.DisplayAllEntries();
            break;
        case 3:
            cout<<"Enter Title to Search: ";
            getline(cin,title);
            newDiary.SearchDiaryByTitle(title);
            break;
        case 4:
            return 0;
        default:
                cout << "Invalid choice, Please try again.\n";
        }
   }
}
