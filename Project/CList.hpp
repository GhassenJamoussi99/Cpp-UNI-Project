#ifndef CLIST_H
#define CLIST_H

#include <cassert>


template <class T>
class CList
{
   struct ListElement
   {
      T data;
      ListElement *next, *prev;
      ListElement()    // Konstruktor
      : next(NULL), prev(NULL)
      {}
   };

   ListElement *first, *last;
   unsigned count;
public:
   CList()
   : first(NULL), last(NULL), count(0)
   {}
   CList(const CList &);
   virtual ~CList();

   CList& operator=(const CList&);

   bool     empty() const { return count == 0; }
   unsigned size()  const { return count;      }

   void push_front(const T&);
   void push_back(const T&);

   void pop_front();
   void pop_back();

   T& front();
   const T& front() const;
   T& back();
   const T& back() const;

   // Input-Iterator als geschachtelte Klasse
   class iterator
   {
      ListElement *actElement;
   public:
      friend class CList<T>;

      iterator(ListElement *init = NULL)
      : actElement(init)
      {}

      iterator(const CList &l)
      {  *this = l.begin();  }

      T& operator*()
      {  return actElement->data;  }

      const T& operator*() const
      {  return actElement->data;  }

      iterator& operator++ () // prefix
      {
         if (actElement)
            actElement = actElement->next;
         return *this;
      }

      iterator operator++(int) // postfix
      {
         iterator temp = *this;
         ++*this;
         return temp;
      }

      bool operator==(const iterator &x) const
      {  return actElement == x.actElement;  }

      bool operator!=(const iterator &x) const
      {  return actElement != x.actElement;  }

   }; // Ende der geschachtelten Klasse iterator

   // Methoden der Klasse CList,
   // die den Iterator ben�tigen

   iterator begin() const {  return iterator(first);  }
   iterator end()   const {  return iterator();       }

   void erase(iterator &pos)
   {
      if (pos.actElement == first)
      {
         pop_front();
         pos.actElement = first;
      }
      else if (pos.actElement == last)
      {
         pop_back();
         pos.actElement = last;
      }
      else
      {
         pos.actElement->next->prev = pos.actElement->prev;
         pos.actElement->prev->next = pos.actElement->next;
         ListElement *temp = pos.actElement;
         pos.actElement = pos.actElement->next;
         delete temp;
         count--;
      }
   }

   iterator insert(iterator pos, const T& data)
   {
      if (pos == begin())
      {
         push_front(data);
         return iterator(first);
      }
      if (pos == end())
      {
         push_back(data);
         return iterator(last);
      }
      ListElement *temp = new ListElement;
      temp->data = data;
      temp->next = pos.actElement;
      temp->prev = pos.actElement->prev;
      pos.actElement->prev->next = temp;
      pos.actElement->prev = temp;
      count++;
      return iterator(temp);
   }

}; // class CList

template <class T>
inline CList<T>::CList(const CList<T> &l)
: first(NULL), last(NULL), count(0)
{
   ListElement *temp = l.last;
   while (temp)
   {
      push_front(temp->data);
      temp = temp->prev;
   }
}

template <class T>
inline CList<T>::~CList()
{
   while (count)
      pop_front();
}

template <class T>
inline CList<T>& CList<T>::operator=(const CList<T> &l)
{
   if (this != &l) // Selbstzuweisung ausschlie�en
   {
      while (count)
         pop_front(); // alles loeschen
      // ... und neu aufbauen
      ListElement *temp = l.last;
      while (temp)
      {
         push_front(temp->data);
         temp = temp->prev;
      }
   }
   return *this;
}

template <class T>
inline void CList<T>::push_front(const T &data)
{
   ListElement *temp = new ListElement;

   temp->data = data;
   temp->next = first;
   if (!first)     // war Liste vorher leer?
      last = temp; // dann letztes = neues Element
   else
      first->prev = temp;
   first = temp;
   count++;
}

template <class T>
inline void CList<T>::push_back(const T &data)
{
   ListElement *temp = new ListElement;

   temp->data = data;
   temp->prev = last;
   if (!last)       // war Liste vorher leer?
      first = temp; // dann erstes = neues Element
   else
      last->next = temp;
   last = temp;
   count++;
}

template <class T>
inline void CList<T>::pop_front()
{
   if (count > 0)
   {
      ListElement *temp = first;

      first = first->next;
      if (!first)       // kein weiteres Element vorhanden?
         last = NULL;
      else
         first->prev = NULL;
      delete temp;
      count--;
   }
}

template <class T>
inline void CList<T>::pop_back()
{
   if (count > 0)
   {
      ListElement *temp = last;

      last = last->prev;
      if (!last)       // kein weiteres Element vorhanden?
         first = NULL;
      else
         last->next = NULL;
      delete temp;
      count--;
   }
}

template <class T>
inline T& CList<T>::front()
{
   assert(count > 0);
   return first->data;
}

template <class T>
inline const T& CList<T>::front() const
{
   assert(count > 0);
   return first->data;
}

template <class T>
inline T& CList<T>::back()
{
   assert(count > 0);
   return last->data;
}

template <class T>
inline const T& CList<T>::back() const
{
   assert(count > 0);
   return last->data;
}

#endif // CLIST_H
