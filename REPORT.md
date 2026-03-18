# Отчет по лабораторной работе №2
## Системы контроля версий на примере Git

**Студент:** Кешишоглян Артур  
**Дата выполнения:** 18.03.2026

---

## 1. Подготовка и настройка

### 1.1 Установка Git

```bash
sudo apt install git
```

**Листинг вывода:**
```
Reading package lists... Done
Building dependency tree... Done
Reading state information... Done
git is already the newest version (1:2.51.0-1ubuntu1).
0 upgraded, 0 newly installed, 0 to remove and 0 not upgraded.
```

### 1.2 Проверка версии Git

```bash
git --version
```

**Листинг вывода:**
```
git version 2.51.0
```

### 1.3 Настройка переменных окружения

```bash
export GITHUB_USERNAME="Artur4566"
export GITHUB_EMAIL="artur.kesh2007@gmail.com"
export GITHUB_TOKEN="ghp_"
```

```bash
echo $GITHUB_USERNAME
echo $GITHUB_EMAIL
```

**Листинг вывода:**
```
Artur4566
artur.kesh2007@gmail.com
```

### 1.4 Настройка Git

```bash
git config --global user.name "Artur4566"
git config --global user.email "artur.kesh2007@gmail.com"
```

```bash
git config --global --list
```

**Листинг вывода:**
```
user.name=Artur4566
user.email=artur.kesh2007@gmail.com
```

### 1.5 Клонирование репозитория

```bash
git clone https://github.com/Artur4566/lab02.git
```

**Листинг вывода:**
```
Cloning into 'lab02'...
warning: You appear to have cloned an empty repository.
```

```bash
cd lab02
ls -la
```

**Листинг вывода:**
```
total 12
drwxrwxr-x 3 ubuntu ubuntu 4096 Mar 18 12:49 .
drwxr-x--- 16 ubuntu ubuntu 400 Mar 18 12:49 ..
drwxrwxr-x 7 ubuntu ubuntu 4096 Mar 18 12:49 .git
```

---

## 2. Выполнение Tutorial

### 2.1 Создание README.md

```bash
cat > README.md <<'EOF'
# Лабораторная работа №2
## Изучение системы контроля версий Git

Данный репозиторий создан в рамках выполнения лабораторной работы 
по дисциплине "Системы контроля версий".

## Автор
Кешишоглян Артур
EOF
```

```bash
cat README.md
```

**Листинг вывода:**
```
# Лабораторная работа №2
## Изучение системы контроля версий Git

Данный репозиторий создан в рамках выполнения лабораторной работы 
по дисциплине "Системы контроля версий".

## Автор
Кешишоглян Артур
```

### 2.2 Первый коммит

```bash
git add README.md
```

```bash
git status
```

**Листинг вывода:**
```
On branch main

No commits yet

Changes to be committed:
  (use "git rm --cached <file>..." to unstage)
        new file:   README.md
```

```bash
git commit -m "Начальный коммит: добавлен README.md"
```

**Листинг вывода:**
```
[main (root-commit) ad92289] Начальный коммит: добавлен README.md
 1 file changed, 7 insertions(+)
 create mode 100644 README.md
```

```bash
git push origin main
```

**Листинг вывода:**
```
Enumerating objects: 3, done.
Counting objects: 100% (3/3), done.
Writing objects: 100% (3/3), 342 bytes | 342.00 KiB/s, done.
Total 3 (delta 0), reused 0 (delta 0)
To https://github.com/Artur4566/lab02.git
 * [new branch]      main -> main
```

### 2.3 Создание .gitignore

```bash
cat > .gitignore <<'EOF'
# Игнорировать директории сборки
build/
*-build/
*/build/*

# Игнорировать временные файлы
*.tmp
*.log
*.cache
*.swp
*.swo

# Игнорировать файлы IDE
.vscode/
.idea/
*.code-workspace

# Игнорировать файлы ОС
.DS_Store
Thumbs.db
EOF
```

```bash
cat .gitignore
```

**Листинг вывода:**
```
# Игнорировать директории сборки
build/
*-build/
*/build/*

# Игнорировать временные файлы
*.tmp
*.log
*.cache
*.swp
*.swo

# Игнорировать файлы IDE
.vscode/
.idea/
*.code-workspace

# Игнорировать файлы ОС
.DS_Store
Thumbs.db
```

