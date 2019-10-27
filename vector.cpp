
template< typename T, unsigned N > 
class vector
{
public:
    void push_back(T && t)
    {
        if ( _size < _cap - 1 )
        {
            new (_mem + _size) T(std::forward<T>(t));
            ++_size;
            return;
        }
        //need to expand
        auto expand = [this](T && t)
        {
            T * _p = (T*) new char[sizeof(T)*_cap*2];
            for (int i=0; i < _size; ++i)
            {
                auto * p = _mem + i;
                new (_p+i) T (std::move(*p));
                p->~T();
            }
            new (_p + _size) T(std::forward<T>(t));
            ++_size;
            _cap *= 2;
            if (_mem != &_data)
                delete (char*)_mem;
            _mem = _p;
        }
        expand(std::forward<T>(t));
    }

    unsigned size() const { return _size; }

    T * _mem = &_data[0];
    unsigned _size = 0;
    unsigned _cap = N;
    char _data[sizeof(T)*N];
};