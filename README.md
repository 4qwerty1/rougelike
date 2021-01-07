## Rogue-like игра!
 
Нарисованная в консоли карта, например:

  `.................K`
  
  `....Z.............`
  
  `..Z.........######`
  
  `.................#`
  
  `......D........P.#`

С клавиатуры можно управлять рыцарем (WASD или стрелочки)

Пока игра пошаговая, после перемещения рыцаря ходят все остальные мобы

Персонажи не должны выходить за пределы карты (и игра не должна падать при этом!).

Столкновения персонажей друг с другом пока не проверяются.


При компиляции с флагом -fsanitize=address ваш код не должен падать. Проверьте это заранее.


Советы/комментарии по реализации:

### Базовый класс и общая иерархия
class Character:

private:

hp - количество хитов

damage - количество наносимого урона 

sym - char, которым данный персонаж обозначается на карте


x, y - координаты (можно сделать простую структуру Point для их хранения)

возможно max_hp - максимальное количество хитов для персонажей данного типа

возможно мана

public:

GetPos - функция, возращающая координаты

GetHp, GetDamage, GetSym - геттеры для hp, damage и sym соответственно 



класс Character должен быть абстрактным


от Character должны наследоваться:

Knight - персонаж, которым вы управляете. (K)

Princess - принцесса, до нее нужно добраться, чтобы выиграть. Она просто стоит на месте, дамаг тоже не наносит (P)

Zombie - чуваки, которые рандомно (или по направлению к герою) перемещаются по карте (Z)

Dragon - тоже враг, сильнее чем зомби (D)

Wall - стена - стоит, ничего не делает. Через нее нельзя пройти (#)

Опционально можно унаследовать зомби и дракона от класса Monster(Enemy), который бы в свою очередь наследовался от Character-а

Можно сделать дополнительный базовый класс Actor/GameObject, от которого будет наследоваться например Wall и Character и все остальные объекты. От Character -- только те, кто обладает каким-то сложным поведением на карте.


### Карта
у вас должна быть карта (class Map), в которой должна храниться сама карта

Карта должна подгружаться из файла. Используйте шаблон проектирования Factory для создания нужного класса персонажа по символу в файле с картой. 

### Game loop

Также должен быть класс, управляющий общим игровым процессом. Содержит основной цикл игры.

В нем может быть удобно хранить вектор указателей на мобов.

### Общие указания
В целом разработка архитектуры остается на ваше усмотрение, но за копипасту кода, плохо организованный код, зависящий от типов персонажей будут снижатся баллы. Не должно быть указателей, за освобождением которых вы следите вручную. RAII должен соблюдаться (легко организовать с помощью unique_ptr, shared_ptr).


P.S. Названия персонажей не обязательно должны соответствовать тому, что описано здесь. 

Сохраняя основной функционал, можете проявлять фантазию, как вам захочется.


## 2я часть Rogue-like игры.

1. Виртуальные функции character_ptr Collide(character_ptr). Collide вызовется при столкновении 2х персонажей и описывает их взаимодействие.
Перегрузки для всех пар типов персонажей. Используйте double dispatch.
Можно альтернативную архитектуру с вынесенным коллайдером, но не должно быть ифов на тип персонажа и дублирования кода.

2. Хотя бы один тип монстров должен научиться стрелять. Соответственно, должен появиться класс Projectile (наследник от Character). Для обозначения projectile-ов в консоли можно использовать символы (^v). При столкновении projectile-а с вашим героем, projectile наносит герою некоторый фиксированный урон и исчезает. При столкновении с другими мобами, projectile может наносить или не наносить урон по вашему усмотрению. При столкновении со стеной или границей карты, projectile так же должен исчезать.

3. Ваш персонаж тоже должен уметь стрелять.

4. Должны появиться аптечки (класс AidKit, наследник от какого-нибудь общего с Character предка). При столкновении рыцаря с аптечкой, он должен хилиться на какое-то фиксированное число (но при этом его hp не может превышать max_hp), после чего аптечка должна исчезать. Другие персонажи могут игнорировать аптечку, или также "съедать ее" (на ваше усмотрение). Projectile-ы могут разрушать или не разрушать аптечку. Projectile как и другие объекты может наследоваться от Actor/GameObject (чтобы удобно было все объекты хранить и коллайдить).



## 3я часть Rogue-like игры.

1. Подключите библиотеку ncurses (pdcurses на винде), используйте ее для отрисовки карты в консоли. Можно использовать какую-нибудь другую библиотеку, если хочется.

2. Все константы должны храниться в config-файле. Таким образом, при изменении, например, hp героя, не нужно будет перекомпилировать игру. Не обязательно писать велосипеды, можно использовать существующие библиотеки для json/yaml/xml/ini и т.п.

3. Ваша игра должна быть realtime - монстры должны ходить не после того, как вы сделаете ход, а раз в какой-то промежуток времени (например, раз в секунду). Для нормального обновления консоли также используйте ncurses.



Всего в рогалике 3 задания, они оцениваются вместе. За 1 и 2 вы можете получить до 6 баллов, за 1, 2 и 3 до 8ми. Все что происходит в игре не должно приводить к странным ситуациям и падениям. За каждую найденную ситуацию при проверке -1 балл. До 10 баллов можно получить, дополнительно сделав какие-нибудь прикольные штуки, например:

1. Бесконечная карта (1 балл)
2. Редактор карт (1 балл)
3. Игровой интерфейс (1-2 балла в зависимости от сложности)
4. Туман войны (1 балл)
5. Полное покрытие юнит-тестами и интеграционными тестами (автоматическая проверка игровых сценариев) (1-2 балла в зависимости от сложности)

Или что угодно другое, что захочется:)
