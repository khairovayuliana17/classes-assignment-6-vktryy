## ЗАДАЧА 1

Создай класс `Hybrid`, который наследует функциональность от базового класса `Human` и добавляет уникальные способности гибрида (помесь вампира и оборотня).

Требования к базовому классу `Human`:

Поля:

- `name` (`std::string`) - имя человека

- `age` (`int`) - возраст

- `alive_status` (`bool`) - статус жизни (`true` - жив, `false` - мертв)

Конструкторы:

- Конструктор по умолчанию:

  - Устанавливает `name` = "Unknown"

  - `age` = 0

  - `alive_status` = `true`

- Параметризованный конструктор:
`Human(const std::string& name, int age)`

Методы:

- `void die()` - меняет `alive_status` на `false`. Выводит: `[name] умер.`

- `void becomeSupernatural()` - выводит: `[name_] превращается в сверхъестественное существо!`

Геттеры для всех полей:

- `std::string getName() const`
- `int getAge() const`
- `bool isAlive() const`

Требования к классу `Hybrid` (наследник `Human`)

Дополнительные поля:

- `vampire_power` (`bool`) - активна ли сила вампира

- `werewolf_power` (`bool`) - активна ли сила оборотня

- `rage_level` (`int`) - уровень ярости (0-100)

Конструкторы:

Использование конструкторов `Human` через `using`

Дополнительный конструктор с инициализацией данных полей:

- `vampire_power` = `false`

- `werewolf_power` = `false`

- `rage_level`  = 0

Методы:

Активация способностей:

- `Hybrid& activateVampirePower()` - активирует силу вампира. Выводит: `[name] активировал силу вампира!` Возвращает `*this`

- `Hybrid& activateWerewolfPower()` - активирует силу оборотня. Выводит: `[name] активировал силу оборотня!` Возвращает `*this`

Управление яростью:

- `Hybrid& increaseRage()` - увеличивает `rage_level` на 10 (максимум 100). Возвращает `*this`

- `void checkRage()` - если `rage_level` >= 70, выводит: `[name] впадает в ярость! Уровень: [rage_level]`

Геттеры для новых полей:

- `bool hasVampirePower() const`
- `bool hasWerewolfPower() const`
- `int getRageLevel() const`

При возникновении вопросов обращайся к тестам, которые находятся в файле `tests/test.cpp`. Обрати внимание, что в данной задаче тебе понадобится изменить **три** файла: `src/human.cpp`, `src/hybrid.cpp`, `include/hybrid.h`.