```bash
git add .gitignore
git commit -m "Добавлен .gitignore с правилами для проекта"
```

**Листинг вывода:**
```
[main 06d24da] Добавлен .gitignore с правилами для проекта
 1 file changed, 17 insertions(+)
 create mode 100644 .gitignore
```

```bash
git push origin main
```

**Листинг вывода:**
```
Enumerating objects: 4, done.
Counting objects: 100% (4/4), done.
Delta compression using up to 2 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 521 bytes | 521.00 KiB/s, done.
Total 3 (delta 0), reused 0 (delta 0), pack-reused 0 (from 0)
To https://github.com/Artur4566/lab02.git
   ad92289..06d24da  main -> main
```

### 2.4 Создание структуры проекта

```bash
mkdir library examples tests
```

```bash
ls -la
```

**Листинг вывода:**
```
total 8
drwxrwxr-x  6 ubuntu ubuntu 160 Mar 18 12:51 .
drwxr-x--- 16 ubuntu ubuntu 400 Mar 18 12:49 ..
drwxrwxr-x  7 ubuntu ubuntu 240 Mar 18 12:50 .git
-rw-rw-r--  1 ubuntu ubuntu 317 Mar 18 12:50 .gitignore
-rw-rw-r--  1 ubuntu ubuntu 361 Mar 18 12:49 README.md
drwxrwxr-x  2 ubuntu ubuntu  40 Mar 18 12:51 examples
drwxrwxr-x  2 ubuntu ubuntu  40 Mar 18 12:51 library
drwxrwxr-x  2 ubuntu ubuntu  40 Mar 18 12:51 tests
```

### 2.5 Создание файлов библиотеки

**library/output.hpp:**

```bash
cat > library/output.hpp <<'EOF'
#ifndef OUTPUT_HPP
#define OUTPUT_HPP

#include <fstream>
#include <iostream>
#include <string>

void display(const std::string& message, std::ostream& stream = std::cout);
void write_to_file(const std::string& message, const std::string& filename);

#endif
EOF
```

```bash
cat library/output.hpp
```

**Листинг вывода:**
```cpp
#ifndef OUTPUT_HPP
#define OUTPUT_HPP

#include <fstream>
#include <iostream>
#include <string>

void display(const std::string& message, std::ostream& stream = std::cout);
void write_to_file(const std::string& message, const std::string& filename);

#endif
```

**library/output.cpp:**

```bash
cat > library/output.cpp <<'EOF'
#include "output.hpp"

void display(const std::string& message, std::ostream& stream)
{
    stream << message;
}

void write_to_file(const std::string& message, const std::string& filename)
{
    std::ofstream file(filename, std::ios::app);
    if (file.is_open()) {
        file << message << std::endl;
        file.close();
    }
}
EOF
```

```bash
cat library/output.cpp
```

**Листинг вывода:**
```cpp
#include "output.hpp"

void display(const std::string& message, std::ostream& stream)
{
    stream << message;
}

void write_to_file(const std::string& message, const std::string& filename)
{
    std::ofstream file(filename, std::ios::app);
    if (file.is_open()) {
        file << message << std::endl;
        file.close();
    }
}
```

### 2.6 Создание примеров

**examples/demo1.cpp:**

```bash
cat > examples/demo1.cpp <<'EOF'
#include "../library/output.hpp"

int main()
{
    display("Привет, мир! Это демонстрация работы библиотеки.\n");
    display("Вторая строка вывода в консоль.\n");
    return 0;
}
EOF
```

```bash
cat examples/demo1.cpp
```

**Листинг вывода:**
```cpp
#include "../library/output.hpp"

int main()
{
    display("Привет, мир! Это демонстрация работы библиотеки.\n");
    display("Вторая строка вывода в консоль.\n");
    return 0;
}
```

**examples/demo2.cpp:**

```bash
cat > examples/demo2.cpp <<'EOF'
#include "../library/output.hpp"

int main()
{
    write_to_file("Первое сообщение в файл", "log.txt");
    write_to_file("Второе сообщение в файл", "log.txt");
    write_to_file("Третье сообщение", "log.txt");
    return 0;
}
EOF
```

