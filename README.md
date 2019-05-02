# C-Winform-Project

TEMPLATE 
Параметрический  один или много код в раз типа. Форма обобшеного стека. Привращается.
Template <class иден - аргимент шаблона, посуществу 
Template <class T>
Class Stack
{
	~Stack(){delete {}s;}
	T pop(){return s[top-1];}
T top() const{return s[top];}
}
Stack <char> obj1;
Stack <char> obj2;
  template <Class T>
T Stack<T>::Top()const{
  return s[top];}
template <class T>
  Stack<T>::~Stack(){delete[]s;}
  // Stack<char>obj1;
  // Stack<int>obj2;
template<class T>
  void swap(T&x, T&y)
  {
    T tmp;
    tmp = x;
    x=y;
    y = tmp;
  }
  template <class T>
  void swap( T*x, T*y)
  {
    T tmp;
    tmp=*x;
    *x = *y;
    *y = tmp;
    }
  int x,y;
  void swap(T*, T*);
  swap(&x, &y);
