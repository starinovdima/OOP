/*!
 * @file
 * @brief  The header file that represents the implementation of the template class Vector
 */

#ifndef LABA4_HOTEL_VECTOR_H
#define LABA4_HOTEL_VECTOR_H

/*!
 * @brief The namespace in which the file is implemented
 * contain all information about
 * table, methods, iterators and e.t.c.
 */

namespace My_vector {

    template <class T>

    /*!
     * @brief An iterator is a tool that helps iterate through the elements of a template class
     * @tparam T Any type of data that is represented in a vector
     * @param m_data An array consisting of n number of elements of type T
     */

    class VectorIt {

    private:
        /*!
         * @tparam T Any type of data that is represented in a vector
         * @param m_data An array consisting of n number of elements of type T
         */
        T *m_data;
    public:
        /*!
         * Default constructor for iterator
         * @post Pointer is initialized to zero
         */
        VectorIt() : m_data(0){}
        /*!
         * A constructor for an iterator initializing with an array of elements
         */
        VectorIt(T *v) : m_data(v) {}
        /*!
         * Copying Constructor
         * @post Marked as default
         */
        VectorIt(const VectorIt<T> &iterator) = default;
        /*!
         * Overloaded copy assignment operator for iterator
         * @post Marked as default
         */
        VectorIt<T> &operator = (const VectorIt<T> &) = default;
        /*!
         * Overloaded prefix increment operator ++ for iterator
         * @post Work as usual prefix increment
         *
         * @return Iterator with new position
         */
        VectorIt<T> &operator ++(){++m_data; return *this;}
        /*!
         * Overloaded postfix increment operator ++ for iterator
         * @post Work as usual postfix increment
         *
         * @return Iterator with new position
         */
        VectorIt<T> operator ++(int) {VectorIt<T> res(*this); ++m_data; return res;}
        /*!
         * Overloaded postfix increment operator -- for iterator
         * *@post Work as usual postfix increment
         *
         * @return Iterator with new position
         */
        VectorIt<T> &operator --() {--m_data; return *this;}
        /*!
         * Overloaded postfix increment operator -- for iterator
         * *@post Work as usual postfix increment
         *
         * @return Iterator with new position
         */
        VectorIt<T> operator --(int){VectorIt<T> res(*this); --m_data; return res;}
        /*!
         * Overloaded operator + for iterator
         * @post An integer is added to the iterator
         *
         * @param ind The value to which you want to shift the pointer positively
         * @return New copy of iterator, which contains new position of the pointer
         */
        VectorIt<T> operator +(int ind){ VectorIt<T> res(m_data + ind); return res;}
        /*!
         * Overloaded operator - for iterator
         * @post An integer is added to the iterator
         *
         * @param ind The value to which you want to shift the pointer positively
         * @return New copy of iterator, which contains new position of the pointer
         */
        VectorIt<T> operator -(int ind){ VectorIt<T> res(m_data - ind); return res;}
        /*!
         * Overloaded operator += for iterator
         *
         * @param ind The value to which you want to shift the pointer positively
         * @return The same iterator containing the new pointer position
         */
        VectorIt<T> operator +=(int ind){ m_data += ind; return *this;}
        /*!
         * Overloaded operator -= for iterator
         *
         * @param ind The value to which you want to shift the pointer positively
         * @return The same iterator containing the new pointer position
         */
        VectorIt<T> operator -=(int ind){ m_data -= ind; return *this;}
        /*!
         * Overloaded operator * for iterator
         *
         * @return Content by pointer to m_data
         */
        T &operator *() {return *m_data;}
        /*!
         * Overloaded operator -> for iterator
         *
         * @return The pointer to element of the table
         */
        T &operator ->(){return m_data;}
        /*!
         * Overloaded operator != for iterator
         *
         * @param it An iterator, with the address of which we will compare the address of an instance of the class
         * @return *false*, when the addresses match. *true* in another case
         */
        bool operator !=(const VectorIt<T> &it) {return m_data != it.m_data;}
        /*!
         * Overloaded operator == for iterator
         *
         * @param it An iterator, with the address of which we will compare the address of an instance of the class
         * @return *true*, when the addresses match. *false* in another case
         */
        bool operator ==(const VectorIt<T> &it) {return m_data == it.m_data;}
        /*!
         * Overloaded operator < for iterator
         *
         * @param iterator An iterator, with the address of which we will compare the address of an instance of the class
         * @return *true*, when *m_data < iterator.m_data*. *false* in another case
         */
        bool operator <(const VectorIt<T> &iterator){return m_data < iterator.m_data;}
        /*!
         * Overloaded operator > for iterator
         *
         * @param iterator An iterator, with the address of which we will compare the address of an instance of the class
         * @return *true*, when *m_data > iterator.m_data*. *false* in another case
         */
        bool operator >(const VectorIt<T> &iterator) {return m_data > iterator.m_data;}
        /*!
         * Overloaded operator <= for iterator
         *
         * @param iterator An iterator, with the address of which we will compare the address of an instance of the class
         * @return *true*, when *m_data <= iterator.m_data*. *false* in another case
         */
        bool operator >=(const VectorIt<T> &iterator) {return m_data >= iterator.m_data;}
        /*!
         * Overloaded operator >= for iterator
         *
         * @param iterator An iterator, with the address of which we will compare the address of an instance of the class
         * @return *true*, when *m_data >= iterator.m_data*. *false* in another case
         */
        bool operator <=(const VectorIt<T> &iterator) {return m_data <= iterator.m_data;}


    };