```bash
cat examples/demo2.cpp
```

**Листинг вывода:**
```cpp
#include "../library/output.hpp"

int main()
{
    write_to_file("Первое сообщение в файл", "log.txt");
    write_to_file("Второе сообщение в файл", "log.txt");
    write_to_file("Третье сообщение", "log.txt");
    return 0;
}
```

### 2.7 Создание тестов

**tests/test_output.cpp:**

```bash
cat > tests/test_output.cpp <<'EOF'
#include "../library/output.hpp"
#include <fstream>
#include <string>
#include <iostream>

int main()
{
    std::cout << "Запуск тестов..." << std::endl;
    
    write_to_file("Тестовое сообщение 1", "test.log");
    write_to_file("Тестовое сообщение 2", "test.log");
    
    std::cout << "Тесты завершены. Проверьте файл test.log" << std::endl;
    return 0;
}
EOF
```

```bash
cat tests/test_output.cpp
```

**Листинг вывода:**
```cpp
#include "../library/output.hpp"
#include <fstream>
#include <string>
#include <iostream>

int main()
{
    std::cout << "Запуск тестов..." << std::endl;
    
    write_to_file("Тестовое сообщение 1", "test.log");
    write_to_file("Тестовое сообщение 2", "test.log");
    
    std::cout << "Тесты завершены. Проверьте файл test.log" << std::endl;
    return 0;
}
```

### 2.8 Обновление README.md

```bash
cat > README.md <<'EOF'
# Лабораторная работа №2
## Изучение системы контроля версий Git

**Автор:** Кешишоглян Артур  
**Дата:** Март 2026

## 📋 Описание проекта
Данный проект представляет собой библиотеку для вывода текста в различные потоки (консоль, файл). 
Создан в рамках изучения системы контроля версий Git.

## 📁 Структура проекта
lab02/
├── library/           # Исходный код библиотеки
│   ├── output.hpp     # Заголовочный файл с объявлениями функций
│   └── output.cpp     # Реализация функций
├── examples/          # Примеры использования
│   ├── demo1.cpp      # Демонстрация вывода в консоль
│   └── demo2.cpp      # Демонстрация записи в файл
├── tests/             # Тесты
│   └── test_output.cpp
├── .gitignore         # Игнорируемые файлы
└── README.md          # Документация проекта

## 🔧 Функционал библиотеки
- `display()` - вывод текста в консоль
- `write_to_file()` - запись текста в файл (в режиме добавления)

## 🎯 Цель лабораторной работы
Освоение основных команд Git:
- Инициализация и клонирование репозиториев
- Создание коммитов
- Работа с ветками
- Разрешение конфликтов
- Создание Pull Request
EOF
```

```bash
cat README.md
```

**Листинг вывода:**
```
# Лабораторная работа №2
## Изучение системы контроля версий Git

**Автор:** Кешишоглян Артур  
**Дата:** Март 2026

## 📋 Описание проекта
Данный проект представляет собой библиотеку для вывода текста в различные потоки (консоль, файл). 
Создан в рамках изучения системы контроля версий Git.

## 📁 Структура проекта
lab02/
├── library/           # Исходный код библиотеки
│   ├── output.hpp     # Заголовочный файл с объявлениями функций
│   └── output.cpp     # Реализация функций
├── examples/          # Примеры использования
│   ├── demo1.cpp      # Демонстрация вывода в консоль
│   └── demo2.cpp      # Демонстрация записи в файл
├── tests/             # Тесты
│   └── test_output.cpp
├── .gitignore         # Игнорируемые файлы
└── README.md          # Документация проекта

## 🔧 Функционал библиотеки
- `display()` - вывод текста в консоль
- `write_to_file()` - запись текста в файл (в режиме добавления)

## 🎯 Цель лабораторной работы
Освоение основных команд Git:
- Инициализация и клонирование репозиториев
- Создание коммитов
- Работа с ветками
- Разрешение конфликтов
- Создание Pull Request
```

### 2.9 Коммит всех изменений

```bash
git status
```

**Листинг вывода:**
```
On branch main
Your branch is up to date with 'origin/main'.

Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   README.md

Untracked files:
  (use "git add <file>..." to include in what will be committed)
        examples/
        library/
        tests/

no changes added to commit (use "git add" and/or "git commit -a")
```

