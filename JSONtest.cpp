#include <iostream>
#include <nlohmann/json.hpp>
#include <fstream>
#include <clocale>

using nlohmann::json;
using namespace std;

class site {
public:
    string name;
    string domain;
    int users;
    double time;
};


void json_record();
site json_read();


int main()
{
    setlocale(LC_ALL, "RU");
    int choice;
    site *sites = new site[2];
    
    cout << "(1) Записать json" << "\n"
        << "(2) Считать json" << endl;
    cin >> choice;
    
    switch (choice) {
    case 1:
        json_record();
        break;

    case 2:
        for (int i = 0; i < 2; i++) {
            sites[i] = json_read();
        }
        
        for (int i = 0; i < 2; i++) {
            cout << left <<
                setw(16) << sites[i].name <<
                setw(24) << sites[i].domain << 
                setw(12) << sites[i].users <<
                setw(12) << sites[i].time << endl;
        }
        
        break;
    default:
        break;
    }
    
  
}

void json_record() {
    ofstream JsonIn("JsonIN.json");

    json sites;
    for (int i = 0; i < 2; i++) {
        string Name, Domain;
        int Users;
        double Time;

        cout << "Имя сайта:" << endl;
        cin >> Name;
        cout << "Домен сайта:" << endl;
        cin >> Domain;
        cout << "Пользователи сайта:" << endl;
        cin >> Users;
        cout << "Время сайта:" << endl;
        cin >> Time;


        sites.push_back({
            {"name", Name},
            {"domain", Domain},
            {"users", Users},
            {"time", Time},
            });

    }
    cout << sites.dump(4) << endl;

    JsonIn << setw(4) << sites << endl;

    JsonIn.close();
}

site json_read() {
    ifstream jsonRead("JsonIN.json");
    json jsonReaded ;
    
    try {
        jsonReaded = json::parse(jsonRead);
        for (auto& element : jsonReaded) {
            int i = 0;
            site site;
            element.at("name").get_to(site.name);
            element.at("domain").get_to(site.domain);
            element.at("users").get_to(site.users);
            element.at("time").get_to(site.time);
            return site;
        }
    }
    catch (...) {
        cout << "Ошибка! Возможно файл пустой." << endl;
    }

    
    
    
    jsonRead.close();
}