#include<bits/stdc++.h>
using namespace std;

template<typename T, int size>
class Stack {
        T m_Buffer[size];
        int m_Top = -1;
public: 
        Stack() = default;
        Stack(const Stack &obj) {
                m_Top = obj.m_Top;
                for(int i=0; i<= m_Top; ++i) {
                        m_Buffer[i] = obj.m_Buffer[i];
                }
        }
        void Push(T elem) {
                m_Buffer[++m_Top] = elem;
        }
        // outside the class 
        void Pop();

        const T& Top() const {
                return m_Buffer[m_Top];
        }
        bool empty() {
                return m_Top == -1;
        }
        static Stack Create() {
                return Stack<T, size>();
        }
};

template<typename T, int size>
void Stack<T, size>::Pop() {
        --m_Top;
}

int main() {
        Stack<float, 10> s;
        s.Push(3.5);
        s.Push(4.22);
        s.Push(1.0);
        while(!s.empty()) {
                cout << s.Top() << " ";
                s.Pop();
        }

        auto s2(s);

        Stack<string, 10> s1;
        s1.Push("diago");
        s1.Push("san");
        s1.Push("love");
        while(!s1.empty()) {
                cout << s1.Top() << " ";
                s1.Pop();
        }

        auto s = Stack<float, 10>::Create();


}