```bash
git add .
```

```bash
git status
```

**Листинг вывода:**
```
On branch main
Your branch is up to date with 'origin/main'.

Changes to be committed:
  (use "git restore --staged <file>..." to unstage)
        modified:   README.md
        new file:   examples/demo1.cpp
        new file:   examples/demo2.cpp
        new file:   library/output.cpp
        new file:   library/output.hpp
        new file:   tests/test_output.cpp
```

```bash
git commit -m "Реализована библиотека для вывода текста"
```

**Листинг вывода:**
```
[main ca10c14] Реализована библиотека для вывода текста
 6 files changed, 93 insertions(+), 4 deletions(-)
 create mode 100644 examples/demo1.cpp
 create mode 100644 examples/demo2.cpp
 create mode 100644 library/output.cpp
 create mode 100644 library/output.hpp
 create mode 100644 tests/test_output.cpp
```

```bash
git push origin main
```

**Листинг вывода:**
```
Enumerating objects: 13, done.
Counting objects: 100% (13/13), done.
Delta compression using up to 2 threads
Compressing objects: 100% (10/10), done.
Writing objects: 100% (11/11), 2.48 KiB | 2.48 MiB/s, done.
Total 11 (delta 0), reused 0 (delta 0), pack-reused 0 (from 0)
To https://github.com/Artur4566/lab02.git
   06d24da..ca10c14  main -> main
```

---

## 3. Домашнее задание Part I

### 3.1 Создание greeting.cpp с плохим стилем

```bash
cat > greeting.cpp <<'EOF'
#include <iostream>
using namespace std;

int main()
{
    cout << "Hello, World!" << endl;
    return 0;
}
EOF
```

```bash
cat greeting.cpp
```

**Листинг вывода:**
```cpp
#include <iostream>
using namespace std;

int main()
{
    cout << "Hello, World!" << endl;
    return 0;
}
```

```bash
git add greeting.cpp
git commit -m "Добавлена программа приветствия (начальная версия)"
```

**Листинг вывода:**
```
[main 6f4012a] Добавлена программа приветствия (начальная версия)
 1 file changed, 6 insertions(+)
 create mode 100644 greeting.cpp
```

### 3.2 Добавление ввода имени

```bash
cat > greeting.cpp <<'EOF'
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string username;
    cout << "Введите ваше имя: ";
    cin >> username;
    cout << "Привет, " << username << "!" << endl;
    return 0;
}
EOF
```

```bash
cat greeting.cpp
```

**Листинг вывода:**
```cpp
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string username;
    cout << "Введите ваше имя: ";
    cin >> username;
    cout << "Привет, " << username << "!" << endl;
    return 0;
}
```

```bash
git commit -am "Добавлен ввод имени пользователя"
```

**Листинг вывода:**
```
[main 04a2369] Добавлен ввод имени пользователя
 1 file changed, 5 insertions(+), 1 deletion(-)
```

```bash
git push origin main
```

**Листинг вывода:**
```
Enumerating objects: 7, done.
Counting objects: 100% (7/7), done.
Delta compression using up to 2 threads
Compressing objects: 100% (6/6), done.
Writing objects: 100% (6/6), 909 bytes | 909.00 KiB/s, done.
Total 6 (delta 2), reused 0 (delta 0), pack-reused 0 (from 0)
remote: Resolving deltas: 100% (2/2), completed with 1 local object.
To https://github.com/Artur4566/lab02.git
   ca10c14..04a2369  main -> main
```

```bash
git log --oneline
```

**Листинг вывода:**
```
04a2369 (HEAD -> main, origin/main) Добавлен ввод имени пользователя
6f4012a Добавлена программа приветствия (начальная версия)
ca10c14 Реализована библиотека для вывода текста
06d24da Добавлен .gitignore с правилами для проекта
ad92289 Начальный коммит: добавлен README.md
```

---

## 4. Домашнее задание Part II

### 4.1 Создание ветки fix-style

```bash
git checkout -b fix-style
```

**Листинг вывода:**
```
Switched to a new branch 'fix-style'
```

```bash
git branch
```

**Листинг вывода:**
```
  main
* fix-style
```

### 4.2 Исправление кода (убираем using namespace std)

