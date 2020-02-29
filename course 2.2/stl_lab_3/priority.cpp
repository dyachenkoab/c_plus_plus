#include <iostream>
#include <list>
#include <string>

using namespace std;

typedef enum {
    LOW,
    NORMAL,
    HIGH
} ElementPriority;

typedef struct {
    string name;
} QueueElement;

class QueueWithPriority {

    list<QueueElement> list_elements;
    list<QueueElement>::iterator it_e;
    int high_priority_elements = 0;
    int low_priority_elements = 0;
    int normal_priority_elements = 0;

public:
// Конструктор, создает пустую очередь
    QueueWithPriority() : list_elements() {
    }

    // Деструктор
    ~QueueWithPriority() {}

    // Добавить в очередь элемент element с приоритетом priority
    void PutElementToQueue(const QueueElement &element, ElementPriority priority) {
        if (priority == LOW) {
            list_elements.push_front(element);
            low_priority_elements++;
        } else if (priority == HIGH) {
            it_e = list_elements.begin();
//            for (int i = 0; i < low_priority_elements+normal_priority_elements; ++i){
//                ++it_e;
//            }
            advance(it_e, low_priority_elements+normal_priority_elements);
            list_elements.insert(it_e, element);
            high_priority_elements++;
        } else {
            it_e = list_elements.begin();
//            for (int i = 0; i < low_priority_elements; ++i) {
//                ++it_e;
//            }
            advance(it_e, low_priority_elements);
            list_elements.insert(it_e, element);
            normal_priority_elements++;
        }
    }

    // Получить элемент из очереди
    // метод должен возвращать элемент с наибольшим приоритетом, который был
    // добавлен в очередь раньше других
    QueueElement GetElementFromQueue() {
        return list_elements.back();
    }

    // Выполнить акселерацию
    void Accelerate(){
        auto it = list_elements.begin();
        auto it_from = list_elements.begin();
        auto it_to = list_elements.begin();
        advance(it_to, low_priority_elements);
        advance(it, low_priority_elements+normal_priority_elements);

        list_elements.splice(it, list_elements, it_from, it_to);
    }

    void print(){
        for(auto i : list_elements){
            cout << i.name << " ";
        }
        cout << "\n";
    }
};


