# Библиотека, использованная для реализации:
[nlohman/json](https://github.com/nlohmann/json)
# Описание функций
## JsonIn() 
создает файловый поток ввода и объект json, затем в цикле вводятся значения временных переменных и эти значения присваиюватся полям объекта json. Итог выводится на экран, затем закрывается файловый поток
```cpp
/* Создание файлового потока */
    ofstream JsonIn("JsonIN.json");
/* Создание объекта json */
    json sites;
    for (int i = 0; i < 2; i++) {
        string Name, Domain;
        int Users;
        double Time;
/* Ввод значений */
        cout << "Имя сайта:" << endl;
        cin >> Name;
        cout << "Домен сайта:" << endl;
        cin >> Domain;
        cout << "Пользователи сайта:" << endl;
        cin >> Users;
        cout << "Время сайта:" << endl;
        cin >> Time;

/* Добавление записи и присваивание ее полям значений переменных, описанных выше */
        sites.push_back({
            {"name", Name},
            {"domain", Domain},
            {"users", Users},
            {"time", Time},
            });

    }
/* Вывод результата на экран */
    cout << sites.dump(4) << endl;
/* Запись в файл */
    JsonIn << setw(4) << sites << endl;

    JsonIn.close();
}
```
## json_read()
Открывает файловый поток на чтение, создает объект json, считывает данные из json файла, затем проходит по каждому объекту внутри Json объекта, присваивает значения полей текущего объекта полям объекта site и возвращает полученный объект site. В случае возникновения исключения выдает ошибку. 
```cpp
site json_read() {
/* Создание файлового потока */
    ifstream jsonRead("JsonIN.json");
/* Создание объекта json */
    json jsonReaded ;
    
    try {
        jsonReaded = json::parse(jsonRead);
        for (auto& element : jsonReaded) {
/* Присваивание значений полей json объекта полям объекта site*/
            int i = 0;
            site site;
            element.at("name").get_to(site.name);
            element.at("domain").get_to(site.domain);
            element.at("users").get_to(site.users);
            element.at("time").get_to(site.time);
            return site;
        }
    }
/* Ошибка */
    catch (...) {
        cout << "Ошибка! Возможно файл пустой." << endl;
    }

    
    
    
    jsonRead.close();
}
```