```bash
cat > greeting.cpp <<'EOF'
#include <iostream>
#include <string>

int main()
{
    std::string username;
    std::cout << "Введите ваше имя: ";
    std::cin >> username;
    std::cout << "Привет, " << username << "!" << std::endl;
    return 0;
}
EOF
```

```bash
cat greeting.cpp
```

**Листинг вывода:**
```cpp
#include <iostream>
#include <string>

int main()
{
    std::string username;
    std::cout << "Введите ваше имя: ";
    std::cin >> username;
    std::cout << "Привет, " << username << "!" << std::endl;
    return 0;
}
```

```bash
git commit -am "Исправление: убрано using namespace std"
```

**Листинг вывода:**
```
[fix-style 5f88643] Исправление: убрано using namespace std
 1 file changed, 4 insertions(+), 5 deletions(-)
```

```bash
git push origin fix-style
```

**Листинг вывода:**
```
Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 2 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 462 bytes | 462.00 KiB/s, done.
Total 3 (delta 1), reused 0 (delta 0), pack-reused 0 (from 0)
remote: Resolving deltas: 100% (1/1), completed with 1 local object.
remote: 
remote: Create a pull request for 'fix-style' on GitHub by visiting:
remote:      https://github.com/Artur4566/lab02/pull/new/fix-style
remote: 
To https://github.com/Artur4566/lab02.git
 * [new branch]      fix-style -> fix-style
```

### 4.3 Добавление комментариев

```bash
cat > greeting.cpp <<'EOF'
#include <iostream>
#include <string>

int main()
{
    // Переменная для хранения имени пользователя
    std::string username;
    
    // Запрос имени у пользователя
    std::cout << "Введите ваше имя: ";
    std::cin >> username;
    
    // Вывод приветствия
    std::cout << "Привет, " << username << "!" << std::endl;
    return 0;
}
EOF
```

```bash
cat greeting.cpp
```

**Листинг вывода:**
```cpp
#include <iostream>
#include <string>

int main()
{
    // Переменная для хранения имени пользователя
    std::string username;
    
    // Запрос имени у пользователя
    std::cout << "Введите ваше имя: ";
    std::cin >> username;
    
    // Вывод приветствия
    std::cout << "Привет, " << username << "!" << std::endl;
    return 0;
}
```

```bash
git commit -am "Добавлены комментарии на русском языке"
```

**Листинг вывода:**
```
[fix-style c32d7fd] Добавлены комментарии на русском языке
 1 file changed, 5 insertions(+)
```

```bash
git push origin fix-style
```

**Листинг вывода:**
```
Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 2 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 563 bytes | 563.00 KiB/s, done.
Total 3 (delta 1), reused 0 (delta 0), pack-reused 0 (from 0)
remote: Resolving deltas: 100% (1/1), completed with 1 local object.
To https://github.com/Artur4566/lab02.git
   5f88643..c32d7fd  fix-style -> fix-style
```

### 4.4 Слияние Pull Request и удаление ветки

```bash
git checkout main
```

**Листинг вывода:**
```
Switched to branch 'main'
Your branch is up to date with 'origin/main'.
```

```bash
git pull origin main
```

**Листинг вывода:**
```
remote: Enumerating objects: 1, done.
remote: Counting objects: 100% (1/1), done.
remote: Total 1 (delta 0), reused 0 (delta 0), pack-reused 0 (from 0)
Unpacking objects: 100% (1/1), 948 bytes | 948.00 KiB/s, done.
From https://github.com/Artur4566/lab02
 * branch            main       -> FETCH_HEAD
   04a2369..e8bba49  main       -> origin/main
Updating 04a2369..e8bba49
Fast-forward
 greeting.cpp | 14 +++++++++-----
 1 file changed, 9 insertions(+), 5 deletions(-)
```

```bash
git branch -d fix-style
```

**Листинг вывода:**
```
Deleted branch fix-style (was c32d7fd).
```

```bash
git branch
```

**Листинг вывода:**
```
* main
```

---

## 5. Домашнее задание Part III

### 5.1 Установка clang-format

```bash
sudo apt install clang-format -y
```

