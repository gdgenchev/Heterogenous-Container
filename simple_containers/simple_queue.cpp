#include "../containers/container.h"

template <typename T>
class SimpleQueue : public Container<T>, public Queue<T> {
public:
    //checking for member while reconstructing the queue.
    bool member(const T& x) {
        bool flag = false;
        int queueSize = Queue<T>::size();
        while (queueSize != 0) {
            T front = Queue<T>::front();
            if (front == x){
                flag = true;
            }
            Queue<T>::pop();
            Queue<T>::push(front);
            --queueSize;
        }
        return flag;
    }

    void push(const T& x) {
        Queue<T>::push(x);
    }

    void pop() {
        Queue<T>::pop();
    }

    Iterator<T> getFirst() {
        return Iterator<T>(Queue<T>::getFront());
    }

    Iterator<T> getLast() {
        return Iterator<T>(Queue<T>::getEnd());
    }
    bool getIteratorForX(const T& x,Iterator<T>& itX) {
        Iterator<T> it(Queue<T>::getFront());
        while (it.valid()) {
            if (x == *it) {
                itX = it;
                return true;
            }
            ++it;
        }
        return false;
    }

    void removeElementsIf(Condition<T> condition) {
        int queueSize = Queue<T>::size();
        while (queueSize != 0) {
            T front = Queue<T>::front();
            if (!condition(front)) {
                Queue<T>::push(front);
            }
            Queue<T>::pop();
            --queueSize;
        }
    }


    int size() const {
        return Queue<T>::size();
    }

    void sort() override {
        std::vector<T> v;
        while(!Queue<T>::isEmpty()) {
            v.push_back(Queue<T>::front());
            Queue<T>::pop();
        }
        std::sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++) {
            Queue<T>::push(v[i]);
        }
    }

    bool isConditionValid (Condition<T> condition) {
        int queueSize = Queue<T>::size();
        while (queueSize != 0) {
            T front= Queue<T>::front();
            if (condition(front)) {
                return true;
            }
            Queue<T>::pop();
            Queue<T>::push(front);
            --queueSize;
        }
        return false;
    }

    void print(std::ostream& os) const {
        Queue<T>::print(os);
    }
};
