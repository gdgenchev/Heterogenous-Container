#include "../containers/container.h"

template <typename T>
class SimpleStack : public Container<T>, public Stack<T>{
private:
    void reconstructStack(std::vector<T> v) {
        for (int i = v.size() - 1; i >= 0; i--) {
            push(v[i]);
        }
    }
public:
    bool member(const T& x) {
        std::vector<T> v;
        bool flag = false;
        while (!Stack<T>::isEmpty()) {
            T topEl = Stack<T>::top();
            if (topEl == x) {
                flag = true;
                break;
            }
            v.push_back(topEl);
            pop();
        }
        reconstructStack(v);
        return flag;
    }

    void push(const T& x) {
        Stack<T>::push(x);
    }

    void pop() {
        Stack<T>::pop();
    }

    Iterator<T> getFirst() {
        Stack<T>::getTop();
    }

    Iterator<T> getLast() {
        Stack<T> reversed;
        Iterator<T> it(Stack<T>::getTop());
        while (it.valid()) {
            reversed.push(*it);
            ++it;
        }
        return  Iterator<T>(reversed.getTop());
    }

    bool getIteratorForX(const T& x, Iterator<T>& itX) {
        Iterator<T> it(getFirst());
        while (it.valid()) {
            if (*it == x) {
                itX = it;
                return true;
            }
            ++it;
        }
        return false;
    }

    void removeElementsIf(Condition<T> condition) {
        std::vector<T> v;
        while (!Stack<T>::isEmpty()) {
            T topEl = Stack<T>::top();
            if (!condition(topEl)) {
                v.push_back(topEl);
            }
            pop();
        }
        reconstructStack(v);
    }

    int size() const {
        return Stack<T>::size();
    }

    void sort() {
        if (!Stack<T>::isEmpty()) {
            T topEl = Stack<T>::top();
            pop();
            sort();
            insert(topEl);
        }
    }

    void insert(int topEl) {
        if (!Stack<T>::isEmpty()) {
            T nextTopEl = Stack<T>::top();
            if (topEl > nextTopEl) {
                Stack<T>::pop();
                insert(topEl);
                Stack<T>::push(nextTopEl);
            } else {
                Stack<T>::push(topEl);
            }
        } else {
            Stack<T>::push(topEl);
        }
    }

    bool isConditionValid (Condition<T> condition) {
        std::vector<T> v;
        bool flag = false;
        while (!Stack<T>::isEmpty()) {
            T topEl = Stack<T>::top();
            if (condition(topEl)) {
                flag = true;
                break;
            }
            v.push_back(topEl);
            pop();
        }
        reconstructStack(v);
        return flag;
    }

    void print(std::ostream& os) const {
        Iterator<T> it(Stack<T>::getTop());
        std::vector<int> values;
        for (it; it.valid(); ++it) {
            values.push_back(*it);
        }
        os << "Stack:";
        for (int i = values.size() - 1; i >= 0; --i) {
            os << " " <<values[i];
        }
        os << std::endl;
    }
};