**Листинг вывода:**
```
Reading package lists... Done
Building dependency tree... Done
Reading state information... Done
clang-format is already the newest version (1:20.0-63ubuntu1).
0 upgraded, 0 newly installed, 0 to remove and 0 not upgraded.
```

```bash
clang-format --version
```

**Листинг вывода:**
```
Ubuntu clang-format version 20.1.8
```

### 5.2 Создание ветки format-code

```bash
git checkout -b format-code
```

**Листинг вывода:**
```
Switched to a new branch 'format-code'
```

```bash
git branch
```

**Листинг вывода:**
```
  main
* format-code
```

### 5.3 Форматирование кода в стиле Google

```bash
clang-format -style=Google -i greeting.cpp
```

```bash
cat greeting.cpp
```

**Листинг вывода:**
```cpp
#include <iostream>
#include <string>

int main() {
  // Переменная для хранения имени пользователя
  std::string username;

  // Запрос имени у пользователя
  std::cout << "Введите ваше имя: ";
  std::cin >> username;

  // Вывод приветствия
  std::cout << "Привет, " << username << "!" << std::endl;
  return 0;
}
```

```bash
git commit -am "Применен стиль форматирования Google"
```

**Листинг вывода:**
```
[format-code 56ec267] Применен стиль форматирования Google
 1 file changed, 11 insertions(+), 12 deletions(-)
```

```bash
git push origin format-code
```

**Листинг вывода:**
```
Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 2 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 384 bytes | 384.00 KiB/s, done.
Total 3 (delta 2), reused 0 (delta 0), pack-reused 0 (from 0)
remote: Resolving deltas: 100% (2/2), completed with 2 local objects.
remote: 
remote: Create a pull request for 'format-code' on GitHub by visiting:
remote:      https://github.com/Artur4566/lab02/pull/new/format-code
remote: 
To https://github.com/Artur4566/lab02.git
 * [new branch]      format-code -> format-code
```

### 5.4 Создание конфликта в ветке main

```bash
git checkout main
```

**Листинг вывода:**
```
Switched to branch 'main'
Your branch is up to date with 'origin/main'.
```

```bash
cat > greeting.cpp <<'EOF'
#include <iostream>
#include <string>

int main()
{
    // Имя пользователя
    std::string username;
    
    // Ввод имени
    std::cout << "Введите ваше имя: ";
    std::cin >> username;
    
    // Вывод приветствия
    std::cout << "Привет, " << username << "!" << std::endl;
    return 0;
}
EOF
```

```bash
cat greeting.cpp
```

**Листинг вывода:**
```cpp
#include <iostream>
#include <string>

int main()
{
    // Имя пользователя
    std::string username;
    
    // Ввод имени
    std::cout << "Введите ваше имя: ";
    std::cin >> username;
    
    // Вывод приветствия
    std::cout << "Привет, " << username << "!" << std::endl;
    return 0;
}
```

```bash
git commit -am "Изменены комментарии в greeting.cpp"
```

**Листинг вывода:**
```
[main 314db76] Изменены комментарии в greeting.cpp
 1 file changed, 2 insertions(+), 2 deletions(-)
```

```bash
git push origin main
```

**Листинг вывода:**
```
Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 2 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 371 bytes | 371.00 KiB/s, done.
Total 3 (delta 2), reused 0 (delta 0), pack-reused 0 (from 0)
remote: Resolving deltas: 100% (2/2), completed with 2 local objects.
To https://github.com/Artur4566/lab02.git
   e8bba49..314db76  main -> main
```

### 5.5 Разрешение конфликта через rebase

```bash
git checkout format-code
```

**Листинг вывода:**
```
Switched to branch 'format-code'
```

```bash
git pull --rebase origin main
```

**Листинг вывода:**
```
remote: Enumerating objects: 5, done.
remote: Counting objects: 100% (5/5), done.
remote: Compressing objects: 100% (2/2), done.
remote: Total 3 (delta 2), reused 3 (delta 2), pack-reused 0 (from 0)
Unpacking objects: 100% (3/3), done.
From https://github.com/Artur4566/lab02
 * branch            main       -> FETCH_HEAD
   e8bba49..314db76  main       -> origin/main
Auto-merging greeting.cpp
CONFLICT (content): Merge conflict in greeting.cpp
error: could not apply 56ec267... Применен стиль форматирования Google
hint: Resolve all conflicts manually, mark them as resolved with
hint: "git add/rm <conflicted_files>", then run "git rebase --continue".
hint: You can instead skip this commit: run "git rebase --skip".
hint: To abort and get back to the state before "git rebase", run "git rebase --abort".
Could not apply 56ec267... Применен стиль форматирования Google
```