    template <class T>

    /*!
     * @brief Constant iterator, which contains methods and operators from input-tag-iterator
     * This iterator will work, when we will use constant methods in template class.
     * All variables in this kind of iterator stay constant
     * @post Further, to distinguish a constant iterator from an ordinary iterator, we will call it const_iterator
     *
     * @tparam T Any type of data that is represented in a vector
     * @param m_data An array consisting of n number of elements of type T
     */

    class VectorItconst : public VectorIt<T>{

    private:
        /*!
        * @tparam T Any type of data that is represented in a vector
        * @param m_data An array consisting of n number of elements of type T
        */
        const T *m_data;
    public:
        /*!
         * Default constructor for const_iterator
         * @post Pointer is initialized to zero
         */
        VectorItconst() : m_data(0){}
        /*!
         * A constructor for an const_iterator initializing with an array of elements
         */
        VectorItconst(const T *a) : m_data(a) {}

        /*!
         * Overloaded operator != for const_iterator
         *
         * @param it An iterator, with the address of which we will compare the address of an instance of the class
         * @return *true*, when the addresses match. *false* in another case
         */
        bool operator !=(const VectorItconst<T> &it) const{return m_data != it.m_data;}
        /*!
        * Overloaded operator == for const_iterator
        *
        * @param it An iterator, with the address of which we will compare the address of an instance of the class
        * @return *true*, when the addresses match. *false* in another case
        */
        bool operator ==(const VectorItconst<T> &it) const{return m_data == it.m_data;}
        /*!
         * Overloaded operator * for const_iterator
         *
         * @return Content by pointer to m_data
         */
        T &operator *() const {return *m_data;}
        /*!
         * Overloaded operator -> for const_iterator
         *
         * @return The pointer to element of the table
         */
        T &operator ->() const {return m_data;}


    };


    template<class T>

    /*!
     * @brief Template class is a vector containing an array of n elements of type T
     *
     * @param m_length_now The number of elements in the vector
     * @param size_Vector  Allocated memory size
     * @param T    The type of data in the vector
     * @param QOUTA The amount by which memory is allocated in the vector
     */

    class Vector {

    private:
        /*!
        * @tparam m_length_now The number of elements in the vector
        * @tparam size_Vector  Allocated memory size
        * @tparam T    The type of data in the vector
        * @tparam QOUTA The amount by which memory is allocated in the vector
        */
        int m_length_now;
        int size_Vector;
        T *m_data;
        const int QUOTA = 10;

    public:
        friend class VectorIt<T>;
        friend class VectorItconst<T>;
        /*!
         * Default constructor for Vector
         * @post Specifies a m_length_now value of 0
         * @post Specifies a size_Vector value of QUOTA
         * @post Allocates memory for an array
         */
        Vector() {
            m_length_now = 0;
            size_Vector = QUOTA;
            m_data = new T[QUOTA];
        }

        /*!
         * Constructor for vector
         * Creates a vector of the specified length
         * @param length The specified length of the vector
         */
        Vector(int length) {

            int n = length / QUOTA;
            if (length % QUOTA != 0)
                n++;
            m_data = new T[QUOTA * n];
            size_Vector = QUOTA * n;
            m_length_now = 0;

        }
        /*!
         * Copying Constructor
         * Creates an object based on another object
         * @param v the specified object
         */

