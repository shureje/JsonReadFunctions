# Описание функций
JsonIn() создает файловый поток ввода и объект json, затем в цикле вводятся значения временных переменных и эти значения присваиюватся полям объекта json. Итог выводится на экран, затем закрывается файловый поток
```
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