### 5.6 Исправление конфликта

```bash
cat > greeting.cpp <<'EOF'
#include <iostream>
#include <string>

int main()
{
    // Имя пользователя
    std::string username;

    // Ввод имени
    std::cout << "Введите ваше имя: ";
    std::cin >> username;

    // Вывод приветствия
    std::cout << "Привет, " << username << "!" << std::endl;
    return 0;
}
EOF
```

```bash
cat greeting.cpp
```

**Листинг вывода:**
```cpp
#include <iostream>
#include <string>

int main()
{
    // Имя пользователя
    std::string username;

    // Ввод имени
    std::cout << "Введите ваше имя: ";
    std::cin >> username;

    // Вывод приветствия
    std::cout << "Привет, " << username << "!" << std::endl;
    return 0;
}
```

```bash
git add greeting.cpp
```

```bash
git rebase --continue
```

**Листинг вывода:**
```
[detached HEAD affa657] Применен стиль форматирования Google
 1 file changed, 2 insertions(+), 2 deletions(-)
Successfully rebased and updated refs/heads/format-code.
```

```bash
git push --force origin format-code
```

**Листинг вывода:**
```
Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 2 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 350 bytes | 350.00 KiB/s, done.
Total 3 (delta 2), reused 0 (delta 0), pack-reused 0 (from 0)
remote: Resolving deltas: 100% (2/2), completed with 2 local objects.
To https://github.com/Artur4566/lab02.git
 + 56ec267...affa657 format-code -> format-code (forced update)
```

### 5.7 Финальное слияние и синхронизация

```bash
git checkout main
```

**Листинг вывода:**
```
Switched to branch 'main'
Your branch is up to date with 'origin/main'.
```

```bash
git pull origin main
```

**Листинг вывода:**
```
remote: Enumerating objects: 1, done.
remote: Counting objects: 100% (1/1), done.
remote: Total 1 (delta 0), reused 0 (delta 0), pack-reused 0 (from 0)
Unpacking objects: 100% (1/1), 950 bytes | 475.00 KiB/s, done.
From https://github.com/Artur4566/lab02
 * branch            main       -> FETCH_HEAD
   314db76..bf73748  main       -> origin/main
Updating 314db76..bf73748
Fast-forward
 greeting.cpp | 4 ++--
 1 file changed, 2 insertions(+), 2 deletions(-)
```

```bash
git branch -d format-code
```

**Листинг вывода:**
```
Deleted branch format-code (was affa657).
```

```bash
git log --oneline --graph --all
```

**Листинг вывода:**
```
*   bf73748 (HEAD -> main, origin/main) Merge pull request #2 from Artur4566/format-code
|\  
| * affa657 (origin/format-code) Применен стиль форматирования Google
|/  
* 314db76 Изменены комментарии в greeting.cpp
*   e8bba49 Merge pull request #1 from Artur4566/fix-style
|\  
| * c32d7fd (origin/fix-style) Добавлены комментарии на русском языке
| * 5f88643 Исправление: убрано using namespace std
|/  
* 04a2369 Добавлен ввод имени пользователя
* 6f4012a Добавлена программа приветствия (начальная версия)
* ca10c14 Реализована библиотека для вывода текста
* 06d24da Добавлен .gitignore с правилами для проекта
* ad92289 Начальный коммит: добавлен README.md
```

---

## 6. Выводы

В ходе выполнения лабораторной работы были изучены основные возможности системы контроля версий Git:

- Создание и клонирование репозиториев (git init, git clone)
- Добавление и коммит изменений (git add, git commit)
- Работа с ветками (git branch, git checkout, git merge)
- Синхронизация с удаленным репозиторием (git push, git pull)
- Разрешение конфликтов при слиянии веток
- Использование rebase для обновления веток
- Работа с Pull Request на GitHub
- Автоматическое форматирование кода с помощью clang-format

**Ссылка на репозиторий:** https://github.com/Artur4566/lab02
```