        Vector(const Vector<T> &v){
            m_data = new T[v.size_Vector];
            m_length_now = v.m_length_now;
            size_Vector = v.size_Vector;
            for(int i = 0;i < m_length_now;i++){
                m_data[i] = v.m_data[i];
            }
        }
        /*!
         * Moving Constructor
         * It works like a copy, only it does not copy the array, but moves its pointer
         * @param v the specified object
         */

        Vector(Vector<T> &&v) : m_length_now(v.m_length_now), size_Vector(v.size_Vector),m_data(v.m_data)
        {
            v.m_data = nullptr;
        }
        /*!
         * Overloaded assignment operator =
         * Assigns all values of the passed vector to the given
         * @param v the object we want to assign
         * @return a reference to a vector
         */

        Vector & operator = (const Vector<T>& v){
            if(this != &v) {
                delete[] m_data;
                m_data = new T[v.size_Vector];
                m_length_now = v.m_length_now;
                size_Vector = v.size_Vector;
                for (int i = 0; i < m_length_now; i++) {
                    m_data[i] = v.m_data[i];
                }
            }
            return *this;
        }
        int getLength(){return m_length_now;}
        int getSizeVector(){return size_Vector;}

        /*!
         * Overloaded move operator
         * Moves all values of the passed vector to the given
         * @param v the object we want to assign
         * @return a reference to a vector
         */

        Vector & operator =(Vector<T> &&v){
            if(this != &v) {
                std::swap(m_length_now, v.m_length_now);
                std::swap(size_Vector, v.size_Vector);
                std::swap(m_data, v.m_data);
            }
            return *this;
        }

        /*!
         *  Destructor
         *  Frees up memory when an object goes out of view
         */

        ~Vector() {
            delete[] m_data;
        }

        /*!
         * Method swap(T &)
         * Swap the value of the transmitted vector and the current one
         * @param s transmitted vector
         */

        void swap(Vector<T> &s){
            std::swap(size_Vector,s.size_Vector);
            std::swap(m_length_now,s.m_length_now);
            std::swap(m_data,s.m_data);
        }
        /*!
         * Method clear()
         * Clears vector and memory
         */

        void clear() {
            delete[] m_data;
            m_data = nullptr;
            m_length_now = 0;
            size_Vector = 0;
        }
        /*!
         * Overloaded operator [] for template class
         * In fact, this operator is used when we want to change the value of the info field in the element with the given key.
         * \throw std::out_of_range When user goes out of bounds of the table, an exception is thrown informing him of this
         * @param index The key by which we get the value
         * @return Non-constant reference to info-field
         */

        T &operator[](int index) {
            if(index < 0 && index > m_length_now)
                throw std::out_of_range("Incorrect index");
            return m_data[index];
        }
        /*!
         * Overloaded operator [] for template class
         * We use this operator when we want to get the constant value of the information field of the table with the given key.
         * This operator does not change the state of the class member.
         * \throw std::out_of_range When user goes out of bounds of the table, an exception is thrown informing him of this
         * @param index The key by which we get the value
         * @return Constant reference to info-field
         */

        const T &operator[](int index) const {
            if(index < 0 && index > m_length_now)
                throw std::out_of_range("Incorrect index");
            return m_data[index];
        }
        /*!
         * Method empty()
         * Checks if the vector is empty
         * @return true when empty
         */

        bool empty(){
            if(m_length_now == 0)
                return true;
            return false;
        }
        /*!
         * Method erase(T &)
         * Excludes the passed element from the array
         * @param el The element we want to exclude from
         */

        void erase(T &el){

            int ind = getPos(el);
            if(ind == -1)
                throw std::invalid_argument("There is no such object in the vector");
            T *new_data = new T[size_Vector];
            for(int i = 0; i < m_length_now; i++) {
                if (i < ind)
                    new_data[i] = m_data[i];
                else if (i > ind)
                    new_data[i-1] = m_data[i];
            }
            delete [] m_data;
            m_length_now -= 1;
            m_data = new_data;

        }
        /*!
         * Method push_back(T &)
         * Adds an element to the end of the array
         * @param el The element we want to add
         */

        void push_back( T& el){
            if(m_length_now == size_Vector){
                int new_size = (size_Vector/QUOTA + 1);
                T *new_data = new T[new_size * QUOTA];
                for(int i = 0; i < m_length_now; i++){
                    new_data[i] = m_data[i];
                }
                size_Vector = new_size * QUOTA;
                delete [] m_data;
                m_data = new_data;
            }
            m_data[m_length_now] = el;
            m_length_now += 1;
        }

        /*!
         * Getter size()
         * Return number of elements
         * @return number of elements (int)
         */

        int size() const { return m_length_now; }

        /*!
         * Getter getPos(T &)
         * Finds the index of an element in a vector
         * @param s The element for which we want to find out the position in the vector
         * @return index of an element (int)
         */

        int getPos(T &s) const{
            for(int i = 0; i < m_length_now; i++){
                if(m_data[i] == s)
                    return i;
            }return -1;
        }
        /*!
         * Overloaded operator ==
         * Checks two vectors for similarity
         * @param v1 first vector
         * @param v2 second vector
         * @return true if the vectors match, false another
         */

        friend bool operator == (const Vector<T> &v1,const Vector<T> &v2){
            if(v1.m_length_now != v2.m_length_now)
                return false;
            for(int i = 0; i < v1.m_length_now; i++){
                if(v1.m_data[i] != v2.m_data[i])
                    return false;
            }
            return true;
        }
        /*!
         * Overloaded operator ==
         * Checks two vectors for similarity
         * @param v1 first vector
         * @param v2 second vector
         * @return false if the vectors match, true another
         */
        friend bool operator != (const Vector<T> &v1,const Vector<T> &v2){
            return !(v1 == v2);
        }

        typedef VectorItconst<T> IteratorC;
        /*!
         * Method cbegind() for template class Table
         * Made to loop through a templated class using a const_iterator
         *
         * @return Const_iterator, which contains const pointer on the first element of the table
         */
        IteratorC cbegin() const {return VectorItconst<T>(this->m_data);}
        /**
         * Method cend() for template class Table
         * Made to loop through a templated class using a const_iterator
         *
         * @return Const_iterator, which contains const pointer on the last element of the table
         */
        IteratorC cend() const{return VectorItconst<T>(this->m_data+m_length_now);}
        /*!
         * Method cfind(const T&) for template class
         * This method begins to iterate through the entire contents of the table using a
         * const_iterator until it finds an element whose key matches the given key.
         *
         * @param s The key by which we get the iterator
         * @return Const_iterator, which contains constant pointer on element table
         */
        IteratorC cfind(const T &s) const{
            int i = getPos(s);
            if(i < 0)
                i = m_length_now;
            return VectorItconst<T>(this->m_data + i);
        }


        typedef VectorIt<T> Iterator;
        /*!
         * Method begin() for template class Table
         * Made to loop through a templated class using an iterator
         *
         * @return Iterator, which contains pointer on the first element of the table
         */
        Iterator begin(){return VectorIt<T>(this->m_data);}
        /**
         * Method begin() for template class Table
         * Made to loop through a templated class using an iterator
         *
         * @return Iterator, which contains pointer on the last element of the table
         */
        Iterator end(){return VectorIt<T>(this->m_data + m_length_now) ;}
        /*!
         * Method find(const T&) for template class
         * This method begins to iterate through the entire contents of the table using an
         * iterator until it finds an element whose key matches the given key.
         *
         * @param s The key by which we get the iterator
         * @return Iterator, which contains pointer on element table
         */
        Iterator find(const T &s) {
            int i = getPos(s);
            if(i < 0)
                i = m_length_now;
            return VectorIt<T>(this->m_data + i);
        }

        void sorted(){
            int i = 1, j = 2;
            while (i < m_length_now)
            {
                if (m_data[i-1] < m_data[i]) {
                    i=j;
                    j++;
                }
                else
                {
                    int temp=m_data[i];
                    m_data[i]=m_data[i-1];
                    m_data[i-1]=temp;
                    i--;
                    if (i==0) {
                        i=j;
                        j++;
                    }
                }
            }
        }

        void up_vector(int how_much){
            this->clear();
            int n = how_much / QUOTA;
            if (how_much % QUOTA != 0)
                n++;
            m_data = new T[QUOTA * n];
            size_Vector = QUOTA * n;
            m_length_now = 0;
        }

    };



}

#endif //LABA4_HOTEL_VECTOR_H
